#ifndef _MAT_FILE_READER_H
#define _MAT_FILE_READER_H

#include <matio.h>
#include <iostream>
#include "SignalValue.h"

class MATFileReader {
public:
    MATFileReader() : targetArray_(nullptr) {}
    int Load(const char* matFile);
    SignalValue Get();
private:
    double** targetArray_;
    SignalValue sv_;
};

#endif // _MAT_FILE_READER_H