#ifndef ECMCOMMAND_PROFILE_CONFIGURATION_H
#define ECMCOMMAND_PROFILE_CONFIGURATION_H

#include "common/class_forward.h"

#include "library_galilMotionController/programs/galil_current_program.h"

#include "library_munk_power_supply/data_registers/segment_time_detailed.h"

#include "library_westinghouse510/pump_command.h"


ECM_CLASS_FORWARD(ECMCommand_ProfileConfiguration);

class ECMCommand_ProfileConfiguration
{
public:
    ECMCommand_ProfileConfiguration();

public:
    GalilCurrentProgram m_GalilParameters;

    registers_Munk::SegmentTimeDetailed m_MunkParameters;

    PumpCommand m_PumpParameters;

};

#endif // ECMCOMMAND_PROFILE_CONFIGURATION_H
