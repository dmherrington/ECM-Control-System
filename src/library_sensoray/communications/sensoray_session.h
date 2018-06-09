#ifndef SENSORAY_SESSION_H
#define SENSORAY_SESSION_H

#include <QObject>

#include "s24xx.h"

/**
\* @file  sensoray_session.h
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

namespace comms_Sensoray {

class SensoraySession : public QObject
{
    Q_OBJECT

public:
    SensoraySession():
        handle(nullptr)
    {

    }

    SensoraySession(const SensoraySession &copy) = delete;

    ~SensoraySession() = default;

    HSESSION handle;

    void setAPIOpen(const bool &status){ connectedAPI = status;}
    void setDeviceConnected(const bool &status) { connectedDevice = status;}
    void setSerialPortConnected(const bool &status) { connectedComms = status; }

    bool isAPIOpen(){ return connectedAPI;}
    bool isDeviceConnected() { return connectedAPI && connectedDevice;}
    bool isSerialPortConnected() { return connectedAPI && connectedDevice && connectedComms; }
private:
    bool connectedAPI = false; /**< Boolean member variable capturing the status of the device connection*/
    bool connectedDevice = false; /**< Boolean member variable capturing the status of the device connection*/
    bool connectedComms = false; /**< Boolean member variable capturing the status of the com port connection post API*/
};

} //end of namespace comms


#endif // SENSORAY_SESSION_H
