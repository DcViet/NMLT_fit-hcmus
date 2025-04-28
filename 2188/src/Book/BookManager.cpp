#include <stdio.h>
#include <string.h>
#include "BookManager.h"

#include <stdio.h>
#include <string.h>

// Hàm hiển thị thông tin một cuốn sách
void displaySingleBook(const char isbn[], const char titles[], const char authors[],
                       const char genres[], const char years[], const char publishers[],
                       const char quantities[], int index, int maxLen)
{
    printf("ISBN: %s\n", &isbn[index]);
    printf("Ten sach: %s\n", &titles[index]);
    printf("Tac gia: %s\n", &authors[index]);
    printf("The loai: %s\n", &genres[index]);
    printf("Nam xuat ban: %s\n", &years[index]);
    printf("Nha xuat ban: %s\n", &publishers[index]);
    printf("So luong: %s\n", &quantities[index]);
    printf("------------------------\n");
}

// Hàm hiển thị danh sách sách
void displayBooks(const char isbn[], const char titles[], const char authors[],
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
        // Gọi hàm hiển thị thông tin một cuốn sách
        displaySingleBook(isbn, titles, authors, genres, years, publishers, quantities, i * maxLen, maxLen);
    }
}


void inputBookInfo(char isbn[], char title[], char author[], char genre[], char year[], char publisher[], char quantity[], int maxLen)
{
    printf("Nhap ISBN: ");
    scanf("%s", isbn);
    getchar();

    printf("Nhap ten sach: ");
    scanf(" %[^\n]s", title);
    getchar();

    printf("Nhap tac gia: ");
    scanf(" %[^\n]s", author);
    getchar();

    printf("Nhap the loai: ");
    scanf(" %[^\n]s", genre);
    getchar();

    printf("Nhap nam xuat ban: ");
    scanf("%s", year);
    getchar();

    printf("Nhap nha xuat ban: ");
    scanf(" %[^\n]s", publisher);
    getchar();

    printf("Nhap so luong: ");
    scanf("%s", quantity);
}
