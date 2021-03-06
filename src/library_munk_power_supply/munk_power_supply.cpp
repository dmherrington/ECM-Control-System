#include "munk_power_supply.h"

MunkPowerSupply::MunkPowerSupply(const std::string &name):
    deviceName(name),
    m_segmentTimeGeneral(),
    m_fwdISetpoint(TypeSupplyOutput::OUTPUT1,SegmentMode::FORWARD),
    m_revISetpoint(TypeSupplyOutput::OUTPUT1,SegmentMode::REVERSE),
    m_fwdVSetpoint(TypeSupplyOutput::OUTPUT1,SegmentMode::FORWARD),
    m_revVSetpoint(TypeSupplyOutput::OUTPUT1,SegmentMode::REVERSE)
{
    //    qRegisterMetaType<SensorState>("SensorState");
    //    qRegisterMetaType<TupleSensorString>("TupleSensorString");

    commsMarshaler = new MunkCommsMarshaler();
    commsMarshaler->AddSubscriber(this);

    pollStatus = new MunkPollStatus();
    pollStatus->connectCallback(this);

    machineState = new Munk_MachineState();
}

MunkPowerSupply::~MunkPowerSupply()
{
    commsMarshaler->DisconnetFromLink();
    delete commsMarshaler;
    commsMarshaler = nullptr;
}

void MunkPowerSupply::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        return;
    }

    QJsonObject saveObject;
    this->write(saveObject);
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}

void MunkPowerSupply::write(QJsonObject &json) const
{
    QJsonArray segmentDataArray;
    std::vector<registers_Munk::SegmentTimeDataDetailed> segmentData =
            this->machineState->getCurrentSegmentData().getRegisterData();

    for(size_t i = 0; i < segmentData.size(); i++)
    {
        QJsonObject segmentObject;
        segmentData.at(i).write(segmentObject);
        segmentDataArray.append(segmentObject);
    }

    json["segmentData"] = segmentDataArray;
}

void MunkPowerSupply::openSerialPort(const std::string &name)
{
    SerialConfiguration config(name);
    config.setBaud(19200);
    commsMarshaler->ConnectToLink(config);
}

void MunkPowerSupply::closeSerialPort()
{
    pollStatus->pausePolling();
    commsMarshaler->DisconnetFromLink();
}

void MunkPowerSupply::resetFaultState()
{
    registers_Munk::Register_FaultReset resetFault;
    resetFault.setSlaveAddress(01);
    commsMarshaler->sendRegisterFaultStateClear(resetFault);
}

bool MunkPowerSupply::isConnected() const
{
    return commsMarshaler->isConnected();
}

void MunkPowerSupply::writeRegisterPulseMode(const registers_Munk::Register_PulseMode &pulseMode)
{
    commsMarshaler->sendRegisterPulseMode(pulseMode);
}

void MunkPowerSupply::generateAndTransmitMessage(const SegmentTimeDetailed &detailedSegmentData)
{
    generateMessages(detailedSegmentData);
    commsProgress.clearCurrentProgress();

    std::vector<registers_Munk::ParameterType> currentRegisters;
    currentRegisters.push_back(registers_Munk::ParameterType::VOLTAGESETPOINT_FORWARD);
    currentRegisters.push_back(registers_Munk::ParameterType::VOLTAGESETPOINT_REVERSE);
    currentRegisters.push_back(registers_Munk::ParameterType::CURRENTSETPOINT_FORWARD);
    currentRegisters.push_back(registers_Munk::ParameterType::CURRENTSETPOINT_REVERSE);
    currentRegisters.push_back(registers_Munk::ParameterType::SEGMENTTIMES);
    currentRegisters.push_back(registers_Munk::ParameterType::MEMORYWRITE);

    commsProgress.transmittingNewSegment(currentRegisters);

    std::vector<AbstractParameterPtr> parameters;
    parameters.push_back(std::make_shared<SegmentVoltageSetpoint>(m_fwdVSetpoint));
    parameters.push_back(std::make_shared<SegmentVoltageSetpoint>(m_revVSetpoint));
    parameters.push_back(std::make_shared<SegmentCurrentSetpoint>(m_fwdISetpoint));
    parameters.push_back(std::make_shared<SegmentCurrentSetpoint>(m_revISetpoint));
    parameters.push_back(std::make_shared<SegmentTimeGeneral>(m_segmentTimeGeneral));
    registers_Munk::ParameterMemoryWritePtr memoryWrite = std::make_shared<ParameterMemoryWrite>();
    memoryWrite->setSlaveAddress(01);
    parameters.push_back(memoryWrite);

    commsMarshaler->sendCompleteMunkParameters(detailedSegmentData, parameters);
}

