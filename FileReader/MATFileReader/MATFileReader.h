#ifndef _MAT_FILE_READER_H
#define _MAT_FILE_READER_H

#include <matio.h>
#include <string.h>
#include <iostream>
#include "SignalValue.h"

class MATFileReader {
public:
    MATFileReader() {}
    int Load(const char* matFile, const char* varName);
    SignalValue Get();
    double GetFcnValue(double x);
    void printFcnValue();
    //void test();
private:
    SignalValue sv_;
};

#endif // _MAT_FILE_READER_H