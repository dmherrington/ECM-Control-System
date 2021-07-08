#ifndef STATUS_MOTOR_FAULT_H
#define STATUS_MOTOR_FAULT_H

#include "ACSC.h"

#include "common/class_forward.h"
#include "common/axis_definitions.h"
#include "common/data_get_set_notifier.h"

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

    bool updateMotorFaultState(const unsigned int &value);

    bool doesMotorFaultExist() const;

    bool isHardwareEmergencyStop() const;
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
    void assembleFaultString();


public:
    void getErrorDetails(unsigned int &code, std::string &errorString) const;
    std::string getErrorString() const;
    unsigned int getErrorCode() const;

public:
    Status_MotorAxisFault& operator = (const Status_MotorAxisFault &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->faultValue = rhs.faultValue;
        this->errorString = rhs.errorString;
        return *this;
    }

    bool operator == (const Status_MotorAxisFault &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->faultValue != rhs.faultValue)
            return false;
        if(this->errorString != rhs.errorString)
            return false;
        return true;
    }

    bool operator != (const Status_MotorAxisFault &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    unsigned int faultValue = 0;
    std::string errorString = "";
};


ECM_CLASS_FORWARD(Status_MotorFault);
class Status_MotorFault : public AbstractStatus
{
public:
    Status_MotorFault();

    Status_MotorFault(const Status_MotorFault &copy);

    ~Status_MotorFault();

public:
    bool updateMotorAxisStatus(const std::vector<Status_MotorAxisFault> &status);

    Status_MotorAxisFault* getMotorAxisStatus(const MotorAxis &axis);

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
        if(this->m_MotorAxisFault != rhs.m_MotorAxisFault){
            return false;
        }
        return true;
    }

    bool operator != (const Status_MotorFault &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis, DataGetSetNotifier<Status_MotorAxisFault>*> m_MotorAxisFault;

};

#endif // STATUS_MOTOR_FAULT_H
