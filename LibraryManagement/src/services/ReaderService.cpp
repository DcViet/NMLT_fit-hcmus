#include <iostream>
#include "../../include/services/ReaderService.h"
#include "../../include/utils/InputHelper.h"
#include "../../include/utils/DateUtils.h"

void ReaderService::addReader(std::vector<Reader>& readers) {
    Reader r;
    r.id = InputHelper::getString("Nhap ma doc gia: ");
    r.name = InputHelper::getString("Nhap ho ten: ");
    r.cmnd = InputHelper::getString("Nhap CMND: ");
    r.gender = InputHelper::getString("Nhap gioi tinh: ");
    r.email = InputHelper::getString("Nhap email: ");
    r.address = InputHelper::getString("Nhap dia chi: ");
    InputHelper::getDate("Nhap ngay lap the (ngay thang nam): ", r.regDate);
    r.expDate = DateUtils::calculateExpDate(r.regDate);
    readers.push_back(r);
    std::cout << "Them doc gia thanh cong!\n";
}