#include "request_custom_string.h"

RequestCustomString::RequestCustomString():
    AbstractRequest(RequestTypes::CUSTOM_STRING,500)
{

}

RequestCustomString::RequestCustomString(const RequestCustomString &copy):
    AbstractRequest(copy)
{

}

AbstractRequest* RequestCustomString::getClone() const
{
    return (new RequestCustomString(*this));
}

void RequestCustomString::getClone(AbstractRequest** state) const
{
    *state = new RequestCustomString(*this);
}

void RequestCustomString::setRequestString(const std::string &request)
{
    this->customRequestString = request;
}

std::string RequestCustomString::getRequestString() const
{
    std::string str = "";
    str += this->customRequestString;
    return str;
}

std::vector<AbstractStatusPtr> RequestCustomString::getStatus() const
{
    std::vector<AbstractStatusPtr> rtn;

    if(buffer.empty()) //in the event the buffer is empty, there is no status to even create
        return rtn;

    Status_CustomRequestPtr statusCustomRequest = std::make_shared<Status_CustomRequest>();
    statusCustomRequest->setResponseReceived(buffer);

    rtn.push_back(statusCustomRequest);

    return rtn;
}
