#include "abstract_request.h"

AbstractRequest::AbstractRequest(const RequestTypes &type)
{
    this->requestType = type;
}
