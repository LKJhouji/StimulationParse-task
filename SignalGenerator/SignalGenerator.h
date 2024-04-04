#ifndef _SIGNAL_GENERATOR_H
#define _SIGNAL_GENERATOR_H

#include "SignalValue.h"
#include "SignalDescriptionSet.h"

class SignalGenerator {
public:
    SignalGenerator(const SignalDescriptionSet& signalDescriptionSet);
    double GetFcnValue(double x);
    const SignalValue& Get();
private:
    SignalValue sigVal_;
};

#endif // _SIGNAL_GENERATOR_H