#include <stdio.h>
#include "../include/Menu.h"

#define MAX_BOOKS 100
#define MAX_READERS 100
#define MAX_BORROWS 100
#define MAX_RETURNS 1000
#define BOOK_FIELD_SIZE 50
#define READER_FIELD_SIZE 50
#define BORROW_FIELD_SIZE 50

int main()
{
    // Khởi tạo mảng cho sách
    char isbn[MAX_BOOKS * BOOK_FIELD_SIZE] = {0};
    char titles[MAX_BOOKS * BOOK_FIELD_SIZE] = {0};
    char authors[MAX_BOOKS * BOOK_FIELD_SIZE] = {0};
    char genres[MAX_BOOKS * BOOK_FIELD_SIZE] = {0};
    char years[MAX_BOOKS * BOOK_FIELD_SIZE] = {0};
    char publishers[MAX_BOOKS * BOOK_FIELD_SIZE] = {0};
    char quantities[MAX_BOOKS * BOOK_FIELD_SIZE] = {0};
    int bookSize = 0;

    // Khởi tạo mảng cho độc giả
    char readerIds[MAX_READERS * READER_FIELD_SIZE] = {0};
    char fullNames[MAX_READERS * READER_FIELD_SIZE] = {0};
    char idCards[MAX_READERS * READER_FIELD_SIZE] = {0};
    char birthDates[MAX_READERS * READER_FIELD_SIZE] = {0};
    char genders[MAX_READERS * READER_FIELD_SIZE] = {0};
    char emails[MAX_READERS * READER_FIELD_SIZE] = {0};
    char addresses[MAX_READERS * READER_FIELD_SIZE] = {0};
    char cardIssueDates[MAX_READERS * READER_FIELD_SIZE] = {0};
    char cardExpiryDates[MAX_READERS * READER_FIELD_SIZE] = {0};
    int readerSize = 0;

    // Khởi tạo mảng cho mượn/trả
    char borrowReaderIds[MAX_BORROWS * BORROW_FIELD_SIZE] = {0};
    char borrowDates[MAX_BORROWS * BORROW_FIELD_SIZE] = {0};
    char dueDates[MAX_BORROWS * BORROW_FIELD_SIZE] = {0};
    char actualReturnDates[MAX_BORROWS * BORROW_FIELD_SIZE] = {0};
    char bookISBNs[MAX_BORROWS * BORROW_FIELD_SIZE] = {0};
    int borrowSize = 0;
    char borrowTickets[MAX_BORROWS * BORROW_FIELD_SIZE] = {0};
    char returnTickets[MAX_RETURNS] = {0};
    int returnSize = 0;

    // Thêm dữ liệu mẫu
    addReader(readerIds, fullNames, idCards, birthDates, genders, emails, addresses,
              cardIssueDates, cardExpiryDates, readerSize, READER_FIELD_SIZE,
              "DG001", "Nguyen Van A", "123456789", "01/01/2000", "Nam",
              "nguyen@example.com", "123 Duong ABC", "01/01/2023", "01/01/2028");

    addReader(readerIds, fullNames, idCards, birthDates, genders, emails, addresses,
              cardIssueDates, cardExpiryDates, readerSize, READER_FIELD_SIZE,
              "DG002", "Tran Thi B", "987654321", "02/02/1999", "Nu",
              "tran@example.com", "456 Duong XYZ", "02/02/2023", "02/02/2028");

    addReader(readerIds, fullNames, idCards, birthDates, genders, emails, addresses,
              cardIssueDates, cardExpiryDates, readerSize, READER_FIELD_SIZE,
              "DG003", "Le Van C", "456789123", "03/03/1998", "Nam",
              "le@example.com", "789 Duong DEF", "03/03/2023", "03/03/2028");

    addBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, BOOK_FIELD_SIZE,
            "1234", "Lap trinh C++", "Nguyen Van A", "Giao trinh", "2022", "NXB Giao Duc", "10");

    addBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, BOOK_FIELD_SIZE,
            "1235", "Lap trinh go", "Nguyen Van B", "Giao trinh", "2021", "NXB Giao Duc", "5");

    int choice;
    do
    {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bookManagementMenu(isbn, titles, authors, genres, years, publishers, quantities,
                               bookSize, MAX_BOOKS, BOOK_FIELD_SIZE);
            break;
        case 2:
            readerManagementMenu(readerIds, fullNames, idCards, birthDates, genders, emails, addresses,
                                 cardIssueDates, cardExpiryDates, readerSize, MAX_READERS, READER_FIELD_SIZE);
            break;

        case 3:
            borrowManagementMenu(borrowReaderIds, borrowDates, dueDates, actualReturnDates, bookISBNs,
                                 borrowSize, MAX_BORROWS, BORROW_FIELD_SIZE,
                                 borrowTickets, returnTickets, returnSize, MAX_RETURNS,

                                 idCards, readerSize, READER_FIELD_SIZE,
                                 isbn, bookSize, BOOK_FIELD_SIZE);
            break;

        case 4:
            statisticsMenu(quantities, bookSize, BOOK_FIELD_SIZE, genres, genders,
                           readerSize, READER_FIELD_SIZE, actualReturnDates, bookISBNs,
                           borrowSize, BORROW_FIELD_SIZE, borrowReaderIds, borrowDates, dueDates,
                           readerIds, fullNames);
            break;
        case 0:
            printf("Thoat chuong trinh...\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}