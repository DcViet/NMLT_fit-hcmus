#include <stdio.h>
#include <string.h>
#include "BookMenu.h"

// Hàm xử lý menu quản lý sách
void bookManagementMenu(
    char isbn[], char titles[], char authors[], char genres[],
    char years[], char publishers[], char quantities[],
    int &bookSize, int maxBooks, int maxLen)
{
    int choice;
    do
    {
        printf("\n=== QUAN LY SACH ===\n");
        printf("1. Hien thi danh sach sach\n");
        printf("2. Them sach\n");
        printf("3. Chinh sua sach\n");
        printf("4. Xoa sach\n");
        printf("5. Tim kiem sach theo ISBN\n");
        printf("6. Tim kiem sach theo ten\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            displayBooks(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen);
            break;

        case 2:
        {
            char newIsbn[maxLen], newTitle[maxLen], newAuthor[maxLen], newGenre[maxLen];
            char newYear[maxLen], newPublisher[maxLen], newQuantity[maxLen];
            inputBookInfo(newIsbn, newTitle, newAuthor, newGenre, newYear, newPublisher, newQuantity, maxLen);

            addBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen,
                    newIsbn, newTitle, newAuthor, newGenre, newYear, newPublisher, newQuantity);
            break;
        }

        case 3:
        {
            char targetIsbn[maxLen];
            char newIsbn[maxLen], newTitle[maxLen], newAuthor[maxLen], newGenre[maxLen];
            char newYear[maxLen], newPublisher[maxLen], newQuantity[maxLen];

            printf("Nhap ISBN sach can chinh sua: ");
            scanf("%s", targetIsbn);
            getchar();

            printf("Nhap thong tin sach moi:\n");
            inputBookInfo(newIsbn, newTitle, newAuthor, newGenre, newYear, newPublisher, newQuantity, maxLen);

            if (editBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen,
                         targetIsbn, newIsbn, newTitle, newAuthor, newGenre, newYear, newPublisher, newQuantity))
            {
                printf("Chinh sua sach thanh cong!\n");
            }
            else
            {
                printf("Khong tim thay sach voi ISBN: %s\n", targetIsbn);
            }
            break;
        }

        case 4:
        {
            char targetIsbn[maxLen];
            printf("Nhap ISBN sach can xoa: ");
            scanf("%s", targetIsbn);
            if (deleteBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen, targetIsbn))
            {
                printf("Xoa sach thanh cong!\n");
            }
            else
            {
                printf("Khong tim thay sach voi ISBN: %s\n", targetIsbn);
            }
            break;
        }

        case 5:
        {
            char targetIsbn[maxLen];
            printf("Nhap ISBN can tim: ");
            scanf("%s", targetIsbn);
            int result = searchBook(isbn, bookSize, maxLen, targetIsbn);
            if (result != -1)
            {
                printf("\n=== THONG TIN SACH TIM THAY ===\n");
                displaySingleBook(isbn, titles, authors, genres, years, publishers, quantities, result * maxLen, maxLen);
            }
            else
            {
                printf("Khong tim thay sach voi ISBN: %s\n", targetIsbn);
            }
            break;
        }

        case 6:
        {
            char targetTitle[maxLen];
            printf("Nhap ten sach can tim: ");
            scanf(" %[^\n]s", targetTitle);
            int result = searchBook(titles, bookSize, maxLen, targetTitle);
            if (result != -1)
            {
                printf("\n=== THONG TIN SACH TIM THAY ===\n");
                displaySingleBook(isbn, titles, authors, genres, years, publishers, quantities, result * maxLen, maxLen);
            }
            else
            {
                printf("Khong tim thay sach voi ten: %s\n", targetTitle);
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
