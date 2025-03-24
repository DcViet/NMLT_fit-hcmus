#include <iostream>
#include "../../include/utils/Menu.h"
#include "../../include/services/BookService.h"
#include "../../include/services/ReaderService.h"
#include "../../include/services/BorrowService.h"

void Menu::display() {
    std::cout << "\n=== QUAN LY THU VIEN ===\n";
    std::cout << "1. Them doc gia\n";
    std::cout << "2. Them sach\n";
    std::cout << "3. Muon sach\n";
    std::cout << "4. Tra sach\n";
    std::cout << "5. Thoat\n";
    std::cout << "Chon chuc nang: ";
}

void Menu::run(Library& library) {
    ReaderService readerService;
    BookService bookService;
    BorrowService borrowService;
    int choice;

    do {
        display();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: readerService.addReader(library.getReaders()); break;
            case 2: bookService.addBook(library.getBooks()); break;
            case 3: borrowService.borrowBook(library.getBorrowTickets(), library.getBooks()); break;
            case 4: borrowService.returnBook(library.getBorrowTickets(), library.getBooks()); break;
            case 5: std::cout << "Tam biet!\n"; break;
            default: std::cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 5);
}