#ifndef TYPE_SEGMENT_MODE_H
#define TYPE_SEGMENT_MODE_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk{

//!
//! \brief The SegmentMode enum
//!
enum class SegmentMode{
    DEAD = 0, /**< */
    FORWARD = 1, /**< */
    REVERSE = 2, /**< */
    ILLEGAL = 3, /**< */
    HIZ = 4 /**< */ //this is technically not correct as the mode is 0, however, we need a seperate definition. This will be type checked below.
};

//!
//! \brief SegmentModeToString
//! \param type
//! \return
//!
inline std::string SegmentModeToString(const SegmentMode &type) {
    switch (type) {
    case SegmentMode::HIZ:
        return "HIZ";
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

//!
//! \brief SegmentModeFromString
//! \param str
//! \return
//!
inline SegmentMode SegmentModeFromString(const std::string &str) {
    if(str == "HIZ")
        return SegmentMode::HIZ;
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

//!
//! \brief SegmentModeToBitArray
//! \param type
//! \param bitArray
//! \return
//!
inline uint32_t SegmentModeToBitArray(const SegmentMode &type, const uint32_t &bitArray) {
    uint32_t ba = 0;
    uint32_t mask = 3<<10;
    int tmpType = (int)type;

    if(type == SegmentMode::HIZ)
        tmpType = 0;

    ba = (bitArray & (~mask)) | (tmpType<<10);
    return ba;
}

//!
//! \brief getListOfSegmentMode
//! \return
//!
inline std::vector<std::string> getListOfSegmentMode()
{
    std::vector<std::string> str;
    str.push_back(data_Munk::SegmentModeToString(SegmentMode::DEAD));
    str.push_back(data_Munk::SegmentModeToString(SegmentMode::FORWARD));
    str.push_back(data_Munk::SegmentModeToString(SegmentMode::REVERSE));
    str.push_back(data_Munk::SegmentModeToString(SegmentMode::ILLEGAL));
    str.push_back(data_Munk::SegmentModeToString(SegmentMode::HIZ));
    return str;
}

} //end of namespace data_Munk


#endif // TYPE_SEGMENT_MODE_H
