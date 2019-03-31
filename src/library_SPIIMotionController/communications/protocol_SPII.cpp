#include "protocol_SPII.h"

#include <iostream>

#include <algorithm>


namespace Comms
{

SPIIProtocol::SPIIProtocol():
    m_SPIIDevice(nullptr)
{

}

void SPIIProtocol::updateDeviceSettings(const SPII_Settings &settings)
{
    m_SPIISettings = settings;
    m_SPIIDevice = settings.getDeviceHandle();
}

BufferLabelValues SPIIProtocol::updateBufferLabels()
{
    BufferLabelValues labels;

}

BufferVariableValues SPIIProtocol::updateBufferVariables(const unsigned int &bufferIndex)
{
    BufferVariableValues vars;

}

void SPIIProtocol::uploadProgramToBuffer(const SPIICommand_UploadProgram *uploadProgram)
{
    Status_BufferState newBufferState;
    newBufferState.setBufferIndex(uploadProgram->getBufferIndex());
    newBufferState.setProgramString(uploadProgram->getCurrentScript());

    bool uploadSuccessful = bufferUpload(uploadProgram->getBufferIndex(), uploadProgram->getCurrentScript());

    if(uploadSuccessful && (uploadProgram->shouldCompileImmediately()))
    {
        if(bufferCompile(uploadProgram->getBufferIndex(), newBufferState))
        {
            //there was no error and therefore we can resume
            //If we basically had uploaded and compiled the DBuffer, we are going to reset all of the available variables
            if(m_SPIISettings.getDBufferIndex() == uploadProgram->getBufferIndex())
            {
                updateBufferVariables(uploadProgram->getBufferIndex());
            }
            //If we had uploaded and compiled the buffer containing the labels, let us regrab all of the labels
            else if(m_SPIISettings.getLabelBufferIndex() == uploadProgram->getBufferIndex())
            {
                updateBufferVariables(uploadProgram->getBufferIndex());
            }
        }
    }
}

bool SPIIProtocol::requestPosition(const int &axisRequest, double &value)
{
    if(m_SPIIDevice == nullptr)
        return false;

    bool rtnValidity = acsc_GetRPosition(*m_SPIIDevice.get(),axisRequest,&value,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    return rtnValidity;
}

bool SPIIProtocol::requestAxisStatus(const int &axisRequest, int &value)
{
    if(m_SPIIDevice == nullptr)
        return false;

    bool rtnValidity = acsc_GetAxisState(*m_SPIIDevice.get(),axisRequest,&value,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    return rtnValidity;
}

bool SPIIProtocol::requestMotorStatus(const int &axisRequest, int &value)
{
    if(m_SPIIDevice == nullptr)
        return false;

    bool rtnValidity = acsc_GetMotorState(*m_SPIIDevice.get(),axisRequest,&value,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    return rtnValidity;
}

bool SPIIProtocol::requestNumberofBuffers(double &value)
{
    if(m_SPIIDevice == nullptr)
        return false;

    bool rtnValidity = acsc_GetBuffersCount(*m_SPIIDevice.get(),&value,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    return rtnValidity;
}

bool SPIIProtocol::requestNumberofAxes(double &value)
{
    if(m_SPIIDevice == nullptr)
        return false;

    bool rtnValidity = acsc_GetAxesCount(*m_SPIIDevice.get(),&value,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    return rtnValidity;
}

bool SPIIProtocol::requestDBufferIndex(double &index)
{
    if(m_SPIIDevice == nullptr)
        return false;

    bool rtnValidity = acsc_GetDBufferIndex(*m_SPIIDevice.get(),&index,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    return rtnValidity;
}

void SPIIProtocol::ReceiveData(ILink *link, const std::vector<uint8_t> &buffer)
{
    UNUSED(link);
    UNUSED(buffer);
}

void SPIIProtocol::SendProtocolCommand(const AbstractCommandPtr command)
{
    switch (command->getCommandType()) {
    case CommandType::UPLOAD_PROGRAM:
    {
        SPIICommand_UploadProgram* uploadProgram = command->as<SPIICommand_UploadProgram>();
        uploadProgramToBuffer(uploadProgram);
        break;
    }
    case CommandType::MOTOR_ON:
    {
        CommandMotorEnable* commandEnable = command->as<CommandMotorEnable>();
        commandMotorEnable(*commandEnable);
        break;
    }
    case CommandType::MOTOR_OFF:
    {
        CommandMotorDisable* commandDisable = command->as<CommandMotorDisable>();
        commandMotorDisable(*commandDisable);
        break;
    }
    case CommandType::JOG_MOVE:
    {
        break;
    }
    default:
    {
        break;
    }
    }
}

void SPIIProtocol::SendProtocolMotionCommand(const AbstractCommandPtr command)
{

}

void SPIIProtocol::SendCustomProtocolCommand(const std::vector<std::string> &stringCommands)
{

}

bool SPIIProtocol::WriteVariableValue(const Command_Variable &value)
{
    bool rtnValidity = false;

    double values[1] = {value.getVariableValue()};

    char ctext[value.getVariableName().size()];
    strcpy(ctext, value.getVariableName().c_str());

    rtnValidity = acsc_WriteReal(*m_SPIIDevice.get(),ACSC_NONE,ctext,0,0,ACSC_NONE,ACSC_NONE,values,static_cast<LP_ACSC_WAITBLOCK>(nullptr));

    return rtnValidity;
}

bool SPIIProtocol::commandMotorEnable(const CommandMotorEnable &enable)
{
    bool rtnValidity = false;

    if(m_SPIIDevice == nullptr)
        return false;

    std::map<MotorAxis,CommandMotorEnable::EnableValue> enableAction = enable.getEnableAction();

    if(enableAction.size() == 0) //there is simply no enable axis commands
        return false;

    std::vector<MotorAxis> changeAxisVector;
    for (std::map<MotorAxis,CommandMotorEnable::EnableValue>::iterator it=enableAction.begin(); it!=enableAction.end(); ++it)
    {
        if(it->second == CommandMotorEnable::EnableValue::CHANGE)
            changeAxisVector.push_back(it->first);
    }

    if(changeAxisVector.empty())
        return false;

    if(changeAxisVector.size() > 1) //this would be a multiaxis enabling
    {
        int changeAxisArray[changeAxisVector.size()];
        std::copy(changeAxisVector.begin(), changeAxisVector.end(), changeAxisArray);
        rtnValidity = acsc_EnableM(*m_SPIIDevice.get(),changeAxisArray,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    }
    else if(changeAxisVector.size() == 1) //this would be a single axis enabling
    {
        rtnValidity = acsc_Enable(*m_SPIIDevice.get(),changeAxisVector.at(0),static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    }

    return rtnValidity;
}

bool SPIIProtocol::commandMotorDisable(const CommandMotorDisable &disable)
{
    bool rtnValidity = false;

    if(m_SPIIDevice == nullptr)
        return false;

    if(disable.shouldDisableAll())
    {
        rtnValidity = acsc_DisableAll(*m_SPIIDevice.get(),static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    }
    else {
        std::map<MotorAxis,CommandMotorDisable::DisableValue> disableAction = disable.getDisableAction();

        if(disableAction.size() == 0) //there is simply no enable axis commands
            return false;

        std::vector<MotorAxis> changeAxisVector;
        for (std::map<MotorAxis,CommandMotorDisable::DisableValue>::iterator it=disableAction.begin(); it!=disableAction.end(); ++it)
        {
            if(it->second == CommandMotorDisable::DisableValue::CHANGE)
                changeAxisVector.push_back(it->first);
        }

        if(changeAxisVector.empty())
            return false;

        if(changeAxisVector.size() > 1) //this would be a multiaxis enabling
        {
            int changeAxisArray[changeAxisVector.size()];
            std::copy(changeAxisVector.begin(), changeAxisVector.end(), changeAxisArray);
            rtnValidity = acsc_DisableM(*m_SPIIDevice.get(),changeAxisArray,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
        }
        else if(changeAxisVector.size() == 1) //this would be a single axis enabling
        {
            rtnValidity = acsc_Disable(*m_SPIIDevice.get(),changeAxisVector.at(0),static_cast<LP_ACSC_WAITBLOCK>(nullptr));
        }
    }

    return rtnValidity;
}

bool SPIIProtocol::commandJogMotion(const CommandJog &jog)
{
    bool rtnValidity = false;

    if(m_SPIIDevice == nullptr)
        return false;

    std::map<MotorAxis, double> jogActionMap = jog.getJogAction();
    if(jogActionMap.size() > 1)
    {
        //this would be a multiaxis jog
        //for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        //std::cout << it->first << " => " << it->second << '\n';
        //rtnValidity = acsc_JogM(*m_SPIIDevice.get(),&index,ACSC_SYNCHRONOUS);
    }
    else if(jogActionMap.size() == 1)
    {
        std::map<MotorAxis, double>::iterator it=jogActionMap.begin();
        //this would imply a single axis jog
        rtnValidity = acsc_Jog(*m_SPIIDevice.get(),ACSC_AMF_VELOCITY,it->first,it->second,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    }
    else {
        //there is simply no jog command
    }

    return rtnValidity;
}

bool SPIIProtocol::commandKillMotion(const CommandStop &stop)
{
    bool rtnValidity = false;

    if(m_SPIIDevice == nullptr)
        return false;

    if(stop.shouldStopAllMotion())
    {
        rtnValidity = acsc_KillAll(*m_SPIIDevice.get(),static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    }

    return rtnValidity;
}

bool SPIIProtocol::programUpload(const CommandUploadProgram &program)
{

}

bool SPIIProtocol::bufferUpload(const unsigned int &index, const std::string &text)
{
    if(m_SPIIDevice == nullptr)
        return false;

    Status_BufferState newState;
    newState.setBufferIndex(index);
    newState.setProgramString(text);

    char ctext[text.size()];
    strcpy(ctext, text.c_str());

    bool validUpload = acsc_LoadBuffer(*m_SPIIDevice.get(), static_cast<int>(index), ctext, static_cast<int>(text.length()),static_cast<LP_ACSC_WAITBLOCK>(nullptr));

    if(validUpload)
        newState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::CURRENT);
    else {
        newState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::ERROR_UPLOAD);
        int bufferSent = 100, bufferReceived = 100;
        char errorBuf[bufferSent];

        int errorCode = acsc_GetLastError();
        acsc_GetErrorString(*m_SPIIDevice.get(),errorCode,errorBuf,bufferSent,&bufferReceived);
        std::string errorString(errorBuf);
        newState.setErrorString(errorString);
    }

    Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewBufferState(newState);});
    return validUpload;
}

bool SPIIProtocol::bufferCompile(const unsigned int &index, Status_BufferState &newState)
{
    if(m_SPIIDevice == nullptr)
        return false;

    newState.setBufferIndex(index);

    bool validCompile = acsc_CompileBuffer(*m_SPIIDevice.get(), static_cast<int>(index), static_cast<LP_ACSC_WAITBLOCK>(nullptr));

    if(validCompile)
        newState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::COMPILED);
    else {
        newState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::ERROR_COMPILING);
        int bufferSent = 100, bufferReceived = 100;
        char errorBuf[bufferSent];

        int errorCode = checkForBufferCompilation(index);
        if(errorCode != 0)
        {
            acsc_GetErrorString(*m_SPIIDevice.get(),errorCode,errorBuf,bufferSent,&bufferReceived);
            std::string errorString(errorBuf);
            newState.setErrorString(errorString);

            unsigned int errorLine = checkForBufferLineError(index);
            newState.setErrorLine(errorLine);
        }
    }

    Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewBufferState(newState);});
    return validCompile;
}

int SPIIProtocol::checkForBufferCompilation(const unsigned int &index)
{
    if(m_SPIIDevice == nullptr)
        return false;
    int bufferError[1];
    bool validRequest = acsc_ReadInteger(*m_SPIIDevice, ACSC_NONE, "PERR", static_cast<int>(index),static_cast<int>(index),ACSC_NONE,ACSC_NONE,bufferError,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    if(validRequest)
        return bufferError[0];

    return -1;
}

unsigned int SPIIProtocol::checkForBufferLineError(const unsigned int &index)
{
    if(m_SPIIDevice == nullptr)
        return false;
    int bufferError[1];
    bool validRequest = acsc_ReadInteger(*m_SPIIDevice, ACSC_NONE, "PERL", static_cast<int>(index),static_cast<int>(index),ACSC_NONE,ACSC_NONE,bufferError,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    if(validRequest)
        return bufferError[0];

    return -1;
}

bool SPIIProtocol::bufferRun(const unsigned int &index, const std::string &label)
{
    //acsc_RunBuffer()
}

bool SPIIProtocol::bufferStop(const unsigned int &index)
{
    //acsc_StopBuffer()
}
} //END Comms
