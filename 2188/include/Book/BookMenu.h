#pragma once

#include "BookManager.h"
#include "BookFunctions.h"

// Hàm xử lý menu quản lý sách
void bookManagementMenu(
    char isbn[], char titles[], char authors[], char genres[],
    char years[], char publishers[], char quantities[],
    int &bookSize, int maxBooks, int maxLen);
