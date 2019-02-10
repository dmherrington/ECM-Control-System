#ifndef I_LINK_SPII_H
#define I_LINK_SPII_H

#include <cstdlib>
#include <memory>
#include <vector>
#include <functional>
#include <QThread>

#include "common/comms/serial_configuration.h"
#include "common/comms/tcp_configuration.h"

#include "ACSC.h"
#include "i_link_events.h"


namespace Comms {

enum class COMMS_TYPE {
    SERIAL,
    ETHERNET,
    PCI,
    SIMULATION
};

typedef struct {
    COMMS_TYPE type;				// 0 - serial, 1 - ethernet, 2 - PCI bus, 3 -simulator
    common::comms::SerialConfiguration serialPort;
    common::comms::TCPConfiguration ethernetPort;
    ACSC_PCI_SLOT PCISlot;
} COMM_SETTINGS;

class ILink
{

public:

    ILink() = default;
    virtual ~ILink() = default;

    void AddListener(const ILinkEvents* ptr)
    {
        m_Listeners.push_back(ptr);
    }

    void EmitEvent(const std::function<void(const ILinkEvents*)> &func) const
    {
        for(const ILinkEvents* listener : m_Listeners)
        {
            func(listener);
        }
    }

    //!
    //! \brief Set the name of the link
    //! \param str Name of link
    //!
    virtual void SetSimulationConnection()
    {
        m_CommunicationSettings.type = COMMS_TYPE::SIMULATION;
    }

    //!
    //! \brief Set the name of the link
    //! \param str Name of link
    //!
    virtual void SetSerialConnection(const common::comms::SerialConfiguration &config)
    {
        m_CommunicationSettings.type = COMMS_TYPE::SERIAL;
        m_CommunicationSettings.serialPort = config;
    }

    //!
    //! \brief Set the name of the link
    //! \param str Name of link
    //!
    virtual void SetEthernetConnection(const common::comms::TCPConfiguration &config)
    {
        m_CommunicationSettings.type = COMMS_TYPE::ETHERNET;
        m_CommunicationSettings.ethernetPort = config;
    }

    //!
    //! \brief Set the name of the link
    //! \param str Name of link
    //!
    virtual void SetPCIConnection(const ACSC_PCI_SLOT &config)
    {
        m_CommunicationSettings.type = COMMS_TYPE::PCI;
        m_CommunicationSettings.PCISlot = config;
    }

    virtual COMM_SETTINGS GetConnectionSettings() const
    {
        return this->m_CommunicationSettings;
    }

    //!
    //! \brief Determine the connection status
    //! \return True if the connection is established, false otherwise
    //!
    virtual bool isConnected() const = 0;


    virtual void Connect(void) = 0;
    virtual void Disconnect(void) = 0;

    virtual void MarshalOnThread(std::function<void()> func) = 0;

protected:
    COMM_SETTINGS m_CommunicationSettings;

private:
    std::vector<const ILinkEvents*> m_Listeners;
};

} //end of namespace Comms

#endif // I_LINK_SPII_H
