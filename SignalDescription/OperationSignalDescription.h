#ifndef _OPERATION_SIGNAL_DESCRIPTION_H
#define _OPERATION_SIGNAL_DESCRIPTION_H

#include <iostream>

#include "Segment.h"
#include "SignalValue.h"
#include "SOSignalDescription.h"
#include "AssistOperation.h"

class OperationSignalDescription : public SOSignalDescription {
public:
    OperationSignalDescription() {}
    ~OperationSignalDescription() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void setOpt(std::string opt) override { opt_ = opt; }
    void setLeftSignal(std::string leftSignal) override { leftSignal_ = leftSignal; }
    void setRightSignal(std::string rightSignal) override { rightSignal_ = rightSignal; }
    void printSOSignalDescription() override;
private:
    std::string opt_;
    std::string leftSignal_;
    std::string rightSignal_;
};

#endif // _OPERATION_SIGNAL_DESCRIPTION_H