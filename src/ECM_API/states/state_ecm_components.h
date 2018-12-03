#ifndef STATE_ECM_COMPONENTS_H
#define STATE_ECM_COMPONENTS_H

/**
\* @file  state_ecm_touchoff.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*  This state class defines the machine in the idle state. The machine should transition to this state when the motor was disabled
\* via standard user command or at the completion of machining.
\*  While in this state, we can accept commands to download/upload programs from galil, load parameters and settigns from files,
\* save files, etc.
\*/
#include "ECM_API/states/state_ecm_types.h"

#include "ECM_API/states/state_abstract_ecm_process.h"
#include "ECM_API/states/state_ecm_idle.h"
#include "ECM_API/states/state_ecm_motion_profile_initialization.h"

#include "ECM_API/states/state_ecm_profile_machine.h"
#include "ECM_API/states/state_ecm_profile_machine_cease.h"
#include "ECM_API/states/state_ecm_profile_machine_complete.h"
#include "ECM_API/states/state_ecm_profile_machine_failed.h"
#include "ECM_API/states/state_ecm_profile_machine_process.h"

#include "ECM_API/states/state_ecm_setup_machine.h"
#include "ECM_API/states/state_ecm_setup_machine_complete.h"
#include "ECM_API/states/state_ecm_setup_machine_failed.h"
#include "ECM_API/states/state_ecm_setup_machine_home.h"
#include "ECM_API/states/state_ecm_setup_machine_pump.h"
#include "ECM_API/states/state_ecm_setup_machine_touchoff.h"

#include "ECM_API/states/state_ecm_upload.h"
#include "ECM_API/states/state_ecm_upload_complete.h"
#include "ECM_API/states/state_ecm_upload_failed.h"
#include "ECM_API/states/state_ecm_upload_motion_profile.h"
#include "ECM_API/states/state_ecm_upload_motion_variables.h"
#include "ECM_API/states/state_ecm_upload_power_pulse_mode.h"
#include "ECM_API/states/state_ecm_upload_power_register_segments.h"
#include "ECM_API/states/state_ecm_upload_pump_parameters.h"

#include "ECM_API/states/state_test.h"

#endif // STATE_ECM_COMPONENTS_H
