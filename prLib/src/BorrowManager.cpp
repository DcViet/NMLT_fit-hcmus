#include <stdio.h>
#include <string.h>
#include "../include/BorrowManager.h"

void createBorrowTicket(
    char readerIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &ticketSize, int maxTickets, int fieldSize,
    const char targetCmnd[], const char borrowDate[],
    const char dueDate[], const char bookISBNsInput[])
{
    if (ticketSize >= maxTickets)
    {
        printf("Khong the tao them phieu muon! Danh sach da day.\n");
        return;
    }

    // Có thể thêm kiểm tra định dạng ngày hoặc trùng lặp phiếu mượn nếu cần
    int index = ticketSize * fieldSize;

    // Lưu CMND
    strncpy(&readerIds[index], targetCmnd, fieldSize - 1);
    readerIds[index + fieldSize - 1] = '\0';

    // Lưu ngày mượn
    strncpy(&borrowDates[index], borrowDate, fieldSize - 1);
    borrowDates[index + fieldSize - 1] = '\0';

    // Lưu ngày đến hạn
    strncpy(&dueDates[index], dueDate, fieldSize - 1);
    dueDates[index + fieldSize - 1] = '\0';

    // Lưu ngày trả thực tế (mặc định là "0-0-0")
    strncpy(&actualReturnDates[index], "0-0-0", fieldSize - 1);
    actualReturnDates[index + fieldSize - 1] = '\0';

    // Lưu ISBN sách
    strncpy(&bookISBNs[index], bookISBNsInput, fieldSize - 1);
    bookISBNs[index + fieldSize - 1] = '\0';

    ticketSize++;
    printf("Phieu muon da duoc tao thanh cong!\n");
}

void createReturnTicket(
    char borrowTickets[], int ticketSize,
    char returnTickets[], int &returnSize, int maxReturns,
    const char targetCmnd[], const char returnDate[],
    const char bookISBNs[], int bookCount, const int bookPrices[], const bool bookLost[])
{
    if (returnSize >= maxReturns)
    {
        printf("Khong the tao them phieu tra! Danh sach da day.\n");
        return;
    }

    // Tính kích thước cần thiết để lưu dữ liệu
    int requiredSize = returnSize + strlen(targetCmnd) + 1 + strlen(returnDate) + 1 + 1; // CMND, ngày trả, số lượng sách
    for (int i = 0; i < bookCount; i++) {
        requiredSize += strlen(bookISBNs + i * 20) + 1; // Độ dài ISBN + 1 byte cho độ dài
    }

    if (requiredSize > maxReturns) {
        printf("Khong du bo nho de tao phieu tra!\n");
        return;
    }

    int index = returnSize;

    // Lưu độ dài và dữ liệu CMND
    returnTickets[index++] = strlen(targetCmnd);
    memcpy(&returnTickets[index], targetCmnd, strlen(targetCmnd));
    index += strlen(targetCmnd);

    // Lưu độ dài và dữ liệu ngày trả
    returnTickets[index++] = strlen(returnDate);
    memcpy(&returnTickets[index], returnDate, strlen(returnDate));
    index += strlen(returnDate);

    // Lưu số lượng sách
    returnTickets[index++] = bookCount;

    // Tính tiền phạt và lưu danh sách ISBN
    int totalFine = 0;
    for (int i = 0; i < bookCount; i++) {
        int isbnLen = strlen(bookISBNs + i * 20);
        returnTickets[index++] = isbnLen;
        memcpy(&returnTickets[index], bookISBNs + i * 20, isbnLen);
        index += isbnLen;

        if (bookLost[i]) {
            totalFine += bookPrices[i] * BOOK_FINE_PERCENT / 100;
        }
    }

    returnSize = index;
    printf("Phieu tra da duoc tao thanh cong! Tien phat: %d VND\n", totalFine);
}

