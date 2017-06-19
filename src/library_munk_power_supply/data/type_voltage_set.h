#ifndef TYPE_VOLTAGE_SET_H
#define TYPE_VOLTAGE_SET_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

//!
//! \brief The VoltageSetFWDType enum
//!
enum class VoltageSetFWDType{
    VoltageFWD1 = 6500, /**<testing */
    VoltageFWD2 = 6540, /**< */
    VoltageFWD3 = 6580, /**< */
    VoltageFWD4 = 6620, /**< */
    VoltageFWD5 = 6660, /**< */
    VoltageFWD6 = 6700, /**< */
    VoltageFWD7 = 6740, /**< */
    VoltageFWD8 = 6780 /**< */
};

//!
//! \brief VoltageSetFWDTypeToString
//! \param type
//! \return
//!
inline std::string VoltageSetFWDTypeToString(const VoltageSetFWDType &type) {
    switch (type) {
    case VoltageSetFWDType::VoltageFWD1:
        return "Voltage FWD 1";
    case VoltageSetFWDType::VoltageFWD2:
        return "Voltage FWD 2";
    case VoltageSetFWDType::VoltageFWD3:
        return "Voltage FWD 3";
    case VoltageSetFWDType::VoltageFWD4:
        return "Voltage FWD 4";
    case VoltageSetFWDType::VoltageFWD5:
        return "Voltage FWD 5";
    case VoltageSetFWDType::VoltageFWD6:
        return "Voltage FWD 6";
    case VoltageSetFWDType::VoltageFWD7:
        return "Voltage FWD 7";
    case VoltageSetFWDType::VoltageFWD8:
        return "Voltage FWD 8";
    default:
        throw std::runtime_error("Unknown voltage set fwd type seen");
    }
}

//!
//! \brief VoltageSetFWDTypeFromString
//! \param str
//! \return
//!
inline VoltageSetFWDType VoltageSetFWDTypeFromString(const std::string &str) {
    if(str == "Voltage FWD 1")
        return VoltageSetFWDType::VoltageFWD1;
    if(str == "Voltage FWD 2")
        return VoltageSetFWDType::VoltageFWD2;
    if(str == "Voltage FWD 3")
        return VoltageSetFWDType::VoltageFWD3;
    if(str == "Voltage FWD 4")
        return VoltageSetFWDType::VoltageFWD4;
    if(str == "Voltage FWD 5")
        return VoltageSetFWDType::VoltageFWD5;
    if(str == "Voltage FWD 6")
        return VoltageSetFWDType::VoltageFWD6;
    if(str == "Voltage FWD 7")
        return VoltageSetFWDType::VoltageFWD7;
    if(str == "Voltage FWD 8")
        return VoltageSetFWDType::VoltageFWD8;
    throw std::runtime_error("Unknown voltage set fwd type seen");
}

//!
//! \brief getListOfVoltageSetFWDTypes
//! \return
//!
inline std::vector<VoltageSetFWDType> getListOfVoltageSetFWDTypes()
{
    std::vector<VoltageSetFWDType> str;
    str.push_back(VoltageSetFWDType::VoltageFWD1);
    str.push_back(VoltageSetFWDType::VoltageFWD2);
    str.push_back(VoltageSetFWDType::VoltageFWD3);
    str.push_back(VoltageSetFWDType::VoltageFWD4);
    str.push_back(VoltageSetFWDType::VoltageFWD5);
    str.push_back(VoltageSetFWDType::VoltageFWD6);
    str.push_back(VoltageSetFWDType::VoltageFWD7);
    str.push_back(VoltageSetFWDType::VoltageFWD8);
    return str;
}

//!
//! \brief getFWDVoltageIndex
//! \param index
//! \return
//!
inline Data::VoltageSetFWDType getFWDVoltageIndex(const int &index)
{
    std::vector<VoltageSetFWDType> objects = getListOfVoltageSetFWDTypes();
    return objects.at(index);
}

//_________________________________________________________________________

//!
//! \brief The VoltageSetREVType enum
//!
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

//!
//! \brief VoltageSetREVTypeToString
//! \param type
//! \return
//!
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

//!
//! \brief VoltageSetREVTypeFromString
//! \param str
//! \return
//!
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

//!
//! \brief getListOfVoltageSetREVTypes
//! \return
//!
inline std::vector<VoltageSetREVType> getListOfVoltageSetREVTypes()
{
    std::vector<VoltageSetREVType> str;
    str.push_back(VoltageSetREVType::VoltageREV1);
    str.push_back(VoltageSetREVType::VoltageREV2);
    str.push_back(VoltageSetREVType::VoltageREV3);
    str.push_back(VoltageSetREVType::VoltageREV4);
    str.push_back(VoltageSetREVType::VoltageREV5);
    str.push_back(VoltageSetREVType::VoltageREV6);
    str.push_back(VoltageSetREVType::VoltageREV7);
    str.push_back(VoltageSetREVType::VoltageREV8);
    return str;
}

//!
//! \brief getREVVoltageIndex
//! \param index
//! \return
//!
inline Data::VoltageSetREVType getREVVoltageIndex(const int &index)
{
    std::vector<VoltageSetREVType> objects = getListOfVoltageSetREVTypes();
    return objects.at(index);
}

} //end of namespace Data

#endif // TYPE_VOLTAGE_SET_H
