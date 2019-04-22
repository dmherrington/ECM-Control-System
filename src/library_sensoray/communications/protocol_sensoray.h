#ifndef PROTOCOL_SENSORAY_H
#define PROTOCOL_SENSORAY_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>
#include <list>

#include "iostream"

#include "common/common.h"
#include "common/comms/serial_configuration.h"

#include "i_link.h"
#include "sensoray_link.h"
#include "sensoray_session.h"
#include "i_protocol_sensoray_events.h"
#include "i_protocol.h"

#include "s24xx.h"

/**
\* @file  protocol_sensoray.h
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

class SensorayProtocol : public IProtocol
{

public:
    SensorayProtocol();

    void AddListner(const IProtocolSensorayEvents* listener);

public:

    //////////////////////////////////////////////////////////////
    /// Method issuing a request to the sensoray device
    //////////////////////////////////////////////////////////////
    bool openSerialPort(const common::comms::SerialConfiguration &config);

    bool closeSerialPort ();

    void transmitDataToSerialPort(const QByteArray &msg);

    //////////////////////////////////////////////////////////////
    /// Method issuing a request to the sensoray device
    //////////////////////////////////////////////////////////////
    void resetSensorayIO();

    void readSensorayADC();

    void updateCurrentSession(SensoraySession* session);
private:

    void Emit(const std::function<void(const IProtocolSensorayEvents*)> func)
    {
        for(const IProtocolSensorayEvents* listener : m_Listners)
            func(listener);
    }

private:
    SensoraySession* m_Session;

    std::vector<const IProtocolSensorayEvents*> m_Listners;
};


} //end of namespace comms

#endif // PROTOCOL_SENSORAY_H
