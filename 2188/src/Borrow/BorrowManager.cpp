#include <stdio.h>
#include <string.h>
#include "BorrowManager.h"
#include "BookFunctions.h"
#include "ReaderManager.h"

int inputAndCheckCMND(char *cmnd, int borrowFieldSize, char idCards[], int readerSize, int readerFieldSize)
{
    printf("Nhap so CMND doc gia: ");
    scanf("%s", cmnd);

    // Kiểm tra xem độc giả có tồn tại không dựa trên CMND
    int readerIndex = searchReaderByCMND(idCards, readerSize, readerFieldSize, cmnd);
    if (readerIndex == -1)
    {
        printf("Khong tim thay doc gia voi CMND: %s. Vui long kiem tra lai!\n", cmnd);
        return -1; // Trả về -1 nếu không tìm thấy độc giả
    }
    return readerIndex; // Trả về chỉ số độc giả nếu tìm thấy
}

int inputAndCheckISBN(char *isbnBook, int borrowFieldSize, char isbn[], int bookSize, int bookFieldSize) {
    printf("Nhap ISBN sach: ");
    scanf("%s", isbnBook);

    // Kiểm tra xem sách có tồn tại không dựa trên ISBN
    int bookIndex = searchBook(isbn, bookSize, bookFieldSize, isbnBook);
    if (bookIndex == -1) {
        printf("Sach voi ISBN %s khong ton tai trong thu vien!\n", isbnBook);
        return -1;  // Trả về -1 nếu không tìm thấy sách
    }
    return bookIndex;  // Trả về chỉ số sách nếu tìm thấy
}
