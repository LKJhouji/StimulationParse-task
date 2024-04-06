#ifndef _CSV_FILE_READER_H
#define _CSV_FILE_READER_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include "SignalValue.h"

class CSVFileReader {
public:
    int Load(const char* csvFile);
    SignalValue Get();
    double GetFcnValue(double x);
    void printFcnValue();
private:
    SignalValue sv_;
};

#endif // _CSV_FILE_READER_H