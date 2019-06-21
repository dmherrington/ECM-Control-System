#include "sensoray_tcp_configuration.h"


namespace comms_Sensoray{

SensorayTCPConfiguration::SensorayTCPConfiguration()
{
    _deviceAddress       = "192.168.15.16";
    _telnetPortNumber    = 23;
    _model = 2426;
}

SensorayTCPConfiguration::SensorayTCPConfiguration(const std::string& deviceAddress, const int &telnetPort, const unsigned short &model)
{
    _deviceAddress       = deviceAddress;
    _telnetPortNumber    = telnetPort;
    _model               = model;
}

SensorayTCPConfiguration::~SensorayTCPConfiguration()
{

}

SensorayTCPConfiguration::SensorayTCPConfiguration(SensorayTCPConfiguration* copy)
{
    _deviceAddress       = copy->getDeviceAddress();
    _telnetPortNumber    = copy->getTelnetPort();
    _model               = copy->getModelType();
}

void SensorayTCPConfiguration::copyFrom(LinkConfiguration* source)
{
    LinkConfiguration::copyFrom(source);
    SensorayTCPConfiguration* ssource = dynamic_cast<SensorayTCPConfiguration*>(source);
    Q_ASSERT(ssource != NULL);
    _deviceAddress               = ssource->getDeviceAddress();
    _telnetPortNumber            = ssource->getTelnetPort();
    _model                       = ssource->getModelType();

}

void SensorayTCPConfiguration::setDeviceAddress(std::string address)
{
    _deviceAddress = address;
}

void SensorayTCPConfiguration::setTelnetPortNumber(int portNumber)
{
    _telnetPortNumber = portNumber;
}

void SensorayTCPConfiguration::setDeviceModel(const unsigned short &model)
{
    _model = model;
}

} //end of namepsace comms

