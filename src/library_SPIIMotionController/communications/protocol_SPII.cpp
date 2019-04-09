#include "protocol_SPII.h"

#include <iostream>

#include <algorithm>


namespace Comms
{

SPIIProtocol::SPIIProtocol():
    m_SPIIDevice(nullptr)
{

}

void SPIIProtocol::AddListner(const IProtocolSPIIEvents* listener)
{
    m_Listners.push_back(listener);
}

void SPIIProtocol::initializeBufferContents()
{
    for(size_t bufferIndex = 0; bufferIndex < m_SPIISettings.getBufferCount() + 1; bufferIndex++)
    {
        BufferData newData;
        newData.setBufferIndex(bufferIndex);
        newData.setBufferCurrent(true);

        if(m_SPIISettings.getDBufferIndex() == bufferIndex)
        {
            newData.setIsDBuffer(true);

            //we need to also retrieve the variables on load
            Operation_VariableList privateVars, userVars;
            retrieveDBufferVariables(m_SPIISettings.getDBufferIndex(), privateVars, userVars);
            Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewStatus_PrivateOperationalVariables(true, privateVars);});
            Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewStatus_UserOperationalVariables(true, userVars);});
        }
        else
            newData.setIsDBuffer(false);

        if(m_SPIISettings.getLabelBufferIndex() == bufferIndex)
        {
            Operation_LabelList relevantLabels;
            retrieveBufferLabels(m_SPIISettings.getLabelBufferIndex(), relevantLabels);
            Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewStatus_OperationalLabels(relevantLabels);});
        }

        retrieveBufferData(bufferIndex,newData);

        Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewBuffer_AvailableData(newData);});
    }
}

void SPIIProtocol::updateDeviceSettings(const SPII_Settings &settings)
{
    m_SPIISettings = settings;
    m_SPIIDevice = settings.getDeviceHandle();
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

    m_SPIISettings.setAxisCount(value);

    return rtnValidity;
}

