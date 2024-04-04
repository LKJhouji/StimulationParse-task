#ifndef _SO_SIGNAL_DESCRIPTION_H
#define _SO_SIGNAL_DESCRIPTION_H

#include "Segment.h"
#include "SignalValue.h"

class SOSignalDescription {
public:
    SOSignalDescription() {}
    virtual ~SOSignalDescription() {}
    virtual void calculate(SignalValue& sv, double& stTime) = 0;
    virtual void addSegment(Segment*& segment) {}
    virtual void setLoopCount(const char* loopCount) {}
    virtual void printSOSignalDescription() {}
    virtual double getDuration() { double a; return a; }
    virtual void setOpt(std::string opt) {}
    virtual void setLeftSignal(std::string leftSignal) {}
    virtual void setRightSignal(std::string rightSignal) {}
};

#endif // _SO_SIGNAL_DESCRIPTION_H