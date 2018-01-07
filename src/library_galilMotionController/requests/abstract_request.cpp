#include "abstract_request.h"

AbstractRequest::AbstractRequest(const RequestTypes &type, const unsigned int &respSize)
{
    this->requestType = type;
    this->bufferSize = respSize;
}


void AbstractRequest::setBufferSize(const unsigned int &size)
{
    this->bufferSize = size;
}

unsigned int AbstractRequest::getAllocatedBufferSize() const
{
    return this->bufferSize;
}

char* AbstractRequest::getBuffer() const
{
    char str[this->bufferSize];
    return str;
    //strcpy(chrArray,str);
}

void AbstractRequest::increaseBufferSize(char* chrArray)
{
    bufferSize+=bufferSize;
    this->getBuffer(chrArray);
}
