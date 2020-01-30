#ifndef STATUS_SAFETY_H
#define STATUS_SAFETY_H

#include "ACSC.h"

#include "common/class_forward.h"
#include "common/axis_definitions.h"
#include "common/data_get_set_notifier.h"

#include "abstract_status.h"

ECM_CLASS_FORWARD(Status_AxisSafety);

class Status_AxisSafety : public AbstractStatus
{
public:
    Status_AxisSafety();

    Status_AxisSafety(const Status_AxisSafety &copy);

public:
    void setAxis(const MotorAxis &axis);
    MotorAxis getAxis() const;

    void setErrorCode(const unsigned int &code, const std::string &errorString);
    void getErrorDetails(unsigned int &code, std::string &errorString) const;
    std::string getErrorString() const;
    unsigned int getErrorCode() const;

public:
    bool updateSafetyState(const unsigned int &value);

    bool doesSafetyFaultExist() const;

    bool isRightLimit() const;
    bool isLeftLimit() const;
    bool isRightLimit2() const;
    bool isLeftLimit2() const;
    bool isOverheated() const;
    bool isDriverAlarm() const;
    bool isHardwareEmergencyStop() const;

public:
    Status_AxisSafety& operator = (const Status_AxisSafety &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->safetyValue = rhs.safetyValue;
        this->currentAxis = rhs.currentAxis;
        this->errorCode = rhs.errorCode;
        this->errorString = rhs.errorString;
        return *this;
    }

    bool operator == (const Status_AxisSafety &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->currentAxis != rhs.currentAxis)
            return false;
        if(this->safetyValue != rhs.safetyValue)
            return false;
        if(this->errorCode != rhs.errorCode)
            return false;
        if(this->errorString != rhs.errorString)
            return false;
        return true;
    }

    bool operator != (const Status_AxisSafety &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    unsigned int safetyValue = 0;

    unsigned int errorCode = 0;
    std::string errorString = "";
};

ECM_CLASS_FORWARD(Status_Safety);
class Status_Safety : public AbstractStatus
{
public:
    Status_Safety();

    Status_Safety(const Status_Safety &copy);

    ~Status_Safety();

    bool updateAxisStatus(const std::vector<Status_AxisSafety> &status);

    Status_AxisSafety* getAxisStatus(const MotorAxis &axis);

public:
    Status_Safety& operator = (const Status_Safety &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->m_AxisSafety = rhs.m_AxisSafety;
        return *this;
    }

    bool operator == (const Status_Safety &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->m_AxisSafety != rhs.m_AxisSafety){
            return false;
        }
        return true;
    }

    bool operator != (const Status_Safety &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis, DataGetSetNotifier<Status_AxisSafety>*> m_AxisSafety;
};




#endif // STATUS_SAFETY_H
