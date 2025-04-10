#ifndef MENU_H
#define MENU_H

#include "../include/ReaderManager.h"
#include "../include/BookManager.h"
#include "../include/BorrowManager.h"
#include "../include/Statistics.h"

// Hàm hiển thị menu chính
void displayMainMenu();

// Hàm xử lý menu quản lý sách
void bookManagementMenu(
    char isbn[], char titles[], char authors[], char genres[],
    char years[], char publishers[], char quantities[],
    int &bookSize, int maxBooks, int maxLen);

// Hàm xử lý menu quản lý độc giả
void readerManagementMenu(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &readerSize, int maxReaders, int fieldSize);

// Hàm xử lý menu quản lý mượn/trả sách
// void borrowManagementMenu(
//     char borrowReaderIds[], char borrowDates[], char dueDates[],
//     char actualReturnDates[], char bookISBNs[],
//     int &borrowSize, int maxBorrows, int borrowFieldSize,
//     char borrowTickets[], char returnTickets[], int &returnSize, int maxReturns);

void borrowManagementMenu(
    char borrowReaderIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &borrowSize, int maxBorrows, int borrowFieldSize,
    char borrowTickets[], char returnTickets[], int &returnSize, int maxReturns,
    char idCards[], int readerSize, int readerFieldSize,
    char isbn[], int bookSize, int bookFieldSize);

// Hàm xử lý menu thống kê
void statisticsMenu(
    const char bookQuantities[], int bookSize, int bookMaxLen,
    const char bookGenres[], const char readerGenders[],
    int readerSize, int readerFieldSize,
    const char borrowActualReturnDates[], const char borrowBookISBNs[],
    int borrowSize, int borrowFieldSize,
    const char borrowReaderIds[], const char borrowDates[], const char borrowDueDates[],
    const char readers[], const char fullNames[]);

#endif