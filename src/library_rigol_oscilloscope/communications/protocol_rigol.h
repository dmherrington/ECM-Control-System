#ifndef PROTOCOL_RIGOL_H
#define PROTOCOL_RIGOL_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>
#include <list>

#include "iostream"

#include "i_link.h"
#include "i_protocol_rigol_events.h"
#include "i_protocol.h"

#include "common/common.h"

#include "commands/acquire/acquire_components.h"

#include "commands/measure/measure_command_item.h"
#include "commands/measure/rigol_measurement_status.h"

namespace comms_Rigol{

class RigolProtocol : public IProtocol
{

public:
    RigolProtocol();

    void AddListner(const IProtocolRigolEvents* listener);

public:
    //////////////////////////////////////////////////////////////
    /// Method issuing a measurement request to the rigol
    //////////////////////////////////////////////////////////////

    void sendSetAcquisitionCommand(const ILink *link, const commands_Rigol::AbstractAcquireCommandPtr command);

    void sendSetMeasurementCommand(const ILink *link, const commands_Rigol::MeasureCommand_Item &command);

    void sendMeasurementRequest(const ILink *link, const commands_Rigol::MeasureCommand_Item &command);
public:

    //!
    //! \brief Read data incoming from some link
    //!
    //! This code is largely a copy from MAVLinkProtocol::receiveBytes in qgroundcontrol
    //! \param link Link which data was read from
    //! \param buffer data that was read.
    //!
    void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) override;

private:

    void Emit(const std::function<void(const IProtocolRigolEvents*)> func)
    {
        for(const IProtocolRigolEvents* listener : m_Listners)
            func(listener);
    }

private:
    std::vector<const IProtocolRigolEvents*> m_Listners;

private:
    std::list<commands_Rigol::AbstractRigolStatus*> responseQueue;


};


} //end of namespace comms


#endif // PROTOCOL_RIGOL_H
