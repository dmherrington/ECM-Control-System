#include "abstract_status.h"

AbstractStatus::AbstractStatus(const RequestTypes &type):
    requestType(type)
{

}

AbstractStatus::AbstractStatus(const AbstractStatus &copy)
{
    this->requestType = copy.requestType;
}

void AbstractStatus::setRequestType(const RequestTypes &type)
{
    this->requestType = type;
}

RequestTypes AbstractStatus::getRequestType() const
{
    return this->requestType;
}

