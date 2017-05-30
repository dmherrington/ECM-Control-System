#ifndef TYPE_DEFINITION_H
#define TYPE_DEFINITION_H

#include <string>
#include <stdexcept>

namespace DataParameter
{

enum class ParameterType{
    SEGMENTTIMES,
    PATTERNWRITECOMMAND
};

inline std::string ParameterTypeToString(const ParameterType &type) {
    switch (type) {
    case ParameterType::SEGMENTTIMES:
        return "Segment Times";
    case ParameterType::PATTERNWRITECOMMAND:
        return "Pattern Write";
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline ParameterType ParameterTypeFromString(const std::string &str) {
    if(str == "Segment Times")
        return ParameterType::SEGMENTTIMES;
    if(str == "Pattern Write")
        return ParameterType::PATTERNWRITECOMMAND;
    throw std::runtime_error("Unknown register type seen");
}


inline int ParameterTypeToInt(const ParameterType &type) {
    switch (type) {
    case ParameterType::SEGMENTTIMES:
        return 4170;
    case ParameterType::PATTERNWRITECOMMAND:
        return 4191;
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}
inline ParameterType ParameterTypeFromInt(const int &str) {
    if(str == 4170)
        return ParameterType::SEGMENTTIMES;
    if(str == 4191)
        return ParameterType::PATTERNWRITECOMMAND;
    throw std::runtime_error("Unknown register type int seen");
}

} //end of namespace DataParameter

#endif // TYPE_DEFINITION_H
