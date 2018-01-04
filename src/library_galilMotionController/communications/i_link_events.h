#ifndef I_LINK_EVENTS_H
#define I_LINK_EVENTS_H

namespace Comms
{

class ILinkEvents
{
public:
    virtual void ConnectionOpened() const = 0;

    virtual void ConnectionClosed() const = 0;
};

} //END Comms

#endif // I_LINK_EVENTS_H
