#ifndef _SIGNAL_VALUE_H
#define _SIGNAL_VALUE_H

#include <vector>
#include <unordered_map>

struct SignalValue {
    std::vector<double> xVector;
    std::vector<double> fcnVector;
};

extern std::unordered_map<double, int> xToIdx;

#endif // _SIGNAL_VALUE_H