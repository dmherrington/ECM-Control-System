#ifndef STATUS_STOP_CODE_H
#define STATUS_STOP_CODE_H


#include <map>

#include "common/environment_time.h"
#include <axis_definitions.h>

class Status_StopCode
{
public:
    Status_StopCode();

    void updateStopCode(const MotorAxis &axis, const uint8_t &pos);

    uint8_t getCurrentStopCode(const MotorAxis &axis);

private:
    std::map<MotorAxis,uint8_t> mapStopCode;
    Data::EnvironmentTime latestUpdate;

};

#endif // STATUS_STOP_CODE_H
