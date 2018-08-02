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

class ILink
{
public:

    //!
    //! \brief ILink
    //!
    ILink()
    {

    }

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
    virtual bool WriteSingleRegister(const unsigned long &data) const = 0;

    //!
    //! \brief setSerialConfiguration
    //! \param config
    //!
    virtual void setSerialConfiguration(const common::comms::SerialConfiguration &config) = 0;

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

private:
    std::vector<const ILinkEvents*> m_Listeners; /**< Member variable containing information about the address to the unit. */

};

} //end of namespace comms_QModBus

#endif // I_LINK_QMODBUS_H
