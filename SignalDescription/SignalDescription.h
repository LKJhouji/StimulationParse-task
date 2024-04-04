#ifndef _SIGNAL_DESCRIPTION_H
#define _SIGNAL_DESCRIPTION_H

#include <vector>
#include <memory>

#include "SegmentSignalDescription.h"
#include "OperationSignalDescription.h"
#include "SignalValue.h"

class SignalDescription {
public:
    SignalDescription() {}
    ~SignalDescription() {}
    void addSOSignalDescription(SOSignalDescription*& soSigDes);
    void setName(std::string name) { name_ = name; }
    void setId(std::string id) { id_ = id; }
    std::string getName() { return name_; }
    std::string getId() { return id_; }
    SignalValue calculate(SignalValue& sv, double& stTime);
    void printSignalDescription();
    double getDuration();
private:
    std::vector<std::shared_ptr<SOSignalDescription>> signalDescription_;
    std::string name_;
    std::string id_;
};

#endif // _SIGNAL_DESCRIPTION_H