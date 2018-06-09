#ifndef SENSORARY_TCP_CONFIGURATION_H
#define SENSORARY_TCP_CONFIGURATION_H

#include <QTcpSocket>

#include <string>
#include "common/comms/link_configuration.h"

/**
\* @file  sensoray_tcp_configuration.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is interact with the sensoray.
\*
\* @section DESCRIPTION
\*
\*
\*/

namespace comms_Sensoray{

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


#endif // SENSORARY_TCP_CONFIGURATION_H
