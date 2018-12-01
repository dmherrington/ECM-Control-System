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
    ProgramGeneric uploadProgram = command.get()->as<CommandUploadProgram>()->getProgram();
    GReturn rtn = link->UploadProgram(uploadProgram.getProgramString());

    std::vector<AbstractRequestPtr> currentRequests;
    RequestListLabelsPtr requestLabels = std::make_shared<RequestListLabels>();
    currentRequests.push_back(requestLabels);
    RequestListVariablesPtr requestVariables = std::make_shared<RequestListVariables>();
    currentRequests.push_back(requestVariables);

    unsigned int requestIndex = 0;
    while ((rtn == G_NO_ERROR) && (requestIndex <= (currentRequests.size() - 1)))
    {
        this->SendProtocolRequest(link,currentRequests.at(requestIndex));
        requestIndex++;
    }

    if(rtn == G_NO_ERROR)
    {
        //If we have gotten to this point, we currently have a newly available program with accompanying labels and variables.
        GalilCurrentProgram newProgram;
        newProgram.setProgram(uploadProgram.getProgramString());

        AbstractStatusPtr labelPtr = requestLabels->getStatus().at(0);
        Status_LabelList* currentLabels = labelPtr.get()->as<Status_LabelList>();

        AbstractStatusPtr variablePtr = requestVariables->getStatus().at(0);
        Status_VariableList* currentVariables = variablePtr.get()->as<Status_VariableList>();

        newProgram.setLabelList(currentLabels->getLabelList());
        newProgram.setVariableList(currentVariables->getVariableList());

        //We had no error and therefore need to call the setup to initialize all of the variables that are contained within the script
        CommandExecuteProfilePtr commandExecuteSetup = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::SETUP,"setup");
        //this->SendProtocolCommand(link,commandExecuteSetup);

        Emit([&](const IProtocolGalilEvents* ptr){ptr->NewProgramUploaded(true,newProgram);});
    }
    else
    {
        handleCommandResponse(link,command,rtn);
        Emit([&](const IProtocolGalilEvents* ptr){ptr->NewProgramUploaded(false);});
    }


}

void GalilProtocol::DownloadCurrentProgram(const ILink *link, const AbstractCommandPtr command)
{
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

void GalilProtocol::UploadProgramVariables(const ILink *link, const ProgramVariableList &varList)
{
    GReturn rtn = G_NO_ERROR;

    std::map<std::string, double> currentVarMap = varList.getVariableMap();
    std::map<std::string, double>::iterator it = currentVarMap.begin();

    Command_VariablePtr newVariable = std::make_shared<Command_Variable>("",0.0);

    for (; it!=currentVarMap.end(); ++it)
    {
        newVariable->setVariableName(it->first);
        newVariable->setVariableValue(it->second);

        rtn = link->WriteCommand(newVariable->getCommandString());
        handleCommandResponse(link,newVariable,rtn);

        if(rtn != G_NO_ERROR)
            break;
    }
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
            switch (command->getCommandType()) {
            case CommandType::SET_VARIABLE:
            {
                std::vector<AbstractStatusPtr> status;

                common::EnvironmentTime updateTime;
                common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,updateTime);

                Command_Variable* variableValue = command.get()->as<Command_Variable>();
                Status_VariableValuePtr variableStatus = std::make_shared<Status_VariableValue>();
                variableStatus->setVariableName(variableValue->getVariableName());
                variableStatus->setVariableValue(variableValue->getVariableValue());
                variableStatus->setTime(updateTime);

                status.push_back(variableStatus);
                Emit([&](const IProtocolGalilEvents* ptr){ptr->NewStatusReceived(status);});
                break;
            }
            default:
                break;
            }
            break;
        }
        case G_BAD_RESPONSE_QUESTION_MARK:
        {
            handleBadCommand_ResponseQuestionMark(link, command->getCommandType());
            break;
        }
        default:
            std::cout<<"There is another bad command response that is not currently supported of value: "<<std::to_string(response)<<std::endl;
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
            handleBadRequest_ResponseQuestionMark(link, request);
            break;
        }
        default:
            break;
        }
}

void GalilProtocol::handleBadRequest_ResponseQuestionMark(const ILink* link, const AbstractRequestPtr request)
{
    unsigned int code;
    std::string description;
    link->WriteTellErrorCode(code,description);
    Emit([&](const IProtocolGalilEvents* ptr){ptr->ErrorBadRequest(request->getRequestType(),description);});

}

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing a custom protocol command provided via string inputs from the user
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief GalilProtocol::SendCustomProtocolCommand
//! \param link
//! \param stringCommands
//!
void GalilProtocol::SendCustomProtocolCommand(const ILink *link, const std::vector<string> &stringCommands)
{
    GReturn rtn = G_NO_ERROR;
    RequestCustomStringPtr request;


    for (size_t i = 0; i < stringCommands.size(); i++)
    {
        request = std::make_shared<RequestCustomString>();
        request->setRequestString(stringCommands.at(i));
        rtn = link->WriteRequest(request);

        handleCustomRequestResponse(link,request,rtn);

        if(rtn != G_NO_ERROR)
            break;
    }

}

//!
//! \brief GalilProtocol::handleCustomRequestResponse
//! \param link
//! \param request
//! \param code
//!
void GalilProtocol::handleCustomRequestResponse(const ILink* link, const RequestCustomStringPtr request, const GReturn &code)
{
    switch (code) {
    case G_NO_ERROR: //this case should not need to be handled here
    {
        //since there was no error we can send it back to the request window
        Status_CustomRequest castResponse(*request->getStatus().at(0).get()->as<Status_CustomRequest>());
        Emit([&](const IProtocolGalilEvents* ptr){ptr->NewCustomStatusReceived(request->getRequestString(),castResponse.getResponseReceived());});
        break;
    }
    case G_BAD_LOST_DATA:
    {
        break;
    }
    case G_BAD_RESPONSE_QUESTION_MARK:
    {
        handleBadCustomRequest_ResponseQuestionMark(link, request);
        break;
    }
    default:
        break;
    }
}

//!
//! \brief GalilProtocol::handleBadCustomRequestResponse
//! \param link
//! \param request
//!
void GalilProtocol::handleBadCustomRequest_ResponseQuestionMark(const ILink* link, const RequestCustomStringPtr request)
{
    unsigned int code;
    std::string description;
    link->WriteTellErrorCode(code,description);
    Emit([&](const IProtocolGalilEvents* ptr){ptr->NewCustomStatusReceived(request->getRequestString(),description);});
}

} //END MAVLINKComms
