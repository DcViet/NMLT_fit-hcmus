#pragma once

#include <stdio.h>
#include <string.h>
#include "Menu.h"

// Hàm hiển thị thông tin một cuốn sách
void displaySingleBook(
    const char isbn[], const char titles[], const char authors[],
    const char genres[], const char years[], const char publishers[],
    const char quantities[], int index, int maxLen);

// Hàm hiển thị danh sách sách
void displayBooks(
    const char isbn[], const char titles[], const char authors[],
    const char genres[], const char years[], const char publishers[],
    const char quantities[], int size, int maxLen);

void inputBookInfo(
    char isbn[], char title[], char author[], char genre[],
    char year[], char publisher[], char quantity[], int maxLen);
