#ifndef READER_MANAGER_H
#define READER_MANAGER_H

// Hằng số
#define FIELD_SIZE 50  // Độ dài mỗi trường dữ liệu
#define FIELD_COUNT 9  // Số lượng trường dữ liệu của độc giả

// Hàm hiển thị danh sách độc giả
void displayReaders(
    const char readerIds[], const char fullNames[], const char idCards[],
    const char birthDates[], const char genders[], const char emails[],
    const char addresses[], const char cardIssueDates[], const char cardExpiryDates[],
    int size, int fieldSize);

// Hàm thêm độc giả vào mảng
void addReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &size, int fieldSize, const char newReader[]);

// Hàm chỉnh sửa độc giả dựa trên mã độc giả
bool editReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int size, int fieldSize, const char targetId[], const char updatedReader[]);

// Hàm xóa độc giả dựa trên mã độc giả
bool deleteReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &size, int fieldSize, const char targetId[]);

// Hàm tìm kiếm độc giả theo CMND
int searchReaderByCMND(
    const char idCards[], int size, int fieldSize, const char targetCmnd[]);

// Hàm tìm kiếm độc giả theo họ tên
int searchReaderByName(
    const char fullNames[], int size, int fieldSize, const char targetName[]);

#endif