#ifndef I_PROTOCOL_SPII_EVENTS_H
#define I_PROTOCOL_SPII_EVENTS_H

#include <string>

#include "common/operation/operation_label_list.h"
#include "common/operation/operation_variable_list.h"

#include "../status/status_components.h"

#include "../buffers/spii_current_program.h"
#include "../buffers/buffer_data.h"

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

    virtual void NewBuffer_ProgramSuite(const bool &success, const SPII_CurrentProgram &program) const = 0;

    virtual void NewStatus_OperationalLabels(const Operation_LabelList &labelList) const = 0;

    virtual void NewStatus_PrivateOperationalVariables(const bool &success, const Operation_VariableList &variableList = Operation_VariableList()) const = 0;

    virtual void NewStatus_UserOperationalVariables(const bool &success, const Operation_VariableList &variableList = Operation_VariableList()) const = 0;

    virtual void NewBuffer_AvailableData(const BufferData &bufferData) const = 0;

    virtual void NewStatus_CustomCommandReceived(const std::string &command, const std::string &response) const = 0;
};


} //END Comms

#endif // I_PROTOCOL_SPII_EVENTS_H
