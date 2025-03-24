#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "../entities/Book.h"
#include "../entities/Reader.h"
#include "../entities/BorrowTicket.h"

class Library {
private:
    std::vector<Reader> readers;
    std::vector<Book> books;
    std::vector<BorrowTicket> borrowTickets;

public:
    std::vector<Reader>& getReaders() { return readers; }
    std::vector<Book>& getBooks() { return books; }
    std::vector<BorrowTicket>& getBorrowTickets() { return borrowTickets; }
};

#endif