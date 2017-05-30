#ifndef TYPE_SEGMENT_MODE_H
#define TYPE_SEGMENT_MODE_H

#include <string>
#include <stdexcept>
#include <bitset>

namespace Data
{

enum class SegmentMode{
    DEAD = 0,
    FORWARD = 1,
    REVERSE = 2,
    ILLEGAL = 3
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


inline uint32_t SegmentModeToBitArray(const SegmentMode &type, const uint32_t &bitArray) {
    uint32_t ba = 0;
    uint32_t mask = 3<<10;
    ba = (bitArray & (~mask)) | ((int)type<<10);
    return ba;
}

} //end of namespace Data

#endif // TYPE_SEGMENT_MODE_H
