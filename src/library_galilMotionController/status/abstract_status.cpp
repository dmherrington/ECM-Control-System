#include "abstract_status.h"

AbstractStatus::AbstractStatus(const StatusTypes &type):
    statusType(type)
{
    this->latestUpdate.CurrentTime(common::Devices::SYSTEMCLOCK,this->latestUpdate);
}

AbstractStatus::AbstractStatus(const AbstractStatus &copy)
{
    this->statusType = copy.statusType;
    this->latestUpdate = copy.latestUpdate;
}

void AbstractStatus::setStatusType(const StatusTypes &type)
{
    this->statusType = type;
}

StatusTypes AbstractStatus::getStatusType() const
{
    return this->statusType;
}

void AbstractStatus::setTime(const common::EnvironmentTime &time)
{
    this->latestUpdate = time;
}

common::EnvironmentTime AbstractStatus::getTime() const
{
    return this->latestUpdate;
}
