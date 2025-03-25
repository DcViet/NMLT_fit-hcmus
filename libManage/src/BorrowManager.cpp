#include <iostream>
#include <string>
using namespace std;

#include "../include/BorrowManager.h"

// Hàm lập phiếu mượn sách
// - borrows: Mảng chứa thông tin phiếu mượn (mỗi phiếu gồm 5 phần tử: readerId, borrowDate, expectedReturnDate, actualReturnDate, isbnList)
// - borrowSize: Số lượng phiếu mượn hiện tại
// - borrowCapacity: Dung lượng tối đa của mảng phiếu mượn
// - books: Mảng chứa thông tin sách
// - bookSize: Số lượng sách hiện tại
void createBorrowTicket(string borrows[], int& borrowSize, int borrowCapacity, string books[], int bookSize) {
    if (borrowSize >= borrowCapacity) {
        cout << "Khong du bo nho de tao phieu muon!\n";
        return;
    }

    int index = borrowSize * 5;
    cout << "Nhap ma doc gia: "; cin >> borrows[index];
    cout << "Nhap ngay muon (dd-mm-yyyy): "; cin >> borrows[index + 1];

    // Tính ngày trả dự kiến (7 ngày sau ngày mượn)
    string borrowDate = borrows[index + 1];
    int day = stoi(borrowDate.substr(0, 2));
    int month = stoi(borrowDate.substr(3, 2));
    int year = stoi(borrowDate.substr(6, 4));
    day += 7;
    if (day > 30) {
        day -= 30;
        month++;
    }
    if (month > 12) {
        month = 1;
        year++;
    }
    borrows[index + 2] = to_string(day) + "-" + to_string(month) + "-" + to_string(year);
    borrows[index + 3] = "0-0-0"; // Ngày trả thực tế ban đầu là trống

    int numBooks;
    cout << "Nhap so luong sach muon muon: "; cin >> numBooks;
    string isbnList = "";
    for (int i = 0; i < numBooks; i++) {
        string isbn;
        cout << "Nhap ISBN sach " << i + 1 << ": "; cin >> isbn;
        bool found = false;
        for (int j = 0; j < bookSize; j++) {
            int bookIndex = j * 8;
            if (books[bookIndex] == isbn && stoi(books[bookIndex + 7]) > 0) {
                books[bookIndex + 7] = to_string(stoi(books[bookIndex + 7]) - 1);
                isbnList += isbn + ",";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Sach khong ton tai hoac da het!\n";
            i--;
        }
    }
    borrows[index + 4] = isbnList.substr(0, isbnList.size() - 1); // Loại bỏ dấu phẩy cuối

    borrowSize++;
    cout << "Lap phieu muon sach thanh cong!\n";
}

// Hàm lập phiếu trả sách
// - borrows: Mảng chứa thông tin phiếu mượn
// - borrowSize: Số lượng phiếu mượn hiện tại
// - books: Mảng chứa thông tin sách
// - bookSize: Số lượng sách hiện tại
void createReturnTicket(string borrows[], int borrowSize, string books[], int bookSize) {
    string readerId;
    cout << "Nhap ma doc gia: "; cin >> readerId;
    for (int i = 0; i < borrowSize; i++) {
        int index = i * 5;
        if (borrows[index] == readerId && borrows[index + 3] == "0-0-0") {
            cout << "Nhap ngay tra thuc te (dd-mm-yyyy): "; cin >> borrows[index + 3];

            // Tăng số lượng sách trong kho
            string isbnList = borrows[index + 4];
            size_t pos = 0;
            while ((pos = isbnList.find(",")) != string::npos) {
                string isbn = isbnList.substr(0, pos);
                for (int j = 0; j < bookSize; j++) {
                    int bookIndex = j * 8;
                    if (books[bookIndex] == isbn) {
                        books[bookIndex + 7] = to_string(stoi(books[bookIndex + 7]) + 1);
                        break;
                    }
                }
                isbnList.erase(0, pos + 1);
            }
            for (int j = 0; j < bookSize; j++) {
                int bookIndex = j * 8;
                if (books[bookIndex] == isbnList) {
                    books[bookIndex + 7] = to_string(stoi(books[bookIndex + 7]) + 1);
                    break;
                }
            }

            // Tính tiền phạt
            string expected = borrows[index + 2];
            string actual = borrows[index + 3];
            int expDay = stoi(expected.substr(0, 2)), expMonth = stoi(expected.substr(3, 2)), expYear = stoi(expected.substr(6, 4));
            int actDay = stoi(actual.substr(0, 2)), actMonth = stoi(actual.substr(3, 2)), actYear = stoi(actual.substr(6, 4));
            int lateDays = (actYear * 360 + actMonth * 30 + actDay) - (expYear * 360 + expMonth * 30 + expDay);
            if (lateDays > 0) {
                int fine = lateDays * 5000;
                cout << "Tre han " << lateDays << " ngay. Tien phat: " << fine << " dong.\n";
            } else {
                cout << "Tra sach dung han.\n";
            }
            cout << "Lap phieu tra sach thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay phieu muon cho ma doc gia " << readerId << "!\n";
}