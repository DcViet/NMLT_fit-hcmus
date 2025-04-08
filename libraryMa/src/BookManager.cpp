#include <iostream>
#include <cstring>
#include "../include/BookManager.h"

using namespace std;

// Hàm hiển thị danh sách sách
void displayBooks(const char books[], int size, int attrCount, int maxLen)
{
    if (size == 0)
    {
        printf("Khong co sach nao trong thu vien!\n");
        return;
    }
    printf("\n=== DANH SACH SACH ===\n");
    for (int i = 0; i < size; i++)
    {
        int index = i * attrCount * maxLen;
        printf("ISBN: %s\n", &books[index]);
        printf("Ten sach: %s\n", &books[index + maxLen]);
        printf("Tac gia: %s\n", &books[index + 2 * maxLen]);
        printf("The loai: %s\n", &books[index + 3 * maxLen]);
        printf("Nam xuat ban: %s\n", &books[index + 4 * maxLen]);
        printf("Nha xuat ban: %s\n", &books[index + 5 * maxLen]);
        printf("So luong: %s\n", &books[index + 6 * maxLen]);
        printf("------------------------\n");
    }
}

// Hàm thêm sách vào mảng
void addBook(char books[], int &size, int attrCount, int maxLen, const char newBook[])
{
    int index = size * attrCount * maxLen;
    memcpy(&books[index], newBook, attrCount * maxLen);
    size++;
}

// Hàm chỉnh sửa sách dựa trên ISBN
bool editBook(char books[], int size, int attrCount, int maxLen, const char isbn[], const char updatedBook[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * attrCount * maxLen;
        if (strcmp(&books[index], isbn) == 0)
        {
            memcpy(&books[index], updatedBook, attrCount * maxLen);
            return true; // Chỉnh sửa thành công
        }
    }
    return false; // Không tìm thấy sách
}

// Hàm xóa sách dựa trên ISBN
bool deleteBook(char books[], int &size, int attrCount, int maxLen, const char isbn[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * attrCount * maxLen;
        if (strcmp(&books[index], isbn) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                memcpy(&books[j * attrCount * maxLen],
                       &books[(j + 1) * attrCount * maxLen],
                       attrCount * maxLen);
            }
            size--;
            return true;
        }
    }
    return false;
}

// Hàm tìm kiếm sách theo ISBN
int searchBookByISBN(const char books[], int size, int attrCount, int maxLen, const char isbn[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * attrCount * maxLen;
        if (strcmp(&books[index], isbn) == 0)
        {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// Hàm tìm kiếm sách theo tên sách
int searchBookByTitle(const char books[], int size, int attrCount, int maxLen, const char title[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * attrCount * maxLen;
        if (strcmp(&books[index + maxLen], title) == 0)
        {
            return i;
        }
    }
    return -1;
}
