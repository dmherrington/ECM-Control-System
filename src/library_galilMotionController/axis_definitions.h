#ifndef AXIS_DEFINITIONS_H
#define AXIS_DEFINITIONS_H

#include <string>
#include <stdexcept>
#include <vector>

/**
\* @file  axis_definitions.h
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

enum class MotorAxis
{
    ALL = 0,
    X = 1,
    Y = 2,
    Z = 3
};

inline std::string AxisToString(const MotorAxis &axis) {
    switch (axis) {
    case MotorAxis::X:
        return "C";
    case MotorAxis::Y:
        return "B";
    case MotorAxis::Z:
        return "A";
    default:
        throw std::runtime_error("Unknown direction type seen");
    }
}

inline MotorAxis AxisFromString(const std::string &str)
{
    if(str == "C")
        return MotorAxis::X;
    else if(str == "B")
        return MotorAxis::Y;
    else if(str == "A")
        return MotorAxis::Z;
    else
        throw std::runtime_error("Unknown axis string seen");
}

inline std::vector<MotorAxis> GetAxisVector()
{
    std::vector<MotorAxis> vec;
    vec.push_back((MotorAxis::X));
    vec.push_back((MotorAxis::Y));
    vec.push_back((MotorAxis::Z));
    return vec;
}

inline std::vector<std::string> GetAxisStringVector()
{
    std::vector<std::string> str;
    str.push_back(AxisToString(MotorAxis::X));
    str.push_back(AxisToString(MotorAxis::Y));
    str.push_back(AxisToString(MotorAxis::Z));
    return str;
}

#endif // AXIS_DEFINITIONS_H
