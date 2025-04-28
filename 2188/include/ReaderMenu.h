#pragma once

#include "ReaderManager.h"

// Hàm xử lý menu quản lý độc giả
void readerManagementMenu(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &readerSize, int maxReaders, int fieldSize);