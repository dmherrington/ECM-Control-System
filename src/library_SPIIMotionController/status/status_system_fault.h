#ifndef STATUS_SYSTEM_FAULT_H
#define STATUS_SYSTEM_FAULT_H

#include "ACSC.h"

#include "common/class_forward.h"
#include "common/axis_definitions.h"

#include "abstract_status.h"

ECM_CLASS_FORWARD(Status_SystemFault);

class Status_SystemFault : public AbstractStatus
{
public:
    Status_SystemFault();

    Status_SystemFault(const Status_SystemFault &copy);

public:
    bool updateSystemFaultState(const int &value);

    bool doesSystemFaultExist() const;

    bool isProgramError() const;
    bool isMemoryOverflow() const;
    bool isMPUOveruse() const;
    bool isHardwareEmergencyStop() const;
    bool isServoInterrupt() const;
    bool isFileIntegrity() const;

private:
    Status_SystemFault& operator = (const Status_SystemFault &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->faultValue = rhs.faultValue;
        return *this;
    }

    bool operator == (const Status_SystemFault &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        return true;
    }

    bool operator != (const Status_SystemFault &rhs) {
        return !(*this == rhs);
    }

private:
    unsigned int faultValue = 0;
};

#endif // STATUS_SYSTEM_FAULT_H
