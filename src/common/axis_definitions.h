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

enum MotorAxis
{
    ALL = -1,
    X = 0,
    Y = 1,
    Z = 2
};

inline std::string AxisToString(const MotorAxis &axis) {
    switch (axis) {
    case MotorAxis::X:
        return "X";
    case MotorAxis::Y:
        return "Y";
    case MotorAxis::Z:
        return "Z";
    default:
        throw std::runtime_error("Unknown direction type seen");
    }
}

inline MotorAxis AxisFromString(const std::string &str)
{
    if(str == "X")
        return MotorAxis::X;
    else if(str == "Y")
        return MotorAxis::Y;
    else if(str == "Z")
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
