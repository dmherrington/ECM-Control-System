#ifndef PROTOCOL_GALIL_H
#define PROTOCOL_GALIL_H

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

#include "programs/program_components.h"

namespace Comms
{

class GalilProtocol : public IProtocol
{

public:
    GalilProtocol();

    void AddListner(const IProtocolGalilEvents* listener);

    //////////////////////////////////////////////////////////////
    /// Methods issuing commands relevant to the galil program
    //////////////////////////////////////////////////////////////
    void UploadNewProgram(const ILink* link, const AbstractCommandPtr program);
    void DownloadCurrentProgram(const ILink* link, const AbstractCommandPtr command);

    void ExecuteProfile(const ILink* link, const AbstractCommandPtr &command);

    //////////////////////////////////////////////////////////////
    /// Methods issuing an explicit galil controller gain command
    //////////////////////////////////////////////////////////////
public:
    void SendProtocolGainCommand(const ILink *link, const CommandControllerGain &command);

    //////////////////////////////////////////////////////////////
    /// Methods issuing an explicit galil command
    //////////////////////////////////////////////////////////////
public:
    void SendProtocolCommand(const ILink *link, const AbstractCommandPtr command);

    void SendProtocolMotionCommand(const ILink* link, const AbstractCommandPtr command);

private:
    void handleCommandResponse(const ILink* link, const AbstractCommandPtr command, const GReturn &response);
    void handleBadCommand_ResponseQuestionMark(const ILink* link, const CommandType &type);

    //////////////////////////////////////////////////////////////
    /// Methods issuing an explicit galil information request
    //////////////////////////////////////////////////////////////
public:
    void SendProtocolRequest(const ILink *link, const AbstractRequestPtr command);

private:
    void handleRequestResponse(const ILink* link, const AbstractRequestPtr request, const GReturn &code);
    void handleBadRequest_ResponseQuestionMark(const ILink* link, const AbstractRequestPtr request) const;


    ////////////////////////////////////////////////////////////////////////////////////
    /// Methods handling an explicit galil command that has been customized by the user
    ////////////////////////////////////////////////////////////////////////////////////
public:
    //!
    //! \brief SendCustomProtocolCommand
    //! \param link
    //! \param stringCommands
    //!
    void SendCustomProtocolCommand(const ILink *link, const std::vector<std::vector> &stringCommands);

private:

    //!
    //! \brief handleCustomRequestResponse
    //! \param link
    //! \param request
    //! \param code
    //!
    void handleCustomRequestResponse(const ILink* link, const std::string &request, const GReturn &code);

    //!
    //! \brief handleBadCustomRequestResponse
    //! \param link
    //! \param request
    //!
    void handleBadCustomRequestResponse(const ILink* link, const std::string &request);

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


} //end of namespace Comms

#endif // PROTOCOL_GALIL_H
