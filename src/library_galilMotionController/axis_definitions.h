#ifndef AXIS_DEFINITIONS_H
#define AXIS_DEFINITIONS_H

#include <string>
#include <stdexcept>

enum class MotorAxis
{
    ALL = 0,
    X = 1,
    Y = 2,
    Z = 3
};

inline std::string AxisToString(const MotorAxis &axis) {
    switch (axis) {
    case MotorAxis::Z:
        return "A";
    default:
        throw std::runtime_error("Unknown direction type seen");
    }
}

#endif // AXIS_DEFINITIONS_H