void MunkPowerSupply::generateMessages(const SegmentTimeDetailed &detailedSegmentData)
{
    //SegmentTime Parameter holding data
    m_segmentTimeGeneral.setSlaveAddress(detailedSegmentData.getSlaveAddress());
    m_segmentTimeGeneral.initializeData();
    m_fwdISetpoint.setSlaveAddress(detailedSegmentData.getSlaveAddress());
    m_fwdISetpoint.initializeData();
    m_revISetpoint.setSlaveAddress(detailedSegmentData.getSlaveAddress());
    m_revISetpoint.initializeData();
    m_fwdVSetpoint.setSlaveAddress(detailedSegmentData.getSlaveAddress());
    m_fwdVSetpoint.initializeData();
    m_revVSetpoint.setSlaveAddress(detailedSegmentData.getSlaveAddress());
    m_revVSetpoint.initializeData();

    //maps holding containers to determine what is unique
    std::map<RegisterDataObject,data_Munk::SegmentLevel> fwdMap;
    std::map<RegisterDataObject,data_Munk::SegmentLevel> revMap;

    std::vector<SegmentTimeDataDetailed> detailedData = detailedSegmentData.getRegisterData();

    std::vector<std::string> fwdLevelVector = getListOfSegmentLevel();
    int fwdLevelCounter = 0;
    std::vector<std::string> revLevelVector = getListOfSegmentLevel();
    int revLevelCounter = 0;

    //allow us to loop through all of the possible data segments
    for(unsigned int i = 0; i < detailedData.size(); i++)
    {
        registers_Munk::SegmentTimeDataDetailed detail = detailedData.at(i);
        //determine the mode of the segment
        data_Munk::SegmentMode mode = detail.getSegmentMode();

        if(mode == data_Munk::SegmentMode::FORWARD)
        {
            if(fwdMap.count(detail.getRegisterDataObject()) > 0)
            {
                //the element had already existed in the forward queue and therefore we do nothing
                std::cout<<"The voltage " <<detail.getRegisterDataObject().voltage <<" and current "<<detail.getRegisterDataObject().current<<" had already existed."<<std::endl;
            }
            else{
                if(fwdLevelCounter >= 8)
                {
                    //emit messageGenerationProgress(Data::DataFaultCodes::DATA_FAULT_TOO_MANY_VI_COMBOS);
                    return;
                }
                //assign a new level to this combination
                data_Munk::SegmentLevel newLevel = SegmentLevelFromString(fwdLevelVector.at(fwdLevelCounter));
                fwdMap.insert(std::pair<RegisterDataObject,data_Munk::SegmentLevel>(detail.getRegisterDataObject(),newLevel));

                SegmentVoltageData vData(newLevel,mode);
                vData.updateVoltageSetpoint(detail.getRegisterDataObject().voltage);
                m_fwdVSetpoint.appendData(vData);
                SegmentCurrentData iData(newLevel,mode);
                iData.updateCurrentSetpoint(detail.getRegisterDataObject().current);
                m_fwdISetpoint.appendData(iData);
                fwdLevelCounter++;
            }
            SegmentLevel level = fwdMap.at(detail.getRegisterDataObject());
            SegmentTimeDataGeneral generalData(level,mode,detail.getTimeValue());
            m_segmentTimeGeneral.appendRegisterData(generalData);
        }
        else if(mode == data_Munk::SegmentMode::REVERSE)
        {
            if(revMap.count(detail.getRegisterDataObject()) > 0)
            {
                //the element had already existed in the forward queue and therefore we do nothing
                std::cout<<"The voltage " <<detail.getRegisterDataObject().voltage <<" and current "<<detail.getRegisterDataObject().current<<" had already existed."<<std::endl;
            }
            else
            {
                if(revLevelCounter >= 8)
                {
                    //emit messageGenerationProgress(Data::DataFaultCodes::DATA_FAULT_TOO_MANY_VI_COMBOS);
                    return;
                }

                //assign a new level to this combination
                data_Munk::SegmentLevel newLevel = SegmentLevelFromString(revLevelVector.at(revLevelCounter));
                revMap.insert(std::pair<RegisterDataObject,data_Munk::SegmentLevel>(detail.getRegisterDataObject(),newLevel));

                SegmentVoltageData vData(newLevel,mode);
                vData.updateVoltageSetpoint(detail.getRegisterDataObject().voltage);
                m_revVSetpoint.appendData(vData);
                SegmentCurrentData iData(newLevel,mode);
                iData.updateCurrentSetpoint(detail.getRegisterDataObject().current);
                m_revISetpoint.appendData(iData);
                revLevelCounter++;
            }
            SegmentLevel level = revMap.at(detail.getRegisterDataObject());
            SegmentTimeDataGeneral generalData(level,mode,detail.getTimeValue());
            m_segmentTimeGeneral.appendRegisterData(generalData);
        }
        else if(mode == data_Munk::SegmentMode::DEAD)
        {
            SegmentTimeDataGeneral generalData;
            generalData.setSegmentMode(data_Munk::SegmentMode::DEAD);
            generalData.setTimeValue(detail.getTimeValue());
            m_segmentTimeGeneral.appendRegisterData(generalData);
        }
        else if(mode == data_Munk::SegmentMode::HIZ)
        {
            SegmentTimeDataGeneral generalData;
            generalData.setSegmentMode(data_Munk::SegmentMode::HIZ);
            generalData.setTimeValue(detail.getTimeValue());
            m_segmentTimeGeneral.appendRegisterData(generalData);
        }
        else{
            //Ken: Figure out what to do this in case
        }
    }
}

