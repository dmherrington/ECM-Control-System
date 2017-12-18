#ifndef STATUS_POSITION_H
#define STATUS_POSITION_H

#include <map>

#include "common/environment_time.h"
#include <axis_definitions.h>

class Status_Position
{
public:
    Status_Position();

    void updatePosition(const MotorAxis &axis, const uint64_t &pos);

    uint64_t getPositionCount(const MotorAxis &axis);

private:
    std::map<MotorAxis,uint64_t> mapPos;
    Data::EnvironmentTime latestUpdate;

};

#endif // STATUS_POSITION_H
