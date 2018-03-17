#ifndef RIGOL_I_LINK_H
#define RIGOL_I_LINK_H

#include <cstdlib>
#include <memory>
#include <vector>
#include <functional>
#include <QThread>
#include <QByteArray>

#include "i_link_events.h"
#include "tcp_configuration.h"

#include "commands/measure/measure_command_item.h"


namespace comms_Rigol{

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
    //! \brief WriteBytes
    //! \param bytes
    //! \param length
    //!
    virtual void WriteBytes(const QByteArray &data_Rigol) const = 0;

    //!
    //! \brief WriteBytesRequest
    //! \param data
    //!
    //!
    virtual std::vector<uint8_t> WriteBytesRequest(const QByteArray &data_Rigol) const = 0;

    //!
    //! \brief setSerialConfiguration
    //! \param config
    //!
    virtual void setTCPConfiguration(const TCPConfiguration &config) = 0;

    //!
    //! \brief Determine the connection status
    //! \return True if the connection is established, false otherwise
    //!
    virtual bool isConnected() const = 0;

    //!
    //! \brief Connect
    //! \return
    //!
    virtual bool Connect(void) = 0;

    //!
    //! \brief Disconnect
    //! \return
    //!
    virtual bool Disconnect(void) = 0;

    //!
    //! \brief MarshalOnThread
    //! \param func
    //!
    virtual void MarshalOnThread(std::function<void()> func) = 0;

private:
    std::vector<const ILinkEvents*> m_Listeners; /**< Member variable containing information about the address to the unit. */

};

} //end of namespace comms


#endif // RIGOL_I_LINK_H
