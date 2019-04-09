#ifndef STATUS_MOTOR_FAULT_H
#define STATUS_MOTOR_FAULT_H

#include "ACSC.h"

#include "common/class_forward.h"
#include "common/axis_definitions.h"

#include "abstract_status.h"

ECM_CLASS_FORWARD(Status_MotorAxisFault);

class Status_MotorAxisFault : public AbstractStatus
{
public:
    Status_MotorAxisFault();

    Status_MotorAxisFault(const Status_MotorAxisFault &copy);

public:
    void setAxis(const MotorAxis &axis);
    MotorAxis getAxis() const;

    bool updateMotorFaultState(const int &value);

    bool doesMotorFaultExist() const;

    bool isRightLimit() const;
    bool isLeftLimit() const;
    bool isNetworkError() const;
    bool isOverheated() const;
    bool isSWRightLimit() const;
    bool isSWLeftLimit() const;
    bool isPrimaryEncoderConnected() const;
    bool isSecondaryEncoderConnected() const;
    bool isDriverAlarm() const;
    bool isPrimaryEncoderError() const;
    bool isSecondaryEncoderError() const;
    bool isPositionError() const;
    bool isCriticalPositionError() const;
    bool isVelocityLimit() const;
    bool isAccelerationLimit() const;
    bool isCurrentLimit() const;
    bool isServoProcessorAlarm() const;

private:
    Status_MotorAxisFault& operator = (const Status_MotorAxisFault &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->faultValue = rhs.faultValue;
        return *this;
    }

    bool operator == (const Status_MotorAxisFault &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        return true;
    }

    bool operator != (const Status_MotorAxisFault &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    unsigned int faultValue = 0;
};

ECM_CLASS_FORWARD(Status_MotorFault);
class Status_MotorFault : public AbstractStatus
{
public:
    Status_MotorFault();

    Status_MotorFault(const Status_MotorFault &copy);

    ~Status_MotorFault();

public:
    Status_MotorFault& operator = (const Status_MotorFault &rhs)
    {
        AbstractStatus::operator =(rhs);
        return *this;
    }

    bool operator == (const Status_MotorFault &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        return true;
    }

    bool operator != (const Status_MotorFault &rhs) {
        return !(*this == rhs);
    }

private:

};

#endif // STATUS_MOTOR_FAULT_H
