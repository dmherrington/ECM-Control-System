#ifndef TYPE_VOLTAGE_SET_H
#define TYPE_VOLTAGE_SET_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk{

inline bool isOfVoltageSegmentType(const int &value)
{
    if((value >= 6500) && (value <= 6800))
        return true;
    return false;
}

//!
//! \brief The VoltageSetFWDType enum
//!
enum class VoltageSetFWDType{
    VoltageFWD1 = 6500, /**<Voltage forward setting of output 1, level 1 to 8 - R/W */
    VoltageFWD2 = 6540, /**<Voltage forward setting of output 2, level 1 to 8 - R/W */
    VoltageFWD3 = 6580, /**<Voltage forward setting of output 3, level 1 to 8 - R/W */
    VoltageFWD4 = 6620, /**<Voltage forward setting of output 4, level 1 to 8 - R/W */
    VoltageFWD5 = 6660, /**<Voltage forward setting of output 5, level 1 to 8 - R/W */
    VoltageFWD6 = 6700, /**<Voltage forward setting of output 6, level 1 to 8 - R/W */
    VoltageFWD7 = 6740, /**<Voltage forward setting of output 7, level 1 to 8 - R/W */
    VoltageFWD8 = 6780  /**<Voltage forward setting of output 8, level 1 to 8 - R/W */
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
inline data_Munk::VoltageSetFWDType getFWDVoltageIndex(const int &index)
{
    std::vector<VoltageSetFWDType> objects = getListOfVoltageSetFWDTypes();
    return objects.at(index);
}


inline bool isForwardVoltageType(const int &value)
{
    std::vector<VoltageSetFWDType> objects = getListOfVoltageSetFWDTypes();
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        if(static_cast<int>(objects.at(i)) == value)
            return true;
    }
    return false;
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
inline data_Munk::VoltageSetREVType getREVVoltageIndex(const int &index)
{
    std::vector<VoltageSetREVType> objects = getListOfVoltageSetREVTypes();
    return objects.at(index);
}

inline bool isReverseVoltageType(const int &value)
{
    std::vector<VoltageSetREVType> objects = getListOfVoltageSetREVTypes();
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        if(static_cast<int>(objects.at(i)) == value)
            return true;
    }
    return false;
}

} //end of namespace data_Munk


#endif // TYPE_VOLTAGE_SET_H
