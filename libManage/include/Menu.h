#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

// Hàm hiển thị menu chính
void displayMenu();

// Hàm chạy chương trình chính
// - readers: Mảng chứa thông tin độc giả
// - readerSize: Số lượng độc giả hiện tại
// - readerCapacity: Dung lượng tối đa của mảng độc giả
// - books: Mảng chứa thông tin sách
// - bookSize: Số lượng sách hiện tại
// - bookCapacity: Dung lượng tối đa của mảng sách
// - borrows: Mảng chứa thông tin phiếu mượn
// - borrowSize: Số lượng phiếu mượn hiện tại
// - borrowCapacity: Dung lượng tối đa của mảng phiếu mượn
void runProgram(string readers[], int& readerSize, int readerCapacity,
                string books[], int& bookSize, int bookCapacity,
                string borrows[], int& borrowSize, int borrowCapacity);

#endif