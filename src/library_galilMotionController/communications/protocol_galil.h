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

    //////////////////////////////////////////////////////////////
    /// Methods issuing an explicit galil command
    //////////////////////////////////////////////////////////////
    void UploadNewProgram(const ILink* link, const std::string &programString);

    //////////////////////////////////////////////////////////////
    /// Methods issuing an explicit galil command
    //////////////////////////////////////////////////////////////
    void SendProtocolCommand(const ILink *link, const AbstractCommandPtr command);

private:
    void handleCommandResponse(const ILink* link, const AbstractCommandPtr command, const GReturn &response);
    void handleBadCommandResponse(const ILink* link, const CommandType &type) const;

    //////////////////////////////////////////////////////////////
    /// Methods issuing an explicit galil information request
    //////////////////////////////////////////////////////////////
public:
    void SendProtocolRequest(const ILink *link, const AbstractRequestPtr command);

private:
    void handleRequestResponse(const ILink* link, const AbstractRequestPtr request, const GReturn &response);
    void handleBadRequestResponse(const ILink* link, const RequestTypes &type) const;

    //void SendProtocolMessage(const ILink *link, const double &message);

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
