#ifndef TYPE_CURRENT_SET_H
#define TYPE_CURRENT_SET_H

#include <string>
#include <stdexcept>
#include <vector>

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

inline bool isOfCurrentSegmentType(const int &value)
{
    if((value >= 6000) && (value <= 6300))
        return true;
    return false;
}

//!
//! \brief The CurrentSetFWDType enum
//!
enum class CurrentSetFWDType{
    CurrentFWD1 = 6000, /**<Current forward setting of output 1, level 1 to 8 - R/W */
    CurrentFWD2 = 6040, /**<Current forward setting of output 2, level 1 to 8 - R/W */
    CurrentFWD3 = 6080, /**<Current forward setting of output 3, level 1 to 8 - R/W */
    CurrentFWD4 = 6120, /**<Current forward setting of output 4, level 1 to 8 - R/W */
    CurrentFWD5 = 6160, /**<Current forward setting of output 5, level 1 to 8 - R/W */
    CurrentFWD6 = 6200, /**<Current forward setting of output 6, level 1 to 8 - R/W */
    CurrentFWD7 = 6240, /**<Current forward setting of output 7, level 1 to 8 - R/W */
    CurrentFWD8 = 6280, /**<Current forward setting of output 8, level 1 to 8 - R/W */
};

//!
//! \brief CurrentSetFWDTypeToString
//! \param type
//! \return
//!
inline std::string CurrentSetFWDTypeToString(const CurrentSetFWDType &type) {
    switch (type) {
    case CurrentSetFWDType::CurrentFWD1:
        return "Current FWD 1";
    case CurrentSetFWDType::CurrentFWD2:
        return "Current FWD 2";
    case CurrentSetFWDType::CurrentFWD3:
        return "Current FWD 3";
    case CurrentSetFWDType::CurrentFWD4:
        return "Current FWD 4";
    case CurrentSetFWDType::CurrentFWD5:
        return "Current FWD 5";
    case CurrentSetFWDType::CurrentFWD6:
        return "Current FWD 6";
    case CurrentSetFWDType::CurrentFWD7:
        return "Current FWD 7";
    case CurrentSetFWDType::CurrentFWD8:
        return "Current FWD 8";
    default:
        throw std::runtime_error("Unknown voltage set fwd type seen");
    }
}

//!
//! \brief CurrentSetFWDTypeFromString
//! \param str
//! \return
//!
inline CurrentSetFWDType CurrentSetFWDTypeFromString(const std::string &str) {
    if(str == "Current FWD 1")
        return CurrentSetFWDType::CurrentFWD1;
    if(str == "Current FWD 2")
        return CurrentSetFWDType::CurrentFWD2;
    if(str == "Current FWD 3")
        return CurrentSetFWDType::CurrentFWD3;
    if(str == "Current FWD 4")
        return CurrentSetFWDType::CurrentFWD4;
    if(str == "Current FWD 5")
        return CurrentSetFWDType::CurrentFWD5;
    if(str == "Current FWD 6")
        return CurrentSetFWDType::CurrentFWD6;
    if(str == "Current FWD 7")
        return CurrentSetFWDType::CurrentFWD7;
    if(str == "Current FWD 8")
        return CurrentSetFWDType::CurrentFWD8;
    throw std::runtime_error("Unknown voltage set fwd type seen");
}

//!
//! \brief getListOfCurrentSetFWDTypes
//! \return
//!
inline std::vector<CurrentSetFWDType> getListOfCurrentSetFWDTypes()
{
    std::vector<CurrentSetFWDType> str;
    str.push_back(CurrentSetFWDType::CurrentFWD1);
    str.push_back(CurrentSetFWDType::CurrentFWD2);
    str.push_back(CurrentSetFWDType::CurrentFWD3);
    str.push_back(CurrentSetFWDType::CurrentFWD4);
    str.push_back(CurrentSetFWDType::CurrentFWD5);
    str.push_back(CurrentSetFWDType::CurrentFWD6);
    str.push_back(CurrentSetFWDType::CurrentFWD7);
    str.push_back(CurrentSetFWDType::CurrentFWD8);
    return str;
}

