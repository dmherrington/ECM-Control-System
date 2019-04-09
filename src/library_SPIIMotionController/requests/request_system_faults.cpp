#include "request_system_faults.h"

Request_SystemFaults::Request_SystemFaults():
    AbstractRequest(RequestTypes::TELL_SYSTEM_FAULTS,500)
{

}

Request_SystemFaults::Request_SystemFaults(const Request_SystemFaults &copy):
    AbstractRequest(copy)
{

}

AbstractRequest* Request_SystemFaults::getClone() const
{
    return (new Request_SystemFaults(*this));
}

void Request_SystemFaults::getClone(AbstractRequest** state) const
{
    *state = new Request_SystemFaults(*this);
}
