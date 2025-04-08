#ifndef BORROW_MANAGER_H
#define BORROW_MANAGER_H
#include <string>
using namespace std;

// Hàm lập phiếu mượn sách
bool processBorrowTicket(char borrows[], int &borrowSize, int borrowCapacity, char books[], int bookSize,
    const char *readerId, const char *borrowDate, const char isbnList[][50], int numBooks);

// Hàm lập phiếu trả sách
bool processReturnTicket(char borrows[], int borrowSize, char books[], int bookSize,
    const char *readerId, const char *returnDate, const char returnedIsbns[][50], int numReturned, int &totalFine);

#endif