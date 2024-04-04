#include "SignalGenerator.h"

SignalGenerator::SignalGenerator(const SignalDescriptionSet& signalDescriptionSet) {
    double stTime = 0;
    SignalDescriptionSet sds = signalDescriptionSet;
    sds.calculate(sigVal_, stTime);
}

double SignalGenerator::GetFcnValue(double x) {
    return sigVal_.fcnVector[xToIdx[x]];
}

const SignalValue& SignalGenerator::Get() {
    return sigVal_;
}