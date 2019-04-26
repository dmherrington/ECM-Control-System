#ifndef COMMS_EVENTS_SPII_H
#define COMMS_EVENTS_SPII_H

#include <string>
#include "common/common.h"

#include "common/operation/operation_items.h"

#include "common/comms/communication_update.h"

#include "status/status_components.h"

#include "../buffers/buffer_data.h"

namespace Comms
{

class CommsEvents
{

public:
    CommsEvents() = default;
    virtual ~CommsEvents() = default;

public:

    /////////////////////////////////////////////////////////
    /// Link Events
    /////////////////////////////////////////////////////////

    virtual void LinkConnectionUpdate(const common::comms::CommunicationUpdate &update)
    {
        UNUSED(update);
    }

    virtual void CustomUserRequestReceived(const std::string &request, const std::string &response)
    {
        UNUSED(request);
        UNUSED(response);
    }

    virtual void NewBuffer_ProgramSuite(const bool &success, const SPII_CurrentProgram &program)
    {
        UNUSED(success);
        UNUSED(program);
    }

    virtual void NewBufferState(const Status_BufferState &state)
    {
        UNUSED(state);
    }

    virtual void NewBuffer_AvailableData(const BufferData &bufferData)
    {
        UNUSED(bufferData);
    }

    virtual void NewStatus_OperationalLabels(const Operation_LabelList &labelList)
    {
        UNUSED(labelList);
    }

    virtual void NewStatus_UploadedOperationalVariables(const bool &success, const Operation_VariableList &variableList)
    {
        UNUSED(success);
        UNUSED(variableList);
    }

    virtual void NewStatus_PrivateOperationalVariables(const bool &success, const Operation_VariableList &variableList)
    {
        UNUSED(success);
        UNUSED(variableList);
    }

    virtual void NewStatus_UserOperationalVariables(const bool &success, const Operation_VariableList &variableList)
    {
        UNUSED(success);
        UNUSED(variableList);
    }

    virtual void NewStatus_CustomCommandReceived(const std::string &command, const std::string &response)
    {
        UNUSED(command);
        UNUSED(response);
    }


};

}

#endif // COMMS_EVENTS_SPII_H
