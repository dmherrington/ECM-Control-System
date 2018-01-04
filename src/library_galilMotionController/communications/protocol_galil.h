#ifndef MAVLINK_COMMS_H
#define MAVLINK_COMMS_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>

#include "i_link.h"
#include "i_protocol_galil_events.h"
#include "i_protocol.h"

#include "commands/command_components.h"
#include "requests/request_components.h"

namespace Comms
{

class GalilProtocol : public IProtocol
{

public:
    GalilProtocol();

    void AddListner(const IProtocolGalilEvents* listener);

    void SendProtocolCommand(const ILink* link, CommandMotorEnable &command);
    void SendProtocolRequest(const ILink* link, RequestTellPosition &request);

    //!
    //! \brief Send message onto some link
    //!
    //! This code is largely a copy from MAVLinkProtocol::sendMessage in qgroundcontrol
    //! \param link Link to put message onto
    //! \param message Message to send
    //!
    void SendProtocolMessage(const ILink *link, const double &message);


    //!
    //! \brief Read data incoming from some link
    //!
    //! This code is largely a copy from MAVLinkProtocol::receiveBytes in qgroundcontrol
    //! \param link Link which data was read from
    //! \param buffer data that was read.
    //!
    void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) override;

private:

    void Emit(const std::function<void(const IProtocolGalilEvents*)> func)
    {
        for(const IProtocolGalilEvents* listener : m_Listners)
            func(listener);
    }

private:
    std::vector<const IProtocolGalilEvents*> m_Listners;
};


} //END MAVLINKComms

#endif // MAVLINK_COMMS_H
