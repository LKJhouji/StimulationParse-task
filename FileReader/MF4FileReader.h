#ifndef _MF4_FILE_READER_H
#define _MF4_FILE_READER_H

#include "SignalValue.h"

class MF4FileReader {
public:
    int Load(const char* mf4File);
    SignalValue Get();
};


#endif // _MF4_FILE_READER_H