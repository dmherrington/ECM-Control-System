#ifndef WESTINGHOUSE_AVAILABLE_REGISTERS_H
#define WESTINGHOUSE_AVAILABLE_REGISTERS_H

#include <string>
#include <stdexcept>
#include <vector>


namespace registers_WestinghousePump{

enum class WestinhouseRegisterTypes{
    OPERATION_SIGNAL,
    FLOWRATE,
    UNKNOWN
};

inline std::string RegisterTypeToString(const WestinhouseRegisterTypes &type) {
    switch (type) {
    case WestinhouseRegisterTypes::OPERATION_SIGNAL:
        return "Operational Signal";
    case WestinhouseRegisterTypes::FLOWRATE:
        return "Flow Rate";
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline WestinhouseRegisterTypes RegisterTypeFromString(const std::string &str) {
    if(str == "Operational Signal")
        return WestinhouseRegisterTypes::OPERATION_SIGNAL;
    if(str == "Flow Rate")
        return WestinhouseRegisterTypes::FLOWRATE;
    throw std::runtime_error("Unknown register type seen");
}


inline int RegisterTypeToInt(const WestinhouseRegisterTypes &type)
{
    switch (type) {
    case WestinhouseRegisterTypes::OPERATION_SIGNAL:
        return 9473;
    case WestinhouseRegisterTypes::FLOWRATE:
        return 1281;
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}


inline WestinhouseRegisterTypes RegisterTypeFromInt(const int &type)
{
    switch (type) {
    case 9473:
        return WestinhouseRegisterTypes::OPERATION_SIGNAL;
    case 1281:
        return WestinhouseRegisterTypes::FLOWRATE;
    default:
        return WestinhouseRegisterTypes::UNKNOWN;
    }
}

inline std::vector<std::string> getListOfRegisterTypes()
{
    std::vector<std::string> str;
    str.push_back(RegisterTypeToString(WestinhouseRegisterTypes::OPERATION_SIGNAL));
    str.push_back(RegisterTypeToString(WestinhouseRegisterTypes::FLOWRATE));

    return str;
}

} //end of namespace registers_WestinghousePump


#endif // WESTINGHOUSE_AVAILABLE_REGISTERS_H