bool SPIIProtocol::requestDBufferIndex(double &index)
{
    if(m_SPIIDevice == nullptr)
        return false;

    bool rtnValidity = acsc_GetDBufferIndex(*m_SPIIDevice.get(),&index,static_cast<LP_ACSC_WAITBLOCK>(nullptr));

    m_SPIISettings.setDBufferIndex(index);

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
        SPIICommand_UploadProgramBuffer* uploadProgram = command->as<SPIICommand_UploadProgramBuffer>();
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
    case CommandType::SPEED:
    {
        CommandSpeed* commandSpeed = command->as<CommandSpeed>();
        commandAxisSpeed(*commandSpeed);
    }
    case CommandType::SET_VARIABLE:
    {
        Command_Variable* commandVariable = command->as<Command_Variable>();
        WriteVariableValue(*commandVariable);
        break;
    }
    case CommandType::SET_VARIABLE_ARRAY:
    {
        Command_VariableArray* commandVariable = command->as<Command_VariableArray>();
        WriteVariableArray(*commandVariable);
        break;
    }
    case CommandType::UPLOAD_OPERATIONAL_VARIABLES:
    {
        Command_UploadOperationalVariables* operationalVariables = command->as<Command_UploadOperationalVariables>();
        WriteOperationalVariables(operationalVariables->getOperationalVariables());
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
    switch (command->getCommandType()) {
    case CommandType::JOG_MOVE:
    {
        CommandJog* commandJog = command->as<CommandJog>();
        commandJogMotion(*commandJog);
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
        CommandRelativeMove* commandRM = command->as<CommandRelativeMove>();
        commandRelativeMove(*commandRM);
        break;
    }
    case CommandType::EXECUTE_PROGRAM:
    {
        CommandExecuteProfile* commandExecute = command->as<CommandExecuteProfile>();
        bufferRun(0,commandExecute->getProfileName());
        break;
    }
    case CommandType::STOP:
    {
        CommandStop* commandStop = command->as<CommandStop>();
        commandKillMotion(*commandStop);
        break;
    }
    default:
    {
        break;
    }
    }
}

void SPIIProtocol::SendCustomProtocolCommand(const std::vector<std::string> &stringCommands)
{
    /*
    std::string begin = "#";
    std::string end = "VG\r";
    std::string dBuffer = std::to_string(bufferNumber);
    std::string concatenatedRequest = begin + dBuffer + end;

    char *cstr = new char[concatenatedRequest.length() + 1];
    strcpy(cstr, concatenatedRequest.c_str());

    int bufferSize = static_cast<int>(startingBufferSize);
    int currentAttempt = 1;
    bool validAttempt = true, retry = true;
    int received = 0;

    std::string bufString;

    while (validAttempt && retry)
    {
        char* buf = new char[bufferSize]();
        validAttempt = acsc_Transaction(*m_SPIIDevice.get(),cstr, strlen(cstr), buf, bufferSize, &received, NULL);

        if(!validAttempt)
            break;

        if(received == bufferSize)
        {
            if((currentAttempt < attempts) || (attempts == -1))
            {
                currentAttempt++;
                bufferSize = bufferSize * 2;
            }
            else {
                retry = false;
                bufString = std::string(buf);
            }
        }
        else {
            retry = false;
            bufString = std::string(buf);
        }

        delete[] buf;
    }

    bufString.erase(bufString.begin()+received, bufString.end());
    QString newQString = QString::fromStdString(bufString);
    QStringList stringList = newQString.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    return stringList;
    */
}

bool SPIIProtocol::ReadIntegerVariableValue(const Request_TellVariable &tellVariable, Status_VariableValue &responseValue)
{
    bool rtnValidity = false;

    int values[1] = {0};

    responseValue.setVariableName(tellVariable.getVariableName());
    responseValue.setVariableUnit(tellVariable.getUnitName());

    char ctext[tellVariable.getVariableName().size()];
    strcpy(ctext, tellVariable.getVariableName().c_str());

    rtnValidity = acsc_ReadInteger(*m_SPIIDevice.get(),ACSC_NONE,ctext,0,0,ACSC_NONE,ACSC_NONE,values,static_cast<LP_ACSC_WAITBLOCK>(nullptr));

    responseValue.setVariableValue(values[0]);

    responseValue.setStatusValidity(rtnValidity);

    return rtnValidity;
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

bool SPIIProtocol::WriteVariableArray(const Command_VariableArray &value)
{
    bool rtnValidity = false;
    std::vector<double> valueVector = value.getVariableValue();

    double valueArray[valueVector.size()];
    std::copy(valueVector.begin(), valueVector.end(), valueArray);

    char ctext[value.getVariableName().size()];
    strcpy(ctext, value.getVariableName().c_str());

    rtnValidity = acsc_WriteReal(*m_SPIIDevice.get(),ACSC_NONE,ctext,0,valueVector.size() - 1,ACSC_NONE,ACSC_NONE,valueArray,static_cast<LP_ACSC_WAITBLOCK>(nullptr));

    return rtnValidity;
}

bool SPIIProtocol::WriteOperationalVariables(const Operation_VariableList &variableList)
{
    bool validity = true;
    std::map<std::string, double> currentVarMap = variableList.getVariableMap();
    std::map<std::string, double>::iterator it = currentVarMap.begin();

    Command_VariablePtr newVariable = std::make_shared<Command_Variable>("",0.0);

    for (; it!=currentVarMap.end(); ++it)
    {
        newVariable->setVariableName(it->first);
        newVariable->setVariableValue(it->second);

        validity = WriteVariableValue(*newVariable.get());
        if(!validity)
            break;
    }

    if(validity)
        Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewStatus_UserOperationalVariables(true,variableList);});
    else
        Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewStatus_UserOperationalVariables(false);});
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

bool SPIIProtocol::commandAxisSpeed(const CommandSpeed &speed)
{
    bool rtnValidity = false;

    if(m_SPIIDevice == nullptr)
        return false;

    std::map<MotorAxis, unsigned int> speedMap = speed.getAxisSpeedMap();
    std::map<MotorAxis, unsigned int>::iterator it;

    for(it = speedMap.begin(); it != speedMap.end(); ++it)
    {
        rtnValidity = acsc_SetVelocity(*m_SPIIDevice.get(), it->first, it->second, static_cast<LP_ACSC_WAITBLOCK>(nullptr));
        if(!rtnValidity)
            break;
    }
    return rtnValidity;

}

