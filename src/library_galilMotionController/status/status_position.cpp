#include "status_position.h"

Status_Position::Status_Position()
{
    mapPos = {{MotorAxis::X,0},{MotorAxis::Y,0},{MotorAxis::Z,0},};
}

void Status_Position::updatePosition(const MotorAxis &axis, const uint64_t &pos)
{
    mapPos[axis] = pos;
}

uint64_t Status_Position::getPositionCount(const MotorAxis &axis)
{
    return mapPos.at(axis);
}

