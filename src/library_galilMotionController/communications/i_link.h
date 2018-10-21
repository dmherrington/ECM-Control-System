#ifndef I_LINK_GALIL_H
#define I_LINK_GALIL_H

#include <cstdlib>
#include <memory>
#include <vector>
#include <functional>
#include <QThread>

#include "i_link_events.h"
#include "requests/abstract_request.h"
#include "commands/abstract_command.h"

#include "gclib.h"

namespace Comms
{

class ILink
{
public:

    ILink()
    {

    }

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
    virtual void SetLinkAddress(const std::string &str)
    {
        address = str;
    }

    virtual std::string GetLinkAddress() const
    {
        return this->address;
    }

    virtual GReturn UploadProgram(const std::string &programText) const = 0;
    virtual GReturn DownloadProgram(std::string &programText) const = 0;

    virtual GReturn WriteCommand(const std::string &command) const = 0;

    virtual GReturn WriteRequest(const AbstractRequestPtr request) const = 0;

    virtual GReturn WriteTellErrorCode(unsigned int &errorCode, std::string &description) const = 0;

    //!
    //! \brief Determine the connection status
    //! \return True if the connection is established, false otherwise
    //!
    virtual bool isConnected() const = 0;


    virtual void Connect(void) = 0;
    virtual void Disconnect(void) = 0;

    virtual void MarshalOnThread(std::function<void()> func) = 0;

protected:
    std::string address; /**< Member variable containing information about the address to the unit. */

private:
    std::vector<const ILinkEvents*> m_Listeners;
};

} //end of namespace Comms

#endif // I_LINK_GALIL_H
