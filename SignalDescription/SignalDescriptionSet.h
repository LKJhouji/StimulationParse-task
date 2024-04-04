#ifndef _SIGNAL_DESCRIPTION_SET_H
#define _SIGNAL_DESCRIPTION_SET_H

#include <vector>

#include "SignalDescription.h"

class SignalDescriptionSet {
public:
    SignalDescriptionSet() {};
    ~SignalDescriptionSet() {};
    void addSignalDescription(SignalDescription*& signalDescription);
    std::string getName() { return name_; }
    void setName(std::string name) { name_ = name; }
    void printSignalDescriptionSet();
    void calculate(SignalValue& sv, double& stTime);
private:
    std::vector<std::shared_ptr<SignalDescription>> signalDescriptionSet_;
    std::string name_;
};


#endif // _SIGNAL_DESCRIPTION_SET_H