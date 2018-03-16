#ifndef COMMS_EVENTS_SENSORAY_H
#define COMMS_EVENTS_SENSORAY_H

#include <QByteArray>

#include <string>
#include "common/common.h"

#include "common/comms/communication_connection.h"
#include "common/comms/communication_update.h"

namespace comms_Sensoray{

class CommsEvents
{
public:

    /////////////////////////////////////////////////////////
    /// Link Events
    /////////////////////////////////////////////////////////

    virtual void ConnectionOpened() const
    {

    }

    virtual void ConnectionClosed() const
    {

    }

    virtual void CommunicationError(const std::string &type, const std::string &msg) const
    {
        UNUSED(type);
        UNUSED(msg);
    }

    virtual void CommunicationUpdate(const std::string &name, const std::string &msg) const
    {
        UNUSED(name);
        UNUSED(msg);
    }

    virtual void NewDataReceived(const QByteArray &buffer) const
    {
        UNUSED(buffer);
    }

    virtual void SerialPortConnection(const common::comms::CommunicationConnection &connection) const
    {
        UNUSED(connection);
    }

    virtual void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
    {
        UNUSED(update);
    }


};

} //end of namespace comms

#endif // COMMS_EVENTS_SENSORAY_H
