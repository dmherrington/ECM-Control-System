#ifndef COMMS_EVENTS_H
#define COMMS_EVENTS_H

#include <string>
#include "common/common.h"
#include "commands/measure/rigol_measurement_status.h"


namespace comms_Rigol{

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

    virtual void NewMeasurementUpdate()
    {

    }

    virtual void NewDataReceived(const std::vector<uint8_t> &buffer) const
    {
        UNUSED(buffer);
    }

    virtual void NewMeaurementReceived(const commands_Rigol::RigolMeasurementStatus &status) const
    {
        UNUSED(status);
    }



};

} //end of namespace comms


#endif // COMMS_EVENTS_H
