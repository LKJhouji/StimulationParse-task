#ifndef _SEGMENT_H
#define _SEGMENT_H

#define TIME_VAL 0.01

#include <stdlib.h>

#include <iostream>
#include <random>
#include <cmath>
#include <memory>

#include "SignalValue.h"

struct Segment {
    Segment(int attributeNum) : attributeNum(attributeNum) {}
    virtual ~Segment() {}
    virtual void setRandom() {}
    virtual void calculate(SignalValue& sv, double& stTime) = 0;
    virtual void printSegment() = 0;
    virtual void sawCal(SignalValue& sv, double t) {}
    virtual void pulseCal(SignalValue& sv, double t) {}
    int attributeNum;
    double value;
    double duration;
    double start;
    double stop;
    double mean;
    double sigma;
    double seed;
    double offset;
    double slope;
    double period;
    double phase;
    double dutyCycle;
    double amplitude;
    double tau;
};

struct ConstSegment : public Segment {
    ConstSegment() : Segment(2) {}
    ~ConstSegment() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
};

struct RampSegment : public Segment {
    RampSegment() : Segment(3) {}
    ~RampSegment() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
};

struct IdleSegment : public Segment {
    IdleSegment() : Segment(1) {}
    ~IdleSegment() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
};

struct NoiseSegment : public Segment {
    NoiseSegment() : Segment(4) {}
    ~NoiseSegment() override {}
    void setRandom() {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
    std::default_random_engine e;
};

struct RampSlopeSegment : public Segment {
    RampSlopeSegment() : Segment(3) {}
    ~RampSlopeSegment() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
};

struct SawSegment : public Segment {
    SawSegment() : Segment(6) {}
    ~SawSegment() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
    void sawCal(SignalValue& sv, double t) override;
};

struct SineSegment : public Segment {
    SineSegment() : Segment(5) {}
    ~SineSegment() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
};

struct PulseSegment : public Segment {
    PulseSegment() : Segment(6) {}
    ~PulseSegment() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
    void pulseCal(SignalValue& sv, double t);
};

struct ExpSegment : public Segment {
    ExpSegment() : Segment(4) {}
    ~ExpSegment() override {}
    void calculate(SignalValue& sv, double& stTime) override;
    void printSegment() override;
};

#endif // _SEGMENT_H