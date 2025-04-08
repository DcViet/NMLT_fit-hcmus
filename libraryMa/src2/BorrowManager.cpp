#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_TICKETS = 5000; // Số lượng phần tử tối đa
const int DATE_LEN = 10;      // Định dạng ngày "dd/mm/yyyy"

const int MAX_FINE_PER_DAY = 5000; // phí phạt quá hạn, 5000đ
const int MAX_BORROW_DAYS = 7;     // mượn tối đa 7 ngày
const int BOOK_FINE_PERCENT = 200; // phí phạt mất sách, 200% giá sách

void createBorrowTicket(
    char borrowTickets[], int &ticketSize, int maxTickets,
    const char readerId[], const char borrowDate[],
    const char dueDate[], const char bookISBNs[], int bookCount)
{
    if (ticketSize >= maxTickets)
    {
        printf("Không thể tạo thêm phiếu mượn!\n");
        return;
    }

    int index = ticketSize;
    borrowTickets[index++] = strlen(readerId);
    memcpy(&borrowTickets[index], readerId, strlen(readerId));
    index += strlen(readerId);

    borrowTickets[index++] = strlen(borrowDate);
    memcpy(&borrowTickets[index], borrowDate, strlen(borrowDate));
    index += strlen(borrowDate);

    borrowTickets[index++] = strlen(dueDate);
    memcpy(&borrowTickets[index], dueDate, strlen(dueDate));
    index += strlen(dueDate);

    borrowTickets[index++] = bookCount; // Lưu số lượng sách
    for (int i = 0; i < bookCount; i++)
    {
        int isbnLen = bookISBNs[i * 20]; // Độ dài ISBN tại vị trí đầu mỗi chuỗi
        borrowTickets[index++] = isbnLen;
        memcpy(&borrowTickets[index], &bookISBNs[i * 20 + 1], isbnLen);
        index += isbnLen;
    }

    ticketSize = index;
    printf("Phiếu mượn đã được tạo thành công!\n");
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
