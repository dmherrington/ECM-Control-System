#ifndef TYPE_PRESCALAR_POWER_H
#define TYPE_PRESCALAR_POWER_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

enum class SegmentPower{
    ONE = 0,
    TEN = 1,
    ONE_HUNDRED = 2,
    ONE_THOUSAND = 3,
    TEN_THOUSAND = 4
};

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

inline uint32_t SegmentPowerToBitArray(const SegmentPower &type, const uint32_t &bitArray) {
    uint32_t ba = 0;
    uint32_t mask = 7<<7;
    ba = (bitArray & (~mask)) | ((int)type<<7);
    return ba;
}

} //end of namespace Data
#endif // TYPE_PRESCALAR_POWER_H
