#include "ecm_api.h"

ECM_API::ECM_API()
{    
    m_Log = new ECMLogging(this->getSoftwareVersions());

    m_Rigol = new RigolOscilliscope();

    m_Munk = new MunkPowerSupply();

    m_Galil = new GalilMotionController();

    m_Sensoray = new Sensoray();

    m_Modbus485 = new Library_QModBus();

    m_Pump = new Westinghouse510(m_Modbus485,03);

}

std::map<std::string, std::string> ECM_API::getSoftwareVersions() const
{
    std::map<std::string, std::string> softwareVersionMap;

    softwareVersionMap.insert(std::pair<std::string,std::string>("ECM API",ECMAPI_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("GALIL Library",LIBGALIL_VERSION_STRING));
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

void ECM_API::initializeOperationalCollection(const ECMCommand_ExecuteCollection &executionCollection, const bool &clearContents)
{
    //gets the file and directory structure ready for us
    m_Log->initializeLogging(executionCollection.getPartNumber(),
                             executionCollection.getSerialNumber(),
                             clearContents);

    //writes the properties of the configuration to a log file
    m_Log->writeExecutionCollection(executionCollection);

    ExecutionProperties props;
    props.setTime(executionCollection.getStartTime());
    props.setMaxIndex(executionCollection.getCollectionSize());
    emit signal_ExecutingCollection(props);

}

void ECM_API::initializeOperationLogs(const ECMCommand_ExecuteCollection &executionCollection,
                                const std::string &descriptor)
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
    operationsString += m_Galil->stateInterface->galilProgram->getProgram();
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "MOTION CONTROLLER OPERATIONAL VARIABLES: \n";
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += m_Galil->stateInterface->galilProgram->getVariableList().getLoggingString();
    operationsString += "\r\n";

    ECMCommand_ProfileConfiguration profileConfig = executionCollection.getActiveConfiguration();
    m_Log->writeLoggingHeader(executionCollection.getPartNumber(),executionCollection.getSerialNumber(),profileConfig.getOperationName(),
                              profileConfig.getProfileName(),operationsString,descriptor,
                              profileConfig.execProperties.getStartTime());
}

void ECM_API::executeOperationalProfile(const ECMCommand_ProfileConfiguration &profileConfig)
{
    //Enable logging of any current machining information that comes through
    m_Log->enableLogging(true);

    //Begin requesting of information from the oscilliscope
    m_Rigol->executeMeasurementPolling(true);

    //Assemble a message to notify any listeners that we are about to execute an operation
    ExecuteOperationProperties props(profileConfig.getOperationName(), profileConfig.getOperationIndex());
    props.setTime(profileConfig.execProperties.getStartTime());

    //Emit the signal notifying the listeners of a new operational profile
    emit signal_ExecutingOperation(props);

    CommandExecuteProfilePtr command = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::PROFILE,
                                                                               profileConfig.getProfileName());
    m_Galil->executeCommand(command);
}

void ECM_API::concludeExecutingOperation(const ECMCommand_ProfileConfiguration &profileConfig)
{
    //Conclude writing to the logs with any wrap up data that we need
    m_Log->WriteConcludingOperationStats(profileConfig.execProperties.getElapsedTime(),
                             profileConfig.execProperties.getProfileCode());

    //Disable the logs so no more contents are written post the machining operation
    m_Log->enableLogging(false);

    //Stop requesting information from the oscilliscope device
    m_Rigol->executeMeasurementPolling(false);

    //Assemble a message to notify any listeners that we are finished executing an operation
    ExecuteOperationProperties props(profileConfig.getOperationName(), profileConfig.getOperationIndex());
    props.setOperatingCondition(ExecutionProperties::ExecutionCondition::ENDING);
    props.setTime(profileConfig.execProperties.getEndTime());

    //Emit the signal notifying the listeners of a completed operational profile
    emit signal_ExecutingOperation(props);

}

void ECM_API::concludeExecutingCollection(const ECMCommand_ExecuteCollection &executionCollection)
{
    //During this process is where we should close the logs and everything associated with the operation
    m_Log->CloseMachiningLog(executionCollection.getElapsedTime());

    //Assemble a message to notify any listeners that we are finished executing an operation
    ExecutionProperties props;
    props.setOperatingCondition(ExecutionProperties::ExecutionCondition::ENDING);
    props.setTime(executionCollection.getEndTime());

    //Emit the signal notifying the listeners of a completed operational profile
    emit signal_ExecutingCollection(props);
}

void ECM_API::notifyNewOuterState(const std::string &stateString)
{
    emit signal_NewOuterState(stateString);
}

void ECM_API::notifyPausedEvent(const std::string notificationText)
{
    emit signal_InPauseEvent(notificationText);
}

void ECM_API::action_StopMachine()
{
    CommandStopPtr commandGalilStop = std::make_shared<CommandStop>();
    m_Galil->executeCommand(commandGalilStop);

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
