#ifndef BOOK_SERVICE_H
#define BOOK_SERVICE_H
#include <vector>
#include "../entities/Book.h"

class BookService {
public:
    void addBook(std::vector<Book>& books);
};

#endif