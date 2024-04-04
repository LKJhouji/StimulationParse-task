#include "SignalDescriptionSet.h"

void SignalDescriptionSet::printSignalDescriptionSet() {
    std::cout << "SignalDescriptionSet: " << std::endl;
    for (int i = 0; i < signalDescriptionSet_.size(); i++) {
        signalDescriptionSet_[i]->printSignalDescription();
    }
}

void SignalDescriptionSet::addSignalDescription(SignalDescription*& signalDescription) {
    idToSeg.insert({signalDescription->getId(), signalDescription});
    std::shared_ptr<SignalDescription> p1(signalDescription);
    signalDescriptionSet_.push_back(p1);
}

void SignalDescriptionSet::calculate(SignalValue& sv, double& stTime) {
    SignalValue tsv;
    for (int i = 0; i < signalDescriptionSet_.size(); i++) {
        signalDescriptionSet_[i]->calculate(tsv, stTime);
    }
    sv.xVector.insert(sv.xVector.end(), tsv.xVector.begin(), tsv.xVector.end());
    sv.fcnVector.insert(sv.fcnVector.end(), tsv.fcnVector.begin(), tsv.fcnVector.end());
}