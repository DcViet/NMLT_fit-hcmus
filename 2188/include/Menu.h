#pragma once

// Hàm hiển thị menu chính
void displayMainMenu();

// Hàm bỏ ký tự '\n' thừa của fgets
void removeNewline(char str[]);

// Hàm nhập 1 trường dữ liệu (field) bất kỳ
void inputField(const char prompt[], char output[], int fieldSize);

