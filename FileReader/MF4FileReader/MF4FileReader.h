#ifndef _MF4_FILE_READER_H
#define _MF4_FILE_READER_H

#include <stdio.h>
#include <time.h>
#include <iostream>

#include "stdafx.h"
#include "ImportMdf4.h"
#include "mdf4.h"
#include "SignalValue.h"

class MF4FileReader {
public:
    int Load(const char* mf4File);
    SignalValue Get();
    void Mf4ToSignalValue(int idx, const char* mf4File, CMdf4DataGroup* pGroup, M4DGBlock *dg,M4CGBlock *cg,M4CNBlock *cn);
    double GetFcnValue(double x);
    void printFcnValue();
private:
    SignalValue sv_;
};


#endif // _MF4_FILE_READER_H