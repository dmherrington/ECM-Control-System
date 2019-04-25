#include "ecm_api.h"

ECM_API::ECM_API()
{    
    m_Log = new ECMLogging(this->getSoftwareVersions());

    m_Rigol = new RigolOscilliscope();

    m_Munk = new MunkPowerSupply();

    m_MotionController = new SPIIMotionController();

    m_Sensoray = new Sensoray();

    m_Modbus485 = new Library_QModBus();

    m_Pump = new Westinghouse510(m_Modbus485,03);

}

std::map<std::string, std::string> ECM_API::getSoftwareVersions() const
{
    std::map<std::string, std::string> softwareVersionMap;

    softwareVersionMap.insert(std::pair<std::string,std::string>("ECM API",ECMAPI_VERSION_STRING));
    //softwareVersionMap.insert(std::pair<std::string,std::string>("SPII Library",LIBGALIL_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("MUNK Library",LIBMUNK_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("WESTINGHOUSE  Library",LIBWESTINGHOUSE_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("SENSORAY Library",LIBSENSORAY_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("RIGOL Library",LIBRIGOL_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("MODBUS Library",LIBMODBUS_VERSION_STRING));

    softwareVersionMap.insert(std::pair<std::string,std::string>("COMMON Library",LIBCOMMON_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("DATA Library",LIBDATA_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("GRAPHING Library",LIBGRAPHING_VERSION_STRING));

    return softwareVersionMap;
}

bool ECM_API::checkLoggingPathValidity(const string &partNumber, const string &serialNumber) const
{
    return m_Log->checkLoggingPath(partNumber, serialNumber);
}

void ECM_API::initializeOperationalCollection(const ECMCommand_ExecuteCollectionPtr executionCollection, const bool &clearContents)
{
    //gets the file and directory structure ready for us
    m_Log->initializeLogging(executionCollection->getPartNumber(),
                             executionCollection->getSerialNumber(),
                             clearContents);

    //writes the properties of the configuration to a log file
    m_Log->writeExecutionCollection(executionCollection);

    ExecutionProperties props;
    props.setTime(executionCollection->getStartTime());
    props.setMaxIndex(executionCollection->getCollectionSize());
    emit signal_ExecutingCollection(props);

}

void ECM_API::initializeLoggingOperation(const std::string &partNumber, const std::string &serialNumber,
                                      const ECMCommand_AbstractProfileConfigPtr configuration, const std::string &description)
{
    switch (configuration->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        ECMCommand_ProfileConfigurationPtr castConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(configuration);

        m_Log->writeProfileLoggingHeader(partNumber,serialNumber,castConfig->getOperationName(),
                                  castConfig->getProfileName(),description,
                                  castConfig->m_ExecProperties.getStartTime());
        break;
    }
    case ProfileOpType::PAUSE:
    {
        ECMCommand_ProfilePausePtr castConfig = static_pointer_cast<ECMCommand_ProfilePause>(configuration);

        m_Log->writePauseLoggingHeader(partNumber,serialNumber,castConfig->getOperationName(),
                                  description, castConfig->m_ExecProperties.getStartTime());

        break;
    }
    default:
        break;
    }

}

void ECM_API::logCurrentOperationalSettings()
{
    std::string operationsString;
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "PUMP OPERATIONAL SETTTINGS: \n";
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += m_Pump->getLogOfOperationalSettings();
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "POWER SUPPLY OPERATIONAL SETTTINGS: \n";
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += m_Munk->getLogOfOperationalSettings();
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "MOTION CONTROLLER OPERATIONAL SCRIPT: \n";
    this->writeHeaderBreaker(operationsString, 100);
    //operationsString += m_MotionController->stateInterface->galilProgram->getProgram();
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "MOTION CONTROLLER OPERATIONAL VARIABLES: \n";
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += m_MotionController->m_StateInterface->m_BufferManager->getCurrentUserVariables().getLoggingString();
    operationsString += "\r\n";

    m_Log->writeCurrentOperationalSettings(operationsString);
}

void ECM_API::writeToLogStartingPosition()
{
    //int startPosition = m_MotionController->stateInterface->getAxisStatus(MotorAxis::Z)->getPosition().getPosition();
    //m_Log->writeStartingPosition(startPosition);
}

void ECM_API::beginLoggingOperationalData(const ProfileOpType &type)
{
    m_Log->beginLoggingOperationalData(type);
}

void ECM_API::beginOperationalProfile(const ECMCommand_AbstractProfileConfigPtr profileConfig, const ExecuteOperationProperties::ExecutionCondition &condition)
{
    //Assemble a message to notify any listeners that we are about to execute an operation
    ExecuteOperationProperties props(profileConfig->getOperationName(), profileConfig->getOperationIndex());
    props.setOperatingCondition(condition);
    props.setTime(profileConfig->m_ExecProperties.getStartTime());

    std::vector<double> machinePosition = m_MotionController->m_StateInterface->m_AxisPosition->getAxisPositionVector();
    props.setCurrentPosition(machinePosition);

    //Emit the signal notifying the listeners of a new operational profile
    emit signal_ExecutingOperation(props);
}

void ECM_API::executeExplicitProfile(const ECMCommand_ProfileConfigurationPtr profileConfig)
{
    //Begin requesting of information from the oscilliscope
    m_Rigol->executeMeasurementPolling(true);

    CommandExecuteProfilePtr command = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::PROFILE,
                                                                               profileConfig->getProfileName());
    m_MotionController->executeCommand(command);
}

