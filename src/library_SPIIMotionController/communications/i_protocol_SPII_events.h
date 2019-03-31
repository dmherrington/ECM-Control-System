#ifndef I_PROTOCOL_SPII_EVENTS_H
#define I_PROTOCOL_SPII_EVENTS_H

#include <string>

#include "common/operation/operation_label_list.h"
#include "common/operation/operation_variable_list.h"

#include "../status/status_components.h"


namespace Comms
{

//!
//! \brief Interface that it to be implemented by users of MavlinkComms to listen for any events it fired
//!
class IProtocolSPIIEvents
{
public:
    virtual ~IProtocolSPIIEvents() = default;

public:
    virtual void NewBufferState(const Status_BufferState &state) const = 0;

    virtual void NewStatusMotor(const Status_Motor &status) const = 0;

    virtual void NewStatus_OperationalLabels(const Operation_LabelList &labelList) const = 0;

    virtual void NewStatus_OperationalVariables(const Operation_VariableList &variableList) = 0;
};


} //END Comms

#endif // I_PROTOCOL_SPII_EVENTS_H
