#ifndef COMMS_MARSHALER_H
#define COMMS_MARSHALER_H

#include "common/publisher.h"

#include <unordered_map>

#include "i_link.h"
#include "galil_link.h"
#include "protocol_galil.h"

#include "i_link_events.h"
#include "comms_events.h"

#include "commands/command_components.h"
#include "requests/request_components.h"

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
    bool ConnectToLink(const std::string &linkName);
    bool DisconnetLink();



    //////////////////////////////////////////////////////////////
    /// Methods issuing Galil commands, requests, programs
    //////////////////////////////////////////////////////////////
    template <typename T>
    void sendGalilCommand(const T& command);

    template <typename T>
    void sendGalilRequest(const T& request);

    void uploadProgram(const std::string &programString) const;

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
    /// React to Link Events
    //////////////////////////////////////////////////////////////

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;

    void StatusReceived(const StatusGeneric &status) const override;

    void BadRequestResponse(const StatusGeneric &status) const override;

    void BadCommandResponse(const StatusGeneric &status) const override;

    //////////////////////////////////////////////////////////////
    /// IProtocolGalilEvents
    //////////////////////////////////////////////////////////////

    //!
    //! \brief A Message has been received over Mavlink protocol
    //! \param linkName Link identifier which generated call
    //! \param message Message that has been received
    //!
    void MessageReceived(const double &message) const override;

    void NewPositionReceived(const Status_Position &status) const override;

private:
    std::shared_ptr<ILink> link;
    std::shared_ptr<GalilProtocol> protocol;

};

}//END Comms

#endif // LINKMARSHALER_H
