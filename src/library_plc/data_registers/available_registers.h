#ifndef WESTINGHOUSE_AVAILABLE_REGISTERS_H
#define WESTINGHOUSE_AVAILABLE_REGISTERS_H

#include <string>
#include <stdexcept>
#include <vector>


namespace registers_PLC{

enum class PLCRegisterTypes{
    PH,
    CONDUCTIVITY,
    UNKNOWN
};

inline std::string RegisterTypeToString(const PLCRegisterTypes &type) {
    switch (type) {
    case PLCRegisterTypes::PH:
        return "pH";
    case PLCRegisterTypes::CONDUCTIVITY:
        return "Conductivity";
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline PLCRegisterTypes RegisterTypeFromString(const std::string &str) {
    if(str == "pH")
        return PLCRegisterTypes::PH;
    if(str == "Conductivity")
        return PLCRegisterTypes::CONDUCTIVITY;
    throw std::runtime_error("Unknown register type seen");
}


inline int RegisterTypeToInt(const PLCRegisterTypes &type)
{
    switch (type) {
    case PLCRegisterTypes::PH:
        return 1;
    case PLCRegisterTypes::CONDUCTIVITY:
        return 3;
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}


inline PLCRegisterTypes RegisterTypeFromInt(const int &type)
{
    switch (type) {
    case 1:
        return PLCRegisterTypes::PH;
    case 3:
        return PLCRegisterTypes::CONDUCTIVITY;
    default:
        return PLCRegisterTypes::UNKNOWN;
    }
}

inline std::vector<std::string> getListOfRegisterTypes()
{
    std::vector<std::string> str;
    str.push_back(RegisterTypeToString(PLCRegisterTypes::PH));
    str.push_back(RegisterTypeToString(PLCRegisterTypes::CONDUCTIVITY));
    return str;
}

} //end of namespace registers_WestinghousePump


#endif // WESTINGHOUSE_AVAILABLE_REGISTERS_H
