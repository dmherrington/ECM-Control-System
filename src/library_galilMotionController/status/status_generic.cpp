#include "status_generic.h"

StatusGeneric::StatusGeneric(const RequestTypes &type):
    requestType(type)
{
    this->buffer = "";
}

void StatusGeneric::setRequestType(const RequestTypes &type)
{
    this->requestType = type;
}

RequestTypes StatusGeneric::getRequestType() const
{
    return this->requestType;
}

void StatusGeneric::setReceivedBuffer(const char* buf)
{
    this->buffer = buf;
}

std::string StatusGeneric::getReceivedBuffer() const
{
    return this->buffer;
}
