#ifndef _CSV_FILE_READER_H
#define _CSV_FILE_READER_H

#include "SignalValue.h"

class CSVFileReader {
public:
    int Load(const char* csvFile);
    SignalValue Get();
};

#endif // _CSV_FILE_READER_H