#ifndef I_LINK_QMODBUS_H
#define I_LINK_QMODBUS_H

#include <cstdlib>
#include <memory>
#include <vector>
#include <functional>
#include <QThread>
#include <QByteArray>

#include "i_link_events.h"
#include "common/comms/serial_configuration.h"
#include "common/comms/tcp_configuration.h"

/**
\* @file  i_link.h
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

enum class COMMS_TYPE {
    SERIAL,
    ETHERNET,
};

typedef struct {
    COMMS_TYPE type;				// 0 - serial, 1 - ethernet
    common::comms::SerialConfiguration serialPort;
    common::comms::TCPConfiguration ethernetPort;
} COMM_SETTINGS;

class ILink
{
public:

    //!
    //! \brief ILink
    //!
    ILink()
    {

    }

    virtual ~ILink() = default;

    //!
    //! \brief AddListener
    //! \param ptr
    //!
    void AddListener(const ILinkEvents* ptr)
    {
        m_Listeners.push_back(ptr);
    }

    //!
    //! \brief EmitEvent
    //! \param func
    //!
    void EmitEvent(const std::function<void(const ILinkEvents*)> &func) const
    {
        for(const ILinkEvents* listener : m_Listeners)
        {
            func(listener);
        }
    }

    //!
    //! \brief RequestReset
    //!
    virtual void RequestReset() = 0;

    //!
    //! \brief GetSlaveAddress
    //! \return
    //!
    virtual unsigned int GetSlaveAddress() const = 0;

    //!
    //! \brief SetSlaveAddress
    //! \param slaveAddress
    //!
    virtual void SetSlaveAddress(const unsigned int &slaveAddress) = 0;

    //!
    //! \brief WriteBytes
    //! \param bytes
    //! \param length
    //!
    virtual bool WriteSingleRegister(const unsigned long &dataRegister, const unsigned long &data) const = 0;

    //!
    //! \brief setSerialConfiguration
    //! \param config
    //!
    virtual void setSerialConfiguration(const common::comms::SerialConfiguration &config)
    {
        m_CommunicationSettings.type = COMMS_TYPE::SERIAL;
        m_CommunicationSettings.serialPort = config;
    }

    //!
    //! \brief setSerialConfiguration
    //! \param config
    //!
    virtual void setTCPConfiguration(const common::comms::TCPConfiguration &config)
    {
        m_CommunicationSettings.type = COMMS_TYPE::ETHERNET;
        m_CommunicationSettings.ethernetPort = config;
    }

    //!
    //! \brief Determine the connection status
    //! \return True if the connection is established, false otherwise
    //!
    virtual bool isConnected() const = 0;

    //!
    //! \brief Connect
    //! \return
    //!
    virtual bool ConnectToDevice(void) = 0;

    //!
    //! \brief Disconnect
    //! \return
    //!
    virtual bool DisconnectFromDevice(void) = 0;

    //!
    //! \brief MarshalOnThread
    //! \param func
    //!
    virtual void MarshalOnThread(std::function<void()> func) = 0;

protected:
    COMM_SETTINGS m_CommunicationSettings;

private:
    std::vector<const ILinkEvents*> m_Listeners; /**< Member variable containing information about the address to the unit. */

};

} //end of namespace Comms

#endif // I_LINK_QMODBUS_H
