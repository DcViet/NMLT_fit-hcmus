#pragma once

// Hàm thống kê số lượng sách trong thư viện
void countBooks(const char quantities[], int size, int maxLen);

// Hàm thống kê số lượng sách theo thể loại
void countBooksByGenre(const char genres[], const char quantities[], int size, int maxLen);

// Hàm thống kê số lượng độc giả
void countReaders(int size, int fieldSize); 

// Hàm thống kê số lượng độc giả theo giới tính
void countReadersByGender(const char genders[], int size, int fieldSize);

// Hàm thống kê số sách đang được mượn
void countBorrowedBooks(const char actualReturnDates[], const char bookISBNs[], int borrowSize, int fieldSize);

// Hàm thống kê danh sách độc giả bị trễ hạn
void listOverdueReaders(
    const char readerIds[], const char borrowDates[], const char dueDates[],
    const char actualReturnDates[], int borrowSize, int borrowFieldSize,
    const char readers[], const char fullNames[], int readerSize, int readerFieldSize);
