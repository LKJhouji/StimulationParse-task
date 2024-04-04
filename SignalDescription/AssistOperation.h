#ifndef _ASSIST_OPERATION_H
#define _ASSIST_OPERATION_H

#include <unordered_map>

#include <string>

#include "SignalValue.h"

class SignalDescription;

extern std::unordered_map<std::string, SignalValue> idToSV;
extern std::unordered_map<std::string, SignalDescription*> idToSeg;

#endif // _ASSIST_OPERATION_H