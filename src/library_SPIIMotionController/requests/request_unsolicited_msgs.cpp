#include "request_unsolicited_msgs.h"

Request_UnsolicitedMsgs::Request_UnsolicitedMsgs():
    AbstractRequest(RequestTypes::UNSOLICITED_MSGS,100)
{

}

Request_UnsolicitedMsgs::Request_UnsolicitedMsgs(const Request_UnsolicitedMsgs &copy):
    AbstractRequest(copy)
{

}

AbstractRequest* Request_UnsolicitedMsgs::getClone() const
{
    return (new Request_UnsolicitedMsgs(*this));
}

void Request_UnsolicitedMsgs::getClone(AbstractRequest** state) const
{
    *state = new Request_UnsolicitedMsgs(*this);
}
