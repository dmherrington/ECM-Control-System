#ifndef TYPE_PRESCALAR_POWER_H
#define TYPE_PRESCALAR_POWER_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

//!
//! \brief The SegmentPower enum
//!
enum class SegmentPower{
    ONE = 0, /**< */
    TEN = 1, /**< */
    ONE_HUNDRED = 2, /**< */
    ONE_THOUSAND = 3, /**< */
    TEN_THOUSAND = 4 /**< */
};

//!
//! \brief SegmentPowerToString
//! \param type
//! \return
//!
inline std::string SegmentPowerToString(const SegmentPower &type) {
    switch (type) {
    case SegmentPower::ONE:
        return "1";
    case SegmentPower::TEN:
        return "10";
    case SegmentPower::ONE_HUNDRED:
        return "100";
    case SegmentPower::ONE_THOUSAND:
        return "1,000";
    case SegmentPower::TEN_THOUSAND:
        return "10,000";
    default:
        throw std::runtime_error("Unknown segment power seen");
    }
}

//!
//! \brief SegmentPowerFromString
//! \param str
//! \return
//!
inline SegmentPower SegmentPowerFromString(const std::string &str) {
    if(str == "1")
        return SegmentPower::ONE;
    if(str == "10")
        return SegmentPower::TEN;
    if(str == "100")
        return SegmentPower::ONE_HUNDRED;
    if(str == "1,000")
        return SegmentPower::ONE_THOUSAND;
    if(str == "10,000")
        return SegmentPower::TEN_THOUSAND;
    throw std::runtime_error("Unknown segment power seen");
}

//!
//! \brief getListOfSegmentPower
//! \return
//!
inline std::vector<std::string> getListOfSegmentPower()
{
    std::vector<std::string> str;
    str.push_back(Data::SegmentPowerToString(SegmentPower::ONE));
    str.push_back(Data::SegmentPowerToString(SegmentPower::TEN));
    str.push_back(Data::SegmentPowerToString(SegmentPower::ONE_HUNDRED));
    str.push_back(Data::SegmentPowerToString(SegmentPower::ONE_THOUSAND));
    str.push_back(Data::SegmentPowerToString(SegmentPower::TEN_THOUSAND));
    return str;
}

//!
//! \brief SegmentPowerToBitArray
//! \param type
//! \param bitArray
//! \return
//!
inline uint32_t SegmentPowerToBitArray(const SegmentPower &type, const uint32_t &bitArray) {
    uint32_t ba = 0;
    uint32_t mask = 7<<7;
    ba = (bitArray & (~mask)) | ((int)type<<7);
    return ba;
}

//!
//! \brief ValueToEquivalentSegmentPower
//! \param value
//! \return
//!
inline SegmentPower ValueToEquivalentSegmentPower(const int &value)
{
    switch (value) {
    case 0:
    case 1:
        return SegmentPower::ONE;
    case 10:
        return SegmentPower::TEN;
    case 100:
        return SegmentPower::ONE_HUNDRED;
    case 1000:
        return SegmentPower::ONE_THOUSAND;
    case 10000:
        return SegmentPower::TEN_THOUSAND;
    default:
        throw std::runtime_error("Unknown segment power seen");
    }
}

} //end of namespace Data
#endif // TYPE_PRESCALAR_POWER_H
