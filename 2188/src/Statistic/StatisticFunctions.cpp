#include <stdio.h>
#include <string.h>
#include <cstdlib>

#include "StatisticFunctions.h"

// Hàm thống kê số lượng sách trong thư viện
void countBooks(const char quantities[], int size, int maxLen)
{
    int totalBooks = 0;
    for (int i = 0; i < size; i++)
    {
        int index = i * maxLen;
        totalBooks += atoi(&quantities[index]); // Chuyển chuỗi số lượng thành số nguyên
    }
    printf("Tong so luong sach trong thu vien: %d\n", totalBooks);
}

// Hàm thống kê số lượng sách theo thể loại
void countBooksByGenre(const char genres[], const char quantities[], int size, int maxLen)
{
    if (size == 0)
    {
        printf("Khong co sach nao trong thu vien!\n");
        return;
    }
    printf("\n=== THONG KE SACH THEO THE LOAI ===\n");
    char genreList[100][maxLen];
    int counts[100] = {0};
    int genreCount = 0;

    for (int i = 0; i < size; i++)
    {
        int index = i * maxLen;
        bool found = false;
        for (int j = 0; j < genreCount; j++)
        {
            if (strcmp(&genres[index], genreList[j]) == 0)
            {
                counts[j] += atoi(&quantities[index]);
                found = true;
                break;
            }
        }
        if (!found)
        {
            strcpy(genreList[genreCount], &genres[index]);
            counts[genreCount] = atoi(&quantities[index]);
            genreCount++;
        }
    }

    for (int i = 0; i < genreCount; i++)
    {
        printf("The loai %s: %d quyen\n", genreList[i], counts[i]);
    }
}

// Hàm thống kê số lượng độc giả
void countReaders(int size, int fieldSize)
{
    printf("Tong so luong doc gia: %d\n", size);
}

// Hàm thống kê số lượng độc giả theo giới tính
void countReadersByGender(const char genders[], int size, int fieldSize)
{
    int male = 0, female = 0, other = 0;
    for (int i = 0; i < size; i++)
    {
        int index = i * fieldSize;
        if (strcmp(&genders[index], "Nam") == 0)
            male++;
        else if (strcmp(&genders[index], "Nu") == 0)
            female++;
        else
            other++;
    }
    printf("So luong doc gia nam: %d\n", male);
    printf("So luong doc gia nu: %d\n", female);
    printf("So luong doc gia khac: %d\n", other);
}

// Hàm thống kê số sách đang được mượn
void countBorrowedBooks(const char actualReturnDates[], const char bookISBNs[], int borrowSize, int fieldSize)
{
    int borrowedBooks = 0;
    for (int i = 0; i < borrowSize; i++)
    {
        int index = i * fieldSize;
        if (strcmp(&actualReturnDates[index], "0-0-0") == 0)
        { // Chưa trả
            const char *isbnList = &bookISBNs[index];
            int len = strlen(isbnList);
            int commaCount = 0;
            for (int j = 0; j < len; j++)
            {
                if (isbnList[j] == ',')
                {
                    commaCount++;
                }
            }
            borrowedBooks += commaCount + 1; // Đếm số ISBN (số dấu phẩy + 1)
        }
    }
    printf("So luong sach dang duoc muon: %d\n", borrowedBooks);
}

// Hàm thống kê danh sách độc giả bị trễ hạn
void listOverdueReaders(
    const char readerIds[], const char borrowDates[], const char dueDates[],
    const char actualReturnDates[], int borrowSize, int borrowFieldSize,
    const char readers[], const char fullNames[], int readerSize, int readerFieldSize)
{
    printf("\n=== DANH SACH DOC GIA TRE HAN ===\n");
    int found = 0;

    char currentDate[11];
    printf("Nhap ngay hien tai (dd-mm-yyyy): ");
    scanf("%10s", currentDate);

    int currDay = (currentDate[0] - '0') * 10 + (currentDate[1] - '0');
    int currMonth = (currentDate[3] - '0') * 10 + (currentDate[4] - '0');
    int currYear = (currentDate[6] - '0') * 1000 + (currentDate[7] - '0') * 100 +
                   (currentDate[8] - '0') * 10 + (currentDate[9] - '0');
    int currentDays = currYear * 360 + currMonth * 30 + currDay;

    for (int i = 0; i < borrowSize; i++)
    {
        int bIndex = i * borrowFieldSize;

        if (strcmp(&actualReturnDates[bIndex], "0-0-0") == 0)
        {
            int dueDay = (dueDates[bIndex] - '0') * 10 + (dueDates[bIndex + 1] - '0');
            int dueMonth = (dueDates[bIndex + 3] - '0') * 10 + (dueDates[bIndex + 4] - '0');
            int dueYear = (dueDates[bIndex + 6] - '0') * 1000 + (dueDates[bIndex + 7] - '0') * 100 +
                          (dueDates[bIndex + 8] - '0') * 10 + (dueDates[bIndex + 9] - '0');
            int dueDays = dueYear * 360 + dueMonth * 30 + dueDay;

            if (currentDays > dueDays)
            {
                for (int j = 0; j < readerSize; j++)
                {
                    int rIndex = j * readerFieldSize;
                    if (strcmp(&readers[rIndex], &readerIds[bIndex]) == 0)
                    {
                        printf("Ma doc gia: %s\n", &readers[rIndex]);
                        printf("Ho ten: %s\n", &fullNames[rIndex]);
                        printf("Ngay muon: %s\n", &borrowDates[bIndex]);
                        printf("Ngay tra du kien: %s\n", &dueDates[bIndex]);
                        printf("So ngay tre han: %d\n", currentDays - dueDays);
                        printf("------------------------\n");
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    if (!found)
    {
        printf("Khong co doc gia nao tre han!\n");
    }
}