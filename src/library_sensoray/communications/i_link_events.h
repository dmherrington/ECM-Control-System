#ifndef I_LINK_EVENTS_SENSORAY_H
#define I_LINK_EVENTS_SENSORAY_H

#include <cstdlib>
#include <vector>
#include <string>

namespace comms_Sensoray{

class ILink;

class ILinkEvents
{
public:

    virtual void ConnectionOpened() const = 0;

    virtual void ConnectionClosed() const = 0;

    virtual void CommunicationError(const std::string &type, const std::string &msg) const = 0;

    virtual void CommunicationUpdate(const std::string &name, const std::string &msg) const = 0;
};

} //end of namespace comms

#endif // I_LINK_EVENTS_SENSORAY_H
