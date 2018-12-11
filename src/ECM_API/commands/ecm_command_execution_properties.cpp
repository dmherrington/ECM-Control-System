#include "ecm_command_execution_properties.h"

ExecutionTimeProperties::ExecutionTimeProperties(const ExecutionTimeProperties &copy)
{
    this->m_startTime = copy.m_startTime;
    this->m_endTime = copy.m_endTime;
}

void ExecutionTimeProperties::establishStartTime()
{
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,this->m_startTime);
}

void ExecutionTimeProperties::establishEndTime()
{
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,this->m_endTime);
}

void ExecutionTimeProperties::setStartTime(const EnvironmentTime &start)
{
    this->m_startTime = start;
}
void ExecutionTimeProperties::setEndTime(const EnvironmentTime &end)
{
    this->m_endTime = end;
}

EnvironmentTime ExecutionTimeProperties::getStartTime() const
{
    return this->m_startTime;
}
EnvironmentTime ExecutionTimeProperties::getEndTime() const
{
    return this->m_endTime;
}
double ExecutionTimeProperties::getElapsedTime()
{
    uint64_t microseconds = this->m_endTime - this->m_startTime;
    return static_cast<double>(microseconds / (1000.0 * 1000.0));
}




ECMCommand_ExecutionProperties::ECMCommand_ExecutionProperties():
    ExecutionTimeProperties()
{

}

ECMCommand_ExecutionProperties::ECMCommand_ExecutionProperties(const ECMCommand_ExecutionProperties &copy):
    ExecutionTimeProperties(copy)
{
    this->executed = copy.executed;
    this->profileCode = copy.profileCode;
}

void ECMCommand_ExecutionProperties::initializeExecution()
{
    setHasProfileExecuted(true);
    establishStartTime();
}

void ECMCommand_ExecutionProperties::completeExecution()
{
    establishEndTime();
}

void ECMCommand_ExecutionProperties::setHasProfileExecuted(const bool &executed)
{
    this->executed = executed;
}

void ECMCommand_ExecutionProperties::setProfileCode(const ProfileState_Machining::MACHININGProfileCodes &code)
{
    this->profileCode = code;
}

bool ECMCommand_ExecutionProperties::hasProfileBeenExecuted() const
{
    return this->executed;
}
bool ECMCommand_ExecutionProperties::hasProfileBeenCompleted() const
{
    if(profileCode == ProfileState_Machining::MACHININGProfileCodes::INCOMPLETE)
        return false;
    return true;
}

ProfileState_Machining::MACHININGProfileCodes ECMCommand_ExecutionProperties::getProfileCode() const
{
    return this->profileCode;
}
