#include "westinghouse_510.h"

Westinghouse510::Westinghouse510(const common::comms::ICommunication *commsObject, const int &pumpAddress, const std::string &name):
    m_Comms(commsObject),
    deviceName(name)
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_SerialPortUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_SerialPortUpdate(common::comms::CommunicationUpdate)));
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_RXNewSerialData(QByteArray)),this,SLOT(slot_SerialPortReceivedData(QByteArray)));

    initializationTimer = new QTimer(this);
    initializationTimer->setSingleShot(true);
    connect(initializationTimer,SIGNAL(timeout()),this,SLOT(slot_PumpInitializationComplete()));

    this->m_State = new Westinghouse510_State();

    m_DataFraming = new comms_WestinghousePump::WestinghouseDataFraming(pumpAddress);

}

//!
//! \brief setPumpFlowRate function transmitting the desired flow rate to the communication object.
//! It is the role of the communication object to then transmit the desired flow rate to the appropriate
//! device.
//! \param desRate object reflecting the desired flow rate of the pump
//!
void Westinghouse510::setPumpFlowRate(const registers_WestinghousePump::Register_FlowRate &desRate)
{
    this->m_Comms->writeToSerialPort(desRate.getModbusRegister());
}

//!
//! \brief setPumpOperations function transmitting the desired operational procedures of the pump.
//! Controls operations such as run/reverse/fault/reset.
//! \param desOps object reflecting the desired operations of the pump
//!
void Westinghouse510::setPumpOperations(const registers_WestinghousePump::Register_OperationSignal &desOps)
{
    if(!desOps.isRun())
    {
        //if we were trying to turn off the pump,
        //let us stop the initialization timer in the event it was running
        initializationTimer->stop();
    }

    this->m_Comms->writeToSerialPort(desOps.getModbusRegister());
}

void Westinghouse510::ceasePumpOperations()
{
    registers_WestinghousePump::Register_OperationSignal newOps;
    newOps.shouldRun(false);
    this->setPumpOperations(newOps);
}

void Westinghouse510::setInitializationTime(const unsigned int &interval)
{
    this->m_State->delayTime.set(interval);
    initializationTimer->setInterval(interval);
}

bool Westinghouse510::isPumpConnected() const
{
    return this->m_Comms->isSerialPortOpen();
}

bool Westinghouse510::isPumpInitialized() const
{
    return this->m_State->pumpInitialized.get();
}

bool Westinghouse510::isPumpRunning() const
{
    return this->m_State->pumpON.get();
}

void Westinghouse510::openPumpConnection(const std::string &portNumber)
{
    common::comms::SerialConfiguration config("WestinghousePort");
    config.setPortName(portNumber);
    this->m_Comms->openSerialPortConnection(config);

    //this->slot_SerialPortReadyToConnect();
}

void Westinghouse510::slot_SerialPortReadyToConnect()
{
//    const auto infos = QSerialPortInfo::availablePorts();
//    for (const QSerialPortInfo &info : infos)
//    {
//        if(info.portName() == "COM14")
//        {
//            config.setPortName("\\\\.\\COM14");
//            this->m_Comms->openSerialPortConnection(config);
//        }
//    }

}

void Westinghouse510::slot_SerialPortUpdate(const common::comms::CommunicationUpdate &update)
{
    using namespace common::comms;
    switch (update.getUpdateType()) {
    case CommunicationUpdate::UpdateTypes::ALERT:

        break;
    case CommunicationUpdate::UpdateTypes::CONNECTED:
    {
        m_State->pumpConnected.set(true);
        registers_WestinghousePump::Register_RunSource updateRunSource(registers_WestinghousePump::Register_RunSource::SourceSetting::SOURCE_RS485);
        this->m_Comms->writeToSerialPort(updateRunSource.getModbusRegister());

        this->ceasePumpOperations();

        break;
    }
    case CommunicationUpdate::UpdateTypes::DISCONNECTED:
        m_State->pumpConnected.set(false);
        break;
//    case CommunicationUpdate::UpdateTypes::ERROR:

//        break;
    case CommunicationUpdate::UpdateTypes::UPDATE:

        break;
    default:
        break;
    }
    emit signal_PumpCommunicationUpdate(update);
}

void Westinghouse510::slot_SerialPortReceivedData(const QByteArray &data)
{
    for(int i = 0; i < data.size(); i++)
    {
        comms_WestinghousePump::WestinghouseFramingState currentState = m_DataFraming->additionalByteRecevied(data.at(i));
        if(currentState == comms_WestinghousePump::WestinghouseFramingState::RECEIVED_ENTIRE_MESSAGE)
        {
            comms_WestinghousePump::WestinghouseMessage rxMSG = m_DataFraming->getCurrentMessage();
            this->parseReceivedMessage(rxMSG);
        }
    }
}

void Westinghouse510::slot_PumpInitializationComplete()
{
    this->m_State->pumpInitialized.set(true);

    emit signal_PumpInitialized();
}

void Westinghouse510::parseReceivedMessage(const comms_WestinghousePump::WestinghouseMessage &msg)
{
    if(msg.isException() == data_WestinghousePump::WestinghouseExceptionTypes::EXCEPTION)
    {

    }
    else {
        if(msg.isReadWriteType() == data_WestinghousePump::RWType::WRITE)
        {
            uint8_t dataHi = msg.getDataByte(2);
            uint8_t dataLo = msg.getDataByte(3);
            int registerCode = dataLo | (dataHi<<8);
            registers_WestinghousePump::WestinhouseRegisterTypes rxType = registers_WestinghousePump::RegisterTypeFromInt(registerCode);
            switch (rxType) {
            case registers_WestinghousePump::WestinhouseRegisterTypes::FLOWRATE:
            {
                registers_WestinghousePump::Register_FlowRate writeFlow;
                writeFlow.parseFromArray(msg.getDataArray());
                if(m_State->flowRate.set(writeFlow.getVolumetricFlow()))
                {
                    emit signal_PumpFlowUpdated(writeFlow.getVolumetricFlow());
                }
                break;
            }
            case registers_WestinghousePump::WestinhouseRegisterTypes::OPERATION_SIGNAL:
            {
                registers_WestinghousePump::Register_OperationSignal writeOps;
                writeOps.parseFromArray(msg.getDataArray());
                if(m_State->pumpON.set(writeOps.isRun()))
                {
                    if(m_State->pumpON.get()) //if the pump has turned on
                    {
                        //begin the initialization countdown
                        initializationTimer->start();
                    }
                    else{
                        if(initializationTimer->isActive())
                            initializationTimer->stop();
                        this->m_State->pumpInitialized.set(false);
                    }

                    emit signal_PumpOperating(writeOps.isRun());
                }
                break;
            }
            default:
                break;
            }
        }
        else
        {

        }
    }
}

std::string Westinghouse510::getLogOfOperationalSettings() const
{
    std::string str;
    //Let us write the header contents
    str += "Volumetric Flow: " + std::to_string(m_State->flowRate.get()) + " lpm. \n";
    str += "Initialization Time: " + std::to_string(m_State->delayTime.get()) +" milliseconds. \n";
    return str;
}


void Westinghouse510::saveToFile(const QString &filePath)
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

void Westinghouse510::write(QJsonObject &json) const
{
    json["pumpDelayTime"] = (int)this->m_State->delayTime.get();
    json["pumpFlowRate"] = this->m_State->flowRate.get();
}


