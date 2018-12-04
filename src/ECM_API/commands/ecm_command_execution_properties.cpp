#include "ecm_command_execution_properties.h"

ECMCommand_ExecutionProperties::ECMCommand_ExecutionProperties()
{

}

ECMCommand_ExecutionProperties::ECMCommand_ExecutionProperties(const ECMCommand_ExecutionProperties &copy)
{
    this->completed = copy.completed;
    this->executed = copy.executed;
    this->m_endTime = copy.m_endTime;
    this->m_startTime =copy.m_startTime;
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

void ECMCommand_ExecutionProperties::establishStartTime()
{
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,m_startTime);
}

void ECMCommand_ExecutionProperties::establishEndTime()
{
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,m_endTime);
}

void ECMCommand_ExecutionProperties::setHasProfileExecuted(const bool &executed)
{
    this->executed = executed;
}
void ECMCommand_ExecutionProperties::setStartTime(const EnvironmentTime &start)
{
    this->m_startTime = start;
}
void ECMCommand_ExecutionProperties::setEndTime(const EnvironmentTime &end)
{
    this->m_endTime = end;
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
EnvironmentTime ECMCommand_ExecutionProperties::getStartTime() const
{
    return this->m_startTime;
}
EnvironmentTime ECMCommand_ExecutionProperties::getEndTime() const
{
    return this->m_endTime;
}
double ECMCommand_ExecutionProperties::getElapsedTime()
{
    uint64_t microseconds = this->m_endTime - this->m_startTime;
    return static_cast<double>(microseconds / (1000.0 * 1000.0));
}

ProfileState_Machining::MACHININGProfileCodes ECMCommand_ExecutionProperties::getProfileCode() const
{
    return this->profileCode;
}
