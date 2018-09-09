#include "status_custom_request.h"

Status_CustomRequest::Status_CustomRequest():
    AbstractStatus(StatusTypes::STATUS_CUSTOM_REQUEST)
{

}

Status_CustomRequest::Status_CustomRequest(const Status_CustomRequest &copy):
    AbstractStatus(copy)
{
    this->response = copy.response;
}

void Status_CustomRequest::setResponseReceived(const std::string &response)
{
    this->response = response;
}

std::string Status_CustomRequest::getResponseReceived() const
{
    return this->response;
}

