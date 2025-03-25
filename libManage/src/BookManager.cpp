#include <iostream>
#include <string>
using namespace std;

#include "../include/BookManager.h"

// Hàm hiển thị danh sách tất cả sách
// - books: Mảng chứa thông tin sách (mỗi sách gồm 8 phần tử: isbn, title, author, publisher, genre, year, price, quantity)
// - size: Số lượng sách hiện tại trong mảng
void displayBooks(string books[], int size) {
    if (size == 0) {
        cout << "Khong co sach nao trong thu vien!\n";
        return;
    }
    cout << "\n=== DANH SACH SACH ===\n";
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        cout << "ISBN: " << books[index] << "\n";
        cout << "Ten sach: " << books[index + 1] << "\n";
        cout << "Tac gia: " << books[index + 2] << "\n";
        cout << "Nha xuat ban: " << books[index + 3] << "\n";
        cout << "The loai: " << books[index + 4] << "\n";
        cout << "Nam xuat ban: " << books[index + 5] << "\n";
        cout << "Gia sach: " << books[index + 6] << "\n";
        cout << "So quyen sach: " << books[index + 7] << "\n";
        cout << "------------------------\n";
    }
}

// Hàm thêm một cuốn sách mới vào mảng
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
// - capacity: Dung lượng tối đa của mảng
void addBook(string books[], int& size, int capacity) {
    if (size >= capacity) {
        cout << "Khong du bo nho de them sach!\n";
        return;
    }

    int index = size * 8;
    cout << "Nhap ISBN: "; cin >> books[index];
    cin.ignore();
    cout << "Nhap ten sach: "; getline(cin, books[index + 1]);
    cout << "Nhap tac gia: "; getline(cin, books[index + 2]);
    cout << "Nhap nha xuat ban: "; getline(cin, books[index + 3]);
    cout << "Nhap the loai: "; cin >> books[index + 4];
    cout << "Nhap nam xuat ban: "; cin >> books[index + 5];
    cout << "Nhap gia sach: "; cin >> books[index + 6];
    cout << "Nhap so quyen sach: "; cin >> books[index + 7];

    size++;
    cout << "Them sach thanh cong!\n";
}

// Hàm chỉnh sửa thông tin một cuốn sách dựa trên ISBN
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void editBook(string books[], int size) {
    string isbn;
    cout << "Nhap ISBN cua sach can chinh sua: "; cin >> isbn;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (books[index] == isbn) {
            cin.ignore();
            cout << "Nhap ten sach moi: "; getline(cin, books[index + 1]);
            cout << "Nhap tac gia moi: "; getline(cin, books[index + 2]);
            cout << "Nhap nha xuat ban moi: "; getline(cin, books[index + 3]);
            cout << "Nhap the loai moi: "; cin >> books[index + 4];
            cout << "Nhap nam xuat ban moi: "; cin >> books[index + 5];
            cout << "Nhap gia sach moi: "; cin >> books[index + 6];
            cout << "Nhap so quyen sach moi: "; cin >> books[index + 7];
            cout << "Chinh sua thong tin sach thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sach voi ISBN " << isbn << "!\n";
}

// Hàm xóa thông tin một cuốn sách dựa trên ISBN
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void deleteBook(string books[], int& size) {
    string isbn;
    cout << "Nhap ISBN cua sach can xoa: "; cin >> isbn;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (books[index] == isbn) {
            for (int j = index; j < (size - 1) * 8; j += 8) {
                books[j] = books[j + 8];     // isbn
                books[j + 1] = books[j + 9]; // title
                books[j + 2] = books[j + 10]; // author
                books[j + 3] = books[j + 11]; // publisher
                books[j + 4] = books[j + 12]; // genre
                books[j + 5] = books[j + 13]; // year
                books[j + 6] = books[j + 14]; // price
                books[j + 7] = books[j + 15]; // quantity
            }
            size--;
            cout << "Xoa sach thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sach voi ISBN " << isbn << "!\n";
}

// Hàm tìm kiếm sách theo ISBN
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void searchBookByISBN(string books[], int size) {
    string isbn;
    cout << "Nhap ISBN can tim: "; cin >> isbn;
    bool found = false;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (books[index] == isbn) {
            cout << "ISBN: " << books[index] << "\n";
            cout << "Ten sach: " << books[index + 1] << "\n";
            cout << "Tac gia: " << books[index + 2] << "\n";
            cout << "Nha xuat ban: " << books[index + 3] << "\n";
            cout << "The loai: " << books[index + 4] << "\n";
            cout << "Nam xuat ban: " << books[index + 5] << "\n";
            cout << "Gia sach: " << books[index + 6] << "\n";
            cout << "So quyen sach: " << books[index + 7] << "\n";
            cout << "------------------------\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay sach voi ISBN " << isbn << "!\n";
}

// Hàm tìm kiếm sách theo tên sách
// - books: Mảng chứa thông tin sách
// - size: Số lượng sách hiện tại trong mảng
void searchBookByTitle(string books[], int size) {
    string title;
    cout << "Nhap ten sach can tim: "; cin.ignore(); getline(cin, title);
    bool found = false;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (books[index + 1] == title) {
            cout << "ISBN: " << books[index] << "\n";
            cout << "Ten sach: " << books[index + 1] << "\n";
            cout << "Tac gia: " << books[index + 2] << "\n";
            cout << "Nha xuat ban: " << books[index + 3] << "\n";
            cout << "The loai: " << books[index + 4] << "\n";
            cout << "Nam xuat ban: " << books[index + 5] << "\n";
            cout << "Gia sach: " << books[index + 6] << "\n";
            cout << "So quyen sach: " << books[index + 7] << "\n";
            cout << "------------------------\n";
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay sach voi ten " << title << "!\n";
}