bool SPIIProtocol::commandJogMotion(const CommandJog &jog)
{
    bool rtnValidity = false;

    if(m_SPIIDevice == nullptr)
        return false;

    std::map<MotorAxis, double> jogActionMap = jog.getJogDirectedAction();

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

bool SPIIProtocol::commandRelativeMove(const CommandRelativeMove &relativeMove)
{
    bool rtnValidity = false;

    if(m_SPIIDevice == nullptr)
        return false;

    std::map<MotorAxis, double> moveActionMap = relativeMove.getRelativeMoveDistance();

    if(moveActionMap.size() > 1)
    {
        //this would be a multiaxis jog
        //for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        //std::cout << it->first << " => " << it->second << '\n';
        //rtnValidity = acsc_JogM(*m_SPIIDevice.get(),&index,ACSC_SYNCHRONOUS);
    }
    else if(moveActionMap.size() == 1)
    {
        std::map<MotorAxis, double>::iterator it=moveActionMap.begin();
        //this would imply a single axis jog
        rtnValidity = acsc_ToPoint(*m_SPIIDevice.get(),ACSC_AMF_RELATIVE,it->first,it->second,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    }
    else {
        //there is simply no relative move command that is applicable at this time
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

bool SPIIProtocol::bufferRun(const unsigned int &index, const std::string &label)
{
    bool validExecution = false;

    if(label.empty())
        validExecution = acsc_RunBuffer(*m_SPIIDevice.get(),static_cast<int>(index),NULL,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    else
    {
        char *cstr = new char[label.length() + 1];
        strcpy(cstr, label.c_str());
        validExecution = acsc_RunBuffer(*m_SPIIDevice.get(),static_cast<int>(index),cstr,static_cast<LP_ACSC_WAITBLOCK>(nullptr));
    }

    return validExecution;
}

bool SPIIProtocol::bufferStop(const unsigned int &index)
{
    bool validExecution = acsc_StopBuffer(*m_SPIIDevice.get(),static_cast<int>(index),static_cast<LP_ACSC_WAITBLOCK>(nullptr));

    return validExecution;
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

    bool validCompile = false;

    newState.setBufferIndex(index);

    bool validCompileCommand = acsc_CompileBuffer(*m_SPIIDevice.get(), static_cast<int>(index), static_cast<LP_ACSC_WAITBLOCK>(nullptr));

    if(validCompileCommand)
    {
        int errorCode = checkForBufferCompilation(index);
        if(errorCode == 0)
        {
            newState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::COMPILED);
            validCompile = true;
        }
        else
        {
            int bufferSent = 100, bufferReceived = 100;
            char errorBuf[bufferSent];

            newState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::ERROR_COMPILING);
            acsc_GetErrorString(*m_SPIIDevice.get(),errorCode,errorBuf,bufferSent,&bufferReceived);
            std::string errorString(errorBuf);
            errorString.erase(errorString.begin() + bufferReceived - 1, errorString.end());
            newState.setErrorString(errorString);

            unsigned int errorLine = checkForBufferLineError(index);
            newState.setErrorLine(errorLine);
        }
    }
    else {
        newState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::ERROR_COMPILING);
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

void SPIIProtocol::uploadProgramToBuffer(const SPIICommand_UploadProgramBuffer *uploadProgram)
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
                Operation_VariableList privateVariables, userVariables;
                retrieveDBufferVariables(m_SPIISettings.getDBufferIndex(), privateVariables, userVariables);

                Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewStatus_PrivateOperationalVariables(true, privateVariables);});
                Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewStatus_UserOperationalVariables(true, userVariables);});
            }
            //If we had uploaded and compiled the buffer containing the labels, let us regrab all of the labels
            else if(m_SPIISettings.getLabelBufferIndex() == uploadProgram->getBufferIndex())
            {
                Operation_LabelList relevantLabels;
                retrieveBufferLabels(m_SPIISettings.getLabelBufferIndex(), relevantLabels);
                Emit([&](const IProtocolSPIIEvents* ptr){ptr->NewStatus_OperationalLabels(relevantLabels);});
            }
        }
    }
}

void SPIIProtocol::retrieveBufferData(const unsigned int &bufferIndex, BufferData &bufferContents)
{
    bufferContents.setProgramString(requestBufferContents(bufferIndex));
    if(checkForBufferCompilation(bufferIndex) == 0)
        bufferContents.setBufferCompiled(true);
    else
        bufferContents.setBufferCompiled(false);
}

void SPIIProtocol::retrieveBufferLabels(const unsigned int &bufferIndex, Operation_LabelList &bufferLabels)
{
    std::string bufferContents = requestBufferContents(bufferIndex);

    QString newQString = QString::fromStdString(bufferContents);
    QStringList lineList = newQString.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    QRegExp rx("(:$)");
    QStringList labelList = lineList.filter(rx);
    for (int labelIndex = 0; labelIndex < labelList.size(); labelIndex++)
    {
        QString labelString = labelList.at(labelIndex);
        labelString.remove(rx);
        bufferLabels.addLabel(labelString.toStdString(),0);
    }
}

