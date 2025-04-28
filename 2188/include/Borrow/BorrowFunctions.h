#pragma once

// Hằng số
#define MAX_TICKETS 5000      // Số lượng phiếu mượn tối đa
#define DATE_LEN 10           // Độ dài định dạng ngày "dd/mm/yyyy"
#define MAX_FINE_PER_DAY 5000 // Phí phạt quá hạn mỗi ngày (5000đ)
#define MAX_BORROW_DAYS 7     // Số ngày mượn tối đa
#define BOOK_FINE_PERCENT 200 // Phí phạt mất sách (200% giá sách)

void createBorrowTicket(
    char readerIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &ticketSize, int maxTickets, int fieldSize,
    const char cmnd[], const char borrowDate[],
    const char dueDate[], const char bookISBNsInput[]);

void createReturnTicket(
    char borrowTickets[], int ticketSize,
    char returnTickets[], int &returnSize, int maxReturns,
    const char cmnd[], const char returnDate[],
    const char bookISBNs[], int bookCount, const int bookPrices[], const bool bookLost[]);
