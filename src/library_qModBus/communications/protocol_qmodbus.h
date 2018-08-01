#ifndef PROTOCOL_QMODBUS_H
#define PROTOCOL_QMODBUS_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>
#include <list>

#include "iostream"

#include "common/common.h"
#include "common/comms/serial_configuration.h"

#include "../../tools/libmodbus/src/modbus.h"

#include "i_link.h"
#include "qmodbus_link.h"
#include "i_protocol_qmodbus_events.h"
#include "i_protocol.h"


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

namespace comms_QModBus{

class QModBusProtocol : public IProtocol
{

public:
    QModBusProtocol();

    void AddListner(const IProtocolQModBusEvents* listener);

public:

    unsigned int getSlaveID() const;

    void setSlaveAddress(const unsigned int &slaveAddress);

    void writeDataToSingleRegister(const unsigned int &slaveAddress, const int &data);
private:

    void Emit(const std::function<void(const IProtocolQModBusEvents*)> func)
    {
        for(const IProtocolQModBusEvents* listener : m_Listners)
            func(listener);
    }


private:

    unsigned int slaveID;

    std::vector<const IProtocolQModBusEvents*> m_Listners;
};


} //end of namespace comms_QModBus

#endif // PROTOCOL_QMODBUS_H
