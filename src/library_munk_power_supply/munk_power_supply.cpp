#include "munk_power_supply.h"

MunkPowerSupply::MunkPowerSupply():
    m_fwdISetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::FORWARD),
    m_revISetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::REVERSE),
    m_fwdVSetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::FORWARD),
    m_revVSetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::REVERSE)
{
    portHelper = new SerialPortHelper(this);
    connect(portHelper,SIGNAL(bytesReceived(QByteArray)),this,SLOT(receivedMSG(QByteArray)));

    m_segmentTimeGeneral = DataParameter::SegmentTimeGeneral();
}

void MunkPowerSupply::transmitMessage(const QByteArray &data)
{
    portHelper->writeBytes(data);
}

void MunkPowerSupply::generateAndTransmitMessage(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
{
    generateMessages(detailedSegmentData);

    QByteArray fwdIArray = m_fwdISetpoint.getFullMessage();
    QByteArray revIArray = m_revISetpoint.getFullMessage();
    QByteArray fwdVArray = m_fwdVSetpoint.getFullMessage();
    QByteArray revVArray = m_revVSetpoint.getFullMessage();
    QByteArray dataArray = m_segmentTimeGeneral.getFullMessage();
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
                    emit messageGenerationProgress(Data::DataFaultCodes::DATA_FAULT_TOO_MANY_VI_COMBOS);
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
                    emit messageGenerationProgress(Data::DataFaultCodes::DATA_FAULT_TOO_MANY_VI_COMBOS);
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

//    emit(signal_NewCurrentSetpoint(m_revISetpoint,m_fwdISetpoint));
//    emit(signal_NewVoltageSetpoint(m_revVSetpoint,m_fwdVSetpoint));
//    emit(signal_NewTimeSetpoint(m_segmentTimeGeneral));
}

void MunkPowerSupply::openSerialPort()
{
    portHelper->openSerialPort();
}

void MunkPowerSupply::configureSerialPort(const QString &name)
{
  portHelper->configureSerialPort(name);
}

void MunkPowerSupply::configureSerialPort(const QString &name, const QSerialPort::BaudRate &rate, const QSerialPort::DataBits &bits, const QSerialPort::Parity &parity, const QSerialPort::StopBits &stop)
{
    UNUSED(name);
    UNUSED(rate);
    UNUSED(bits);
    UNUSED(parity);
    UNUSED(stop);
}

void MunkPowerSupply::closeSerialPort()
{
    portHelper->closeSerialPort();
}

void MunkPowerSupply::receivedMSG(const QByteArray &data)
{
    std::cout<<"I saw the receiving msg"<<std::endl;
}
