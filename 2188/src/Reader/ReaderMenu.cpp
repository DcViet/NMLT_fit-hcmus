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

            inputReader(newReaderId, newFullName, newIdCard,
                        newBirthDate, newGender, newEmail,
                        newAddress, newCardIssueDate, newCardExpiryDate,
                        fieldSize);

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

            inputField("Nhap ID doc gia can chinh sua: ", targetId, fieldSize);

            printf("Nhap thong tin moi cho doc gia:\n");
            inputReader(
                newReaderId, newFullName, newIdCard,
                newBirthDate, newGender, newEmail,
                newAddress, newCardIssueDate, newCardExpiryDate,
                fieldSize);

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
            inputField("Nhap CMND can tim: ", targetCmnd, fieldSize);

            int result = searchReader(idCards, readerSize, fieldSize, targetCmnd);
            if (result != -1)
            {
                printf("\n=== THONG TIN DOC GIA TIM THAY ===\n");
                displayReader(
                    readerIds, fullNames, idCards, birthDates, genders, emails,
                    addresses, cardIssueDates, cardExpiryDates, result, fieldSize);
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
            inputField("Nhap ho ten can tim: ", targetName, fieldSize);

            int result = searchReader(fullNames, readerSize, fieldSize, targetName);
            if (result != -1)
            {
                printf("\n=== THONG TIN DOC GIA TIM THAY ===\n");
                displayReader(
                    readerIds, fullNames, idCards, birthDates, genders, emails,
                    addresses, cardIssueDates, cardExpiryDates, result, fieldSize);
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