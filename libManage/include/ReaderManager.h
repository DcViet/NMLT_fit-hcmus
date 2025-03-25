#ifndef READER_MANAGER_H
#define READER_MANAGER_H
#include <string>
using namespace std;

// Hàm hiển thị danh sách tất cả độc giả
// - readers: Mảng chứa thông tin độc giả (mỗi độc giả gồm 8 phần tử: id, name, cmnd, gender, email, address, regDate, expDate)
// - size: Số lượng độc giả hiện tại trong mảng
void displayReaders(string readers[], int size);

// Hàm thêm một độc giả mới vào mảng
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
// - capacity: Dung lượng tối đa của mảng
void addReader(string readers[], int& size, int capacity);

// Hàm chỉnh sửa thông tin một độc giả dựa trên mã độc giả
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void editReader(string readers[], int size);

// Hàm xóa thông tin một độc giả dựa trên mã độc giả
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void deleteReader(string readers[], int& size);

// Hàm tìm kiếm độc giả theo CMND
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void searchReaderByCMND(string readers[], int size);

// Hàm tìm kiếm độc giả theo họ tên
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void searchReaderByName(string readers[], int size);

#endif