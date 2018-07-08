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

void GalilProtocol::UploadNewProgram(const ILink *link, const AbstractCommandPtr command)
{
    std::cout<<"I am trying to upload a new program"<<std::endl;
    ProgramGeneric uploadProgram = command.get()->as<CommandUploadProgram>()->getProgram();
    GReturn rtn = link->UploadProgram(uploadProgram.getProgramString());
    if(rtn == G_NO_ERROR)
        Emit([&](const IProtocolGalilEvents* ptr){ptr->NewProgramUploaded(uploadProgram);});
    else
        handleCommandResponse(link,command,rtn);
}

void GalilProtocol::DownloadCurrentProgram(const ILink *link, const AbstractCommandPtr command)
{
    std::cout<<"I am trying to download a new program"<<std::endl;
    std::string programText;
    GReturn rtn = link->DownloadProgram(programText);
    if(rtn == G_NO_ERROR)
    {
        ProgramGeneric newProgram;
        newProgram.setProgramString(programText);
        Emit([&](const IProtocolGalilEvents* ptr){ptr->NewProgramDownloaded(newProgram);});
    }
    else
        handleCommandResponse(link,command,rtn);
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
    GReturn rtn = link->WriteCommand(command->getCommandString());
    handleCommandResponse(link,command,rtn);
}

void GalilProtocol::SendProtocolMotionCommand(const ILink *link, const AbstractCommandPtr command)
{
    std::string commandString = command->getCommandString();
    if(commandString.empty())
        return;
    GReturn rtn = link->WriteCommand(commandString);
    handleCommandResponse(link,command,rtn);

    if(rtn == G_NO_ERROR)
    {
        CommandMotionStartPtr motionPTR = std::make_shared<CommandMotionStart>();
        rtn = link->WriteCommand(motionPTR->getCommandString());
        handleCommandResponse(link,motionPTR,rtn);
    }
    else
    {
        std::cout<<"There was an error sending the command."<<std::endl;
    }
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
            handleBadCommand_ResponseQuestionMark(link, command->getCommandType());
            break;
        }
        default:
            std::cout<<"There is another bad command response"<<std::endl;
            break;
        }
}

void GalilProtocol::handleBadCommand_ResponseQuestionMark(const ILink* link, const CommandType &type)
{
    unsigned int code;
    std::string description;
    link->WriteTellErrorCode(code,description);
    Emit([&](const IProtocolGalilEvents* ptr){ptr->ErrorBadCommand(type,std::string(description));});
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing an explicit galil information request
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GalilProtocol::SendProtocolRequest(const ILink *link, const AbstractRequestPtr request)
{
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
    unsigned int code;
    std::string description;
    link->WriteTellErrorCode(code,description);
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
