#include <iostream>
#include <cstring>
#include "../include/BookManager.h"

using namespace std;

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
        int index = i * maxLen;
        printf("ISBN: %s\n", &isbn[index]);
        printf("Ten sach: %s\n", &titles[index]);
        printf("Tac gia: %s\n", &authors[index]);
        printf("The loai: %s\n", &genres[index]);
        printf("Nam xuat ban: %s\n", &years[index]);
        printf("Nha xuat ban: %s\n", &publishers[index]);
        printf("So luong: %s\n", &quantities[index]);
        printf("------------------------\n");
    }
}

// Hàm thêm sách vào mảng
void addBook(char isbn[], char titles[], char authors[], char genres[],
             char years[], char publishers[], char quantities[],
             int &size, int maxLen, const char newBook[])
{
    int index = size * maxLen;

    // Sao chép từng thuộc tính vào mảng tương ứng
    memcpy(&isbn[index], &newBook[0 * maxLen], maxLen);
    memcpy(&titles[index], &newBook[1 * maxLen], maxLen);
    memcpy(&authors[index], &newBook[2 * maxLen], maxLen);
    memcpy(&genres[index], &newBook[3 * maxLen], maxLen);
    memcpy(&years[index], &newBook[4 * maxLen], maxLen);
    memcpy(&publishers[index], &newBook[5 * maxLen], maxLen);
    memcpy(&quantities[index], &newBook[6 * maxLen], maxLen);

    size++;
}

// Hàm chỉnh sửa sách dựa trên ISBN
bool editBook(char isbn[], char titles[], char authors[], char genres[],
              char years[], char publishers[], char quantities[],
              int size, int maxLen, const char targetIsbn[], const char updatedBook[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * maxLen;
        if (strcmp(&isbn[index], targetIsbn) == 0)
        {
            // Sao chép từng thuộc tính từ updatedBook vào mảng tương ứng
            memcpy(&isbn[index], &updatedBook[0 * maxLen], maxLen);
            memcpy(&titles[index], &updatedBook[1 * maxLen], maxLen);
            memcpy(&authors[index], &updatedBook[2 * maxLen], maxLen);
            memcpy(&genres[index], &updatedBook[3 * maxLen], maxLen);
            memcpy(&years[index], &updatedBook[4 * maxLen], maxLen);
            memcpy(&publishers[index], &updatedBook[5 * maxLen], maxLen);
            memcpy(&quantities[index], &updatedBook[6 * maxLen], maxLen);
            return true; // Chỉnh sửa thành công
        }
    }
    return false; // Không tìm thấy sách
}

// Hàm xóa sách dựa trên ISBN
bool deleteBook(char isbn[], char titles[], char authors[], char genres[],
                char years[], char publishers[], char quantities[],
                int &size, int maxLen, const char targetIsbn[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * maxLen;
        if (strcmp(&isbn[index], targetIsbn) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                // Di chuyển từng thuộc tính từ phần tử tiếp theo lên phần tử hiện tại
                memcpy(&isbn[j * maxLen], &isbn[(j + 1) * maxLen], maxLen);
                memcpy(&titles[j * maxLen], &titles[(j + 1) * maxLen], maxLen);
                memcpy(&authors[j * maxLen], &authors[(j + 1) * maxLen], maxLen);
                memcpy(&genres[j * maxLen], &genres[(j + 1) * maxLen], maxLen);
                memcpy(&years[j * maxLen], &years[(j + 1) * maxLen], maxLen);
                memcpy(&publishers[j * maxLen], &publishers[(j + 1) * maxLen], maxLen);
                memcpy(&quantities[j * maxLen], &quantities[(j + 1) * maxLen], maxLen);
            }
            size--;
            return true;
        }
    }
    return false;
}

// Hàm tìm kiếm sách theo ISBN
int searchBookByISBN(const char isbn[], int size, int maxLen, const char targetIsbn[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * maxLen;
        if (strcmp(&isbn[index], targetIsbn) == 0)
        {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// Hàm tìm kiếm sách theo tên sách
int searchBookByTitle(const char titles[], int size, int maxLen, const char targetTitle[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * maxLen;
        if (strcmp(&titles[index], targetTitle) == 0)
        {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}
