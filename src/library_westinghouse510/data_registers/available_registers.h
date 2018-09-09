#ifndef WESTINGHOUSE_AVAILABLE_REGISTERS_H
#define WESTINGHOUSE_AVAILABLE_REGISTERS_H

#include <string>
#include <stdexcept>
#include <vector>


namespace registers_WestinghousePump{

enum class WestinhouseRegisterTypes{
    OPERATION_SIGNAL,
    FLOWRATE,
    RUN_SOURCE,
    UNKNOWN
};

inline std::string RegisterTypeToString(const WestinhouseRegisterTypes &type) {
    switch (type) {
    case WestinhouseRegisterTypes::OPERATION_SIGNAL:
        return "Operational Signal";
    case WestinhouseRegisterTypes::FLOWRATE:
        return "Flow Rate";
    case WestinhouseRegisterTypes::RUN_SOURCE:
        return "Run Source";
    default:
        throw std::runtime_error("Unknown register type seen");
    }
}

inline WestinhouseRegisterTypes RegisterTypeFromString(const std::string &str) {
    if(str == "Operational Signal")
        return WestinhouseRegisterTypes::OPERATION_SIGNAL;
    if(str == "Flow Rate")
        return WestinhouseRegisterTypes::FLOWRATE;
    if(str == "Run Source")
        return WestinhouseRegisterTypes::RUN_SOURCE;
    throw std::runtime_error("Unknown register type seen");
}


inline int RegisterTypeToInt(const WestinhouseRegisterTypes &type)
{
    switch (type) {
    case WestinhouseRegisterTypes::OPERATION_SIGNAL:
        return 9473;
    case WestinhouseRegisterTypes::FLOWRATE:
        return 1281;
    case WestinhouseRegisterTypes::RUN_SOURCE:
        return 0002;
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
    case 0002:
        return WestinhouseRegisterTypes::RUN_SOURCE;
    default:
        return WestinhouseRegisterTypes::UNKNOWN;
    }
}

inline std::vector<std::string> getListOfRegisterTypes()
{
    std::vector<std::string> str;
    str.push_back(RegisterTypeToString(WestinhouseRegisterTypes::OPERATION_SIGNAL));
    str.push_back(RegisterTypeToString(WestinhouseRegisterTypes::FLOWRATE));
    str.push_back(RegisterTypeToString(WestinhouseRegisterTypes::RUN_SOURCE));

    return str;
}

} //end of namespace registers_WestinghousePump


#endif // WESTINGHOUSE_AVAILABLE_REGISTERS_H
