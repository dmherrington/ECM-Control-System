#include "munk_power_supply.h"

MunkPowerSupply::MunkPowerSupply():
    m_segmentTimeGeneral(),
    m_fwdISetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::FORWARD),
    m_revISetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::REVERSE),
    m_fwdVSetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::FORWARD),
    m_revVSetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::REVERSE)
{
    qRegisterMetaType<data::SensorState>("SensorState");
    qRegisterMetaType<common::TupleSensorString>("TupleSensorString");

    commsMarshaler = new comms::MunkCommsMarshaler();
    commsMarshaler->AddSubscriber(this);

    pollStatus = new MunkPollStatus();
    pollStatus->connectCallback(this);
    pollStatus->beginPolling();
}

MunkPowerSupply::~MunkPowerSupply()
{
    commsMarshaler->DisconnetFromLink();
    delete commsMarshaler;
    commsMarshaler = nullptr;
}

void MunkPowerSupply::openSerialPort(const QString &name)
{
    comms::SerialConfiguration config(name.toStdString());
    commsMarshaler->ConnectToLink(config);
}

void MunkPowerSupply::closeSerialPort()
{
    pollStatus->pausePolling();
    commsMarshaler->DisconnetFromLink();
}

void MunkPowerSupply::generateAndTransmitMessage(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
{
    generateMessages(detailedSegmentData);
    commsProgress.clearCurrentProgress();
    std::vector<MunkMessageType> messages;

    QByteArray fwdVArray = m_fwdVSetpoint.getFullMessage();
    if(fwdVArray.size() > 0)
    {
        commsMarshaler->sendForwardVoltageSetpoint(m_fwdVSetpoint);
        messages.push_back(MunkMessageType::FWDVolt);
    }

    QByteArray fwdIArray = m_fwdISetpoint.getFullMessage();
    if(fwdIArray.size() > 0)
    {
        commsMarshaler->sendForwardCurrentSetpoint(m_fwdISetpoint);
        messages.push_back(MunkMessageType::REVVolt);
    }

    QByteArray revVArray = m_revVSetpoint.getFullMessage();
    if(revVArray.size() > 0)
    {
        commsMarshaler->sendReverseVoltageSetpoint(m_revVSetpoint);
        messages.push_back(MunkMessageType::FWDCur);
    }

    QByteArray revIArray = m_revISetpoint.getFullMessage();
    if(revIArray.size() > 0)
    {
        commsMarshaler->sendReverseCurrentSetpoint(m_revISetpoint);
        messages.push_back(MunkMessageType::REVCur);
    }

    QByteArray dataArray = m_segmentTimeGeneral.getFullMessage();
    if(dataArray.size() > 0)
    {
        commsMarshaler->sendSegmentTime(m_segmentTimeGeneral);
        messages.push_back(MunkMessageType::SEGTime);
    }

    commsMarshaler->sendCommitToEEPROM();
    messages.push_back(MunkMessageType::Mem);
    commsProgress.transmittingNewSegment(messages);

    int needed = 0;
    int required = 0;
    commsProgress.currentProgress(needed,required);
    emit signal_SegmentWriteProgress(needed,required);
}

void MunkPowerSupply::generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
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
    std::map<Data::RegisterDataObject,Data::SegmentLevel> fwdMap;
    std::map<Data::RegisterDataObject,Data::SegmentLevel> revMap;

    std::vector<DataParameter::SegmentTimeDataDetailed> detailedData = detailedSegmentData.getRegisterData();

    std::vector<std::string> fwdLevelVector = Data::getListOfSegmentLevel();
    int fwdLevelCounter = 0;
    std::vector<std::string> revLevelVector = Data::getListOfSegmentLevel();
    int revLevelCounter = 0;

    //allow us to loop through all of the possible data segments
    for(unsigned int i = 0; i < detailedData.size(); i++)
    {
        DataParameter::SegmentTimeDataDetailed detail = detailedData.at(i);
        //determine the mode of the segment
        Data::SegmentMode mode = detail.getSegmentMode();

        if(mode == Data::SegmentMode::FORWARD)
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
                Data::SegmentLevel newLevel = Data::SegmentLevelFromString(fwdLevelVector.at(fwdLevelCounter));
                fwdMap.insert(std::pair<Data::RegisterDataObject,Data::SegmentLevel>(detail.getRegisterDataObject(),newLevel));

                DataParameter::SegmentVoltageData vData(newLevel,mode);
                vData.updateVoltageSetpoint(detail.getRegisterDataObject().voltage);
                m_fwdVSetpoint.appendData(vData);
                DataParameter::SegmentCurrentData iData(newLevel,mode);
                iData.updateCurrentSetpoint(detail.getRegisterDataObject().current);
                m_fwdISetpoint.appendData(iData);
                fwdLevelCounter++;
            }
            Data::SegmentLevel level = fwdMap.at(detail.getRegisterDataObject());
            DataParameter::SegmentTimeDataGeneral generalData(level,mode,detail.getTimeValue());
            m_segmentTimeGeneral.appendRegisterData(generalData);
        }
        else if(mode == Data::SegmentMode::REVERSE)
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
                Data::SegmentLevel newLevel = Data::SegmentLevelFromString(revLevelVector.at(revLevelCounter));
                revMap.insert(std::pair<Data::RegisterDataObject,Data::SegmentLevel>(detail.getRegisterDataObject(),newLevel));

                DataParameter::SegmentVoltageData vData(newLevel,mode);
                vData.updateVoltageSetpoint(detail.getRegisterDataObject().voltage);
                m_revVSetpoint.appendData(vData);
                DataParameter::SegmentCurrentData iData(newLevel,mode);
                iData.updateCurrentSetpoint(detail.getRegisterDataObject().current);
                m_revISetpoint.appendData(iData);
                revLevelCounter++;
            }
            Data::SegmentLevel level = revMap.at(detail.getRegisterDataObject());
            DataParameter::SegmentTimeDataGeneral generalData(level,mode,detail.getTimeValue());
            m_segmentTimeGeneral.appendRegisterData(generalData);
        }
        else if(mode == Data::SegmentMode::DEAD)
        {
            DataParameter::SegmentTimeDataGeneral generalData;
            generalData.setSegmentMode(Data::SegmentMode::DEAD);
            generalData.setTimeValue(detail.getTimeValue());
            m_segmentTimeGeneral.appendRegisterData(generalData);
        }
        else if(mode == Data::SegmentMode::HIZ)
        {
            DataParameter::SegmentTimeDataGeneral generalData;
            generalData.setSegmentMode(Data::SegmentMode::HIZ);
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
    //pollStatus->beginPolling();
    emit signal_ConnectionStatusUpdated(true);
}

