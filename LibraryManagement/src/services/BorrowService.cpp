#include <iostream>
#include "../../include/services/BorrowService.h"
#include "../../include/utils/InputHelper.h"
#include "../../include/utils/DateUtils.h"
#include "../../include/core/Constants.h"  // Thêm dòng này để sử dụng Constants

void BorrowService::borrowBook(std::vector<BorrowTicket>& tickets, std::vector<Book>& books) {
    BorrowTicket ticket;
    ticket.readerId = InputHelper::getString("Nhap ma doc gia: ");
    InputHelper::getDate("Nhap ngay muon (ngay thang nam): ", ticket.borrowDate);
    ticket.expectedReturnDate = DateUtils::calculateReturnDate(ticket.borrowDate);

    int numBooks = InputHelper::getInt("Nhap so luong sach muon muon: ");
    for (int i = 0; i < numBooks; i++) {
        std::string isbn = InputHelper::getString("Nhap ISBN sach " + std::to_string(i + 1) + ": ");
        bool found = false;
        for (auto& book : books) {
            if (book.isbn == isbn && book.quantity > 0) {
                book.quantity--;
                ticket.isbnList.push_back(isbn);
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Sach khong ton tai hoac da het!\n";
            i--;
        }
    }
    tickets.push_back(ticket);
    std::cout << "Muon sach thanh cong!\n";
}

void BorrowService::returnBook(std::vector<BorrowTicket>& tickets, std::vector<Book>& books) {
    std::string readerId = InputHelper::getString("Nhap ma doc gia: ");
    for (auto& ticket : tickets) {
        if (ticket.readerId == readerId && ticket.actualReturnDate.day == 0) {
            InputHelper::getDate("Nhap ngay tra thuc te (ngay thang nam): ", ticket.actualReturnDate);

            for (const auto& isbn : ticket.isbnList) {
                for (auto& book : books) {
                    if (book.isbn == isbn) {
                        book.quantity++;
                        break;
                    }
                }
            }

            int lateDays = DateUtils::calculateLateDays(ticket.expectedReturnDate, ticket.actualReturnDate);
            int fine = lateDays * Constants::FINE_PER_DAY;  // Sử dụng Constants::FINE_PER_DAY
            if (fine > 0) {
                std::cout << "Tre han " << lateDays << " ngay. Tien phat: " << fine << " dong.\n";
            } else {
                std::cout << "Tra sach dung han.\n";
            }
            return;
        }
    }
    std::cout << "Khong tim thay phieu muon!\n";
}