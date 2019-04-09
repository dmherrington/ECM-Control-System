#include "status_system_fault.h"

Status_SystemFault::Status_SystemFault():
    AbstractStatus(StatusTypes::STATUS_SYSTEM_FAULTS)
{

}

Status_SystemFault::Status_SystemFault(const Status_SystemFault &copy):
    AbstractStatus(copy)
{
    faultValue = copy.faultValue;
}

bool Status_SystemFault::updateSystemFaultState(const int &value)
{
    if(this->faultValue != value)
    {
        this->faultValue = value;
        return true;
    }
    return false;
}

bool Status_SystemFault::doesSystemFaultExist() const
{
    if(faultValue != 0)
        return true;
    return false;
}

bool Status_SystemFault::isProgramError() const
{
    return faultValue & ACSC_SAFETY_PROG;
}
bool Status_SystemFault::isMemoryOverflow() const
{
    return faultValue &ACSC_SAFETY_MEM;
}
bool Status_SystemFault::isMPUOveruse() const
{
    return faultValue & ACSC_SAFETY_TIME;
}
bool Status_SystemFault::isHardwareEmergencyStop() const
{
    return faultValue & ACSC_SAFETY_ES;
}
bool Status_SystemFault::isServoInterrupt() const
{
    return faultValue & ACSC_SAFETY_INT;
}
bool Status_SystemFault::isFileIntegrity() const
{
    return faultValue & ACSC_SAFETY_INTGR;
}
