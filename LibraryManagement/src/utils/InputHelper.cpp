#include <iostream>
#include <limits>              // Thêm để sử dụng std::numeric_limits
#include "../../include/utils/InputHelper.h"
#include "../../include/core/Date.h"  // Thêm để định nghĩa Date

std::string InputHelper::getString(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    return input;
}

int InputHelper::getInt(const std::string& prompt) {
    std::cout << prompt;
    int value;
    std::cin >> value;
    return value;
}

void InputHelper::getDate(const std::string& prompt, Date& date) {
    std::cout << prompt;
    std::cin >> date.day >> date.month >> date.year;
}