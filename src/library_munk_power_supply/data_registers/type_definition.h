#ifndef MUNK_REGISTER_DEFINITIONS_H
#define MUNK_REGISTER_DEFINITIONS_H

#include <string>
#include <stdexcept>
#include <vector>


namespace registers_Munk{

enum class ParameterType{
    SEGMENTTIMES,
    PATTERNWRITECOMMAND,
    CURRENTSETPOINT_FORWARD,
    CURRENTSETPOINT_REVERSE,
    MEMORYWRITE,
    VOLTAGESETPOINT_FORWARD,
    VOLTAGESETPOINT_REVERSE,
    FAULT_STATE,
    TB_SELECT,
    TB_COUNT,
    TB_TEMPERATURE,
    STATUS_STATE,
    FAULT_DETAILED,
    PULSE_MODE
};

inline std::string ParameterTypeToString(const ParameterType &type) {
    switch (type) {
    case ParameterType::SEGMENTTIMES:
        return "Segment Times";
    case ParameterType::MEMORYWRITE:
        return "Memory Write";
    case ParameterType::PULSE_MODE:
        return "Pulse Mode";
    default:
        throw std::runtime_error("Unknown parameter type seen");
    }
}

inline ParameterType ParameterTypeFromString(const std::string &str) {
    if(str == "Segment Times")
        return ParameterType::SEGMENTTIMES;
    if(str == "Memory Write")
        return ParameterType::MEMORYWRITE;
    throw std::runtime_error("Unknown register type seen");
}


inline int ParameterTypeToInt(const ParameterType &type)
{
    switch (type) {
    case ParameterType::SEGMENTTIMES:
        return 4170;
    case ParameterType::MEMORYWRITE:
        return 4191;
    case ParameterType::PULSE_MODE:
        return 4430;
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline std::vector<std::string> getListOfParameterTypes()
{
    std::vector<std::string> str;
    str.push_back(registers_Munk::ParameterTypeToString(ParameterType::SEGMENTTIMES));
    str.push_back(registers_Munk::ParameterTypeToString(ParameterType::MEMORYWRITE));
    return str;
}

inline ParameterType ParameterTypeFromInt(const int &param)
{
    if((param >= 4170) || (param <= 4185))
        return ParameterType::SEGMENTTIMES;
    else if(param == 4191)
        return ParameterType::MEMORYWRITE;
}

} //end of namepsace registers_Munk


#endif // MUNK_REGISTER_DEFINITIONS_H
