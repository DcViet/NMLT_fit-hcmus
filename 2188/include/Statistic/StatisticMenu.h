#pragma once

#include "StatisticFunctions.h"

// Hàm xử lý menu thống kê
void statisticsMenu(
    const char bookQuantities[], int bookSize, int bookMaxLen,
    const char bookGenres[], const char readerGenders[],
    int readerSize, int readerFieldSize,
    const char borrowActualReturnDates[], const char borrowBookISBNs[],
    int borrowSize, int borrowFieldSize,
    const char borrowReaderIds[], const char borrowDates[], const char borrowDueDates[],
    const char readers[], const char fullNames[]);
