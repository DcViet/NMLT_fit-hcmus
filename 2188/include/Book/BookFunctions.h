#pragma once
#include "BookManager.h"

#define MAX_BOOKS 100
#define MAX_READERS 100
#define MAX_BORROWS 100
#define MAX_RETURNS 1000
#define BOOK_FIELD_SIZE 50
#define READER_FIELD_SIZE 50
#define BORROW_FIELD_SIZE 50

void addBook(char isbn[], char titles[], char authors[], char genres[],
             char years[], char publishers[], char quantities[],
             int &size, int maxLen,
             const char newIsbn[], const char newTitle[], const char newAuthor[],
             const char newGenre[], const char newYear[], const char newPublisher[],
             const char newQuantity[]);

bool editBook(char isbn[], char titles[], char authors[], char genres[],
              char years[], char publishers[], char quantities[],
              int size, int maxLen, const char targetIsbn[],
              const char newIsbn[], const char newTitle[], const char newAuthor[],
              const char newGenre[], const char newYear[], const char newPublisher[],
              const char newQuantity[]);

// Hàm xóa sách dựa trên ISBN
bool deleteBook(char isbn[], char titles[], char authors[], char genres[],
                char years[], char publishers[], char quantities[],
                int &size, int maxLen, const char targetIsbn[]);

// Hàm tìm kiếm sách 
int searchBook(const char arr[], int size, int maxLen, const char target[]);