void SPIIProtocol::retrieveDBufferVariables(const unsigned int &bufferIndex, Operation_VariableList &privateVariables, Operation_VariableList &userVariables)
{
    QStringList bufferVariableList = requestBufferVariables(bufferIndex);

    privateVariables.clearVariableList();
    userVariables.clearVariableList();

    int beginPrivateCount = bufferVariableList.count("beginOfPrivateVariables");
    int endPrivateCount = bufferVariableList.count("endOfPrivateVariables");

    int beginUserCount = bufferVariableList.count("beginOfUserVariables");
    int endUserCount = bufferVariableList.count("endOfUserVariables");

    bool errorUser = false, errorPrivate = false;

    if((beginPrivateCount == 1) && (endPrivateCount == 1))
    {
        int beginPrivate = bufferVariableList.indexOf("beginOfPrivateVariables");
        int endPrivate = bufferVariableList.indexOf("endOfPrivateVariables");
        for(int privateIndex = beginPrivate + 1; privateIndex < endPrivate; privateIndex++)
        {
            QString privateVariable = bufferVariableList.at(privateIndex);
            privateVariables.addVariable(privateVariable.toStdString(), 0.0);
        }
    }
    else {
        errorPrivate = true;
    }

    if((beginUserCount == 1) && (endUserCount == 1))
    {
        int beginUser = bufferVariableList.indexOf("beginOfUserVariables");
        int endUser = bufferVariableList.indexOf("endOfUserVariables");

        for(int userIndex = beginUser + 1; userIndex < endUser; userIndex++)
        {
            QString userVariable = bufferVariableList.at(userIndex);
            userVariables.addVariable(userVariable.toStdString(), 0.0);
        }
    }
    else {
        errorUser = true;
    }
}

QStringList SPIIProtocol::requestBufferVariables(const unsigned int &bufferNumber, const int &attempts, const unsigned int &startingBufferSize)
{
    std::string begin = "#";
    std::string end = "VG\r";
    std::string dBuffer = std::to_string(bufferNumber);
    std::string concatenatedRequest = begin + dBuffer + end;

    char *cstr = new char[concatenatedRequest.length() + 1];
    strcpy(cstr, concatenatedRequest.c_str());

    int bufferSize = static_cast<int>(startingBufferSize);
    int currentAttempt = 1;
    bool validAttempt = true, retry = true;
    int received = 0;

    std::string bufString;

    while (validAttempt && retry)
    {
        char* buf = new char[bufferSize]();
        validAttempt = acsc_Transaction(*m_SPIIDevice.get(),cstr, strlen(cstr), buf, bufferSize, &received, NULL);

        if(!validAttempt)
            break;

        if(received == bufferSize)
        {
            if((currentAttempt < attempts) || (attempts == -1))
            {
                currentAttempt++;
                bufferSize = bufferSize * 2;
            }
            else {
                retry = false;
                bufString = std::string(buf);
            }
        }
        else {
            retry = false;
            bufString = std::string(buf);
        }

        delete[] buf;
    }

    bufString.erase(bufString.begin()+received, bufString.end());
    QString newQString = QString::fromStdString(bufString);
    QStringList stringList = newQString.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    return stringList;
}

std::string SPIIProtocol::requestBufferContents(const unsigned int &bufferNumber, const int &attempts, const unsigned int &startingBufferSize)
{
    int bufferSize = static_cast<int>(startingBufferSize);
    int currentAttempt = 1;
    bool validAttempt = true, retry = true;
    int received = 0;

    std::string rtnString;

    while (validAttempt && retry)
    {
        char* buf = new char[bufferSize]();
        validAttempt = acsc_UploadBuffer(*m_SPIIDevice.get(),static_cast<int>(bufferNumber),0,buf,bufferSize,&received,NULL);
        if(!validAttempt)
            break;

        if(received == bufferSize)
        {
            if((currentAttempt < attempts) || (attempts == -1))
            {
                currentAttempt++;
                bufferSize = bufferSize * 2;
            }
            else {
                retry = false;
                rtnString = std::string(buf);
            }
        }
        else {
            retry = false;
            rtnString = std::string(buf);
        }
        delete[] buf;
    }

    return rtnString;
}

bool SPIIProtocol::requestRealScalarVariable(const std::string &variableName, double &value)
{
    double currentValue[0];

    char *cstr = new char[variableName.length() + 1];
    strcpy(cstr, variableName.c_str());

    bool validRequest = acsc_ReadReal(*m_SPIIDevice.get(),ACSC_NONE,cstr,ACSC_NONE,ACSC_NONE,ACSC_NONE,ACSC_NONE,currentValue,NULL);
    value = currentValue[0];
    return validRequest;
}


} //END Comms
