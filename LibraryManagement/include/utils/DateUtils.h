#ifndef DATE_UTILS_H
#define DATE_UTILS_H
#include "../core/Date.h"

class DateUtils {
public:
    static Date calculateExpDate(Date regDate);
    static Date calculateReturnDate(Date borrowDate);
    static int calculateLateDays(Date expected, Date actual);
};

#endif