#ifndef WESTINGHOUSE_AVAILABLE_REGISTERS_H
#define WESTINGHOUSE_AVAILABLE_REGISTERS_H

#include <string>
#include <stdexcept>
#include <vector>


namespace registers_WestinghousePump{

enum class RegisterType{
    OPERATION_SIGNAL,
    FLOWRATE,
    UNKNOWN
};

inline std::string RegisterTypeToString(const RegisterType &type) {
    switch (type) {
    case RegisterType::OPERATION_SIGNAL:
        return "Operational Signal";
    case RegisterType::FLOWRATE:
        return "Flow Rate";
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline RegisterType RegisterTypeFromString(const std::string &str) {
    if(str == "Operational Signal")
        return RegisterType::OPERATION_SIGNAL;
    if(str == "Flow Rate")
        return RegisterType::FLOWRATE;
    throw std::runtime_error("Unknown register type seen");
}


inline int RegisterTypeToInt(const RegisterType &type)
{
    switch (type) {
    case RegisterType::OPERATION_SIGNAL:
        return 9473;
    case RegisterType::FLOWRATE:
        return 1281;
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}


inline RegisterType RegisterTypeFromInt(const int &type)
{
    switch (type) {
    case 9473:
        return RegisterType::OPERATION_SIGNAL;
    case 1281:
        return RegisterType::FLOWRATE;
    default:
        return RegisterType::UNKNOWN;
    }
}

inline std::vector<std::string> getListOfRegisterTypes()
{
    std::vector<std::string> str;
    str.push_back(RegisterTypeToString(RegisterType::OPERATION_SIGNAL));
    str.push_back(RegisterTypeToString(RegisterType::FLOWRATE));

    return str;
}

} //end of namespace registers_WestinghousePump


#endif // WESTINGHOUSE_AVAILABLE_REGISTERS_H
