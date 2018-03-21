#include "abstract_rigol_status.h"


namespace commands_Rigol {


AbstractRigolStatus::AbstractRigolStatus(const CommandTypes &type):
    commandType(type)
{
    this->requestTime.CurrentTime(common::Devices::SYSTEMCLOCK,this->requestTime);
    this->measurementTime.CurrentTime(common::Devices::SYSTEMCLOCK,this->measurementTime);
}

AbstractRigolStatus::AbstractRigolStatus(const AbstractRigolStatus &copy)
{
    this->commandType = copy.commandType;
    this->measurementTime = copy.measurementTime;
    this->receivedTime = copy.receivedTime;
    this->requestTime = copy.requestTime;
}

void AbstractRigolStatus::setCommandType(const CommandTypes &type)
{
    this->commandType = type;
}

CommandTypes AbstractRigolStatus::getCommandType() const
{
    return this->commandType;
}

void AbstractRigolStatus::updateMeasurementTime()
{
    this->measurementTime.CurrentTime(common::Devices::SYSTEMCLOCK,this->measurementTime);
}

common::EnvironmentTime AbstractRigolStatus::getMeasurementTime() const
{
    return this->measurementTime;
}

void AbstractRigolStatus::updateReceivedTime()
{
    this->receivedTime.CurrentTime(common::Devices::SYSTEMCLOCK,this->receivedTime);
}

common::EnvironmentTime AbstractRigolStatus::getReceivedTime() const
{
    return this->receivedTime;
}

common::EnvironmentTime AbstractRigolStatus::getRequestTime() const
{
    return this->requestTime;
}

} //end of namespace commands

