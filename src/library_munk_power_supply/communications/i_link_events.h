#ifndef I_LINK_EVENTS_MUNK_H
#define I_LINK_EVENTS_MUNK_H

#include <cstdlib>
#include <vector>
#include <string>


namespace comms_Munk{

class ILink;

class ILinkEvents
{
public:

    virtual void ConnectionOpened() const = 0;

    virtual void ConnectionClosed() const = 0;

    virtual void ReceiveData(const std::vector<uint8_t> &buffer) const = 0;

    virtual void CommunicationError(const std::string &type, const std::string &msg) const = 0;

    virtual void CommunicationUpdate(const std::string &name, const std::string &msg) const = 0;
};

} //end of namespace comms_Munk


#endif // I_LINK_EVENTS_MUNK_H
