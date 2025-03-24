#ifndef BORROW_SERVICE_H
#define BORROW_SERVICE_H
#include <vector>
#include "../entities/BorrowTicket.h"
#include "../entities/Book.h"

class BorrowService {
public:
    void borrowBook(std::vector<BorrowTicket>& tickets, std::vector<Book>& books);
    void returnBook(std::vector<BorrowTicket>& tickets, std::vector<Book>& books);
};

#endif