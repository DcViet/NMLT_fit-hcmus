#include <iostream>
#include <string>
using namespace std;

#include "../include/Menu.h"
#include "../include/ReaderManager.h"
#include "../include/BookManager.h"
#include "../include/BorrowManager.h"
#include "../include/Statistics.h"

// Hàm hiển thị menu chính
void displayMenu() {
    cout << "\n=== QUAN LY THU VIEN ===\n";
    cout << "1. Xem danh sach doc gia\n";
    cout << "2. Them doc gia\n";
    cout << "3. Chinh sua thong tin doc gia\n";
    cout << "4. Xoa doc gia\n";
    cout << "5. Tim kiem doc gia theo CMND\n";
    cout << "6. Tim kiem doc gia theo ho ten\n";
    cout << "7. Xem danh sach sach\n";
    cout << "8. Them sach\n";
    cout << "9. Chinh sua thong tin sach\n";
    cout << "10. Xoa sach\n";
    cout << "11. Tim kiem sach theo ISBN\n";
    cout << "12. Tim kiem sach theo ten sach\n";
    cout << "13. Lap phieu muon sach\n";
    cout << "14. Lap phieu tra sach\n";
    cout << "15. Thong ke so luong sach\n";
    cout << "16. Thong ke sach theo the loai\n";
    cout << "17. Thong ke so luong doc gia\n";
    cout << "18. Thong ke doc gia theo gioi tinh\n";
    cout << "19. Thong ke so sach dang duoc muon\n";
    cout << "20. Thong ke doc gia tre han\n";
    cout << "21. Thoat\n";
    cout << "Chon chuc nang: ";
}

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
                string borrows[], int& borrowSize, int borrowCapacity) {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: displayReaders(readers, readerSize); break;
            case 2: addReader(readers, readerSize, readerCapacity); break;
            case 3: editReader(readers, readerSize); break;
            case 4: deleteReader(readers, readerSize); break;
            case 5: searchReaderByCMND(readers, readerSize); break;
            case 6: searchReaderByName(readers, readerSize); break;
            case 7: displayBooks(books, bookSize); break;
            case 8: addBook(books, bookSize, bookCapacity); break;
            case 9: editBook(books, bookSize); break;
            case 10: deleteBook(books, bookSize); break;
            case 11: searchBookByISBN(books, bookSize); break;
            case 12: searchBookByTitle(books, bookSize); break;
            case 13: createBorrowTicket(borrows, borrowSize, borrowCapacity, books, bookSize); break;
            case 14: createReturnTicket(borrows, borrowSize, books, bookSize); break;
            case 15: countBooks(books, bookSize); break;
            case 16: countBooksByGenre(books, bookSize); break;
            case 17: countReaders(readers, readerSize); break;
            case 18: countReadersByGender(readers, readerSize); break;
            case 19: countBorrowedBooks(borrows, borrowSize); break;
            case 20: listOverdueReaders(borrows, borrowSize, readers, readerSize); break;
            case 21: cout << "Tam biet!\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 21);
}