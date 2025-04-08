#include <string>
using namespace std;

#include "../include/Menu.h"

int main() {
    const int READER_CAPACITY = 100 * 8; // 100 độc giả, mỗi độc giả 8 phần tử
    const int BOOK_CAPACITY = 100 * 8;   // 100 sách, mỗi sách 8 phần tử
    const int BORROW_CAPACITY = 100 * 5; // 100 phiếu mượn, mỗi phiếu 5 phần tử

    string readers[READER_CAPACITY] = {};
    string books[BOOK_CAPACITY] = {};
    string borrows[BORROW_CAPACITY] = {};
    int readerSize = 0, bookSize = 0, borrowSize = 0;

    runProgram(readers, readerSize, READER_CAPACITY / 8,
               books, bookSize, BOOK_CAPACITY / 8,
               borrows, borrowSize, BORROW_CAPACITY / 5);

    return 0;
}