#include "status_motor_fault.h"

Status_MotorAxisFault::Status_MotorAxisFault():
    AbstractStatus(StatusTypes::STATUS_MOTOR_FAULTS_PER_AXIS)
{

}

Status_MotorAxisFault::Status_MotorAxisFault(const Status_MotorAxisFault &copy):
    AbstractStatus(copy)
{
    currentAxis = copy.currentAxis;
    faultValue = copy.faultValue;
}

void Status_MotorAxisFault::setAxis(const MotorAxis &axis)
{
    currentAxis = axis;
}

MotorAxis Status_MotorAxisFault::getAxis() const
{
    return this->currentAxis;
}

bool Status_MotorAxisFault::updateMotorFaultState(const int &value)
{
    if(this->faultValue != value)
    {
        this->faultValue = value;
        return true;
    }
    return false;
}

bool Status_MotorAxisFault::doesMotorFaultExist() const
{
    if(faultValue != 0)
        return true;
    return false;
}

bool Status_MotorAxisFault::isRightLimit() const
{
    return faultValue & ACSC_SAFETY_RL;
}
bool Status_MotorAxisFault::isLeftLimit() const
{
    return faultValue &ACSC_SAFETY_LL;
}
bool Status_MotorAxisFault::isNetworkError() const
{
    return faultValue & ACSC_SAFETY_NETWORK;
}
bool Status_MotorAxisFault::isOverheated() const
{
    return faultValue & ACSC_SAFETY_HOT;
}
bool Status_MotorAxisFault::isSWRightLimit() const
{
    return faultValue & ACSC_SAFETY_SRL;
}
bool Status_MotorAxisFault::isSWLeftLimit() const
{
    return faultValue & ACSC_SAFETY_SLL;
}
bool Status_MotorAxisFault::isPrimaryEncoderConnected() const
{
    return faultValue & ACSC_SAFETY_ENCNC;
}
bool Status_MotorAxisFault::isSecondaryEncoderConnected() const
{
    return faultValue & ACSC_SAFETY_ENC2NC;
}
bool Status_MotorAxisFault::isDriverAlarm() const
{
    return faultValue & ACSC_SAFETY_DRIVE;
}
bool Status_MotorAxisFault::isPrimaryEncoderError() const
{
    return faultValue & ACSC_SAFETY_ENC;
}
bool Status_MotorAxisFault::isSecondaryEncoderError() const
{
    return faultValue & ACSC_SAFETY_ENC2;
}
bool Status_MotorAxisFault::isPositionError() const
{
    return faultValue & ACSC_SAFETY_PE;
}
bool Status_MotorAxisFault::isCriticalPositionError() const
{
    return faultValue & ACSC_SAFETY_CPE;
}
bool Status_MotorAxisFault::isVelocityLimit() const
{
    return faultValue & ACSC_SAFETY_VL;
}
bool Status_MotorAxisFault::isAccelerationLimit() const
{
    return faultValue & ACSC_SAFETY_AL;
}
bool Status_MotorAxisFault::isCurrentLimit() const
{
    return faultValue & ACSC_SAFETY_CL;
}
bool Status_MotorAxisFault::isServoProcessorAlarm() const
{
    return faultValue & ACSC_SAFETY_SP;
}
