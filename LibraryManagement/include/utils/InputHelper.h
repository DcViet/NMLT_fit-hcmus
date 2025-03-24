#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H
#include <string>
#include "../core/Date.h"  // Thêm dòng này để định nghĩa Date

class InputHelper {
public:
    static std::string getString(const std::string& prompt);
    static int getInt(const std::string& prompt);
    static void getDate(const std::string& prompt, Date& date);
};

#endif