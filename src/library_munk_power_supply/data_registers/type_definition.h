#ifndef TYPE_DEFINITION_H
#define TYPE_DEFINITION_H

#include <string>
#include <stdexcept>
#include <vector>

namespace DataParameter
{

enum class ParameterType{
    SEGMENTTIMES,
    PATTERNWRITECOMMAND,
    CURRENTSETPOINT,
    MEMORYWRITE,
    VOLTAGESETPOINT,
    FAULT_STATE,
    STATUS_STATE,
    FAULT_DETAILED
};

inline std::string ParameterTypeToString(const ParameterType &type) {
    switch (type) {
    case ParameterType::SEGMENTTIMES:
        return "Segment Times";
    case ParameterType::MEMORYWRITE:
        return "Memory Write";
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
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline std::vector<std::string> getListOfParameterTypes()
{
    std::vector<std::string> str;
    str.push_back(DataParameter::ParameterTypeToString(ParameterType::SEGMENTTIMES));
    str.push_back(DataParameter::ParameterTypeToString(ParameterType::MEMORYWRITE));
    return str;
}

inline ParameterType ParameterTypeFromInt(const int &param)
{
    if((param >= 4170) || (param <= 4185))
        return ParameterType::SEGMENTTIMES;
    else if(param == 4191)
        return ParameterType::MEMORYWRITE;
}

} //end of namespace DataParameter

#endif // TYPE_DEFINITION_H