void ECM_API::executePauseProfile(const ECMCommand_ProfilePausePtr profileConfig)
{
    //Stop requesting of information from the oscilliscope
    m_Rigol->executeMeasurementPolling(false);

    //Lastly, send a command to make sure the power supply has been stopped
    CommandSetBitPtr command = std::make_shared<CommandSetBit>();
    command->setValue(0,2,false);
    m_MotionController->executeCommand(command);
}

void ECM_API::concludeExecutingOperation(const ECMCommand_AbstractProfileConfigPtr profileConfig)
{
    //Stop requesting information from the oscilliscope device
    m_Rigol->executeMeasurementPolling(false);

    //int concludingPosition = m_MotionController->stateInterface->getAxisStatus(MotorAxis::Z)->getPosition().getPosition();
    int concludingPosition = 0;
    //Conclude writing to the logs with any wrap up data that we need
    m_Log->WriteConcludingOperationStats(profileConfig->m_ExecProperties.getElapsedTime(),
                                         concludingPosition, profileConfig->m_ExecProperties.getProfileCode());

    //Disable the logs so no more contents are written post the machining operation
    m_Log->enableLogging(false);

    //Assemble a message to notify any listeners that we are finished executing an operation
    ExecuteOperationProperties props(profileConfig->getOperationName(), profileConfig->getOperationIndex());
    props.setOperatingCondition(ExecutionProperties::ExecutionCondition::ENDING);
    props.setTime(profileConfig->m_ExecProperties.getEndTime());

    std::vector<double> machinePosition = m_MotionController->m_StateInterface->m_AxisPosition->getAxisPositionVector();
    props.setCurrentPosition(machinePosition);

    //Emit the signal notifying the listeners of a completed operational profile
    emit signal_ExecutingOperation(props);

}

void ECM_API::concludeExecutingCollection(const ECMCommand_ExecuteCollectionPtr executionCollection)
{
    //During this process is where we should close the logs and everything associated with the operation
    m_Log->CloseMachiningLog(executionCollection->getElapsedTime());

    //Assemble a message to notify any listeners that we are finished executing the collection
    ExecutionProperties props;
    props.setOperatingCondition(ExecutionProperties::ExecutionCondition::ENDING);
    props.setTime(executionCollection->getEndTime());

    //Emit the signal notifying the listeners of a completed operational profile
    emit signal_ExecutingCollection(props);
}

void ECM_API::notifyNewOuterState(const ECM::API::ECMState &state, const std::string &stateString)
{
    emit signal_NewOuterState(state, stateString);
}

void ECM_API::notifyPausedEvent(const std::string notificationText)
{
    emit signal_InPauseEvent(notificationText);
}

void ECM_API::action_StopMachine()
{
    CommandStopPtr commandMotionStop = std::make_shared<CommandStop>();
    m_MotionController->executeCommand(commandMotionStop);

    m_Pump->ceasePumpOperations();
}

void ECM_API::action_EStopMachine()
{
    CommandEStopPtr commandEStop = std::make_shared<CommandEStop>();
    m_MotionController->executeCommand(commandEStop);

    m_Pump->ceasePumpOperations();
}

void ECM_API::writeHeaderBreaker(std::string &logString, const unsigned int &size) const
{
    //Write header breaker line at the top
    for(size_t i = 0; i < size; i++)
    {
        logString = logString + "*";
    }
    //bump the header to the next line
    logString = logString + "\n";
}
