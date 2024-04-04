#include "STIReader.h"

int STIReader::load(const char* stiFile) {
    parseXml_= std::make_shared<ParseXml>(stiFile);
    if (parseXml_.get() == nullptr) return -1;
    sigDesSet_ = parseXml_->parse();
    return 0;
}