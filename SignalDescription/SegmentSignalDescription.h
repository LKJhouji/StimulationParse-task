#ifndef _SEGMENT_SIGNAL_DESCRIPTION_H
#define _SEGMENT_SIGNAL_DESCRIPTION_H

#include <vector>

#include "Segment.h"
#include "SOSignalDescription.h"

class SegmentSignalDescription : public SOSignalDescription {
public:
    SegmentSignalDescription() {}
    ~SegmentSignalDescription() override {}
    void addSegment(Segment*& segment) override;
    void setLoopCount(const char* loopCount) { loopCount_ = atoi(loopCount); }
    void printSOSignalDescription() override;
    void calculate(SignalValue& sv, double& stTime) override;
    double getDuration() override;
private:
    std::vector<std::shared_ptr<Segment>> segmentSignalDescription_;
    int loopCount_;
};

#endif // _SEGMENT_SIGNAL_DESCRIPTION_H