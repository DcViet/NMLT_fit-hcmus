#ifndef READER_SERVICE_H
#define READER_SERVICE_H
#include <vector>
#include "../entities/Reader.h"

class ReaderService {
public:
    void addReader(std::vector<Reader>& readers);
};

#endif