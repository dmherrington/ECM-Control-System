#ifndef COMMS_EVENTS_H
#define COMMS_EVENTS_H

#include <string>

namespace Comms
{

class CommsEvents
{
public:

    /////////////////////////////////////////////////////////
    /// Link Events
    /////////////////////////////////////////////////////////


    virtual void LinkCommunicationError(const std::string &linkName, const std::string &type, const std::string &msg) const
    {
        UNUSED(linkName);
        UNUSED(type);
        UNUSED(msg);
    }

    virtual void LinkCommunicationUpdate(const std::string &linkName, const std::string &name, const std::string &msg) const
    {
        UNUSED(linkName);
        UNUSED(name);
        UNUSED(msg);
    }

    virtual void LinkConnected(const std::string &linkName) const
    {
        UNUSED(linkName);
    }

    virtual void LinkConnectionRemoved(const std::string &linkName) const
    {
        UNUSED(linkName);
    }

    virtual void StatusMessage(const std::string &linkName, const std::string &msg)
    {
        UNUSED(linkName);
        UNUSED(msg);
    }

};

}

#endif // COMMS_EVENTS_H
