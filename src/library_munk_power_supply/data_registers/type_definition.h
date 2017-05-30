#ifndef TYPE_DEFINITION_H
#define TYPE_DEFINITION_H

#include <string>
#include <stdexcept>

namespace Data
{

enum class RegisterType{
    SEGMENTTIMES,
    PATTERNWRITECOMMAND
};

inline std::string RegisterTypeToString(const RegisterType &type) {
    switch (type) {
    case RegisterType::SEGMENTTIMES:
        return "Segment Times";
    case RegisterType::PATTERNWRITECOMMAND:
        return "Pattern Write";
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline RegisterType RegisterTypeFromString(const std::string &str) {
    if(str == "Segment Times")
        return RegisterType::SEGMENTTIMES;
    if(str == "Pattern Write")
        return RegisterType::PATTERNWRITECOMMAND;
    throw std::runtime_error("Unknown register type seen");
}


inline int RegisterTypeToInt(const RegisterType &type) {
    switch (state) {
    case RegisterType::SEGMENTTIMES:
        return 4170;
    case RegisterType::PATTERNWRITECOMMAND:
        return 4191;
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}
inline RegisterType RegisterTypeFromInt(const int &str) {
    if(str == 4170)
        return RegisterType::SEGMENTTIMES;
    if(str == 4191)
        return RegisterType::PATTERNWRITECOMMAND;
    throw std::runtime_error("Unknown register type int seen");
}

} //end of namespace Data

#endif // TYPE_DEFINITION_H
