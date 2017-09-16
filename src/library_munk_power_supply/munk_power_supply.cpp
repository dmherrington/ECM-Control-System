#include "munk_power_supply.h"

MunkPowerSupply::MunkPowerSupply()
{
    portHelper = new SerialPortHelper(this);
    connect(portHelper,SIGNAL(bytesReceived(QByteArray)),this,SLOT(receivedMSG(QByteArray)));

//    DataParameter::SegmentTimeDetailed detailedData(1);
//    DataParameter::SegmentTimeDataDetailed detailedOne(10,50,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
//    detailedData.appendRegisterData(detailedOne);
//    DataParameter::SegmentTimeDataDetailed detailedFour(10,102,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
//    detailedData.appendRegisterData(detailedFour);
//    DataParameter::SegmentTimeDataDetailed detailedFive(50,133,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
//    detailedData.appendRegisterData(detailedFive);
//    DataParameter::SegmentTimeDataDetailed detailedSeven(70,151,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
//    detailedData.appendRegisterData(detailedSeven);
//    DataParameter::SegmentTimeDataDetailed detailedEight(80,10,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
//    detailedData.appendRegisterData(detailedEight);

//    generateMessages(detailedData);
}

void MunkPowerSupply::transmitMessage(const QByteArray &data)
{
    portHelper->writeBytes(data);
}

void MunkPowerSupply::generateAndTransmitMessage(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
{
    generateMessages(detailedSegmentData);
}

void MunkPowerSupply::generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
{
    //SegmentTime Parameter holding data
    DataParameter::SegmentTimeGeneral generalSegment;
    generalSegment.setSlaveAddress(detailedSegmentData.getSlaveAddress());

    //maps holding containers to determine what is unique
    std::map<Data::RegisterDataObject,Data::SegmentLevel> fwdMap;
    std::map<Data::RegisterDataObject,Data::SegmentLevel> revMap;

    std::vector<DataParameter::SegmentTimeDataDetailed> detailedData = detailedSegmentData.getRegisterData();
    //this restricts it to only assume 1 output supply for now
    DataParameter::SegmentCurrentSetpoint fwdISetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::FORWARD);
    fwdISetpoint.setSlaveAddress(detailedSegmentData.getSlaveAddress());
    DataParameter::SegmentCurrentSetpoint revISetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::REVERSE);
    revISetpoint.setSlaveAddress(detailedSegmentData.getSlaveAddress());

    DataParameter::SegmentVoltageSetpoint fwdVSetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::FORWARD);
    fwdVSetpoint.setSlaveAddress(detailedSegmentData.getSlaveAddress());
    DataParameter::SegmentVoltageSetpoint revVSetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::REVERSE);
    revVSetpoint.setSlaveAddress(detailedSegmentData.getSlaveAddress());

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
                fwdVSetpoint.appendData(vData);
                DataParameter::SegmentCurrentData iData(newLevel,mode);
                iData.updateCurrentSetpoint(detail.getRegisterDataObject().current);
                fwdISetpoint.appendData(iData);
                fwdLevelCounter++;
            }
            Data::SegmentLevel level = fwdMap.at(detail.getRegisterDataObject());
            DataParameter::SegmentTimeDataGeneral generalData(level,mode,detail.getTimeValue());
            generalSegment.appendRegisterData(generalData);
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
                revVSetpoint.appendData(vData);
                DataParameter::SegmentCurrentData iData(newLevel,mode);
                iData.updateCurrentSetpoint(detail.getRegisterDataObject().current);
                revISetpoint.appendData(iData);
                revLevelCounter++;
            }
            Data::SegmentLevel level = revMap.at(detail.getRegisterDataObject());
            DataParameter::SegmentTimeDataGeneral generalData(level,mode,detail.getTimeValue());
            generalSegment.appendRegisterData(generalData);
        }
        else if(mode == Data::SegmentMode::DEAD)
        {
            DataParameter::SegmentTimeDataGeneral generalData;
            generalData.setSegmentMode(Data::SegmentMode::DEAD);
            generalData.setTimeValue(detail.getTimeValue());
            generalSegment.appendRegisterData(generalData);
        }
        else if(mode == Data::SegmentMode::HIZ)
        {
            DataParameter::SegmentTimeDataGeneral generalData;
            generalData.setSegmentMode(Data::SegmentMode::HIZ);
            generalData.setTimeValue(detail.getTimeValue());
            generalSegment.appendRegisterData(generalData);
        }
        else{
            //Ken: Figure out what to do this in case
        }
    }

    emit(signal_NewCurrentSetpoint(revISetpoint,fwdISetpoint));
    emit(signal_NewVoltageSetpoint(revVSetpoint,fwdVSetpoint));
    emit(signal_NewTimeSetpoint(generalSegment));

    //returnMSG = {fwdISetpoint,revISetpoint,fwdVSetpoint,revVSetpoint,generalSegment};
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

}

void MunkPowerSupply::receivedMSG(const QByteArray &data)
{
    std::cout<<"I saw the receiving msg"<<std::endl;
}
