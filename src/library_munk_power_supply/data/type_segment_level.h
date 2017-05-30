#ifndef TYPE_SEGMENT_LEVEL_H
#define TYPE_SEGMENT_LEVEL_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

enum class SegmentLevel{
    LEVEL1 = 0,
    LEVEL2 = 1,
    LEVEL3 = 2,
    LEVEL4 = 3,
    LEVEL5 = 4,
    LEVEL6 = 5,
    LEVEL7 = 6,
    LEVEL8 = 7
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

inline std::vector<std::string> getListOfSegmentLevel()
{
    std::vector<std::string> str;
    str.push_back(Data::SegmentLevelToString(SegmentLevel::LEVEL1));
    str.push_back(Data::SegmentLevelToString(SegmentLevel::LEVEL2));
    str.push_back(Data::SegmentLevelToString(SegmentLevel::LEVEL3));
    str.push_back(Data::SegmentLevelToString(SegmentLevel::LEVEL4));
    str.push_back(Data::SegmentLevelToString(SegmentLevel::LEVEL5));
    str.push_back(Data::SegmentLevelToString(SegmentLevel::LEVEL6));
    str.push_back(Data::SegmentLevelToString(SegmentLevel::LEVEL7));
    str.push_back(Data::SegmentLevelToString(SegmentLevel::LEVEL8));
    return str;
}

inline uint32_t SegmentLevelToBitArray(const SegmentLevel &type, const uint32_t &bitArray) {
    uint32_t ba = 0;
    uint32_t mask = 15<<12;
    ba = (bitArray & (~mask)) | ((int)type<<12);
    return ba;
}

} //end of namespace Data

#endif // TYPE_SEGMENT_LEVEL_H
