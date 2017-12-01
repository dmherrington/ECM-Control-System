#ifndef TYPE_DIRECTION_H
#define TYPE_DIRECTION_H

#include <string>
#include <stdexcept>

enum class Direction{
    DIRECTION_UP = 0, /**< */
    DIRECION_DOWN= 1 /**< */
};

//!
//! \brief DirectionToString
//! \param type
//! \return
//!
inline std::string DirectionToString(const Direction &direction) {
    switch (direction) {
    case Direction::DIRECTION_UP:
        return "-";
    case Direction::DIRECION_DOWN:
        return "";
    default:
        throw std::runtime_error("Unknown direction type seen");
    }
}

//!
//! \brief DirectionFromString
//! \param str
//! \return
//!
inline Direction DirectionFromString(const std::string &str) {
    if(str == "-")
        return Direction::DIRECTION_UP;
    if(str == "")
        return Direction::DIRECION_DOWN;
    throw std::runtime_error("Unknown direction type seen");
}

#endif // TYPE_DIRECTION_H
