#include "OperationSignalDescription.h"

#include "SignalDescription.h"

void OperationSignalDescription::calculate(SignalValue& sv, double& stTime) {
    SignalValue svl = idToSV[leftSignal_];
    SignalValue svr = idToSV[rightSignal_];
    SignalValue tsv;
    if (opt_ == "eAdd") {
        double t = 0;
        int i = 0;
        for (; i < std::min(svl.xVector.size(), svr.xVector.size()); i++, t += TIME_VAL) {
            tsv.xVector.push_back(stTime + t);
            tsv.fcnVector.push_back(svl.fcnVector[i] + svr.fcnVector[i]);
        }
        if (i < svl.xVector.size()) {
            for (; i < svl.xVector.size(); i++, t += TIME_VAL) {
                tsv.xVector.push_back(stTime + t);
                tsv.fcnVector.push_back(svl.fcnVector[i]);
            }
        }
        else if (i < svr.xVector.size()) {
            for (; i < svr.xVector.size(); i++, t += TIME_VAL) {
                tsv.xVector.push_back(stTime + t);
                tsv.fcnVector.push_back(svr.fcnVector[i]);
            }
        }
        stTime += std::max(idToSeg[leftSignal_]->getDuration(), idToSeg[rightSignal_]->getDuration());
    }
    else {
        double t = 0;
        int i = 0;
        for (; i < std::min(svl.xVector.size(), svr.xVector.size()); i++, t += TIME_VAL) {
            tsv.xVector.push_back(stTime + t);
            tsv.fcnVector.push_back(svl.fcnVector[i] * svr.fcnVector[i]);
        }
        if (i < svl.xVector.size()) {
            for (; i < svl.xVector.size(); i++, t += TIME_VAL) {
                tsv.xVector.push_back(stTime + t);
                tsv.fcnVector.push_back(0);
            }
        }
        else if (i < svr.xVector.size()) {
            for (; i < svr.xVector.size(); i++, t += TIME_VAL) {
                tsv.xVector.push_back(stTime + t);
                tsv.fcnVector.push_back(0);
            }
        }
        stTime += std::max(idToSeg[leftSignal_]->getDuration(), idToSeg[rightSignal_]->getDuration());
    }
    sv.xVector.insert(sv.xVector.end(), tsv.xVector.begin(), tsv.xVector.end());
    sv.fcnVector.insert(sv.fcnVector.end(), tsv.fcnVector.begin(), tsv.fcnVector.end());
}

void OperationSignalDescription::printSOSignalDescription() {
    idToSeg[leftSignal_]->printSignalDescription();
    idToSeg[rightSignal_]->printSignalDescription();
}