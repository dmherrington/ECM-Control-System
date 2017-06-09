#ifndef TYPE_VOLTAGE_SET_H
#define TYPE_VOLTAGE_SET_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

enum class VoltageSetFWDType{
    VoltageFWD1 = 6500,
    VoltageFWD2 = 6540,
    VoltageFWD3 = 6580,
    VoltageFWD4 = 6620,
    VoltageFWD5 = 6660,
    VoltageFWD6 = 6700,
    VoltageFWD7 = 6740,
    VoltageFWD8 = 6780,
};

enum class VoltageSetREVType{
    VoltageREV1 = 6520,
    VoltageREV2 = 6560,
    VoltageREV3 = 6600,
    VoltageREV4 = 6640,
    VoltageREV5 = 6680,
    VoltageREV6 = 6720,
    VoltageREV7 = 6760,
    VoltageREV8 = 6800,
};

inline std::string VoltageSetREVTypeToString(const VoltageSetREVType &type) {
    switch (type) {
    case VoltageSetREVType::VoltageREV1:
        return "Voltage REV 1";
    case VoltageSetREVType::VoltageREV2:
        return "Voltage REV 2";
    case VoltageSetREVType::VoltageREV3:
        return "Voltage REV 3";
    case VoltageSetREVType::VoltageREV4:
        return "Voltage REV 4";
    case VoltageSetREVType::VoltageREV5:
        return "Voltage REV 5";
    case VoltageSetREVType::VoltageREV6:
        return "Voltage REV 6";
    case VoltageSetREVType::VoltageREV7:
        return "Voltage REV 7";
    case VoltageSetREVType::VoltageREV8:
        return "Voltage REV 8";
    default:
        throw std::runtime_error("Unknown voltage set rev type seen");
    }
}


inline VoltageSetREVType VoltageSetREVTypeFromString(const std::string &str) {
    if(str == "Voltage REV 1")
        return VoltageSetREVType::VoltageREV1;
    if(str == "Voltage REV 2")
        return VoltageSetREVType::VoltageREV2;
    if(str == "Voltage REV 3")
        return VoltageSetREVType::VoltageREV3;
    if(str == "Voltage REV 4")
        return VoltageSetREVType::VoltageREV4;
    if(str == "Voltage REV 5")
        return VoltageSetREVType::VoltageREV5;
    if(str == "Voltage REV 6")
        return VoltageSetREVType::VoltageREV6;
    if(str == "Voltage REV 7")
        return VoltageSetREVType::VoltageREV7;
    if(str == "Voltage REV 8")
        return VoltageSetREVType::VoltageREV8;
    throw std::runtime_error("Unknown voltage set rev type seen");
}

inline std::vector<std::string> getListOfVoltageSetREVTypes()
{
    std::vector<std::string> str;
    return str;
}

inline std::vector<VoltageSetREVType> getListOfVoltageSetREVTypes()
{
    std::vector<VoltageSetREVType> str;
    str.push_back();
    str.push_back();
    return str;
}

} //end of namespace Data

#endif // TYPE_VOLTAGE_SET_H
