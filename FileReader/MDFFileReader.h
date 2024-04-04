#ifndef _MDF_FILE_READER_H
#define _MDF_FILE_READER_H

#include "SignalValue.h"

class MDFFileReader {
public:
    int Load(const char* mdfFile);
    SignalValue Get();
};

#endif // _MDF_FILE_READER_H