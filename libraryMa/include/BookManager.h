#ifndef BOOK_MANAGER_H
#define BOOK_MANAGER_H
#include <string>
using namespace std;

// Hàm hiển thị danh sách tất cả sách
void displayBooks(char books[], int size, int attrCount, int maxLen);

// Hàm thêm một cuốn sách mới vào mảng
void addBook(char books[], int &size, int attrCount, int maxLen);

// Hàm chỉnh sửa thông tin một cuốn sách dựa trên ISBN
void editBook(char books[], int size, int attrCount, int maxLen);

// Hàm xóa thông tin một cuốn sách dựa trên ISBN
void deleteBook(char books[], int &size, int attrCount, int maxLen);

// Hàm tìm kiếm sách theo ISBN (mã sách)
void searchBookByISBN(char books[], int size, int attrCount, int maxLen);

// Hàm tìm kiếm sách theo tên sách
void searchBookByTitle(char books[], int size, int attrCount, int maxLen);


#endif