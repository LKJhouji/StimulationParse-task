#ifndef _SIGNAL_GROUP_VALUE_H
#define _SIGNAL_GROUP_VALUE_H

#include <vector>
#include <list>

struct SignalGroupValue {
    std::vector<double> xVector;
    std::list<std::vector<double>> yVector;
    std::list<std::vector<double>> variableNames;
};

#endif //_SIGNAL_GROUP_VALUE_H