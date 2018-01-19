#include "protocol_galil.h"

#include <iostream>

#include <algorithm>

#include "programs/program_generic.h"

namespace Comms
{

GalilProtocol::GalilProtocol()
{

}

void GalilProtocol::AddListner(const IProtocolGalilEvents* listener)
{
    m_Listners.push_back(listener);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing commands relevant to the galil program
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GalilProtocol::UploadNewProgram(const ILink *link, const ProgramGeneric &program)
{
    std::cout<<"I am trying to upload a new program"<<std::endl;
    std::string programString = program.buildProgram();
    GReturn rtn = link->UploadProgram(programString);
}

void GalilProtocol::DownloadCurrentProgram(const ILink *link)
{
    std::cout<<"I am trying to download a new program"<<std::endl;
}

void GalilProtocol::ExecuteProfile(const ILink *link, const AbstractCommandPtr &command)
{
    std::cout<<"I am trying to execute a new profile"<<std::endl;
    //First, let us establish the correct gains for the galil
//    CommandControllerGain commandGain(profile.profileGain);
//    SendProtocolGainCommand(link,commandGain);
    //Next, let us exectue the profile
//    CommandExecuteProfilePtr commandPtr = std::make_shared<CommandExecuteProfile>(command);
//    SendProtocolCommand(link,commandPtr);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing an explicit galil controller gain command
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GalilProtocol::SendProtocolGainCommand(const ILink *link, const CommandControllerGain &command)
{
    //Grab the proportional gain and set it
    std::string pCommandString = command.getCommandString(GainType::PGain);
    GReturn rtn = link->WriteCommand(pCommandString);
    //Grab the integral gain and set it
    std::string iCommandString = command.getCommandString(GainType::IGain);
    rtn = link->WriteCommand(iCommandString);
    //Grab the derivative gain and set it
    std::string dCommandString = command.getCommandString(GainType::DGain);
    rtn = link->WriteCommand(dCommandString);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing an explicit galil command
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GalilProtocol::SendProtocolCommand(const ILink *link, const AbstractCommandPtr command)
{
    std::cout<<"I am in here"<<std::endl;
    GReturn rtn = link->WriteCommand(command->getCommandString());
    handleCommandResponse(link,command,rtn);
}

void GalilProtocol::handleCommandResponse(const ILink *link, const AbstractCommandPtr command, const GReturn &response)
{
        switch (response) {
        case G_NO_ERROR:
        {
            break;
        }
        case G_BAD_RESPONSE_QUESTION_MARK:
        {
            handleBadCommandResponse(link, command->getCommandType());
            break;
        }
        default:
            break;
        }
}

void GalilProtocol::handleBadCommandResponse(const ILink* link, const CommandType &type) const
{
    char error[100];
    link->WriteTellErrorCode(error);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing an explicit galil information request
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GalilProtocol::SendProtocolRequest(const ILink *link, const AbstractRequestPtr request)
{
    std::cout<<"I am trying to send a protocol request of type: "<<RequestToString(request->getRequestType())<<std::endl;
    GReturn rtn = link->WriteRequest(request);
    handleRequestResponse(link,request,rtn);
}

void GalilProtocol::handleRequestResponse(const ILink *link, const AbstractRequestPtr request, const GReturn &code)
{
        switch (code) {
        case G_NO_ERROR:
        {
            std::vector<AbstractStatusPtr> status = request->getStatus();
            Emit([&](const IProtocolGalilEvents* ptr){ptr->NewStatusReceived(status);});
            break;
        }
        case G_BAD_LOST_DATA:
        {
            break;
        }
        case G_BAD_RESPONSE_QUESTION_MARK:
        {
            handleBadRequestResponse(link, request);
            break;
        }
        default:
            break;
        }
}

void GalilProtocol::generateNewStatus(const AbstractRequestPtr request, char *&buf)
{

}
void GalilProtocol::handleBadRequestResponse(const ILink* link, const AbstractRequestPtr request) const
{
    char error[100];
    link->WriteTellErrorCode(error);
}

//void GalilProtocol::SendProtocolMessage(const ILink *link, const double &message)
//{
//    // Create buffer
//    static uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
//    // Write message into buffer, prepending start sign
//    int len = mavlink_msg_to_send_buffer(buffer, &message);
//    // If link is connected
//    if (link->isConnected())
//    {
//        // Send the portion of the buffer now occupied by the message
//        link->WriteBytes((const char*)buffer, len);
//    }
//    Emit([&](const IProtocolGalilEvents* ptr){ptr->MessageReceived(2.5);});
//}



//!
//! \brief Read data incoming from some link
//!
//! This code is largely a copy from MAVLinkProtocol::receiveBytes in qgroundcontrol
//! \param link Link which data was read from
//! \param buffer data that was read.
//!
void GalilProtocol::ReceiveData(ILink *link, const std::vector<uint8_t> &buffer)
{
    //where the response is seen
}

} //END MAVLINKComms
