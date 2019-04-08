#ifndef PROTOCOL_SPII_H
#define PROTOCOL_SPII_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>

#include "ACSC.h"

#include "i_link.h"
#include "i_protocol_SPII_events.h"
#include "i_protocol.h"
#include "spii_settings.h"

#include "../requests/request_components.h"
#include "../status/status_components.h"

#include "common/axis_definitions.h"

#include "i_link.h"

#include "common/commands/command_components.h"
#include "../commands/spii_command_upload_program_buffer.h"

#include "../buffers/buffer_data.h"
#include "../buffers/buffer_label_values.h"
#include "../buffers/buffer_variable_values.h"

namespace Comms
{

class SPIIProtocol : public IProtocol
{

public:
    SPIIProtocol();

    void AddListner(const IProtocolSPIIEvents* listener);


    void initializeBufferContents();

    //////////////////////////////////////////////////////////////
    /// Methods issuing an explicit galil command
    //////////////////////////////////////////////////////////////
public:
    void SendProtocolCommand(const AbstractCommandPtr command);

    void SendProtocolMotionCommand(const AbstractCommandPtr command);

    void SendCustomProtocolCommand(const std::vector<std::string> &stringCommands);

    void testObject(Operation_VariableList &privateVariables, Operation_VariableList &userVariables);


public:
    bool WriteVariableValue(const Command_Variable &value);

    bool WriteVariableArray(const Command_VariableArray &value);

    bool WriteOperationalVariables(const Operation_VariableList &variableList);

public:
    bool commandMotorEnable(const CommandMotorEnable &enable);

    bool commandMotorDisable(const CommandMotorDisable &disable);

    bool commandJogMotion(const CommandJog &jog);

    bool commandRelativeMove(const CommandRelativeMove &relativeMove);

    bool commandKillMotion(const CommandStop &stop);


public:
    bool bufferUpload(const unsigned int &index, const std::string &text);

    bool bufferCompile(const unsigned int &index, Status_BufferState &newState);

    bool bufferRun(const unsigned int &index, const std::string &label = "");

    bool bufferStop(const unsigned int &index);

    int checkForBufferCompilation(const unsigned int &index);

    unsigned int checkForBufferLineError(const unsigned int &index);

private:
    void uploadProgramToBuffer(const SPIICommand_UploadProgramBuffer* uploadProgram);

    void retrieveBufferData(const unsigned int &bufferIndex, BufferData &bufferContents);

    void retrieveBufferLabels(const unsigned int &bufferIndex, Operation_LabelList &bufferLabels);

    void retrieveDBufferVariables(const unsigned int &bufferIndex, Operation_VariableList &privateVariables, Operation_VariableList &userVariables);

    QStringList requestBufferVariables(const unsigned int &bufferNumber, const int &attempts = -1, const unsigned int &startingBufferSize = 1000);

    std::string requestBufferContents(const unsigned int &bufferNumber, const int &attempts = -1, const unsigned int &startingBufferSize = 1000);


public:
    void updateDeviceSettings(const SPII_Settings &settings);

    bool requestPosition(const int &axisRequest, double &value);

    bool requestAxisStatus(const int &axisRequest, int &value);

    bool requestMotorStatus(const int &axisRequest, int &value);

    bool requestNumberofBuffers(double &count);

    bool requestNumberofAxes(double &count);

    bool requestDBufferIndex(double &index);

    bool requestRealScalarVariable(const std::string &variableName, double &value);


public:
    void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) override;


private:

    void Emit(const std::function<void(const IProtocolSPIIEvents*)> func)
    {
        for(const IProtocolSPIIEvents* listener : m_Listners)
            func(listener);
    }

private:
    std::shared_ptr<HANDLE>  m_SPIIDevice;
    SPII_Settings m_SPIISettings; /**< Member variable containing a pointer to the SPII interface */

private:
    std::vector<const IProtocolSPIIEvents*> m_Listners;
};


} //end of namespace Comms

#endif // PROTOCOL_SPII_H
