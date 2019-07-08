#ifndef STATUS_CUSTOM_REQUEST_H
#define STATUS_CUSTOM_REQUEST_H

#include "status/abstract_status.h"
#include "common/class_forward.h"

ECM_CLASS_FORWARD(Status_CustomRequest);

class Status_CustomRequest : public AbstractStatus
{
public:
    Status_CustomRequest();

    Status_CustomRequest(const Status_CustomRequest &copy);

public:
    void setResponseReceived(const std::string &response);

    std::string getResponseReceived() const;

public:
    Status_CustomRequest& operator = (const Status_CustomRequest &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->response = rhs.response;
        return *this;
    }

    bool operator == (const Status_CustomRequest &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->response != rhs.response){
            return false;
        }
        return true;
    }

    bool operator != (const Status_CustomRequest &rhs) {
        return !(*this == rhs);
    }

private:
    std::string response = "";
};

#endif // STATUS_CUSTOM_REQUEST_H
