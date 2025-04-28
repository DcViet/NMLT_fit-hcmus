#include <stdio.h>
#include <string.h>
#include "StatisticsMenu.h"

// Hàm xử lý menu thống kê
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
    do
    {
        printf("\n=== THONG KE ===\n");
        printf("1. Tong so sach trong thu vien\n");
        printf("2. Thong ke sach theo the loai\n");
        printf("3. Tong so doc gia\n");
        printf("4. Thong ke doc gia theo gioi tinh\n");
        printf("5. Thong ke sach dang muon\n");
        printf("6. Danh sach doc gia tre han\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
            listOverdueReaders(borrowReaderIds, borrowDates, borrowDueDates,
                               borrowActualReturnDates, borrowSize, borrowFieldSize,
                               readers, fullNames, readerSize, readerFieldSize);
            break;
        case 0:
            printf("Quay lai menu chinh...\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}
