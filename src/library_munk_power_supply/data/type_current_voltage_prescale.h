#ifndef TYPE_CURRENT_VOLTAGE_PRESCALE_H
#define TYPE_CURRENT_VOLTAGE_PRESCALE_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

enum class SegmentVIPower{
    ONE = 0,
    ONE_HUNDREDTH = 1,
    ONE_TENTH = 2,
    TEN = 3,
    ONE_HUNDRED = 5
};

inline std::string SegmentVIPowerToString(const SegmentVIPower &type) {
    switch (type) {
    case SegmentVIPower::ONE:
        return "1";
    case SegmentVIPower::ONE_HUNDREDTH:
        return "0.01";
    case SegmentVIPower::ONE_TENTH:
        return "0.1";
    case SegmentVIPower::TEN:
        return "10";
    case SegmentVIPower::ONE_HUNDRED:
        return "100";
    default:
        throw std::runtime_error("Unknown segment power seen");
    }
}

inline SegmentVIPower SegmentVIPowerFromString(const std::string &str) {
    if(str == "1")
        return SegmentVIPower::ONE;
    if(str == "0.01")
        return SegmentVIPower::ONE_HUNDREDTH;
    if(str == "0.1")
        return SegmentVIPower::ONE_TENTH;
    if(str == "10")
        return SegmentVIPower::TEN;
    if(str == "100")
        return SegmentVIPower::ONE_HUNDRED;
    throw std::runtime_error("Unknown segment power seen");
}

inline std::vector<std::string> getListOfSegmentVIPower()
{
    std::vector<std::string> str;
    str.push_back(Data::SegmentVIPowerToString(SegmentVIPower::ONE));
    str.push_back(Data::SegmentVIPowerToString(SegmentVIPower::ONE_HUNDREDTH));
    str.push_back(Data::SegmentVIPowerToString(SegmentVIPower::ONE_TENTH));
    str.push_back(Data::SegmentVIPowerToString(SegmentVIPower::TEN));
    str.push_back(Data::SegmentVIPowerToString(SegmentVIPower::ONE_HUNDRED));
    return str;
}

inline uint32_t SegmenVIPowerToBitArray(const SegmentVIPower &type, const uint32_t &bitArray) {
    uint32_t ba = 0;
    uint32_t mask = 7<<12;
    ba = (bitArray & (~mask)) | ((int)type<<12);
    return ba;
}

} //end of namespace Data

#endif // TYPE_CURRENT_VOLTAGE_PRESCALE_H
