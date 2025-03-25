#include <iostream>
#include <string>
using namespace std;

#include "../include/ReaderManager.h"

// Hàm hiển thị danh sách tất cả độc giả
// - readers: Mảng chứa thông tin độc giả (mỗi độc giả gồm 8 phần tử: id, name, cmnd, gender, email, address, regDate, expDate)
// - size: Số lượng độc giả hiện tại trong mảng
void displayReaders(string readers[], int size) {
    if (size == 0) {
        cout << "Khong co doc gia nao trong thu vien!\n";
        return;
    }
    cout << "\n=== DANH SACH DOC GIA ===\n";
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        cout << "Ma doc gia: " << readers[index] << "\n";
        cout << "Ho ten: " << readers[index + 1] << "\n";
        cout << "CMND: " << readers[index + 2] << "\n";
        cout << "Gioi tinh: " << readers[index + 3] << "\n";
        cout << "Email: " << readers[index + 4] << "\n";
        cout << "Dia chi: " << readers[index + 5] << "\n";
        cout << "Ngay lap the: " << readers[index + 6] << "\n";
        cout << "Ngay het han: " << readers[index + 7] << "\n";
        cout << "------------------------\n";
    }
}

// Hàm thêm một độc giả mới vào mảng
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
// - capacity: Dung lượng tối đa của mảng
void addReader(string readers[], int& size, int capacity) {
    if (size >= capacity) {
        cout << "Khong du bo nho de them doc gia!\n";
        return;
    }

    int index = size * 8;
    cout << "Nhap ma doc gia: "; cin >> readers[index];
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, readers[index + 1]);
    cout << "Nhap CMND: "; cin >> readers[index + 2];
    cout << "Nhap gioi tinh: "; cin >> readers[index + 3];
    cout << "Nhap email: "; cin >> readers[index + 4];
    cin.ignore();
    cout << "Nhap dia chi: "; getline(cin, readers[index + 5]);
    cout << "Nhap ngay lap the (dd-mm-yyyy): "; cin >> readers[index + 6];

    // Tính ngày hết hạn (48 tháng sau ngày lập thẻ)
    string regDate = readers[index + 6];
    int day = stoi(regDate.substr(0, 2));
    int month = stoi(regDate.substr(3, 2));
    int year = stoi(regDate.substr(6, 4));
    year += 4; // 48 tháng = 4 năm
    readers[index + 7] = to_string(day) + "-" + to_string(month) + "-" + to_string(year);

    size++;
    cout << "Them doc gia thanh cong!\n";
}

// Hàm chỉnh sửa thông tin một độc giả dựa trên mã độc giả
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void editReader(string readers[], int size) {
    string id;
    cout << "Nhap ma doc gia can chinh sua: "; cin >> id;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (readers[index] == id) {
            cin.ignore();
            cout << "Nhap ho ten moi: "; getline(cin, readers[index + 1]);
            cout << "Nhap CMND moi: "; cin >> readers[index + 2];
            cout << "Nhap gioi tinh moi: "; cin >> readers[index + 3];
            cout << "Nhap email moi: "; cin >> readers[index + 4];
            cin.ignore();
            cout << "Nhap dia chi moi: "; getline(cin, readers[index + 5]);
            cout << "Nhap ngay lap the moi (dd-mm-yyyy): "; cin >> readers[index + 6];

            // Tính lại ngày hết hạn
            string regDate = readers[index + 6];
            int day = stoi(regDate.substr(0, 2));
            int month = stoi(regDate.substr(3, 2));
            int year = stoi(regDate.substr(6, 4));
            year += 4;
            readers[index + 7] = to_string(day) + "-" + to_string(month) + "-" + to_string(year);

            cout << "Chinh sua thong tin thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay doc gia voi ma " << id << "!\n";
}

// Hàm xóa thông tin một độc giả dựa trên mã độc giả
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void deleteReader(string readers[], int& size) {
    string id;
    cout << "Nhap ma doc gia can xoa: "; cin >> id;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (readers[index] == id) {
            for (int j = index; j < (size - 1) * 8; j += 8) {
                readers[j] = readers[j + 8];     // id
                readers[j + 1] = readers[j + 9]; // name
                readers[j + 2] = readers[j + 10]; // cmnd
                readers[j + 3] = readers[j + 11]; // gender
                readers[j + 4] = readers[j + 12]; // email
                readers[j + 5] = readers[j + 13]; // address
                readers[j + 6] = readers[j + 14]; // regDate
                readers[j + 7] = readers[j + 15]; // expDate
            }
            size--;
            cout << "Xoa doc gia thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay doc gia voi ma " << id << "!\n";
}

// Hàm tìm kiếm độc giả theo CMND
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void searchReaderByCMND(string readers[], int size) {
    string cmnd;
    cout << "Nhap CMND can tim: "; cin >> cmnd;
    bool found = false;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (readers[index + 2] == cmnd) {
            cout << "Ma doc gia: " << readers[index] << "\n";
            cout << "Ho ten: " << readers[index + 1] << "\n";
            cout << "CMND: " << readers[index + 2] << "\n";
            cout << "Gioi tinh: " << readers[index + 3] << "\n";
            cout << "Email: " << readers[index + 4] << "\n";
            cout << "Dia chi: " << readers[index + 5] << "\n";
            cout << "Ngay lap the: " << readers[index + 6] << "\n";
            cout << "Ngay het han: " << readers[index + 7] << "\n";
            cout << "------------------------\n";
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay doc gia voi CMND " << cmnd << "!\n";
}

// Hàm tìm kiếm độc giả theo họ tên
// - readers: Mảng chứa thông tin độc giả
// - size: Số lượng độc giả hiện tại trong mảng
void searchReaderByName(string readers[], int size) {
    string name;
    cout << "Nhap ho ten can tim: "; cin.ignore(); getline(cin, name);
    bool found = false;
    for (int i = 0; i < size; i++) {
        int index = i * 8;
        if (readers[index + 1] == name) {
            cout << "Ma doc gia: " << readers[index] << "\n";
            cout << "Ho ten: " << readers[index + 1] << "\n";
            cout << "CMND: " << readers[index + 2] << "\n";
            cout << "Gioi tinh: " << readers[index + 3] << "\n";
            cout << "Email: " << readers[index + 4] << "\n";
            cout << "Dia chi: " << readers[index + 5] << "\n";
            cout << "Ngay lap the: " << readers[index + 6] << "\n";
            cout << "Ngay het han: " << readers[index + 7] << "\n";
            cout << "------------------------\n";
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay doc gia voi ho ten " << name << "!\n";
}