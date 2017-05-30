#ifndef TYPE_PRESCALAR_POWER_H
#define TYPE_PRESCALAR_POWER_H

#include <string>
#include <stdexcept>

namespace Data
{

enum class SegmentMode{
    DEAD,
    FORWARD,
    REVERSE,
    ILLEGAL
};

inline std::string SegmentModeToString(const SegmentMode &type) {
    switch (type) {
    case SegmentMode::DEAD:
        return "DEAD";
    case SegmentMode::FORWARD:
        return "FORWARD";
    case SegmentMode::REVERSE:
        return "REVERSE";
    case SegmentMode::ILLEGAL:
        return "ILLEGAL";
    default:
        throw std::runtime_error("Unknown segment mode seen");
    }
}

inline SegmentMode SegmentModeFromString(const std::string &str) {
    if(str == "DEAD")
        return SegmentMode::DEAD;
    if(str == "FORWARD")
        return SegmentMode::FORWARD;
    if(str == "REVERSE")
        return SegmentMode::REVERSE;
    if(str == "ILLEGAL")
        return SegmentMode::ILLEGAL;
    throw std::runtime_error("Unknown segment mode seen");
}


} //end of namespace Data
#endif // TYPE_PRESCALAR_POWER_H
