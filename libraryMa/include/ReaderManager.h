#ifndef READER_MANAGER_H
#define READER_MANAGER_H
// #include <string>
using namespace std;

// Hàm hiển thị danh sách tất cả độc giả
void displayReaders(char readers[], int size);

// Hàm thêm một độc giả mới vào mảng
void addReader(char readers[], int &size);

// Hàm chỉnh sửa thông tin một độc giả dựa trên mã độc giả
void editReader(char readers[], int size);

// Hàm xóa thông tin một độc giả dựa trên mã độc giả
void deleteReader(char readers[], int &size);

// Hàm tìm kiếm độc giả theo CMND
void searchReaderByCMND(char readers[], int size);

// Hàm tìm kiếm độc giả theo họ tên
void searchReaderByName(char readers[], int size);

#endif