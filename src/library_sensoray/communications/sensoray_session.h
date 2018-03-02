#ifndef SENSORAY_SESSION_H
#define SENSORAY_SESSION_H

#include <QObject>

#include "s24xx.h"

namespace sensoray{
namespace comms {

class SensoraySession : public QObject
{
    Q_OBJECT

public:
    SensoraySession():
        handle(nullptr)
    {

    }

    SensoraySession(const SensoraySession &copy)
    {
        this->connectedAPI = copy.connectedAPI;
        this->connectedDevice = copy.connectedDevice;
        this->connectedComms = copy.connectedComms;
        this->handle = copy.handle;
    }

    ~SensoraySession() = default;

    HSESSION handle;

    void setAPIOpen(const bool &status){ connectedAPI = status;}
    void setDeviceConnected(const bool &status) { connectedDevice = status;}
    void setCommPortOpened(const bool &status) { connectedComms = status; }

    bool isAPIOpen(){ return connectedAPI;}
    bool isDeviceConnected() { return connectedDevice;}
    bool isCommPortOpened() { return connectedComms; }
private:
    bool connectedAPI = false; /**< Boolean member variable capturing the status of the device connection*/
    bool connectedDevice = false; /**< Boolean member variable capturing the status of the device connection*/
    bool connectedComms = false; /**< Boolean member variable capturing the status of the com port connection post API*/
};

} //end of namespace comms
} //end of namespace sensoray

#endif // SENSORAY_SESSION_H
