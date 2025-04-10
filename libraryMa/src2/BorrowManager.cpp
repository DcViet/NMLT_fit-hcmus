#include <stdio.h>
#include <string.h>
#include "../include2/BorrowManager.h"

void createBorrowTicket(
    char readerIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &ticketSize, int maxTickets, int fieldSize,
    const char readerId[], const char borrowDate[],
    const char dueDate[], const char bookISBNsInput[])
{
    if (ticketSize >= maxTickets)
    {
        printf("Khong the tao them phieu muon!\n");
        return;
    }

    int index = ticketSize * fieldSize;

    strncpy(&readerIds[index], readerId, fieldSize);
    readerIds[index + fieldSize - 1] = '\0';

    strncpy(&borrowDates[index], borrowDate, fieldSize);
    borrowDates[index + fieldSize - 1] = '\0';

    strncpy(&dueDates[index], dueDate, fieldSize);
    dueDates[index + fieldSize - 1] = '\0';

    strncpy(&actualReturnDates[index], "0-0-0", fieldSize);
    actualReturnDates[index + fieldSize - 1] = '\0';

    strncpy(&bookISBNs[index], bookISBNsInput, fieldSize);
    bookISBNs[index + fieldSize - 1] = '\0';

    ticketSize++;
    printf("Phieu muon da duoc tao thanh cong!\n");
}

void createReturnTicket(
    char borrowTickets[], int ticketSize,
    char returnTickets[], int &returnSize, int maxReturns,
    const char readerId[], const char returnDate[],
    const char bookISBNs[], int bookCount, const int bookPrices[], const bool bookLost[])
{
    if (returnSize >= maxReturns)
    {
        printf("Khong the tao them phieu tra!\n");
        return;
    }

    int index = returnSize;
    returnTickets[index++] = strlen(readerId);
    memcpy(&returnTickets[index], readerId, strlen(readerId));
    index += strlen(readerId);

    returnTickets[index++] = strlen(returnDate);
    memcpy(&returnTickets[index], returnDate, strlen(returnDate));
    index += strlen(returnDate);

    returnTickets[index++] = bookCount;
    int totalFine = 0;

    for (int i = 0; i < bookCount; i++)
    {
        int isbnLen = bookISBNs[i * 20];
        returnTickets[index++] = isbnLen;
        memcpy(&returnTickets[index], &bookISBNs[i * 20 + 1], isbnLen);
        index += isbnLen;

        if (bookLost[i])
        {
            totalFine += bookPrices[i] * BOOK_FINE_PERCENT / 100;
        }
    }

    returnSize = index;
    printf("Phieu tra da duoc tao thanh cong! Tien phat: %d VND\n", totalFine);
}

void createBorrowTicket(
    char readerIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &ticketSize, int maxTickets, int fieldSize,
    const char readerId[], const char borrowDate[],
    const char dueDate[], const char bookISBNsInput[])
{
    if (ticketSize >= maxTickets)
    {
        printf("Khong the tao them phieu muon!\n");
        return;
    }

    int index = ticketSize * fieldSize;

    // Lưu readerId
    strncpy(&readerIds[index], readerId, fieldSize);
    readerIds[index + fieldSize - 1] = '\0';

    // Lưu borrowDate
    strncpy(&borrowDates[index], borrowDate, fieldSize);
    borrowDates[index + fieldSize - 1] = '\0';

    // Lưu dueDate
    strncpy(&dueDates[index], dueDate, fieldSize);
    dueDates[index + fieldSize - 1] = '\0';

    // Lưu ngày trả thực tế (mặc định "0-0-0" khi mới tạo)
    strncpy(&actualReturnDates[index], "0-0-0", fieldSize);
    actualReturnDates[index + fieldSize - 1] = '\0';

    // Lưu danh sách ISBN
    strncpy(&bookISBNs[index], bookISBNsInput, fieldSize);
    bookISBNs[index + fieldSize - 1] = '\0';

    ticketSize++;
    printf("Phieu muon da duoc tao thanh cong!\n");
}

void createReturnTicket(
    char borrowTickets[], int ticketSize,
    char returnTickets[], int &returnSize, int maxReturns,
    const char readerId[], const char returnDate[],
    const char bookISBNs[], int bookCount, const int bookPrices[], const bool bookLost[])
{
    if (returnSize >= maxReturns)
    {
        printf("Không thể tạo thêm phiếu trả!\n");
        return;
    }

    int index = returnSize;
    returnTickets[index++] = strlen(readerId);
    memcpy(&returnTickets[index], readerId, strlen(readerId));
    index += strlen(readerId);

    returnTickets[index++] = strlen(returnDate);
    memcpy(&returnTickets[index], returnDate, strlen(returnDate));
    index += strlen(returnDate);

    returnTickets[index++] = bookCount;
    int totalFine = 0;

    for (int i = 0; i < bookCount; i++)
    {
        int isbnLen = bookISBNs[i * 20];
        returnTickets[index++] = isbnLen;
        memcpy(&returnTickets[index], &bookISBNs[i * 20 + 1], isbnLen);
        index += isbnLen;

        if (bookLost[i])
        {
            totalFine += bookPrices[i] * BOOK_FINE_PERCENT / 100;
        }
    }

    returnSize = index;
    printf("Phiếu trả đã được tạo thành công! Tiền phạt: %d VND\n", totalFine);
}
