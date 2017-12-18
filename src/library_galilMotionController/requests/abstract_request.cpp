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

void AbstractRequest::getBuffer(char *chrArray) const
{
    char str[this->bufferSize];
    strcpy(chrArray,str);
}

void AbstractRequest::increaseBufferSize(char* chrArray)
{
    bufferSize+=bufferSize;
}

void AbstractRequest::receivedResponse(const char* chrArray)
{
    //by default the abstract class says that we do nothing with the response
}
