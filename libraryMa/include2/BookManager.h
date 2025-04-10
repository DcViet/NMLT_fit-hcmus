#ifndef BOOK_MANAGER_H
#define BOOK_MANAGER_H

// Hàm hiển thị danh sách sách
void displayBooks(
    const char isbn[], const char titles[], const char authors[],
    const char genres[], const char years[], const char publishers[],
    const char quantities[], int size, int maxLen);

// Hàm thêm sách vào mảng
void addBook(
    char isbn[], char titles[], char authors[], char genres[],
    char years[], char publishers[], char quantities[],
    int *size, int maxLen, const char newBook[]);

// Hàm chỉnh sửa sách dựa trên ISBN
int editBook(
    char isbn[], char titles[], char authors[], char genres[],
    char years[], char publishers[], char quantities[],
    int size, int maxLen, const char targetIsbn[], const char updatedBook[]);

// Hàm xóa sách dựa trên ISBN
int deleteBook(
    char isbn[], char titles[], char authors[], char genres[],
    char years[], char publishers[], char quantities[],
    int *size, int maxLen, const char targetIsbn[]);

// Hàm tìm kiếm sách theo ISBN
int searchBookByISBN(
    const char isbn[], int size, int maxLen, const char targetIsbn[]);

// Hàm tìm kiếm sách theo tên sách
int searchBookByTitle(
    const char titles[], int size, int maxLen, const char targetTitle[]);

#endif