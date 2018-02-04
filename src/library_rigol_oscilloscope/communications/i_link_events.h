#ifndef I_LINK_EVENTS_H
#define I_LINK_EVENTS_H

#include <cstdlib>
#include <vector>
#include <string>

namespace rigol {
namespace comms{

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

} //end of namespace comms
} //end of namespace rigol

#endif // I_LINK_EVENTS_H