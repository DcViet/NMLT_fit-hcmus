#include <stdio.h>
#include <string.h>
#include "BookFunctions.h"


void addBook(char isbn[], char titles[], char authors[], char genres[],
             char years[], char publishers[], char quantities[],
             int &size, int maxLen,
             const char newIsbn[], const char newTitle[], const char newAuthor[],
             const char newGenre[], const char newYear[], const char newPublisher[],
             const char newQuantity[])
{
    if (size >= maxLen)
    {
        printf("Thu vien da day, khong the them sach!\n");
        return;
    }
    int index = size * maxLen;
    strncpy(&isbn[index], newIsbn, maxLen - 1);
    isbn[index + maxLen - 1] = '\0';
    strncpy(&titles[index], newTitle, maxLen - 1);
    titles[index + maxLen - 1] = '\0';
    strncpy(&authors[index], newAuthor, maxLen - 1);
    authors[index + maxLen - 1] = '\0';
    strncpy(&genres[index], newGenre, maxLen - 1);
    genres[index + maxLen - 1] = '\0';
    strncpy(&years[index], newYear, maxLen - 1);
    years[index + maxLen - 1] = '\0';
    strncpy(&publishers[index], newPublisher, maxLen - 1);
    publishers[index + maxLen - 1] = '\0';
    strncpy(&quantities[index], newQuantity, maxLen - 1);
    quantities[index + maxLen - 1] = '\0';
    size++;
}

// Hàm chỉnh sửa sách dựa trên ISBN
bool editBook(char isbn[], char titles[], char authors[], char genres[],
              char years[], char publishers[], char quantities[],
              int size, int maxLen, const char targetIsbn[],
              const char newIsbn[], const char newTitle[], const char newAuthor[],
              const char newGenre[], const char newYear[], const char newPublisher[],
              const char newQuantity[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * maxLen;
        if (strcmp(&isbn[index], targetIsbn) == 0)
        {
            // Sao chép từng thuộc tính với strncpy từ các giá trị riêng lẻ
            strncpy(&isbn[index], newIsbn, maxLen - 1);
            isbn[index + maxLen - 1] = '\0';

            strncpy(&titles[index], newTitle, maxLen - 1);
            titles[index + maxLen - 1] = '\0';

            strncpy(&authors[index], newAuthor, maxLen - 1);
            authors[index + maxLen - 1] = '\0';

            strncpy(&genres[index], newGenre, maxLen - 1);
            genres[index + maxLen - 1] = '\0';

            strncpy(&years[index], newYear, maxLen - 1);
            years[index + maxLen - 1] = '\0';

            strncpy(&publishers[index], newPublisher, maxLen - 1);
            publishers[index + maxLen - 1] = '\0';

            strncpy(&quantities[index], newQuantity, maxLen - 1);
            quantities[index + maxLen - 1] = '\0';

            return true; // Chỉnh sửa thành công
        }
    }
    printf("Khong tim thay sach voi ISBN: %s\n", targetIsbn);
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
            // Di chuyển toàn bộ dữ liệu từ phần tử tiếp theo lên trước
            int bytesToMove = (size - i - 1) * maxLen;
            if (bytesToMove > 0)
            {
                memmove(&isbn[index], &isbn[index + maxLen], bytesToMove);
                memmove(&titles[index], &titles[index + maxLen], bytesToMove);
                memmove(&authors[index], &authors[index + maxLen], bytesToMove);
                memmove(&genres[index], &genres[index + maxLen], bytesToMove);
                memmove(&years[index], &years[index + maxLen], bytesToMove);
                memmove(&publishers[index], &publishers[index + maxLen], bytesToMove);
                memmove(&quantities[index], &quantities[index + maxLen], bytesToMove);
            }
            size--;
            return true; // Xóa thành công
        }
    }
    printf("Khong tim thay sach voi ISBN: %s\n", targetIsbn);
    return false; // Không tìm thấy sách
}

// Hàm tìm kiếm sách 
int searchBook(const char arr[], int size, int maxLen, const char target[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * maxLen;
        if (strcmp(&arr[index], target) == 0)
        {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}
