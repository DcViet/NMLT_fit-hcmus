#include <stdio.h>
#include <string.h>
#include "BookManager.h"

// Hàm hiển thị thông tin một cuốn sách
void displaySingleBook(
    const char isbn[], const char titles[], const char authors[],
    const char genres[], const char years[], const char publishers[],
    const char quantities[], int bookIndex, int maxLen)
{
    int offset = bookIndex * maxLen;

    printf("ISBN: %s\n", &isbn[offset]);
    printf("Ten sach: %s\n", &titles[offset]);
    printf("Tac gia: %s\n", &authors[offset]);
    printf("The loai: %s\n", &genres[offset]);
    printf("Nam xuat ban: %s\n", &years[offset]);
    printf("Nha xuat ban: %s\n", &publishers[offset]);
    printf("So luong: %s\n", &quantities[offset]);
    printf("------------------------\n");
}

// Hàm hiển thị danh sách sách
void displayBooks(
    const char isbn[], const char titles[], const char authors[],
    const char genres[], const char years[], const char publishers[],
    const char quantities[], int size, int maxLen)
{
    if (size == 0)
    {
        printf("Khong co sach nao trong thu vien!\n");
        return;
    }

    printf("\n=== DANH SACH SACH ===\n");
    for (int i = 0; i < size; i++)
    {
        displaySingleBook(isbn, titles, authors, genres, years, publishers, quantities, i, maxLen);
    }
}

void inputBookInfo(
    char isbn[], char title[], char author[], char genre[],
    char year[], char publisher[], char quantity[], int maxLen)
{
    inputField("Nhap ISBN: ", isbn, maxLen);
    inputField("Nhap ten sach: ", title, maxLen);
    inputField("Nhap tac gia: ", author, maxLen);
    inputField("Nhap the loai: ", genre, maxLen);
    inputField("Nhap nam xuat ban: ", year, maxLen);
    inputField("Nhap nha xuat ban: ", publisher, maxLen);
    inputField("Nhap so luong: ", quantity, maxLen);
}
