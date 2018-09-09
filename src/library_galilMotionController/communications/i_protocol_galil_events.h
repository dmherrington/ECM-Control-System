#ifndef I_PROTOCOL_GALIL_EVENTS_H
#define I_PROTOCOL_GALIL_EVENTS_H

#include "requests/request_components.h"

#include "status/status_components.h"

#include "programs/program_components.h"

#include "commands/command_components.h"

namespace Comms
{

//!
//! \brief Interface that it to be implemented by users of MavlinkComms to listen for any events it fired
//!
class IProtocolGalilEvents
{
public:
    //!
    //! \brief NewCustomStatusReceived
    //! \param initialCommand
    //! \param newStatus
    //!
    virtual void NewCustomStatusReceived(const std::string &initialCommand, const std::string &newStatus) const = 0;

    //!
    //! \brief NewStatusReceived
    //! \param status
    //!
    virtual void NewStatusReceived(const std::vector<AbstractStatusPtr> &status) const = 0;

    //!
    //! \brief NewPositionReceived
    //! \param status
    //!
    virtual void NewPositionReceived(const Status_Position &status) const = 0;

    //!
    //! \brief NewProgramUploaded
    //! \param program
    //!
    virtual void NewProgramUploaded(const ProgramGeneric &program) const = 0;

    //!
    //! \brief NewProgramDownloaded
    //! \param program
    //!
    virtual void NewProgramDownloaded(const ProgramGeneric &program) const = 0;

    //!
    //! \brief ErrorBadCommand
    //! \param type
    //! \param description
    //!
    virtual void ErrorBadCommand(const CommandType &type, const std::string &description) const = 0;

    //!
    //! \brief ErrorBadRequest
    //! \param type
    //! \param description
    //!
    virtual void ErrorBadRequest(const RequestTypes &type, const std::string &description) const = 0;
};


} //END Comms

#endif // I_PROTOCOL_GALIL_EVENTS_H
