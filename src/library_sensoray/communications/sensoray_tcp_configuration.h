#ifndef SENSORARY_TCP_CONFIGURATION_H
#define SENSORARY_TCP_CONFIGURATION_H

#include <QTcpSocket>

#include <string>
#include "common/comms/link_configuration.h"

namespace sensoray{
namespace comms{

class SensorayTCPConfiguration : public common::comms::LinkConfiguration
{
public:
    SensorayTCPConfiguration();
    SensorayTCPConfiguration(const std::string &deviceAddress, const int &listenPort, const unsigned short &model);
    SensorayTCPConfiguration(SensorayTCPConfiguration* copy);

    // Destructor
    ~SensorayTCPConfiguration();

    std::string getDeviceAddress() const { return _deviceAddress; }
    int getTelnetPort() const { return _telnetPortNumber; }
    unsigned short getModelType() const{return _model;}

    void setDeviceAddress(std::string address);
    void setTelnetPortNumber(int portNumber);
    void setDeviceModel(const unsigned short &model);

    /// From LinkConfiguration
    void        copyFrom        (LinkConfiguration* source);

private:
    int _telnetPortNumber;
    std::string _deviceAddress;
    unsigned short _model;
};

} //end of namepsace comms
} //end of namespace sensoray

#endif // SENSORARY_TCP_CONFIGURATION_H
