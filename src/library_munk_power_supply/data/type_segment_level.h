#ifndef TYPE_SEGMENT_LEVEL_H
#define TYPE_SEGMENT_LEVEL_H

#include <string>
#include <stdexcept>
#include <QBitArray>
#include <bitset>

namespace Data
{

enum class SegmentLevel{
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL4,
    LEVEL5,
    LEVEL6,
    LEVEL7,
    LEVEL8
};

inline std::string SegmentLevelToString(const SegmentLevel &type) {
    switch (type) {
    case SegmentLevel::LEVEL1:
        return "Level 1";
    case SegmentLevel::LEVEL2:
        return "Level 2";
    case SegmentLevel::LEVEL3:
        return "Level 3";
    case SegmentLevel::LEVEL4:
        return "Level 4";
    case SegmentLevel::LEVEL5:
        return "Level 5";
    case SegmentLevel::LEVEL6:
        return "Level 6";
    case SegmentLevel::LEVEL7:
        return "Level 7";
    case SegmentLevel::LEVEL8:
        return "Level 8";
    default:
        throw std::runtime_error("Unknown segment level seen");
    }
}

inline SegmentLevel SegmentLevelFromString(const std::string &str) {
    if(str == "Level 1")
        return SegmentLevel::LEVEL1;
    if(str == "Level 2")
        return SegmentLevel::LEVEL2;
    if(str == "Level 3")
        return SegmentLevel::LEVEL3;
    if(str == "Level 4")
        return SegmentLevel::LEVEL4;
    if(str == "Level 5")
        return SegmentLevel::LEVEL5;
    if(str == "Level 6")
        return SegmentLevel::LEVEL6;
    if(str == "Level 7")
        return SegmentLevel::LEVEL7;
    if(str == "Level 8")
        return SegmentLevel::LEVEL8;
    throw std::runtime_error("Unknown segment level seen");
}

inline std::bitset SegmentLevelBitArray(const SegmentLevel &str) {
    std::bitset<4>ba("0000");

    switch (type) {
    case SegmentLevel::LEVEL1:
    {
        break;
    }
    case SegmentLevel::LEVEL2:
    {
        ba.set(3);
        break;
    }
    case SegmentLevel::LEVEL3:
    {
        ba.set(2);
        break;
    }
    case SegmentLevel::LEVEL4:
    {
        ba.set(2);
        ba.set(3);
        break;
    }
    case SegmentLevel::LEVEL5:
    {
        ba.set(1);
        break;
    }
    case SegmentLevel::LEVEL6:
    {
        ba.set(1);
        ba.set(3);
        break;
    }
    case SegmentLevel::LEVEL7:
    {
        ba.set(1);
        ba.set(2);
        break;
    }
    case SegmentLevel::LEVEL8:
    {
        ba.set(1);
        ba.set(2);
        ba.set(3);
        break;
    }
    default:
        throw std::runtime_error("Unknown segment level seen");
    }

    return ba;
}

} //end of namespace Data

#endif // TYPE_SEGMENT_LEVEL_H
