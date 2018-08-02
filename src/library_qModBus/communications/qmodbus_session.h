#ifndef QMODBUS_SESSION_H
#define QMODBUS_SESSION_H

#include <QObject>

#include "modbus.h"

/**
\* @file  qmodbus_session.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is interact with the QModBus.
\*
\* @section DESCRIPTION
\*
\*
\*/

namespace comms_QModBus {

class QModBusSession : public QObject
{
    Q_OBJECT

public:
    QModBusSession():
        m_serialModbus(nullptr)
    {

    }

    QModBusSession(const QModBusSession &copy) = delete;

    ~QModBusSession() = default;

public:
    modbus_t* m_serialModbus;

    void setSerialPortConnected(const bool &status) { connectedDevice = status;}
    bool isSerialPortConnected() { return connectedDevice; }

private:
    bool connectedDevice = false; /**< Boolean member variable capturing the status of the device connection*/
};

} //end of namespace comms_QModBus

#endif // QMODBUS_SESSION_H
