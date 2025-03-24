// #include "../include/core/Date.h"
// #include "../core/Date.h"

// Date calculateExpDate(Date regDate) {
//     Date expDate = regDate;
//     expDate.year += 4; // 48 tháng = 4 năm
//     return expDate;
// }

// Date calculateReturnDate(Date borrowDate) {
//     Date returnDate = borrowDate;
//     returnDate.day += 7;
//     if (returnDate.day > 30) {
//         returnDate.day -= 30;
//         returnDate.month++;
//     }
//     if (returnDate.month > 12) {
//         returnDate.month = 1;
//         returnDate.year++;
//     }
//     return returnDate;
// }

// int calculateLateDays(Date expected, Date actual) {
//     int expectedDays = expected.year * 360 + expected.month * 30 + expected.day;
//     int actualDays = actual.year * 360 + actual.month * 30 + actual.day;
//     return (actualDays > expectedDays) ? (actualDays - expectedDays) : 0;
// }

#include "../../include/utils/DateUtils.h"
#include "../../include/core/Constants.h"
#include "../../include/core/Date.h"

Date DateUtils::calculateExpDate(Date regDate) {
    Date expDate = regDate;
    expDate.year += Constants::EXPIRATION_MONTHS / Constants::MONTHS_PER_YEAR;
    return expDate;
}

Date DateUtils::calculateReturnDate(Date borrowDate) {
    Date returnDate = borrowDate;
    returnDate.day += Constants::BORROW_DAYS;
    if (returnDate.day > Constants::DAYS_PER_MONTH) {
        returnDate.day -= Constants::DAYS_PER_MONTH;
        returnDate.month++;
    }
    if (returnDate.month > Constants::MONTHS_PER_YEAR) {
        returnDate.month = 1;
        returnDate.year++;
    }
    return returnDate;
}

int DateUtils::calculateLateDays(Date expected, Date actual) {
    int expectedDays = expected.year * 360 + expected.month * Constants::DAYS_PER_MONTH + expected.day;
    int actualDays = actual.year * 360 + actual.month * Constants::DAYS_PER_MONTH + actual.day;
    return (actualDays > expectedDays) ? (actualDays - expectedDays) : 0;
}