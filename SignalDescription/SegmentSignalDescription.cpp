#include "SegmentSignalDescription.h"

void SegmentSignalDescription::addSegment(Segment*& segment) {
    std::shared_ptr<Segment> p1(segment);
    segmentSignalDescription_.push_back(p1);
}

void SegmentSignalDescription::printSOSignalDescription() {
    std::cout << "  SegmentSignalDescription: " << loopCount_ << std::endl;
    for (int i = 0; i < segmentSignalDescription_.size(); i++) {
        segmentSignalDescription_[i]->printSegment();
    }
}

void SegmentSignalDescription::calculate(SignalValue& sv, double& stTime) {
    SignalValue tsv;
    for (int i = 0; i < segmentSignalDescription_.size(); i++) {
        segmentSignalDescription_[i]->calculate(tsv, stTime);
    }
    sv.xVector.insert(sv.xVector.end(), tsv.xVector.begin(), tsv.xVector.end());
    sv.fcnVector.insert(sv.fcnVector.end(), tsv.fcnVector.begin(), tsv.fcnVector.end());
}

double SegmentSignalDescription::getDuration() {
    double duration = 0;
    for (int i = 0; i < segmentSignalDescription_.size(); i++) {
        duration += segmentSignalDescription_[i]->duration;
    }
    return duration;
}