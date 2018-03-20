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
    virtual void NewStatusReceived(const std::vector<AbstractStatusPtr> &status) const = 0;

    virtual void NewPositionReceived(const Status_Position &status) const = 0;

    virtual void NewProgramDownloaded(const ProgramGeneric &program) const = 0;

    virtual void NewProgramUploaded(const ProgramGeneric &program) const = 0;

    virtual void ErrorBadCommand(const CommandType &type, const std::string &description) const = 0;
};


} //END Comms

#endif // I_PROTOCOL_GALIL_EVENTS_H
