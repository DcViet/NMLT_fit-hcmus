#pragma once

// Hằng số
#define FIELD_SIZE 50  // Độ dài mỗi trường dữ liệu
#define FIELD_COUNT 9  // Số lượng trường dữ liệu của độc giả

void addReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &size, int fieldSize,
    const char newReaderId[], const char newFullName[], const char newIdCard[],
    const char newBirthDate[], const char newGender[], const char newEmail[],
    const char newAddress[], const char newCardIssueDate[], const char newCardExpiryDate[]);

bool editReader(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int size, int fieldSize, const char targetId[],
    const char newReaderId[], const char newFullName[], const char newIdCard[],
    const char newBirthDate[], const char newGender[], const char newEmail[],
    const char newAddress[], const char newCardIssueDate[], const char newCardExpiryDate[]);

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
