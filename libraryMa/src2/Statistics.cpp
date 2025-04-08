#include <iostream>
#include <string>
using namespace std;

#include "../include/Statistics.h"

// Hàm thống kê số lượng sách trong thư viện
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void countBooks(string books[], int size) {
    int totalBooks = 0;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        totalBooks += stoi(books[index + 7]); // Tổng số quyển sách
    }
    cout << "Tong so luong sach trong thu vien: " << totalBooks << "\n";
}

// Hàm thống kê số lượng sách theo thể loại
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void countBooksByGenre(string books[], int size) {
    if (size == 0) {
        cout << "Khong co sach nao trong thu vien!\n";
        return;
    }
    cout << "\n=== THONG KE SACH THEO THE LOAI ===\n";
    string genres[100] = {};
    int counts[100] = {0};
    int genreCount = 0;

    for (int i = 0; i < size; i++) {
        int index = i * 8;
        string genre = books[index + 4];
        bool found = false;
        for (int j = 0; j < genreCount; j++) {
            if (genres[j] == genre) {
                counts[j] += stoi(books[index + 7]);
                found = true;
                break;
            }
        }
        if (!found) {
            genres[genreCount] = genre;
            counts[genreCount] = stoi(books[index + 7]);
            genreCount++;
        }
    }

    for (int i = 0; i < genreCount; i++) {
        cout << "The loai " << genres[i] << ": " << counts[i] << " quyen\n";
    }
}

// Hàm thống kê số lượng độc giả
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void countReaders(string readers[], int size) {
    cout << "Tong so luong doc gia: " << size << "\n";
}

// Hàm thống kê số lượng độc giả theo giới tính
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void countReadersByGender(string readers[], int size) {
    int male = 0, female = 0;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (readers[index + 3] == "Nam") male++;
        else if (readers[index + 3] == "Nu") female++;
    }
    cout << "So luong doc gia nam: " << male << "\n";
    cout << "So luong doc gia nu: " << female << "\n";
}

// Hàm thống kê số sách đang được mượn
// - borrows: Mảng chứa thông tin phiếu mượn
// - borrowSize: Số lượng phiếu mượn hiện tại
void countBorrowedBooks(string borrows[], int borrowSize) {
    int borrowedBooks = 0;
    for (int i = 0; i < borrowSize; i++) {
        int index = i * 5;
        if (borrows[index + 3] == "0-0-0") { // Chưa trả
            string isbnList = borrows[index + 4];
            size_t pos = 0;
            while ((pos = isbnList.find(",")) != string::npos) {
                borrowedBooks++;
                isbnList.erase(0, pos + 1);
            }
            borrowedBooks++; // Đếm ISBN cuối cùng
        }
    }
    cout << "So luong sach dang duoc muon: " << borrowedBooks << "\n";
}

// Hàm thống kê danh sách độc giả bị trễ hạn
// - borrows: Mảng chứa thông tin phiếu mượn
// - borrowSize: Số lượng phiếu mượn hiện tại
// - readers: Mảng chứa thông tin độc giả
// - readerSize: Số lượng độc giả hiện tại
void listOverdueReaders(string borrows[], int borrowSize, string readers[], int readerSize) {
    cout << "\n=== DANH SACH DOC GIA TRE HAN ===\n";
    bool found = false;
    string currentDate;
    cout << "Nhap ngay hien tai (dd-mm-yyyy): "; cin >> currentDate;
    int currDay = stoi(currentDate.substr(0, 2));
    int currMonth = stoi(currentDate.substr(3, 2));
    int currYear = stoi(currentDate.substr(6, 4));
    int currentDays = currYear * 360 + currMonth * 30 + currDay;

    for (int i = 0; i < borrowSize; i++) {
        int index = i * 5;
        if (borrows[index + 3] == "0-0-0") { // Chưa trả
            string expected = borrows[index + 2];
            int expDay = stoi(expected.substr(0, 2));
            int expMonth = stoi(expected.substr(3, 2));
            int expYear = stoi(expected.substr(6, 4));
            int expectedDays = expYear * 360 + expMonth * 30 + expDay;

            if (currentDays > expectedDays) {
                string readerId = borrows[index];
                for (int j = 0; j < readerSize; j++) {
                    int rIndex = j * 8;
                    if (readers[rIndex] == readerId) {
                        cout << "Ma doc gia: " << readers[rIndex] << "\n";
                        cout << "Ho ten: " << readers[rIndex + 1] << "\n";
                        cout << "Ngay muon: " << borrows[index + 1] << "\n";
                        cout << "Ngay tra du kien: " << borrows[index + 2] << "\n";
                        cout << "So ngay tre han: " << (currentDays - expectedDays) << "\n";
                        cout << "------------------------\n";
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    if (!found) cout << "Khong co doc gia nao tre han!\n";
}