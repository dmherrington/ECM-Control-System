#ifndef TYPE_DIRECTION_H
#define TYPE_DIRECTION_H

#include <string>
#include <stdexcept>

/**
\* @file  type_direction.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

enum class Direction{
    DIRECTION_INCREASE = 0, /**< */
    DIRECTION_DECREASE = 1 /**< */
};

inline int DirectionToSign(const Direction &direction)
{
    switch (direction) {
    case Direction::DIRECTION_INCREASE:
        return -1;
    case Direction::DIRECTION_DECREASE:
        return 1;
    default:
        throw std::runtime_error("Unknown direction type seen");
    }
}

//!
//! \brief DirectionToString
//! \param type
//! \return
//!
inline std::string DirectionToString(const Direction &direction) {

    int signValue = DirectionToSign(direction);
    if(signValue < 0)
        return "-";
    else
        return "";
}

//!
//! \brief DirectionFromString
//! \param str
//! \return
//!
inline Direction DirectionFromString(const std::string &str) {
    if(str == "-")
        return Direction::DIRECTION_DECREASE;
    if(str == "")
        return Direction::DIRECTION_INCREASE;
    throw std::runtime_error("Unknown direction type seen");
}

#endif // TYPE_DIRECTION_H
