#include "abstract_request.h"

AbstractRequest::AbstractRequest(const RequestTypes &type, const unsigned int &respSize)
{
    this->requestType = type;
    this->bufferSize = respSize;
}

AbstractRequest::AbstractRequest(const AbstractRequest &copy)
{
    this->descriptor = copy.descriptor;
    this->requestType = copy.requestType;
    this->bufferSize = copy.bufferSize;
    this->buffer =copy.buffer;
    this->latestUpdate = copy.latestUpdate;
}

void AbstractRequest::setTupleDescription(const common::TupleECMData &tuple)
{
    this->descriptor = tuple;
}

common::TupleECMData AbstractRequest::getTupleDescription() const
{
    return this->descriptor;
}


void AbstractRequest::setBufferSize(const unsigned int &size)
{
    this->bufferSize = size;
}

unsigned int AbstractRequest::getAllocatedBufferSize() const
{
    return this->bufferSize;
}

std::string AbstractRequest::getBuffer()
{
//    char str[this->bufferSize];
//    *buffer = &str;
    return buffer;
    //strcpy(chrArray,str);
}

void AbstractRequest::increaseBufferSize()
{
    bufferSize+=bufferSize;
}