//!
//! \brief getREVCurrentIndex
//! \param index
//! \return
//!
inline Data::CurrentSetFWDType getFWDCurrentIndex(const int &index)
{
    std::vector<CurrentSetFWDType> objects = getListOfCurrentSetFWDTypes();
    return objects.at(index);
}

inline bool isForwardCurrentType(const int &value)
{
    std::vector<CurrentSetFWDType> objects = getListOfCurrentSetFWDTypes();
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        if(static_cast<int>(objects.at(i)) == value)
            return true;
    }
    return false;
}

//_________________________________________________________________________

//!
//! \brief The CurrentSetREVType enum
//!
enum class CurrentSetREVType{
    CurrentREV1 = 6020,
    CurrentREV2 = 6060,
    CurrentREV3 = 6100,
    CurrentREV4 = 6140,
    CurrentREV5 = 6180,
    CurrentREV6 = 6220,
    CurrentREV7 = 6260,
    CurrentREV8 = 6300,
};

//!
//! \brief CurrentSetREVTypeToString
//! \param type
//! \return
//!
inline std::string CurrentSetREVTypeToString(const CurrentSetREVType &type) {
    switch (type) {
    case CurrentSetREVType::CurrentREV1:
        return "Current REV 1";
    case CurrentSetREVType::CurrentREV2:
        return "Current REV 2";
    case CurrentSetREVType::CurrentREV3:
        return "Current REV 3";
    case CurrentSetREVType::CurrentREV4:
        return "Current REV 4";
    case CurrentSetREVType::CurrentREV5:
        return "Current REV 5";
    case CurrentSetREVType::CurrentREV6:
        return "Current REV 6";
    case CurrentSetREVType::CurrentREV7:
        return "Current REV 7";
    case CurrentSetREVType::CurrentREV8:
        return "Current REV 8";
    default:
        throw std::runtime_error("Unknown voltage set rev type seen");
    }
}

//!
//! \brief CurrentSetREVTypeFromString
//! \param str
//! \return
//!
inline CurrentSetREVType CurrentSetREVTypeFromString(const std::string &str) {
    if(str == "Current REV 1")
        return CurrentSetREVType::CurrentREV1;
    if(str == "Current REV 2")
        return CurrentSetREVType::CurrentREV2;
    if(str == "Current REV 3")
        return CurrentSetREVType::CurrentREV3;
    if(str == "Current REV 4")
        return CurrentSetREVType::CurrentREV4;
    if(str == "Current REV 5")
        return CurrentSetREVType::CurrentREV5;
    if(str == "Current REV 6")
        return CurrentSetREVType::CurrentREV6;
    if(str == "Current REV 7")
        return CurrentSetREVType::CurrentREV7;
    if(str == "Current REV 8")
        return CurrentSetREVType::CurrentREV8;
    throw std::runtime_error("Unknown voltage set rev type seen");
}

//!
//! \brief getListOfCurrentSetREVTypes
//! \return
//!
inline std::vector<CurrentSetREVType> getListOfCurrentSetREVTypes()
{
    std::vector<CurrentSetREVType> str;
    str.push_back(CurrentSetREVType::CurrentREV1);
    str.push_back(CurrentSetREVType::CurrentREV2);
    str.push_back(CurrentSetREVType::CurrentREV3);
    str.push_back(CurrentSetREVType::CurrentREV4);
    str.push_back(CurrentSetREVType::CurrentREV5);
    str.push_back(CurrentSetREVType::CurrentREV6);
    str.push_back(CurrentSetREVType::CurrentREV7);
    str.push_back(CurrentSetREVType::CurrentREV8);
    return str;
}

//!
//! \brief getREVCurrentIndex
//! \param index
//! \return
//!
inline Data::CurrentSetREVType getREVCurrentIndex(const int &index)
{
    std::vector<CurrentSetREVType> objects = getListOfCurrentSetREVTypes();
    return objects.at(index);
}

inline bool isReverseCurrentType(const int &value)
{
    std::vector<CurrentSetREVType> objects = getListOfCurrentSetREVTypes();
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        if(static_cast<int>(objects.at(i)) == value)
            return true;
    }
    return false;
}

} //end of namespace Data

#endif // TYPE_CURRENT_SET_H
