#ifndef STATUS_GENERIC_H
#define STATUS_GENERIC_H

#include <string.h>

#include "requests/request_types.h"

class StatusGeneric
{
public:
    StatusGeneric(const RequestTypes &type);

    void setRequestType(const RequestTypes &type);
    RequestTypes getRequestType() const;

    void setReceivedBuffer(const char* buf);
    std::string getReceivedBuffer() const;

private:
    RequestTypes requestType;
    std::string buffer;
};

#endif // STATUS_GENERIC_H
