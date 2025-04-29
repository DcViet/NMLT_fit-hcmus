#include <stdio.h>
#include <string.h>
#include "./BookManager.h"

// Hàm hiển thị thông tin một cuốn sách
void displaySingleBook(
    const char isbn[], const char titles[], const char authors[],
    const char genres[], const char years[], const char publishers[],
    const char quantities[], int bookIndex, int fieldSize)
{
    int offset = bookIndex * fieldSize;

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
    const char quantities[], int size, int fieldSize)
{
    if (size == 0)
    {
        printf("Khong co sach nao trong thu vien!\n");
        return;
    }

    printf("\n=== DANH SACH SACH ===\n");
    for (int i = 0; i < size; i++)
    {
        displaySingleBook(isbn, titles, authors, genres, years, publishers, quantities, i, fieldSize);
    }
}

void inputBookInfo(
    char isbn[], char title[], char author[], char genre[],
    char year[], char publisher[], char quantity[], int fieldSize)
{
    inputField("Nhap ISBN: ", isbn, fieldSize);
    inputField("Nhap ten sach: ", title, fieldSize);
    inputField("Nhap tac gia: ", author, fieldSize);
    inputField("Nhap the loai: ", genre, fieldSize);
    inputField("Nhap nam xuat ban: ", year, fieldSize);
    inputField("Nhap nha xuat ban: ", publisher, fieldSize);
    inputField("Nhap so luong: ", quantity, fieldSize);
}
