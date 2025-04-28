#include <stdio.h>
#include <string.h>
#include "ReaderManager.h"

// Hàm hiển thị thông tin một độc giả
void displayReader(const char readerIds[], const char fullNames[], const char idCards[],
                   const char birthDates[], const char genders[], const char emails[],
                   const char addresses[], const char cardIssueDates[], const char cardExpiryDates[], int index, int fieldSize)
{
    int idx = index * fieldSize;
    printf("\n=== THONG TIN DOC GIA ===\n");
    printf("Ma doc gia: %s\n", &readerIds[idx]);
    printf("Ho ten: %s\n", &fullNames[idx]);
    printf("CMND: %s\n", &idCards[idx]);
    printf("Ngay sinh: %s\n", &birthDates[idx]);
    printf("Gioi tinh: %s\n", &genders[idx]);
    printf("Email: %s\n", &emails[idx]);
    printf("Dia chi: %s\n", &addresses[idx]);
    printf("Ngay lap the: %s\n", &cardIssueDates[idx]);
    printf("Ngay het han: %s\n", &cardExpiryDates[idx]);
    printf("------------------------\n");
}

// Hàm hiển thị danh sách độc giả
void displayReaders(const char readerIds[], const char fullNames[], const char idCards[],
                    const char birthDates[], const char genders[], const char emails[],
                    const char addresses[], const char cardIssueDates[], const char cardExpiryDates[], int size, int fieldSize)
{
    if (size == 0)
    {
        printf("Khong co doc gia nao trong thu vien!\n");
        return;
    }

    printf("\n=== DANH SACH DOC GIA ===\n");
    for (int i = 0; i < size; i++)
    {
        displayReader(readerIds, fullNames, idCards, birthDates, genders, emails, addresses, cardIssueDates, cardExpiryDates, i, fieldSize);
    }
}
