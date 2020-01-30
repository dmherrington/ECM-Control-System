#ifndef STATUS_AXIS_STATE_H
#define STATUS_AXIS_STATE_H

#include "common/data_get_set_notifier.h"
#include "common/axis_definitions.h"

#include "status_position.h"
#include "status_axis.h"
#include "status_motor.h"
#include "status_motor_fault.h"
#include "status_safety.h"

class Status_AxisState
{
public:
    Status_AxisState(const MotorAxis &axis = MotorAxis::Z);

    Status_AxisState(const Status_AxisState & copy);

    ~Status_AxisState() = default;

    MotorAxis getCurrentAxis() const
    {
        return currentAxis;
    }

    double getAxisPosition() const
    {
        return this->m_AxisPosition.get().getPosition();
    }

public:
    DataGetSetNotifier<Status_PositionPerAxis> m_AxisPosition; /**< Member variable containing the current positon relating
to this current objects axis. */

    DataGetSetNotifier<Status_PerAxis> m_AxisStatus; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */

    DataGetSetNotifier<Status_MotorPerAxis> m_MotorStatus; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */

    DataGetSetNotifier<Status_MotorAxisFault> m_MotorFault; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */

    DataGetSetNotifier<Status_AxisSafety> m_AxisSafety; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */

private:
    MotorAxis currentAxis;

};

#endif // STATUS_AXIS_STATE_H
