#ifndef WESTINGHOUSE_AVAILABLE_REGISTERS_H
#define WESTINGHOUSE_AVAILABLE_REGISTERS_H

#include <string>
#include <stdexcept>
#include <vector>


namespace registers_PLC{

enum class PLCRegisterTypes{
    OPERATION_SIGNAL,
    FLOWRATE,
    RUN_SOURCE,
    LOOPBACK,
    UNKNOWN
};

inline std::string RegisterTypeToString(const PLCRegisterTypes &type) {
    switch (type) {
    case PLCRegisterTypes::OPERATION_SIGNAL:
        return "Operational Signal";
    case PLCRegisterTypes::FLOWRATE:
        return "Flow Rate";
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline PLCRegisterTypes RegisterTypeFromString(const std::string &str) {
    if(str == "Operational Signal")
        return PLCRegisterTypes::OPERATION_SIGNAL;
    if(str == "Flow Rate")
        return PLCRegisterTypes::FLOWRATE;
    throw std::runtime_error("Unknown register type seen");
}


inline int RegisterTypeToInt(const PLCRegisterTypes &type)
{
    switch (type) {
    case PLCRegisterTypes::OPERATION_SIGNAL:
        return 9473;
    case PLCRegisterTypes::FLOWRATE:
        return 1281;
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}


inline PLCRegisterTypes RegisterTypeFromInt(const int &type)
{
    switch (type) {
    case 9473:
        return PLCRegisterTypes::OPERATION_SIGNAL;
    case 1281:
        return PLCRegisterTypes::FLOWRATE;
    default:
        return PLCRegisterTypes::UNKNOWN;
    }
}

inline std::vector<std::string> getListOfRegisterTypes()
{
    std::vector<std::string> str;
    str.push_back(RegisterTypeToString(PLCRegisterTypes::OPERATION_SIGNAL));
    str.push_back(RegisterTypeToString(PLCRegisterTypes::FLOWRATE));
    return str;
}

} //end of namespace registers_WestinghousePump


#endif // WESTINGHOUSE_AVAILABLE_REGISTERS_H
