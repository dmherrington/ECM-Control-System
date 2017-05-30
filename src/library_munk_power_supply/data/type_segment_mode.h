#ifndef TYPE_SEGMENT_MODE_H
#define TYPE_SEGMENT_MODE_H

#include <string>
#include <stdexcept>
#include <bitset>

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

inline std::bitset SegmentModeBitArray(const SegmentLevel &str) {
    std::bitset<2>ba("00");

    switch (type) {
    case SegmentMode::DEAD:
    {
        break;
    }
    case SegmentMode::FORWARD:
    {
        ba.set(1);
        break;
    }
    case SegmentMode::REVERSE:
    {
        ba.set(0);
        break;
    }
    case SegmentMode::ILLEGAL:
    {
        ba.set();
        break;
    }
    default:
        throw std::runtime_error("Unknown segment mode seen");
    }

    return ba;
}


} //end of namespace Data

#endif // TYPE_SEGMENT_MODE_H