void MunkPowerSupply::ConnectionClosed() const
{
    emit signal_ConnectionStatusUpdated(false);
}

void MunkPowerSupply::CommunicationError(const std::string &type, const std::string &msg) const
{
    emit signal_CommunicationError(type,msg);
}

void MunkPowerSupply::CommunicationUpdate(const std::string &name, const std::string &msg) const
{
    emit signal_CommunicationUpdate(name,msg);
}

void MunkPowerSupply::FaultCodeRegister1Received(const std::string &msg)
{
    emit signal_FaultCodeRecieved(1,msg);
}

void MunkPowerSupply::FaultCodeRegister2Received(const std::string &msg)
{
    emit signal_FaultCodeRecieved(2,msg);
}

void MunkPowerSupply::FaultCodeRegister3Received(const std::string &msg)
{
    emit signal_FaultCodeRecieved(3,msg);
}

void MunkPowerSupply::ForwardVoltageSetpointAcknowledged(const int &numberOfRegisters)
{
    std::string msg = "The forward voltage setpoints have been set for ";
    msg += std::to_string(numberOfRegisters);
    msg += " registers.";
    emit signal_SegmentSetAck(msg);

    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(MunkMessageType::FWDVolt,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::ReverseVoltageSetpointAcknowledged(const int &numberOfRegisters)
{
    std::string msg = "The reverse voltage setpoints have been set for ";
    msg += std::to_string(numberOfRegisters);
    msg += " registers.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(MunkMessageType::REVVolt,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::ForwardCurrentSetpointAcknowledged(const int &numberOfRegisters)
{
    std::string msg = "The forward current setpoints have been set for ";
    msg += std::to_string(numberOfRegisters);
    msg += " registers.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(MunkMessageType::FWDCur,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::ReverseCurrentSetpointAcknowledged(const int &numberOfRegisters)
{
    std::string msg = "The reverse current setpoints have been set for ";
    msg += std::to_string(numberOfRegisters);
    msg += " registers.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(MunkMessageType::REVCur,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::SegmentTimeAcknowledged(const int &numberOfRegisters)
{
    std::string msg = "The segment times have been set for ";
    msg += std::to_string(numberOfRegisters);
    msg += " registers.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(MunkMessageType::SEGTime,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}

void MunkPowerSupply::SegmentCommitedToMemoryAcknowledged()
{
    std::string msg = "The segment has been commited to memory.";
    emit signal_SegmentSetAck(msg);
    int completed = 0;
    int required = 0;
    commsProgress.receivedAckProgress(MunkMessageType::Mem,completed,required);
    emit signal_SegmentWriteProgress(completed,required);
}


void MunkPowerSupply::ExceptionResponseReceived(const Data::ReadWriteType &RWType, const std::string &meaning) const
{
    if(RWType == Data::ReadWriteType::READ)
        emit signal_SegmentException("READING",meaning);
    else
        emit signal_SegmentException("WRITING",meaning);
}

void MunkPowerSupply::cbi_MunkFaultStateRequest(const DataParameter::RegisterFaultState &request) const
{
    common::TupleSensorString tupleSensor;
    tupleSensor.sourceName = "TestSource";
    tupleSensor.sensorName = "TestSensor";

    common::EnvironmentTime time;
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,time);

    data::SensorState stateSensor;
    stateSensor.ConstructSensor(data::SENSOR_VOLTAGE , "Sensor_Voltage");

    stateSensor.validityTime->setTime(time);
    double r = ((double) rand() / (RAND_MAX));
    ((data::SensorVoltage*)stateSensor.getSensorData().get())->SetVoltage(r*10.0,data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
    emit signal_NewSensorData(tupleSensor,stateSensor);

    //commsMarshaler->sendRegisterFaultStateRequest(request);
}


