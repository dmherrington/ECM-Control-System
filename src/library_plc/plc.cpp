#include "plc.h"

PLC::PLC(const int &plcAddress, const std::string &name):
    deviceName(name)
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    m_Comms = new Library_QModBus();

    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_PortUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_PortUpdate(common::comms::CommunicationUpdate)));
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_RXNewRegister(ModbusRegister)),this,SLOT(slot_RXNewRegisterData(ModbusRegister)));

    m_DataFraming = new comms_PLC::PLCDataFraming(plcAddress);

    m_PollMachine = new PLCPollMachine();
    m_PollMachine->AddSubscriber(this);

    registers_PLC::AbstractPLCRegisterPtr registerPH = std::make_shared<registers_PLC::Register_pH>();
    registers_PLC::AbstractPLCRegisterPtr registerConductivity = std::make_shared<registers_PLC::Register_Conductivity>();

    m_PollMachine->addReadRegister(registerPH);
    m_PollMachine->addReadRegister(registerConductivity);
}


bool PLC::isDeviceConnected() const
{
    return this->m_Comms->isModbusPortOpen();
}

void PLC::openPLCConnection(const common::comms::TCPConfiguration &linkConfig)
{
    this->m_Comms->openEthernetPortConnection(linkConfig);
}

void PLC::closePLCConnection()
{
    this->m_Comms->closePortConnection();
}

void PLC::PLCPolling_NewReadRequest(const registers_PLC::AbstractPLCRegisterPtr req)
{
    this->m_Comms->readModbusDataPort(req->getModbusRegister());
}

void PLC::slot_PortUpdate(const common::comms::CommunicationUpdate &update)
{
    using namespace common::comms;
    switch (update.getUpdateType()) {
    case CommunicationUpdate::UpdateTypes::ALERT:

        break;
    case CommunicationUpdate::UpdateTypes::CONNECTED:
    {
        //Now we can notify the remaining parties
        common::comms::CommunicationUpdate commsUpdate(this->deviceName, ECMDevice::DEVICE_PLC);
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("PLC Device Connected.");
        emit signal_CommunicationUpdate(commsUpdate);

        common::NotificationUpdate newUpdate(this->deviceName,ECMDevice::DEVICE_PLC,common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL);
        newUpdate.setPeripheralMessage("PLC Device Connected.");
        emit signal_PLCNotification(newUpdate);

        m_PollMachine->beginPolling();
        break;
    }
    case CommunicationUpdate::UpdateTypes::DISCONNECTED:
    {
        //m_PollMachine->pausePolling();
        break;
    }
    case CommunicationUpdate::UpdateTypes::UPDATE:

        break;
    default:
        break;
    }
}

void PLC::slot_RXNewRegisterData(const ModbusRegister &regObj)
{
    common::EnvironmentTime currentTime;
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,currentTime);

    double currentValue = GetDoubleValue(regObj.readRegisterValue(), 32, 8);

    common_data::SensorState newSensorMeasurement;
    newSensorMeasurement.setObservationTime(currentTime);

    switch (registers_PLC::RegisterTypeFromInt(regObj.getRegisterCode())) {
    case registers_PLC::PLCRegisterTypes::PH:
    {
        //First let us construct the tuple describing the measurement
        common::TupleSensorString sensorTuple(QString::fromStdString(this->deviceName),
                                              QString::fromStdString(""),
                                              QString::fromStdString(registers_PLC::RegisterTypeToString(registers_PLC::PLCRegisterTypes::PH)));

            newSensorMeasurement.ConstructSensor(common_data::SENSOR_PH,"pH");
            ((common_data::Sensor_pH*)newSensorMeasurement.getSensorData().get())->setPH(currentValue,common_data::pHUnit::UNIT_BASE);
            emit signal_PLCNewSensorValue(sensorTuple,newSensorMeasurement);
        break;
    }
    case registers_PLC::PLCRegisterTypes::CONDUCTIVITY:
    {
        //First let us construct the tuple describing the measurement
        common::TupleSensorString sensorTuple(QString::fromStdString(this->deviceName),
                                              QString::fromStdString(""),
                                              QString::fromStdString(registers_PLC::RegisterTypeToString(registers_PLC::PLCRegisterTypes::CONDUCTIVITY)));

        newSensorMeasurement.ConstructSensor(common_data::SENSOR_CONDUCTIVITY,"Conductivity");
        ((common_data::Sensor_Conductivity*)newSensorMeasurement.getSensorData().get())->setConductivity(currentValue,common_data::ConductivityUnit::UNIT_BASE);
        emit signal_PLCNewSensorValue(sensorTuple,newSensorMeasurement);
        break;
    }
    default:
        break;
    }
}


