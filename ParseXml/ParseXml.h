#ifndef _PARSEXML_H
#define _PARSEXML_H

#include <unordered_set>
#include <vector>
#include <iostream>
#include "SignalDescriptionSet.h"
#include "tinystr.h"
#include "tinyxml.h"


class ParseXml {
public:
    ParseXml(const char* relevantPath);
    ~ParseXml();
    SignalDescriptionSet parse();
private:
    void parseSignalDescriptionSet(TiXmlElement*& ele);
    void parseSignalDescription(TiXmlElement*& ele);
    void parseSegmentSignalDescription(TiXmlElement*& ele, SignalDescription*& sigDes);
    void parseOperationSignalDescription(TiXmlElement*& ele, SignalDescription*& sigDes);
    void parseSegment(TiXmlElement*& ele, SOSignalDescription*& segSigDes);
    Segment* newSegment(TiXmlElement*& ele);

private:
    SignalDescriptionSet sigDesSet_;
    FILE* xmlFile_;
    const char* relePath_;
};

#endif // _PARSEXML_H