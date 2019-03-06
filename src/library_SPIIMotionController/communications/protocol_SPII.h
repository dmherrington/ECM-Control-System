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
#include "../commands/spii_command_upload_program.h"

namespace Comms
{

class SPIIProtocol : public IProtocol
{

public:
    SPIIProtocol();

    //////////////////////////////////////////////////////////////
    /// Methods issuing an explicit galil command
    //////////////////////////////////////////////////////////////
public:
    void SendProtocolCommand(const AbstractCommandPtr command);

    void SendProtocolMotionCommand(const AbstractCommandPtr command);

    void SendCustomProtocolCommand(const std::vector<std::string> &stringCommands);


public:
    bool commandMotorEnable(const CommandMotorEnable &enable);

    bool commandMotorDisable(const CommandMotorDisable &disable);

    bool commandJogMotion(const CommandJog &jog);

    bool commandKillMotion(const CommandStop &stop);

public:
    bool programUpload(const CommandUploadProgram &program);

    bool bufferUpload(const unsigned int &index, const std::string &text);

    bool bufferCompile(const unsigned int &index);

    bool bufferRun(const unsigned int &index, const std::string &label);

    bool bufferStop(const unsigned int &index);

    int checkForBufferCompilation(const unsigned int &index);

public:
    void updateDeviceSettings(const SPII_Settings &settings);

    bool requestPosition(const int &axisRequest, double &value);

    bool requestAxisStatus(const int &axisRequest, int &value);

    bool requestMotorStatus(const int &axisRequest, int &value);

    bool requestNumberofBuffers(double &count);

    bool requestNumberofAxes(double &count);

    bool requestDBufferIndex(double &index);

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
