#ifndef BOOK_MANAGER_H
#define BOOK_MANAGER_H
#include <string>
using namespace std;

// Hàm hiển thị danh sách tất cả sách
// - books: Mảng chứa thông tin sách (mỗi sách gồm 8 phần tử: isbn, title, author, publisher, genre, year, price, quantity)
// - size: Số lượng sách hiện tại trong mảng
void displayBooks(string books[], int size);

// Hàm thêm một cuốn sách mới vào mảng
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
// - capacity: Dung lượng tối đa của mảng
void addBook(string books[], int& size, int capacity);

// Hàm chỉnh sửa thông tin một cuốn sách dựa trên ISBN
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void editBook(string books[], int size);

// Hàm xóa thông tin một cuốn sách dựa trên ISBN
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void deleteBook(string books[], int& size);

// Hàm tìm kiếm sách theo ISBN (mã sách)
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void searchBookByISBN(string books[], int size);

// Hàm tìm kiếm sách theo tên sách
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void searchBookByTitle(string books[], int size);

#endif