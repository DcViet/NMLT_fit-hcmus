#ifndef BOOK_H
#define BOOK_H
#include <string>

struct Book {
    std::string isbn, title, author, publisher, genre;
    int year, price, quantity;
};

#endif