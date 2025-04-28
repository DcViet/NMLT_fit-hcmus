#pragma once
#include "BookFunctions.h"
#include "ReaderManager.h"

int inputAndCheckCMND(char *cmnd, int borrowFieldSize, char idCards[], int readerSize, int readerFieldSize);

int inputAndCheckISBN(char *isbnBook, int borrowFieldSize, char isbn[], int bookSize, int bookFieldSize);


