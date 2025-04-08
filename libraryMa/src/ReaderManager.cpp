#include <iostream>
#include <cstring>
#include <cstdio>
#include "../include/ReaderManager.h"

using namespace std;

const int FIELD_SIZE = 50;
const int FIELD_COUNT = 9;

// Hàm hiển thị danh sách độc giả
void displayReaders(const char readers[], int size)
{
    if (size == 0)
    {
        printf("Khong co doc gia nao trong thu vien!\n");
        return;
    }
    printf("\n=== DANH SACH DOC GIA ===\n");
    for (int i = 0; i < size; i++)
    {
        int index = i * FIELD_COUNT * FIELD_SIZE;
        printf("Ma doc gia: %s\n", &readers[index]);
        printf("Ho ten: %s\n", &readers[index + FIELD_SIZE]);
        printf("CMND: %s\n", &readers[index + 2 * FIELD_SIZE]);
        printf("Ngay sinh: %s\n", &readers[index + 3 * FIELD_SIZE]);
        printf("Gioi tinh: %s\n", &readers[index + 4 * FIELD_SIZE]);
        printf("Email: %s\n", &readers[index + 5 * FIELD_SIZE]);
        printf("Dia chi: %s\n", &readers[index + 6 * FIELD_SIZE]);
        printf("Ngay lap the: %s\n", &readers[index + 7 * FIELD_SIZE]);
        printf("Ngay het han: %s\n", &readers[index + 8 * FIELD_SIZE]);
        printf("------------------------\n");
    }
}

// Hàm thêm độc giả vào mảng
void addReader(char readers[], int &size, const char newReader[])
{
    int index = size * FIELD_COUNT * FIELD_SIZE;
    memcpy(&readers[index], newReader, FIELD_COUNT * FIELD_SIZE);
    size++;
}

// Hàm chỉnh sửa độc giả dựa trên mã độc giả
bool editReader(char readers[], int size, const char id[], const char updatedReader[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * FIELD_COUNT * FIELD_SIZE;
        if (strcmp(&readers[index], id) == 0)
        {
            memcpy(&readers[index], updatedReader, FIELD_COUNT * FIELD_SIZE);
            return true; // Chỉnh sửa thành công
        }
    }
    return false; // Không tìm thấy độc giả
}

// Hàm xóa độc giả dựa trên mã độc giả
bool deleteReader(char readers[], int &size, const char id[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * FIELD_COUNT * FIELD_SIZE;
        if (strcmp(&readers[index], id) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                memcpy(&readers[j * FIELD_COUNT * FIELD_SIZE],
                       &readers[(j + 1) * FIELD_COUNT * FIELD_SIZE],
                       FIELD_COUNT * FIELD_SIZE);
            }
            size--;
            return true;
        }
    }
    return false;
}

// Hàm tìm kiếm độc giả theo CMND
int searchReaderByCMND(const char readers[], int size, const char cmnd[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * FIELD_COUNT * FIELD_SIZE;
        if (strcmp(&readers[index + 2 * FIELD_SIZE], cmnd) == 0)
        {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// Hàm tìm kiếm độc giả theo họ tên
int searchReaderByName(const char readers[], int size, const char name[])
{
    for (int i = 0; i < size; i++)
    {
        int index = i * FIELD_COUNT * FIELD_SIZE;
        if (strcmp(&readers[index + FIELD_SIZE], name) == 0)
        {
            return i;
        }
    }
    return -1;
}
