#include <stdio.h>
#include <string.h>
#include "../include/Menu.h"

// Hàm hiển thị menu chính
void displayMainMenu()
{
    printf("\n=== HE THONG QUAN LY THU VIEN ===\n");
    printf("1. Quan ly sach\n");
    printf("2. Quan ly doc gia\n");
    printf("3. Quan ly muon/tra sach\n");
    printf("4. Thong ke\n");
    printf("0. Thoat\n");
    printf("Chon chuc nang: ");
}

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
            // case 2: {
            //     char newBook[7 * maxLen];
            //     printf("Nhap thong tin sach (ISBN, Ten, Tac gia, The loai, Nam, NXB, So luong): ");
            //     scanf(" %[^\n]s", newBook);
            //     addBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen, newBook); // Sửa &bookSize thành bookSize
            //     break;
            // }

        case 2:
        {
            char newIsbn[maxLen], newTitle[maxLen], newAuthor[maxLen], newGenre[maxLen];
            char newYear[maxLen], newPublisher[maxLen], newQuantity[maxLen];
            printf("Nhap ISBN: ");
            scanf("%s", newIsbn);
            getchar();
            printf("Nhap ten sach: ");
            scanf(" %[^\n]s", newTitle);
            getchar();
            printf("Nhap tac gia: ");
            scanf(" %[^\n]s", newAuthor);
            getchar();
            printf("Nhap the loai: ");
            scanf(" %[^\n]s", newGenre);
            getchar();
            printf("Nhap nam xuat ban: ");
            scanf("%s", newYear);
            getchar();
            printf("Nhap nha xuat ban: ");
            scanf(" %[^\n]s", newPublisher);
            getchar();
            printf("Nhap so luong: ");
            scanf("%s", newQuantity);
            addBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen,
                    newIsbn, newTitle, newAuthor, newGenre, newYear, newPublisher, newQuantity);
            break;
        }
            // case 3: {
            //     char targetIsbn[maxLen], updatedBook[7 * maxLen];
            //     printf("Nhap ISBN sach can chinh sua: ");
            //     scanf("%s", targetIsbn);
            //     printf("Nhap thong tin moi (ISBN, Ten, Tac gia, The loai, Nam, NXB, So luong): ");
            //     scanf(" %[^\n]s", updatedBook);
            //     if (editBook(isbn, titles, authors, genres, years, publishers, quantities, bookSize, maxLen, targetIsbn, updatedBook)) {
            //         printf("Chinh sua sach thanh cong!\n");
            //     } else {
            //         printf("Khong tim thay sach voi ISBN: %s\n", targetIsbn);
            //     }
            //     break;
            // }

        case 3:
        {
            char targetIsbn[maxLen];
            char newIsbn[maxLen], newTitle[maxLen], newAuthor[maxLen], newGenre[maxLen];
            char newYear[maxLen], newPublisher[maxLen], newQuantity[maxLen];

            printf("Nhap ISBN sach can chinh sua: ");
            scanf("%s", targetIsbn);
            getchar(); // Xóa ký tự xuống dòng

            printf("Nhap ISBN moi: ");
            scanf("%s", newIsbn);
            getchar();
            printf("Nhap ten sach moi: ");
            scanf(" %[^\n]s", newTitle);
            getchar();
            printf("Nhap tac gia moi: ");
            scanf(" %[^\n]s", newAuthor);
            getchar();
            printf("Nhap the loai moi: ");
            scanf(" %[^\n]s", newGenre);
            getchar();
            printf("Nhap nam xuat ban moi: ");
            scanf("%s", newYear);
            getchar();
            printf("Nhap nha xuat ban moi: ");
            scanf(" %[^\n]s", newPublisher);
            getchar();
            printf("Nhap so luong moi: ");
            scanf("%s", newQuantity);

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
            // case 5: {
            //     char targetIsbn[maxLen];
            //     printf("Nhap ISBN can tim: ");
            //     scanf("%s", targetIsbn);
            //     int result = searchBookByISBN(isbn, bookSize, maxLen, targetIsbn);
            //     if (result != -1) {
            //         printf("Tim thay sach tai vi tri: %d\n", result);
            //     } else {
            //         printf("Khong tim thay sach voi ISBN: %s\n", targetIsbn);
            //     }
            //     break;
            // }

        case 5:
        {
            char targetIsbn[maxLen];
            printf("Nhap ISBN can tim: ");
            scanf("%s", targetIsbn);
            int result = searchBookByISBN(isbn, bookSize, maxLen, targetIsbn);
            if (result != -1)
            {
                // Hiển thị thông tin sách tìm thấy
                printf("\n=== THONG TIN SACH TIM THAY ===\n");
                int index = result * maxLen;
                printf("ISBN: %s\n", &isbn[index]);
                printf("Ten sach: %s\n", &titles[index]);
                printf("Tac gia: %s\n", &authors[index]);
                printf("The loai: %s\n", &genres[index]);
                printf("Nam xuat ban: %s\n", &years[index]);
                printf("Nha xuat ban: %s\n", &publishers[index]);
                printf("So luong: %s\n", &quantities[index]);
                printf("------------------------\n");
            }
            else
            {
                printf("Khong tim thay sach voi ISBN: %s\n", targetIsbn);
            }
            break;
        }

            // case 6: {
            //     char targetTitle[maxLen];
            //     printf("Nhap ten sach can tim: ");
            //     scanf(" %[^\n]s", targetTitle);
            //     int result = searchBookByTitle(titles, bookSize, maxLen, targetTitle);
            //     if (result != -1) {
            //         printf("Tim thay sach tai vi tri: %d\n", result);
            //     } else {
            //         printf("Khong tim thay sach voi ten: %s\n", targetTitle);
            //     }
            //     break;
            // }

        case 6:
        {
            char targetTitle[maxLen];
            printf("Nhap ten sach can tim: ");
            scanf(" %[^\n]s", targetTitle);
            int result = searchBookByTitle(titles, bookSize, maxLen, targetTitle);
            if (result != -1)
            {
                printf("\n=== THONG TIN SACH TIM THAY ===\n");
                int index = result * maxLen;
                printf("ISBN: %s\n", &isbn[index]);
                printf("Ten sach: %s\n", &titles[index]);
                printf("Tac gia: %s\n", &authors[index]);
                printf("The loai: %s\n", &genres[index]);
                printf("Nam xuat ban: %s\n", &years[index]);
                printf("Nha xuat ban: %s\n", &publishers[index]);
                printf("So luong: %s\n", &quantities[index]);
                printf("------------------------\n");
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


void borrowManagementMenu(
    char borrowReaderIds[], char borrowDates[], char dueDates[],
    char actualReturnDates[], char bookISBNs[],
    int &borrowSize, int maxBorrows, int borrowFieldSize,
    char borrowTickets[], char returnTickets[], int &returnSize, int maxReturns,
    char idCards[], int readerSize, int readerFieldSize,      // Danh sách CMND độc giả
    char isbn[], int bookSize, int bookFieldSize)            // Danh sách sách
{
    int choice;
    do {
        printf("\n=== QUAN LY MUON/TRA SACH ===\n");
        printf("1. Tao phieu muon sach\n");
        printf("2. Tao phieu tra sach\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự xuống dòng

        switch (choice) {
            case 1: {
                char cmnd[borrowFieldSize], borrowDate[DATE_LEN + 1], dueDate[DATE_LEN + 1], isbn[borrowFieldSize];
                printf("Nhap so CMND doc gia: ");
                scanf("%s", cmnd);
                // Kiểm tra xem độc giả có tồn tại không dựa trên CMND
                int readerIndex = searchReaderByCMND(idCards, readerSize, readerFieldSize, cmnd);
                if (readerIndex == -1) {
                    printf("Khong tim thay doc gia voi CMND: %s. Vui long kiem tra lai!\n", cmnd);
                    break;
                }

                printf("Nhap ngay muon (dd/mm/yyyy): ");
                scanf("%s", borrowDate);
                printf("Nhap ngay den han (dd/mm/yyyy): ");
                scanf("%s", dueDate);
                printf("Nhap ISBN sach: ");
                scanf("%s", isbn);

                // Kiểm tra xem sách có tồn tại không
                int bookIndex = searchBookByISBN(isbn, bookSize, bookFieldSize, isbn);
                if (bookIndex == -1) {
                    printf("Sach voi ISBN %s khong ton tai trong thu vien!\n", isbn);
                    break;
                }

                createBorrowTicket(borrowReaderIds, borrowDates, dueDates, actualReturnDates, bookISBNs,
                                   borrowSize, maxBorrows, borrowFieldSize, cmnd, borrowDate, dueDate, isbn);
                break;
            }
 
            case 2: {
                char cmnd[borrowFieldSize], returnDate[DATE_LEN + 1], isbnList[10 * borrowFieldSize];
                int bookCount, prices[10];
                bool lost[10];

                printf("Nhap so CMND doc gia: ");
                scanf("%s", cmnd);

                // Kiểm tra độc giả tồn tại
                int readerIndex = searchReaderByCMND(idCards, readerSize, readerFieldSize, cmnd);
                if (readerIndex == -1) {
                    printf("Khong tim thay doc gia voi CMND: %s. Vui long kiem tra lai!\n", cmnd);
                    break;
                }

                printf("Nhap ngay tra (dd/mm/yyyy): ");
                scanf("%s", returnDate);
                printf("Nhap so luong sach tra: ");
                scanf("%d", &bookCount);
                if (bookCount > 10) {
                    printf("So luong sach qua gioi han (toi da 10 sach)!\n");
                    break;
                }

                // Nhập và kiểm tra danh sách ISBN
                for (int i = 0; i < bookCount; i++) {
                    printf("Nhap ISBN sach %d: ", i + 1);
                    scanf("%s", isbnList + i * borrowFieldSize);

                    // Kiểm tra sách tồn tại
                    int bookIndex = searchBookByISBN(isbn, bookSize, bookFieldSize, isbnList + i * borrowFieldSize);
                    if (bookIndex == -1) {
                        printf("Sach voi ISBN %s khong ton tai trong thu vien!\n", isbnList + i * borrowFieldSize);
                        break;
                    }

                    // Kiểm tra sách đã mượn
                    bool borrowed = false;
                    for (int j = 0; j < borrowSize; j++) {
                        int borrowIndex = j * borrowFieldSize;
                        if (strcmp(&borrowReaderIds[borrowIndex], cmnd) == 0 &&
                            strcmp(&bookISBNs[borrowIndex], isbnList + i * borrowFieldSize) == 0) {
                            borrowed = true;
                            break;
                        }
                    }
                    if (!borrowed) {
                        printf("Sach voi ISBN %s chua duoc muon boi doc gia nay!\n", isbnList + i * borrowFieldSize);
                        break;
                    }

                    printf("Nhap gia sach %d (VND): ", i + 1);
                    scanf("%d", &prices[i]);
                    printf("Sach co bi mat khong? (1: Co, 0: Khong): ");
                    int tempLost;
                    scanf("%d", &tempLost);
                    lost[i] = (tempLost != 0);
                }

                // Chỉ tạo phiếu trả nếu tất cả kiểm tra thành công
                if (bookCount > 0) {
                    createReturnTicket(borrowTickets, borrowSize, returnTickets, returnSize, maxReturns,
                                       cmnd, returnDate, isbnList, bookCount, prices, lost);
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