#ifndef GALIL_STATUS_H
#define GALIL_STATUS_H

#include <string>
#include <map>
#include <vector>

#include "axis_definitions.h"

#include "common/data_get_set_notifier.h"

#include "status/status_position.h"

class GalilStatus
{
public:
    GalilStatus(const MotorAxis &axis);

public:
    void setPosition(const Status_Position &pos);

    bool setMotorEnabled(const bool &isRunning);

    bool setMotorMoving(const bool &isMoving);

public:
    bool isMotorEnabled() const;

    bool isAxisinMotion() const;

    Status_Position getPosition() const;


public:
    MotorAxis currentAxis;

    DataGetSetNotifier<bool> motorRunning;
    DataGetSetNotifier<bool> axisMoving;

    DataGetSetNotifier<Status_Position> position;
};

#endif // GALIL_STATUS_H
