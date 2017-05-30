#ifndef TYPE_PRESCALAR_POWER_H
#define TYPE_PRESCALAR_POWER_H

#include <string>
#include <stdexcept>

namespace Data
{

enum class SegmentPower{
    ONE,
    TEN,
    ONE_HUNDRED,
    ONE_THOUSAND,
    TEN_THOUSAND
};

inline std::string SegmentModeToString(const SegmentPower &type) {
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


} //end of namespace Data
#endif // TYPE_PRESCALAR_POWER_H
