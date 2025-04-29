#pragma once

#include "Menu.h"

// Hằng số
// #define FIELD_SIZE 50
// #define FIELD_COUNT 9 

void displayReader(
    const char readerIds[], const char fullNames[], const char idCards[],
    const char birthDates[], const char genders[], const char emails[],
    const char addresses[], const char cardIssueDates[], const char cardExpiryDates[],
    int index, int fieldSize);

// Hàm hiển thị danh sách độc giả
void displayReaders(
    const char readerIds[], const char fullNames[], const char idCards[],
    const char birthDates[], const char genders[], const char emails[],
    const char addresses[], const char cardIssueDates[], const char cardExpiryDates[],
    int size, int fieldSize);

void inputReader(
    char newReaderId[], char newFullName[], char newIdCard[],
    char newBirthDate[], char newGender[], char newEmail[],
    char newAddress[], char newCardIssueDate[], char newCardExpiryDate[],
    int fieldSize);


