#ifndef COMMS_EVENTS_GALIL_H
#define COMMS_EVENTS_GALIL_H

#include <string>
#include "common/common.h"

#include "common/comms/communication_update.h"

#include "status/status_components.h"
#include "programs/program_components.h"
#include "commands/command_components.h"

namespace Comms
{

class CommsEvents
{
public:

    /////////////////////////////////////////////////////////
    /// Link Events
    /////////////////////////////////////////////////////////

    virtual void LinkConnectionUpdate(const common::comms::CommunicationUpdate &update)
    {
        UNUSED(update);
    }

    virtual void LinkConnected()
    {

    }

    virtual void LinkDisconnected() const
    {

    }

    virtual void CustomUserRequestReceived(const std::string &request, const std::string &response)
    {
        UNUSED(request);
        UNUSED(response);
    }

    virtual void ErrorBadCommand(const std::string &commandType, const std::string &text)
    {
        UNUSED(commandType);
        UNUSED(text);
    }

    virtual void NewProgramDownloaded(const ProgramGeneric &program)
    {
        UNUSED(program);
    }

    virtual void NewProgramUploaded(const ProgramGeneric &program)
    {
        UNUSED(program);
    }

    virtual void StatusMessage(const std::string &msg) const
    {
        UNUSED(msg);
    }

    virtual void NewStatusInputs(const StatusInputs &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusPosition(const Status_Position &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusMotorEnabled(const Status_MotorEnabled &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusMotorInMotion(const Status_AxisInMotion &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusMotorStopCode(const Status_StopCode &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusVariableValue(const Status_VariableValue &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusLabelList(const Status_LabelList &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusVariableList(const Status_VariableList &status)
    {
        UNUSED(status);
    }

};

}

#endif // COMMS_EVENTS_GALIL_H
