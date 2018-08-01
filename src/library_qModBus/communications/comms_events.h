#ifndef COMMS_EVENTS_QMODBUS_H
#define COMMS_EVENTS_QMODBUS_H

#include <QByteArray>

#include <string>
#include "common/common.h"

#include "common/comms/communication_connection.h"
#include "common/comms/communication_update.h"

/**
\* @file  comms_events.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is interact with the sensoray.
\*
\* @section DESCRIPTION
\*
\*
\*/

namespace comms_QModBus{

class CommsEvents
{
public:

    /////////////////////////////////////////////////////////
    /// Link Events
    /////////////////////////////////////////////////////////

    //!
    //! \brief ConnectionStatusUpdated
    //! \param update
    //!
    virtual void ConnectionStatusUpdated(const common::comms::CommunicationUpdate &update) const
    {
        UNUSED(update);
    }

    //////////////////////////////////////////////////////////////
    /// IProtocolSensorayEvents
    //////////////////////////////////////////////////////////////

    //!
    //! \brief SerialPortStatusUpdate
    //! \param update
    //!
    virtual void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
    {
        UNUSED(update);
    }

    //!
    //! \brief NewDataReceived
    //! \param buffer
    //!
    virtual void NewDataReceived(const QByteArray &buffer) const
    {
        UNUSED(buffer);
    }

};

} //end of namespace comms_QModBus

#endif // COMMS_EVENTS_QMODBUS_H
