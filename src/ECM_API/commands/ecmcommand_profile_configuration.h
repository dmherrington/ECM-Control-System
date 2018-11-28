#ifndef ECMCOMMAND_PROFILE_CONFIGURATION_H
#define ECMCOMMAND_PROFILE_CONFIGURATION_H

#include "common/class_forward.h"

#include "library_galilMotionController/programs/galil_current_operation.h"
#include "library_galilMotionController/motion_command_touchoff_config.h"

#include "library_munk_power_supply/data_registers/segment_time_detailed.h"
#include "library_munk_power_supply/data_registers/register_pulse_mode.h"

#include "library_westinghouse510/command_pump_properties.h"

ECM_CLASS_FORWARD(ECMCommand_ProfileConfiguration);

class ECMCommand_ProfileConfiguration
{
public:
    ECMCommand_ProfileConfiguration();

    ECMCommand_ProfileConfiguration(const ECMCommand_ProfileConfiguration &copy);

public:
    bool shouldProfileExecute() const;

    void setProfileExecution(const bool &varExecute);

private:
    bool execute = false;

public:

    GalilCurrentOperation m_GalilOperation;

    MotionCommand_TouchoffConfig m_Touchoff;

    registers_Munk::SegmentTimeDetailed m_MunkSegment;

    registers_Munk::Register_PulseMode m_MunkPulseMode;

    Command_PumpProperties m_PumpParameters;

};

#endif // ECMCOMMAND_PROFILE_CONFIGURATION_H
