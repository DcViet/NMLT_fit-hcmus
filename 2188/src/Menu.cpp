#include <stdio.h>
#include <string.h>
#include "Menu.h"

// Hàm hiển thị menu chính
void displayMainMenu()
{
    printf("\n=== HE THONG QUAN LY THU VIEN ===\n");
    printf("1. Quan ly sach\n");
    printf("2. Quan ly doc gia\n");
    printf("3. Quan ly muon/tra sach\n");
    printf("4. Thong ke\n");
    printf("0. Thoat\n");
    printf("Chon chuc nang: ");
}

// Hàm bỏ ký tự '\n' thừa của fgets
void removeNewline(char str[])
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

// Hàm nhập 1 trường dữ liệu (field) bất kỳ
void inputField(const char prompt[], char output[], int fieldSize)
{
    printf("%s", prompt);
    if (fgets(output, fieldSize, stdin) != NULL)
    {
        removeNewline(output);
    }
}

