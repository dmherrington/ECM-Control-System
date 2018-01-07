#include "comms_marshaler.h"

namespace Comms
{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler()
{
    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<GalilLink>();
    link->AddListener(this);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<GalilProtocol>();
    protocol->AddListner(this);
    //protocol->ResetMetadataForLink(); I dont know why this is done
}


///////////////////////////////////////////////////////////////////////////////////////////////
/// Connect/Disconnect from Galil Methods
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Connect to an already created link
//! \param linkName Name of link to connect to
//! \return True if connection succesfull, false otherwise
//!
bool CommsMarshaler::ConnectToLink(const std::string &linkName)
{
    return link->Connect();
}

bool CommsMarshaler::DisconnetLink()
{
    return link->Disconnect();
}

///////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing Galil commands, requests, programs
///////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void CommsMarshaler::sendGalilCommand(const T &command)
{
    std::cout<<"Lets send a galil command"<<std::endl;

    T newCommand = command;
    auto func = [this, &newCommand]() {
            protocol->SendProtocolCommand(link.get(), newCommand);
    };

    link->MarshalOnThread(func);
}

template <typename T>
void CommsMarshaler::sendGalilRequest(const T &request)
{
    std::cout<<"Lets send a galil request"<<std::endl;
    T newRequest = request;
    auto func = [this, &newRequest]() {
            protocol->SendProtocolRequest(link.get(), newRequest);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::uploadProgram(const std::string &programString) const
{

}

///////////////////////////////////////////////////////////////////////////////////////////////
/// Query
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Issue a message to a given link
//!
//! The type used in the shall be an underlaying type which the protocol understands
//! \param link Link to send message on
//! \param message Message to send
//!
template <typename T>
void CommsMarshaler::SendGalilMessage(const T& message)
{
    ///////////////////
    /// Define function that sends the given message
    ///////////////////
    auto func = [this, message]() {
            protocol->SendProtocolMessage(link.get(), message);
    };

    link->MarshalOnThread(func);
}





//////////////////////////////////////////////////////////////
/// React to Link Events
//////////////////////////////////////////////////////////////

void CommsMarshaler::ConnectionOpened() const
{
    Emit([&](const CommsEvents *ptr){ptr->LinkConnected();});
}

void CommsMarshaler::ConnectionClosed() const
{
    Emit([&](const CommsEvents *ptr){ptr->LinkDisconnected();});
}

//////////////////////////////////////////////////////////////
/// MAVLINK Protocol Events
//////////////////////////////////////////////////////////////


//!
//! \brief A Message has been received over Mavlink protocol
//! \param linkName Link identifier which generated call
//! \param message Message that has been received
//!
void CommsMarshaler::MessageReceived(const double &message) const
{
    Emit([&](CommsEvents *ptr)
    {
        ptr->StatusMessage("Testing");
    });
}

void CommsMarshaler::NewPositionReceived(const Status_Position &status) const
{

}

template void CommsMarshaler::sendGalilCommand<CommandMotorEnable>(const CommandMotorEnable&);

template void CommsMarshaler::sendGalilRequest<RequestTellPosition>(const RequestTellPosition&);

template void CommsMarshaler::SendGalilMessage<double>(const double&);

}//END Comms
