#ifndef I_PROTOCOL_SENSORARY_EVENTS_H
#define I_PROTOCOL_SENSORARY_EVENTS_H

#include <string>
#include <memory>

#include "i_link.h"

#include "common/comms/communication_update.h"
#include "common/comms/communication_connection.h"

namespace sensoray {
namespace comms{

//!
//! \brief Interface that it to be implemented by users of rigol comms to listen for any events it fired
//!
class IProtocolSensorayEvents
{
public:
    virtual void SerialPortConnectionUpdate(const common::comms::CommunicationConnection &connection) const = 0;
    virtual void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const = 0;
    virtual void ResponseReceived(const QByteArray &buffer) const = 0;
};


} //end of namespace comms
} //end of namespace sensoray

#endif // I_PROTOCOL_SENSORARY_EVENTS_H
