#ifndef _MAT_FILE_READER_H
#define _MAT_FILE_READER_H

#include "SignalValue.h"

class MATileReader {
public:
    int Load(const char* matFile);
    SignalValue Get();
};

#endif // _MAT_FILE_READER_H