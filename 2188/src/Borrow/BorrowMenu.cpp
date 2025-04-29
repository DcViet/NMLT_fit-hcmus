#include <stdio.h>
#include <string.h>
#include "BorrowMenu.h"

void borrowManagementMenu(
    char borrowReaderIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &borrowSize, int maxBorrows, int borrowFieldSize,
    char borrowTickets[], char returnTickets[], int &returnSize, int maxReturns,
    char idCards[], int readerSize, int readerFieldSize, 
    char isbn[], int bookSize, int bookFieldSize)        
{
    int choice;
    do
    {
        printf("\n=== QUAN LY MUON/TRA SACH ===\n");
        printf("1. Tao phieu muon sach\n");
        printf("2. Tao phieu tra sach\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice)
        {
        case 1:
        {
            char cmnd[borrowFieldSize], borrowDate[DATE_LEN + 1], dueDate[DATE_LEN + 1], isbnBook[borrowFieldSize];

            // Kiểm tra xem độc giả có tồn tại không dựa trên CMND
            if (inputAndCheckCMND(cmnd, borrowFieldSize, idCards, readerSize, readerFieldSize) == -1)
                break;
            // Kiểm tra xem sách có tồn tại không
            if (inputAndCheckISBN(isbnBook, borrowFieldSize, isbn, bookSize, bookFieldSize) == -1)
                break;

            printf("Nhap ngay muon (dd/mm/yyyy): ");
            scanf("%s", borrowDate);
            printf("Nhap ngay den han (dd/mm/yyyy): ");
            scanf("%s", dueDate);
            createBorrowTicket(borrowReaderIds, borrowDates, dueDates, actualReturnDates, bookISBNs,
                               borrowSize, maxBorrows, borrowFieldSize, cmnd, borrowDate, dueDate, isbn);
            break;
        }

        case 2:
        {
            char cmnd[borrowFieldSize], returnDate[DATE_LEN + 1], isbnList[10 * borrowFieldSize];
            int bookCount, prices[10];
            bool lost[10];

            // Kiểm tra xem độc giả có tồn tại không dựa trên CMND
            if (inputAndCheckCMND(cmnd, borrowFieldSize, idCards, readerSize, readerFieldSize) == -1)
                break;

            // Nhập số lượng sách trả
            printf("Nhap so luong sach tra (toi da 10): ");
            scanf("%d", &bookCount);
            getchar(); // Xóa ký tự xuống dòng

            // Kiểm tra bookCount hợp lệ
            // if (bookCount <= 0 || bookCount > 10)
            // {
            //     printf("So luong sach khong hop le!\n");
            //     break;
            // }

            // Nhập ngày trả
            printf("Nhap ngay tra (dd/mm/yyyy): ");
            scanf("%s", returnDate);
            getchar(); // Xóa ký tự xuống dòng

            // Nhập và kiểm tra danh sách ISBN
            bool valid = true;
            for (int i = 0; i < bookCount; i++)
            {
                // Nhập ISBN
                printf("Nhap ISBN sach thu %d: ", i + 1);
                scanf("%s", isbnList + i * borrowFieldSize);
                getchar(); // Xóa ký tự xuống dòng

                // Kiểm tra sách đã mượn
                bool borrowed = false;
                for (int j = 0; j < borrowSize; j++)
                {
                    int borrowIndex = j * borrowFieldSize;
                    if (strcmp(&borrowReaderIds[borrowIndex], cmnd) == 0 &&
                        strcmp(&bookISBNs[borrowIndex], isbnList + i * borrowFieldSize) == 0)
                    {
                        borrowed = true;
                        break;
                    }
                }
                if (!borrowed)
                {
                    printf("Sach voi ISBN %s chua duoc muon boi doc gia nay!\n", isbnList + i * borrowFieldSize);
                    valid = false;
                    // Tiếp tục nhập các ISBN khác thay vì break
                    continue;
                }

                // Nhập giá sách và trạng thái mất
                // printf("Nhap gia sach %d (VND): ", i + 1);
                // scanf("%d", &prices[i]);
                // getchar(); 
                // if (prices[i] < 0)
                // {
                //     printf("Gia sach khong hop le!\n");
                //     valid = false;
                //     continue;
                // }

                printf("Sach co bi mat khong? (1: Co, 0: Khong): ");
                int tempLost;
                scanf("%d", &tempLost);
                getchar(); // Xóa ký tự xuống dòng
                lost[i] = (tempLost != 0);
            }

            // Chỉ tạo phiếu trả nếu tất cả kiểm tra thành công
            if (valid && bookCount > 0)
            {
                createReturnTicket(borrowTickets, borrowSize, returnTickets, returnSize, maxReturns,
                                   cmnd, returnDate, isbnList, bookCount, prices, lost);
                printf("Tao phieu tra thanh cong!\n");
            }
            else
            {
                printf("Khong the tao phieu tra do co loi!\n");
            }
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
