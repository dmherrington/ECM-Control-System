#ifndef COMMS_MARSHALER_GALIL_H
#define COMMS_MARSHALER_GALIL_H

#include "common/publisher.h"

#include <unordered_map>

#include "i_link.h"
#include "galil_link.h"
#include "protocol_galil.h"

#include "i_link_events.h"
#include "comms_events.h"

#include "commands/command_components.h"
#include "requests/request_components.h"

#include "programs/program_generic.h"
#include "programs/galil_current_program.h"

#include "status/status_components.h"

namespace Comms
{

class CommsMarshaler : public Publisher<CommsEvents>, private ILinkEvents, private IProtocolGalilEvents
{
public:

    CommsMarshaler();


    //////////////////////////////////////////////////////////////
    /// Connect/Disconnect from Galil Methods
    //////////////////////////////////////////////////////////////

    //!
    //! \brief Connect to an already created link
    //! \param linkName Name of link to connect to
    //! \return True if connection successful, false otherwise
    //!
    void ConnectToLink(const std::string &linkName);
    void DisconnetLink();
    bool isDeviceConnected() const;


    //////////////////////////////////////////////////////////////
    /// Methods issuing Galil commands, requests, programs
    //////////////////////////////////////////////////////////////

    void sendCustomGalilCommands(const std::vector<std::string> &stringCommands);

    void sendAbstractGalilCommand(const AbstractCommandPtr command);

    void sendAbstractGalilMotionCommand(const AbstractCommandPtr command);

    void sendAbstractGalilRequest(const AbstractRequestPtr request) const;

    void sendGalilProfileExecution(const AbstractCommandPtr &command);

    void sendGalilControllerGains(const CommandControllerGain &command);

    void uploadProgram(const AbstractCommandPtr uploadCommand) const;

    void downloadProgram(const AbstractCommandPtr downloadCommand) const;

    void uploadGalilProfileVariables(const ProgramVariableList &varList) const;

    //!
    //! \brief Issue a message to a given link
    //!
    //! The type used in the shall be an underlying type which the protocol understands
    //! \param link Link to send message on
    //! \param message Message to send
    //!
    template <typename T>
    void SendGalilMessage(const T& message);

private:
    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed from ILinkEvents
    //////////////////////////////////////////////////////////////

    void ConnectionUpdate(const common::comms::CommunicationUpdate &update) const override;

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;

    void StatusReceived(const AbstractStatus &status) const override;

    void BadRequestResponse(const AbstractStatus &status) const override;

    void BadCommandResponse(const AbstractStatus &status) const override;

    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed from IProtocolGalilEvents
    //////////////////////////////////////////////////////////////

    void NewCustomStatusReceived(const std::string &initialCommand, const std::string &newStatus) const override;

    void NewProgramUploaded(const bool &success, const GalilCurrentProgram &program = GalilCurrentProgram()) const override;

    void NewProgramDownloaded(const ProgramGeneric &program) const override;

    void NewPositionReceived(const Status_Position &status) const override;

    void NewStatusReceived(const std::vector<AbstractStatusPtr> &status) const override;

    void ErrorBadCommand(const CommandType &type, const std::string &description) const override;

    void ErrorBadRequest(const RequestTypes &type, const std::string &description) const override;

private:
    void parseStatus(const AbstractStatusPtr &status) const;

private:
    std::shared_ptr<ILink> link;
    std::shared_ptr<GalilProtocol> protocol;

};

}//END Comms

#endif // LINKMARSHALER_H
