#ifndef I_PROTOCOL_SENSORARY_EVENTS_H
#define I_PROTOCOL_SENSORARY_EVENTS_H

#include <string>
#include <memory>

#include "i_link.h"

namespace sensoray {
namespace comms{

//!
//! \brief Interface that it to be implemented by users of rigol comms to listen for any events it fired
//!
class IProtocolSensorayEvents
{
public:
    virtual void ResponseReceived(const QByteArray &buffer) const = 0;
};


} //end of namespace comms
} //end of namespace sensoray

#endif // I_PROTOCOL_SENSORARY_EVENTS_H
