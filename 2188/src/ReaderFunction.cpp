#include <stdio.h>
#include <string.h>
#include "ReaderManager.h"

void addReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &size, int fieldSize,
    const char newReaderId[], const char newFullName[], const char newIdCard[],
    const char newBirthDate[], const char newGender[], const char newEmail[],
    const char newAddress[], const char newCardIssueDate[], const char newCardExpiryDate[])
{
    if (size >= fieldSize) {
        printf("Danh sach doc gia da day, khong the them!\n");
        return;
    }

    int index = size * fieldSize;

    // Sao chép từng giá trị vào mảng tương ứng
    strncpy(&readerIds[index], newReaderId, fieldSize - 1);
    readerIds[index + fieldSize - 1] = '\0';

    strncpy(&fullNames[index], newFullName, fieldSize - 1);
    fullNames[index + fieldSize - 1] = '\0';

    strncpy(&idCards[index], newIdCard, fieldSize - 1);
    idCards[index + fieldSize - 1] = '\0';

    strncpy(&birthDates[index], newBirthDate, fieldSize - 1);
    birthDates[index + fieldSize - 1] = '\0';

    strncpy(&genders[index], newGender, fieldSize - 1);
    genders[index + fieldSize - 1] = '\0';

    strncpy(&emails[index], newEmail, fieldSize - 1);
    emails[index + fieldSize - 1] = '\0';

    strncpy(&addresses[index], newAddress, fieldSize - 1);
    addresses[index + fieldSize - 1] = '\0';

    strncpy(&cardIssueDates[index], newCardIssueDate, fieldSize - 1);
    cardIssueDates[index + fieldSize - 1] = '\0';

    strncpy(&cardExpiryDates[index], newCardExpiryDate, fieldSize - 1);
    cardExpiryDates[index + fieldSize - 1] = '\0';

    size++;
    printf("Them doc gia thanh cong!\n");
}


bool editReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int size, int fieldSize, const char targetId[],
    const char newReaderId[], const char newFullName[], const char newIdCard[],
    const char newBirthDate[], const char newGender[], const char newEmail[],
    const char newAddress[], const char newCardIssueDate[], const char newCardExpiryDate[])
{
    for (int i = 0; i < size; i++) {
        int index = i * fieldSize;
        if (strcmp(&readerIds[index], targetId) == 0) {
            // Sao chép từng giá trị mới vào mảng tương ứng
            strncpy(&readerIds[index], newReaderId, fieldSize - 1);
            readerIds[index + fieldSize - 1] = '\0';
            strncpy(&fullNames[index], newFullName, fieldSize - 1);
            fullNames[index + fieldSize - 1] = '\0';
            strncpy(&idCards[index], newIdCard, fieldSize - 1);
            idCards[index + fieldSize - 1] = '\0';
            strncpy(&birthDates[index], newBirthDate, fieldSize - 1);
            birthDates[index + fieldSize - 1] = '\0';
            strncpy(&genders[index], newGender, fieldSize - 1);
            genders[index + fieldSize - 1] = '\0';
            strncpy(&emails[index], newEmail, fieldSize - 1);
            emails[index + fieldSize - 1] = '\0';
            strncpy(&addresses[index], newAddress, fieldSize - 1);
            addresses[index + fieldSize - 1] = '\0';
            strncpy(&cardIssueDates[index], newCardIssueDate, fieldSize - 1);
            cardIssueDates[index + fieldSize - 1] = '\0';
            strncpy(&cardExpiryDates[index], newCardExpiryDate, fieldSize - 1);
            cardExpiryDates[index + fieldSize - 1] = '\0';

            return true; // Chỉnh sửa thành công
        }
    }
    printf("Khong tim thay doc gia voi ID: %s\n", targetId);
    return false; // Không tìm thấy độc giả
}

// Hàm xóa độc giả dựa trên mã độc giả
bool deleteReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &size, int fieldSize, const char targetId[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * fieldSize;
        if (strcmp(&readerIds[index], targetId) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                // Di chuyển từng thuộc tính từ phần tử tiếp theo lên phần tử hiện tại
                memcpy(&readerIds[j * fieldSize], &readerIds[(j + 1) * fieldSize], fieldSize);
                memcpy(&fullNames[j * fieldSize], &fullNames[(j + 1) * fieldSize], fieldSize);
                memcpy(&idCards[j * fieldSize], &idCards[(j + 1) * fieldSize], fieldSize);
                memcpy(&birthDates[j * fieldSize], &birthDates[(j + 1) * fieldSize], fieldSize);
                memcpy(&genders[j * fieldSize], &genders[(j + 1) * fieldSize], fieldSize);
                memcpy(&emails[j * fieldSize], &emails[(j + 1) * fieldSize], fieldSize);
                memcpy(&addresses[j * fieldSize], &addresses[(j + 1) * fieldSize], fieldSize);
                memcpy(&cardIssueDates[j * fieldSize], &cardIssueDates[(j + 1) * fieldSize], fieldSize);
                memcpy(&cardExpiryDates[j * fieldSize], &cardExpiryDates[(j + 1) * fieldSize], fieldSize);
            }
            size--;
            return true;
        }
    }
    return false;
}

// Hàm tìm kiếm độc giả theo CMND
int searchReaderByCMND(
    const char idCards[], int size, int fieldSize, const char targetCmnd[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * fieldSize;
        if (strcmp(&idCards[index], targetCmnd) == 0)
        {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// Hàm tìm kiếm độc giả theo họ tên
int searchReaderByName(
    const char fullNames[], int size, int fieldSize, const char targetName[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * fieldSize;
        if (strcmp(&fullNames[index], targetName) == 0)
        {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}
