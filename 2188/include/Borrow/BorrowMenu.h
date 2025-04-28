#pragma once

#include "BorrowFunctions.h"
#include "BorrowManager.h"
#include "ReaderManager.h"

void borrowManagementMenu(
    char borrowReaderIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &borrowSize, int maxBorrows, int borrowFieldSize,
    char borrowTickets[], char returnTickets[], int &returnSize, int maxReturns,
    char idCards[], int readerSize, int readerFieldSize,
    char isbn[], int bookSize, int bookFieldSize);

