#ifndef BORROW_TICKET_H
#define BORROW_TICKET_H
#include <string>
#include <vector>
#include "../core/Date.h"

struct BorrowTicket {
    std::string readerId;
    Date borrowDate, expectedReturnDate, actualReturnDate;
    std::vector<std::string> isbnList;
};

#endif