#ifndef STATISTICS_H
#define STATISTICS_H
#include <string>
using namespace std;

// Hàm thống kê số lượng sách trong thư viện
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void countBooks(string books[], int size);

// Hàm thống kê số lượng sách theo thể loại
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void countBooksByGenre(string books[], int size);

// Hàm thống kê số lượng độc giả
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void countReaders(string readers[], int size);

// Hàm thống kê số lượng độc giả theo giới tính
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void countReadersByGender(string readers[], int size);

// Hàm thống kê số sách đang được mượn
// - borrows: Mảng chứa thông tin phiếu mượn
// - borrowSize: Số lượng phiếu mượn hiện tại
void countBorrowedBooks(string borrows[], int borrowSize);

// Hàm thống kê danh sách độc giả bị trễ hạn
// - borrows: Mảng chứa thông tin phiếu mượn
// - borrowSize: Số lượng phiếu mượn hiện tại
// - readers: Mảng chứa thông tin độc giả
// - readerSize: Số lượng độc giả hiện tại
void listOverdueReaders(string borrows[], int borrowSize, string readers[], int readerSize);

#endif