#ifndef STATUS_AXIS_STATE_H
#define STATUS_AXIS_STATE_H

#include "common/data_get_set_notifier.h"

#include "status_axis.h"
#include "status_motor.h"
#include "status_position.h"

class Status_AxisState
{
public:
    Status_AxisState();

    DataGetSetNotifier<SPII::Status_Axis> m_AxisStatus; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */

    DataGetSetNotifier<SPII::Status_Motor> m_MotorStatus; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */

    DataGetSetNotifier<SPII::Status_Position> m_AxisPosition;
};

#endif // STATUS_AXIS_STATE_H
