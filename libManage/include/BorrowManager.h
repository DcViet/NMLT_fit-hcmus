#ifndef BORROW_MANAGER_H
#define BORROW_MANAGER_H
#include <string>
using namespace std;

// Hàm lập phiếu mượn sách
// - borrows: Mảng chứa thông tin phiếu mượn (mỗi phiếu gồm 5 phần tử: readerId, borrowDate, expectedReturnDate, actualReturnDate, isbnList)
// - borrowSize: Số lượng phiếu mượn hiện tại
// - borrowCapacity: Dung lượng tối đa của mảng phiếu mượn
// - books: Mảng chứa thông tin sách
// - bookSize: Số lượng sách hiện tại
void createBorrowTicket(string borrows[], int& borrowSize, int borrowCapacity, string books[], int bookSize);

// Hàm lập phiếu trả sách
// - borrows: Mảng chứa thông tin phiếu mượn
// - borrowSize: Số lượng phiếu mượn hiện tại
// - books: Mảng chứa thông tin sách
// - bookSize: Số lượng sách hiện tại
void createReturnTicket(string borrows[], int borrowSize, string books[], int bookSize);

#endif