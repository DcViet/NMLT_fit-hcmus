#pragma once

#include "Menu.h"
// Hằng số

// #define FIELD_SIZE 50
// #define FIELD_COUNT 7 

// Hàm hiển thị thông tin một cuốn sách
void displaySingleBook(
    const char isbn[], const char titles[], const char authors[],
    const char genres[], const char years[], const char publishers[],
    const char quantities[], int index, int fieldSize);

// Hàm hiển thị danh sách sách
void displayBooks(
    const char isbn[], const char titles[], const char authors[],
    const char genres[], const char years[], const char publishers[],
    const char quantities[], int size, int fieldSize);

void inputBookInfo(
    char isbn[], char title[], char author[], char genre[],
    char year[], char publisher[], char quantity[], int fieldSize);
