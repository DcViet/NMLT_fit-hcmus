#ifndef READER_H
#define READER_H
#include <string>
#include "../core/Date.h"

struct Reader {
    std::string id, name, cmnd, gender, email, address;
    Date regDate, expDate;
};

#endif