#include <iostream>
#include "../../include/services/BookService.h"
#include "../../include/utils/InputHelper.h"

void BookService::addBook(std::vector<Book>& books) {
    Book b;
    b.isbn = InputHelper::getString("Nhap ISBN: ");
    b.title = InputHelper::getString("Nhap ten sach: ");
    b.author = InputHelper::getString("Nhap tac gia: ");
    b.publisher = InputHelper::getString("Nhap nha xuat ban: ");
    b.year = InputHelper::getInt("Nhap nam xuat ban: ");
    b.genre = InputHelper::getString("Nhap the loai: ");
    b.price = InputHelper::getInt("Nhap gia sach: ");
    b.quantity = InputHelper::getInt("Nhap so quyen sach: ");
    books.push_back(b);
    std::cout << "Them sach thanh cong!\n";
}