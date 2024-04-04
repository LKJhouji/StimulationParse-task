#include "ParseXml.h"

SignalDescriptionSet ParseXml::parse() {
    TiXmlDocument doc(relePath_);
    if (!doc.LoadFile()) {
        std::cerr << "Failed to load XML file : " << doc.ErrorDesc() << std::endl;
        exit(-1);
    }

    TiXmlElement *root = doc.RootElement()->FirstChildElement();
    if (!root) {
        std::cerr << "Invalid root element." << std::endl;
        exit(-1);
    }
    parseSignalDescriptionSet(root);
    return sigDesSet_;
}

void ParseXml::parseSignalDescriptionSet(TiXmlElement*& ele) {
    TiXmlAttribute* attr = ele->FirstAttribute();
    sigDesSet_.setName(attr->Value());
    TiXmlElement* ele1 = ele->FirstChildElement();
    for (; ele1 != nullptr; ele1 = ele1->NextSiblingElement()) {
        parseSignalDescription(ele1);
    }
}

void ParseXml::parseSignalDescription(TiXmlElement*& ele) {
    TiXmlAttribute* attr = ele->FirstAttribute();
    SignalDescription* sigDes = new SignalDescription();
    sigDes->setName(attr->Value());
    attr = attr->Next();
    sigDes->setId(attr->Value());

    TiXmlElement* ele1 = ele->FirstChildElement();
    for (; ele1 != nullptr; ele1 = ele1->NextSiblingElement()) {
        if (strcmp(ele1->Value(), "SegmentSignalDescription") == 0) parseSegmentSignalDescription(ele1, sigDes);
        else if (strcmp(ele1->Value(), "OperationSignalDescription") == 0) parseOperationSignalDescription(ele1, sigDes);
    }
    sigDesSet_.addSignalDescription(sigDes);
}

void ParseXml::parseSegmentSignalDescription(TiXmlElement*& ele, SignalDescription*& sigDes) {
    TiXmlAttribute* attr = ele->FirstAttribute();
    SOSignalDescription* segSigDes = new SegmentSignalDescription();
    segSigDes->setLoopCount(attr->Value());

    TiXmlElement* ele1 = ele->FirstChildElement();
    for (; ele1 != nullptr; ele1 = ele1->NextSiblingElement()) {
        if (strcmp(ele1->Value(), "LoopSegment") != 0) parseSegment(ele1, segSigDes);
    }
    sigDes->addSOSignalDescription(segSigDes);
}

void ParseXml::parseOperationSignalDescription(TiXmlElement*& ele, SignalDescription*& sigDes) {
    SOSignalDescription* opeSigDes = new OperationSignalDescription();
    TiXmlElement* ele1 = ele->FirstChildElement();
    TiXmlAttribute* attr = ele1->FirstAttribute();
    opeSigDes->setOpt(attr->Value());
    TiXmlElement* ele2 = ele1->FirstChildElement();
    attr = ele2->FirstAttribute();
    opeSigDes->setLeftSignal(attr->Value());
    ele2 = ele2->NextSiblingElement();
    attr = ele2->FirstAttribute();
    opeSigDes->setRightSignal(attr->Value());
    sigDes->addSOSignalDescription(opeSigDes);
}

void ParseXml::parseSegment(TiXmlElement*& ele, SOSignalDescription*& segSigDes) {
    Segment* seg = newSegment(ele);
    if (seg == nullptr) return;
    TiXmlElement* ele1 = ele->FirstChildElement();
    for (; ele1 != nullptr; ele1 = ele1->NextSiblingElement()) {
        const char* parameterName = ele1->Value();
        TiXmlElement* ele2 = ele1->FirstChildElement();
        const char* s = ele2->GetText();
        double parameterValue = strtod(s, nullptr);
        if (strcmp(parameterName, "Duration") == 0) seg->duration = parameterValue;
        if (strcmp(parameterName, "Value") == 0) seg->value = parameterValue;
        if (strcmp(parameterName, "Stop") == 0) seg->stop = parameterValue;
        if (strcmp(parameterName, "Start") == 0) seg->start = parameterValue;
        if (strcmp(parameterName, "Mean") == 0) seg->mean = parameterValue;
        if (strcmp(parameterName, "Sigma") == 0) seg->sigma = parameterValue;
        if (strcmp(parameterName, "Seed") == 0) seg->seed = parameterValue;
        if (strcmp(parameterName, "Offset") == 0) seg->offset = parameterValue;
        if (strcmp(parameterName, "Slope") == 0) seg->slope = parameterValue;
        if (strcmp(parameterName, "Period") == 0) seg->period = parameterValue;
        if (strcmp(parameterName, "Phase") == 0) seg->phase = parameterValue;   
        if (strcmp(parameterName, "DutyCycle") == 0) seg->dutyCycle = parameterValue;
        if (strcmp(parameterName, "Amplitude") == 0) seg->amplitude = parameterValue;
        if (strcmp(parameterName, "Tau") == 0) seg->tau = parameterValue;
    }   
    segSigDes->addSegment(seg);
}

ParseXml::ParseXml(const char* relevantPath) {
    relePath_ = relevantPath;
    if ((xmlFile_ = fopen(relevantPath, "r+")) == nullptr) {
        std::cerr << "Failed to open XML file : " << relevantPath << std::endl;
        exit(-1);
    }
}

ParseXml::~ParseXml() {
    fclose(xmlFile_);
    xmlFile_ = nullptr;
}

Segment* ParseXml::newSegment(TiXmlElement*& ele) {
    const char* name = ele->Value();
    Segment* seg = nullptr;
    if (strcmp(name, "ConstSegment") == 0) seg = new ConstSegment();
    if (strcmp(name, "RampSegment") == 0) seg = new RampSegment();
    if (strcmp(name, "SinSegment") == 0) seg = new SineSegment();
    if (strcmp(name, "IdleSegment") == 0) seg = new IdleSegment();
    if (strcmp(name, "NoiseSegment") == 0) seg = new NoiseSegment();
    if (strcmp(name, "RampSlopeSegment") == 0) seg = new RampSlopeSegment();
    if (strcmp(name, "SawSegment") == 0) seg = new SawSegment();
    if (strcmp(name, "SineSegment") == 0) seg = new SineSegment();
    if (strcmp(name, "PulseSegment") == 0) seg = new PulseSegment();
    if (strcmp(name, "ExpSegment") == 0) seg = new ExpSegment();
    return seg;   
}