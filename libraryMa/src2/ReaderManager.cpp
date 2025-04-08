#include <iostream>
#include <cstring>
#include <cstdio>
#include "../include/ReaderManager.h"

using namespace std;

const int FIELD_SIZE = 50;
const int FIELD_COUNT = 9;

// Hàm hiển thị danh sách độc giả
void displayReaders(
    const char readerIds[], const char fullNames[], const char idCards[],
    const char birthDates[], const char genders[], const char emails[],
    const char addresses[], const char cardIssueDates[], const char cardExpiryDates[],
    int size, int fieldSize)
{
    if (size == 0)
    {
        printf("Khong co doc gia nao trong thu vien!\n");
        return;
    }
    printf("\n=== DANH SACH DOC GIA ===\n");
    for (int i = 0; i < size; i++)
    {
        int index = i * fieldSize;
        printf("Ma doc gia: %s\n", &readerIds[index]);
        printf("Ho ten: %s\n", &fullNames[index]);
        printf("CMND: %s\n", &idCards[index]);
        printf("Ngay sinh: %s\n", &birthDates[index]);
        printf("Gioi tinh: %s\n", &genders[index]);
        printf("Email: %s\n", &emails[index]);
        printf("Dia chi: %s\n", &addresses[index]);
        printf("Ngay lap the: %s\n", &cardIssueDates[index]);
        printf("Ngay het han: %s\n", &cardExpiryDates[index]);
        printf("------------------------\n");
    }
}

// Hàm thêm độc giả vào mảng
void addReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &size, int fieldSize, const char newReader[])
{
    int index = size * fieldSize;
    
    // Sao chép từng thuộc tính vào mảng tương ứng
    memcpy(&readerIds[index], &newReader[0 * fieldSize], fieldSize);
    memcpy(&fullNames[index], &newReader[1 * fieldSize], fieldSize);
    memcpy(&idCards[index], &newReader[2 * fieldSize], fieldSize);
    memcpy(&birthDates[index], &newReader[3 * fieldSize], fieldSize);
    memcpy(&genders[index], &newReader[4 * fieldSize], fieldSize);
    memcpy(&emails[index], &newReader[5 * fieldSize], fieldSize);
    memcpy(&addresses[index], &newReader[6 * fieldSize], fieldSize);
    memcpy(&cardIssueDates[index], &newReader[7 * fieldSize], fieldSize);
    memcpy(&cardExpiryDates[index], &newReader[8 * fieldSize], fieldSize);
    
    size++;
}

// Hàm chỉnh sửa độc giả dựa trên mã độc giả
bool editReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int size, int fieldSize, const char targetId[], const char updatedReader[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * fieldSize;
        if (strcmp(&readerIds[index], targetId) == 0)
        {
            // Sao chép từng thuộc tính từ updatedReader vào mảng tương ứng
            memcpy(&readerIds[index], &updatedReader[0 * fieldSize], fieldSize);
            memcpy(&fullNames[index], &updatedReader[1 * fieldSize], fieldSize);
            memcpy(&idCards[index], &updatedReader[2 * fieldSize], fieldSize);
            memcpy(&birthDates[index], &updatedReader[3 * fieldSize], fieldSize);
            memcpy(&genders[index], &updatedReader[4 * fieldSize], fieldSize);
            memcpy(&emails[index], &updatedReader[5 * fieldSize], fieldSize);
            memcpy(&addresses[index], &updatedReader[6 * fieldSize], fieldSize);
            memcpy(&cardIssueDates[index], &updatedReader[7 * fieldSize], fieldSize);
            memcpy(&cardExpiryDates[index], &updatedReader[8 * fieldSize], fieldSize);
            return true; // Chỉnh sửa thành công
        }
    }
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
