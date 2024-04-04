#include "Segment.h"

void ConstSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            sv.fcnVector.push_back(value);
        }
    }
    stTime += duration;
}

void RampSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            sv.fcnVector.push_back((stop - start) / duration * t + start);
        }
    }
    stTime += duration;
}

void IdleSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            sv.fcnVector.push_back(0);
        }
        stTime += duration;
    }
}

void NoiseSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            std::uniform_real_distribution<double> u(0, 1);
            double u1 = u(e), u2 = u(e);
            double z = sqrt(-2 * log(1 - u1)) * sin(2 * M_PI * u2);
            double fx = 1 / sqrt(2 * M_PI * sigma * sigma) * exp(-(z * z) / 2);
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            sv.fcnVector.push_back(fx);
        }
    }
    stTime += duration;
}

void RampSlopeSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            sv.fcnVector.push_back(slope * t + offset);
        }
    }
    stTime += duration;
}

void SawSegment::sawCal(SignalValue& sv, double t) {
    double tr = period * dutyCycle, tf = period - tr;
    double Time = t + phase * period;
    Time -= (int)(Time / period) * period;
    if (0 < Time && Time <= tr) {
        sv.fcnVector.push_back(amplitude * Time / tr + offset);
    }
    else if (tr < Time && Time <= period) {
        sv.fcnVector.push_back(amplitude + offset - (amplitude * (Time - tr) / tf));
    }
}

void SawSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            sawCal(sv, t);
        }
    }
    stTime += duration;
}

void SineSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            sv.fcnVector.push_back(amplitude * sin(2 * M_PI * (t + phase * period) / period) + offset);
        }
    }
    stTime += duration;
}

void PulseSegment::pulseCal(SignalValue& sv, double t) {
    double th = period * dutyCycle;
    double Time = t + phase * period;
    Time -= (int)(Time / period) * period;
    if (0 < Time && Time <= th) {
        sv.fcnVector.push_back(amplitude + offset);
    }
    if (th < Time && Time <= period) {
        sv.fcnVector.push_back(offset);
    }
}

void PulseSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            pulseCal(sv, t);
        }
    }
    stTime += duration;
}

void ExpSegment::calculate(SignalValue& sv, double& stTime) {
    for (double t = 0; t < duration; t += TIME_VAL) {
        if (t < 0 || t >= duration) {
            std::cerr << "Segment: time is out of range" << std::endl;
            exit(-1);
        }
        else {
            xToIdx.insert({stTime + t, sv.xVector.size()});
            sv.xVector.push_back(stTime + t);
            sv.fcnVector.push_back((stop - start) * (1 - exp(-t / tau)) + start);
        }
    }
    stTime += duration;
}

void ConstSegment::printSegment() {
    std::cout << "    ConstSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
    std::cout << "\tvalue: " << value << std::endl;
}

void RampSegment::printSegment() {
    std::cout << "    RampSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
    std::cout << "\tstart: " << start << std::endl;
    std::cout << "\tstop: " << stop << std::endl;
}

void IdleSegment::printSegment() {
    std::cout << "    IdleSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
}

void NoiseSegment::printSegment() {
    std::cout << "    NoiseSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
    std::cout << "\tsigma: " << sigma << std::endl;
    std::cout << "\tseed: " << seed << std::endl;
    std::cout << "\tsigma: " << sigma << std::endl;
}

void RampSlopeSegment::printSegment() {
    std::cout << "    RampSlopeSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
    std::cout << "\tslope: " << slope << std::endl;
    std::cout << "\toffset: " << offset << std::endl;
}

void SawSegment::printSegment() {
    std::cout << "    SawSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
    std::cout << "\tperiod: " << period << std::endl;
    std::cout << "\tdutyCycle: " << dutyCycle << std::endl;
    std::cout << "\tphase: " << phase << std::endl;
    std::cout << "\tamplitude: " << amplitude << std::endl;
    std::cout << "\toffset: " << offset << std::endl;
}

void SineSegment::printSegment() {
    std::cout << "    SineSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
    std::cout << "\tperiod: " << period << std::endl;
    std::cout << "\tphase: " << phase << std::endl;
    std::cout << "\tamplitude: " << amplitude << std::endl;
    std::cout << "\toffset: " << offset << std::endl;
}

void PulseSegment::printSegment() {
    std::cout << "    PulseSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
    std::cout << "\tperiod: " << period << std::endl;
    std::cout << "\tdutyCycle: " << dutyCycle << std::endl;
    std::cout << "\tphase: " << phase << std::endl;
    std::cout << "\tamplitude: " << amplitude << std::endl;
    std::cout << "\toffset: " << offset << std::endl;
}

void ExpSegment::printSegment() {
    std::cout << "    ExpSegment: " << std::endl;
    std::cout << "\tduration: " << duration << std::endl;
    std::cout << "\tstart: " << start << std::endl;
    std::cout << "\tstop: " << stop << std::endl;
    std::cout << "\ttau: " << tau << std::endl;
}