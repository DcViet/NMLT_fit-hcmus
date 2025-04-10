#include <stdio.h>
#include "../include/Menu.h"

void displayMainMenu() {
    printf("\n=== QUAN LY THU VIEN ===\n");
    printf("1. Quan ly sach\n");
    printf("2. Quan ly doc gia\n");
    printf("3. Quan ly muon/tra sach\n");
    printf("4. Thong ke\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon: ");
}

void bookManagementMenu(
    char isbn[], char titles[], char authors[], char genres[],
    char years[], char publishers[], char quantities[],
    int &bookSize, int maxBooks, int maxLen)
{
    int choice;
    do {
        printf("\n=== QUAN LY SACH ===\n");
        printf("1. Hien thi danh sach sach\n");
        printf("2. Them sach\n");
        printf("3. Sua sach\n");
        printf("4. Xoa sach\n");
        printf("5. Tim sach theo ISBN\n");
        printf("6. Tim sach theo ten\n");
        printf("0. Quay lai\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen);
                break;
            case 2: {
                char newBook[7 * maxLen];
                printf("Nhap thong tin sach (ISBN, Ten, Tac gia, The loai, Nam XB, NXB, So luong): ");
                scanf("%s %s %s %s %s %s %s", 
                      &newBook[0 * maxLen], &newBook[1 * maxLen], &newBook[2 * maxLen],
                      &newBook[3 * maxLen], &newBook[4 * maxLen], &newBook[5 * maxLen],
                      &newBook[6 * maxLen]);
                addBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen, newBook);
                break;
            }
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

void readerManagementMenu(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &readerSize, int maxReaders, int fieldSize)
{
    int choice;
    do {
        printf("\n=== QUAN LY DOC GIA ===\n");
        printf("1. Hien thi danh sach doc gia\n");
        printf("2. Them doc gia\n");
        printf("3. Sua doc gia\n");
        printf("4. Xoa doc gia\n");
        printf("5. Tim doc gia theo CMND\n");
        printf("6. Tim doc gia theo ho ten\n");
        printf("0. Quay lai\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayReaders(readerIds, fullNames, idCards, birthDates, genders, emails,
                               addresses, cardIssueDates, cardExpiryDates, readerSize, fieldSize);
                break;
            case 2: {
                char newReader[9 * fieldSize];
                printf("Nhap thong tin doc gia (Ma, Ho ten, CMND, Ngay sinh, Gioi tinh, Email, Dia chi, Ngay lap the, Ngay het han): ");
                scanf("%s %s %s %s %s %s %s %s %s",
                      &newReader[0 * fieldSize], &newReader[1 * fieldSize], &newReader[2 * fieldSize],
                      &newReader[3 * fieldSize], &newReader[4 * fieldSize], &newReader[5 * fieldSize],
                      &newReader[6 * fieldSize], &newReader[7 * fieldSize], &newReader[8 * fieldSize]);
                addReader(readerIds, fullNames, idCards, birthDates, genders, emails,
                          addresses, cardIssueDates, cardExpiryDates, readerSize, fieldSize, newReader);
                break;
            }
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

void borrowManagementMenu(
    char borrowReaderIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &borrowSize, int maxBorrows, int borrowFieldSize,
    char borrowTickets[], char returnTickets[], int &returnSize, int maxReturns)
{
    int choice;
    do {
        printf("\n=== QUAN LY MUON/TRA SACH ===\n");
        printf("1. Tao phieu muon\n");
        printf("2. Tao phieu tra\n");
        printf("0. Quay lai\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char readerId[FIELD_SIZE], borrowDate[FIELD_SIZE], dueDate[FIELD_SIZE], isbnList[FIELD_SIZE];
                printf("Nhap thong tin phieu muon (Ma doc gia, Ngay muon, Ngay tra du kien, Danh sach ISBN): ");
                scanf("%s %s %s %s", readerId, borrowDate, dueDate, isbnList);
                createBorrowTicket(borrowReaderIds, borrowDates, dueDates, actualReturnDates, bookISBNs,
                                   borrowSize, maxBorrows, borrowFieldSize, readerId, borrowDate, dueDate, isbnList);
                break;
            }
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

void statisticsMenu(
    const char bookQuantities[], int bookSize, int bookMaxLen,
    const char bookGenres[], const char readerGenders[],
    int readerSize, int readerFieldSize,
    const char borrowActualReturnDates[], const char borrowBookISBNs[],
    int borrowSize, int borrowFieldSize,
    const char borrowReaderIds[], const char borrowDates[], const char borrowDueDates[],
    const char readers[], const char fullNames[])
{
    int choice;
    do {
        printf("\n=== THONG KE ===\n");
        printf("1. Tong so sach\n");
        printf("2. So sach theo the loai\n");
        printf("3. Tong so doc gia\n");
        printf("4. So doc gia theo gioi tinh\n");
        printf("5. So sach dang duoc muon\n");
        printf("6. Danh sach doc gia tre han\n");
        printf("0. Quay lai\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                countBooks(bookQuantities, bookSize, bookMaxLen);
                break;
            case 2:
                countBooksByGenre(bookGenres, bookQuantities, bookSize, bookMaxLen);
                break;
            case 3:
                countReaders(readerSize, readerFieldSize);
                break;
            case 4:
                countReadersByGender(readerGenders, readerSize, readerFieldSize);
                break;
            case 5:
                countBorrowedBooks(borrowActualReturnDates, borrowBookISBNs, borrowSize, borrowFieldSize);
                break;
            case 6:
                listOverdueReaders(borrowReaderIds, borrowDates, borrowDueDates, borrowActualReturnDates,
                                   borrowSize, borrowFieldSize, readers, fullNames, readerSize, readerFieldSize);
                break;
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}