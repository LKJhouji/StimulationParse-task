#include "SignalDescription.h"

void SignalDescription::addSOSignalDescription(SOSignalDescription*& soSigDes) {
    std::shared_ptr<SOSignalDescription> p1(soSigDes);
    signalDescription_.push_back(p1);
}

void SignalDescription::printSignalDescription() {
    std::cout << "  SignalDescription: " << name_ << " " << id_ << std::endl;
    for (int i = 0; i < signalDescription_.size(); i++) {
        signalDescription_[i]->printSOSignalDescription(); 
    }
}

SignalValue SignalDescription::calculate(SignalValue& sv, double& stTime) {
    SignalValue tsv;
    for (int i = 0; i < signalDescription_.size(); i++) {
        signalDescription_[i]->calculate(tsv, stTime);
    }
    idToSV.insert({id_, tsv});
    sv.xVector.insert(sv.xVector.end(), tsv.xVector.begin(), tsv.xVector.end());
    sv.fcnVector.insert(sv.fcnVector.end(), tsv.fcnVector.begin(), tsv.fcnVector.end());
}

double SignalDescription::getDuration() {
    double duration = 0;
    for (int i = 0; i < signalDescription_.size(); i++) {
        duration += signalDescription_[i]->getDuration();
    }
    return duration;
}