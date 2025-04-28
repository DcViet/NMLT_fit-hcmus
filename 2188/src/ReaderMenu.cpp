#include <stdio.h>
#include <string.h>
#include "ReaderMenu.h"

// Hàm xử lý menu quản lý độc giả
void readerManagementMenu(
    char readerIds[], char fullNames[], char idCards[],
    char birthDates[], char genders[], char emails[],
    char addresses[], char cardIssueDates[], char cardExpiryDates[],
    int &readerSize, int maxReaders, int fieldSize)
{
    int choice;
    do
    {
        printf("\n=== QUAN LY DOC GIA ===\n");
        printf("1. Hien thi danh sach doc gia\n");
        printf("2. Them doc gia\n");
        printf("3. Chinh sua doc gia\n");
        printf("4. Xoa doc gia\n");
        printf("5. Tim kiem doc gia theo CMND\n");
        printf("6. Tim kiem doc gia theo ho ten\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayReaders(readerIds, fullNames, idCards, birthDates, genders, emails, addresses,
                           cardIssueDates, cardExpiryDates, readerSize, fieldSize);
            break;
        case 2:
        {
            char newReaderId[fieldSize], newFullName[fieldSize], newIdCard[fieldSize];
            char newBirthDate[fieldSize], newGender[fieldSize], newEmail[fieldSize];
            char newAddress[fieldSize], newCardIssueDate[fieldSize], newCardExpiryDate[fieldSize];

            printf("Nhap ID doc gia: ");
            scanf("%s", newReaderId);
            getchar();
            printf("Nhap ho ten: ");
            scanf(" %[^\n]s", newFullName);
            getchar();
            printf("Nhap so CMND: ");
            scanf("%s", newIdCard);
            getchar();
            printf("Nhap ngay sinh (dd/mm/yyyy): ");
            scanf("%s", newBirthDate);
            getchar();
            printf("Nhap gioi tinh: ");
            scanf("%s", newGender);
            getchar();
            printf("Nhap email: ");
            scanf("%s", newEmail);
            getchar();
            printf("Nhap dia chi: ");
            scanf(" %[^\n]s", newAddress);
            getchar();
            printf("Nhap ngay cap the (dd/mm/yyyy): ");
            scanf("%s", newCardIssueDate);
            getchar();
            printf("Nhap ngay het han the (dd/mm/yyyy): ");
            scanf("%s", newCardExpiryDate);

            addReader(readerIds, fullNames, idCards, birthDates, genders, emails, addresses,
                      cardIssueDates, cardExpiryDates, readerSize, fieldSize,
                      newReaderId, newFullName, newIdCard, newBirthDate, newGender,
                      newEmail, newAddress, newCardIssueDate, newCardExpiryDate);
            break;
        }
        case 3:
        {
            char targetId[fieldSize];
            char newReaderId[fieldSize], newFullName[fieldSize], newIdCard[fieldSize];
            char newBirthDate[fieldSize], newGender[fieldSize], newEmail[fieldSize];
            char newAddress[fieldSize], newCardIssueDate[fieldSize], newCardExpiryDate[fieldSize];

            printf("Nhap ID doc gia can chinh sua: ");
            scanf("%s", targetId);
            getchar();

            printf("Nhap ID doc gia moi: ");
            scanf("%s", newReaderId);
            getchar();
            printf("Nhap ho ten moi: ");
            scanf(" %[^\n]s", newFullName);
            getchar();
            printf("Nhap so CMND moi: ");
            scanf("%s", newIdCard);
            getchar();
            printf("Nhap ngay sinh moi (dd/mm/yyyy): ");
            scanf("%s", newBirthDate);
            getchar();
            printf("Nhap gioi tinh moi: ");
            scanf("%s", newGender);
            getchar();
            printf("Nhap email moi: ");
            scanf("%s", newEmail);
            getchar();
            printf("Nhap dia chi moi: ");
            scanf(" %[^\n]s", newAddress);
            getchar();
            printf("Nhap ngay cap the moi (dd/mm/yyyy): ");
            scanf("%s", newCardIssueDate);
            getchar();
            printf("Nhap ngay het han the moi (dd/mm/yyyy): ");
            scanf("%s", newCardExpiryDate);

            if (editReader(readerIds, fullNames, idCards, birthDates, genders, emails, addresses,
                           cardIssueDates, cardExpiryDates, readerSize, fieldSize, targetId,
                           newReaderId, newFullName, newIdCard, newBirthDate, newGender,
                           newEmail, newAddress, newCardIssueDate, newCardExpiryDate))
            {
                printf("Chinh sua doc gia thanh cong!\n");
            }
            else
            {
                printf("Khong tim thay doc gia voi ID: %s\n", targetId);
            }
            break;
        }
        case 4:
        {
            char targetId[fieldSize];
            printf("Nhap ma doc gia can xoa: ");
            scanf("%s", targetId);
            if (deleteReader(readerIds, fullNames, idCards, birthDates, genders, emails, addresses,
                             cardIssueDates, cardExpiryDates, readerSize, fieldSize, targetId))
            {
                printf("Xoa doc gia thanh cong!\n");
            }
            else
            {
                printf("Khong tim thay doc gia voi ma: %s\n", targetId);
            }
            break;
        }
        case 5:
        {
            char targetCmnd[fieldSize];
            printf("Nhap CMND can tim: ");
            scanf("%s", targetCmnd);
            int result = searchReaderByCMND(idCards, readerSize, fieldSize, targetCmnd);
            if (result != -1)
            {
                printf("\n=== THONG TIN DOC GIA TIM THAY ===\n");
                int index = result * fieldSize;
                printf("ID doc gia: %s\n", &readerIds[index]);
                printf("Ho ten: %s\n", &fullNames[index]);
                printf("So CMND: %s\n", &idCards[index]);
                printf("Ngay sinh: %s\n", &birthDates[index]);
                printf("Gioi tinh: %s\n", &genders[index]);
                printf("Email: %s\n", &emails[index]);
                printf("Dia chi: %s\n", &addresses[index]);
                printf("Ngay cap the: %s\n", &cardIssueDates[index]);
                printf("Ngay het han the: %s\n", &cardExpiryDates[index]);
                printf("------------------------\n");
            }
            else
            {
                printf("Khong tim thay doc gia voi CMND: %s\n", targetCmnd);
            }
            break;
        }
        case 6:
        {
            char targetName[fieldSize];
            printf("Nhap ho ten can tim: ");
            scanf(" %[^\n]s", targetName);
            int result = searchReaderByName(fullNames, readerSize, fieldSize, targetName);
            if (result != -1)
            {
                printf("\n=== THONG TIN DOC GIA TIM THAY ===\n");
                int index = result * fieldSize;
                printf("ID doc gia: %s\n", &readerIds[index]);
                printf("Ho ten: %s\n", &fullNames[index]);
                printf("So CMND: %s\n", &idCards[index]);
                printf("Ngay sinh: %s\n", &birthDates[index]);
                printf("Gioi tinh: %s\n", &genders[index]);
                printf("Email: %s\n", &emails[index]);
                printf("Dia chi: %s\n", &addresses[index]);
                printf("Ngay cap the: %s\n", &cardIssueDates[index]);
                printf("Ngay het han the: %s\n", &cardExpiryDates[index]);
                printf("------------------------\n");
            }
            else
            {
                printf("Khong tim thay doc gia voi ho ten: %s\n", targetName);
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