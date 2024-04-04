#ifndef _STI_READER_H
#define _STI_READER_H

#include <iostream>
#include <memory>
#include "ParseXml.h"
#include "SignalDescriptionSet.h"

class STIReader {
public:
    STIReader() : parseXml_(nullptr) {}
    ~STIReader() {}
    int load(const char* stiFile);
    SignalDescriptionSet get() { return sigDesSet_; }
private:
    std::shared_ptr<ParseXml> parseXml_;
    SignalDescriptionSet sigDesSet_;
};

#endif // _STI_READER_H