/////////////////////////////////////////////////////////
/// Virtual Functions imposed from comms::CommsEvents
/////////////////////////////////////////////////////////

void MunkPowerSupply::ConnectionOpened() const
{
    common::comms::CommunicationUpdate connection;
    connection.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
    emit signal_MunkCommunicationUpdate(connection);

    common::NotificationUpdate newUpdate("Munk PS",ECMDevice::DEVICE_POWERSUPPLY,common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL);
    newUpdate.setPeripheralMessage("Munk Power Suppy Connected.");
    emit signal_MunkNotification(newUpdate);

    pollStatus->beginPolling();
}

void MunkPowerSupply::ConnectionClosed() const
{
    common::comms::CommunicationUpdate connection;
    connection.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED);
    emit signal_MunkCommunicationUpdate(connection);
}

void MunkPowerSupply::CommunicationError(const std::string &type, const std::string &msg) const
{
    emit signal_CommunicationError(type,msg);
}

void MunkPowerSupply::CommunicationUpdate(const std::string &name, const std::string &msg) const
{
    emit signal_CommunicationUpdate(name,msg);
}

void MunkPowerSupply::FaultCodeReceived(const data_Munk::FaultRegisterType &faultRegister, const unsigned int &code)
{
    response_Munk::FaultRegisterState newFaultState(faultRegister,code);
    if(machineState->updateRegisterFaults(newFaultState))
    {
        emit signal_MunkFaultCodeStatus(true,newFaultState.getCurrentFaultCodes());
    }
}

void MunkPowerSupply::FaultStateCleared()
{
    std::vector<std::string> faultCleared;
    emit signal_MunkFaultCodeStatus(false,faultCleared);
}

void MunkPowerSupply::ForwardVoltageSetpointAcknowledged()
{
    std::string msg = "The forward voltage setpoints have been set.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(registers_Munk::ParameterType::VOLTAGESETPOINT_FORWARD,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::ReverseVoltageSetpointAcknowledged()
{
    std::string msg = "The reverse voltage setpoints have been set.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(registers_Munk::ParameterType::VOLTAGESETPOINT_REVERSE,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::ForwardCurrentSetpointAcknowledged()
{
    std::string msg = "The forward current setpoints have been set.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(registers_Munk::ParameterType::CURRENTSETPOINT_FORWARD,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::ReverseCurrentSetpointAcknowledged()
{
    std::string msg = "The reverse current setpoints have been set.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(registers_Munk::ParameterType::CURRENTSETPOINT_REVERSE,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::SegmentTimeAcknowledged()
{
    std::string msg = "The segment times have been set.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(registers_Munk::ParameterType::SEGMENTTIMES,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::SegmentCommitedToMemoryAcknowledged()
{
    std::string msg = "The segment has been commited to memory.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(registers_Munk::ParameterType::MEMORYWRITE,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::NewSegmentSequence(const bool &success, const SegmentTimeDetailed &segmentData)
{
    this->machineState->updateCurrentSegmentData(segmentData);
    this->onFinishedUploadingSegments(success);
}

void MunkPowerSupply::NewPulseMode(const bool &success, const registers_Munk::Register_PulseMode &pulseMode)
{
    this->onFinishedUploadingPulseMode(success);
}

void MunkPowerSupply::ExceptionResponseReceived(const MunkRWType &RWType, const std::string &meaning) const
{
    if(RWType == data_Munk::MunkRWType::READ)
        emit signal_SegmentException("READING",meaning);
    else
        emit signal_SegmentException("WRITING",meaning);
}

void MunkPowerSupply::cbi_MunkFaultStateRequest(const RegisterFaultState &request) const
{
    commsMarshaler->sendRegisterFaultStateRequest(request);
}

std::string MunkPowerSupply::getLogOfOperationalSettings() const
{
    std::string str;

    SegmentTimeDetailed segmentData = this->machineState->getCurrentSegmentData();
    std::vector<registers_Munk::SegmentTimeDataDetailed> registerData = segmentData.getRegisterData();
    for(size_t i = 0; i < registerData.size(); i++)
    {
        str += registerData.at(i).getLoggingString() + "\n";
    }

    return str;
}


