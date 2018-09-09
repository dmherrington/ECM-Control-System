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

#include "ECM_API/states/state_abstract_ecm_process.h"
#include "ECM_API/states/state_ecm_power_supply_setup.h"
#include "ECM_API/states/state_ecm_profile_machine.h"
#include "ECM_API/states/state_ecm_profile_machine_cease.h"
#include "ECM_API/states/state_ecm_profile_machine_process.h"
#include "ECM_API/states/state_ecm_profile_machine_setup.h"
#include "ECM_API/states/state_ecm_initialization.h"
#include "ECM_API/states/state_ecm_touchoff.h"
#include "ECM_API/states/state_ecm_touchoff_disable.h"
#include "ECM_API/states/state_ecm_touchoff_enable.h"
#include "ECM_API/states/state_ecm_touchoff_execute.h"

#endif // STATE_ECM_COMPONENTS_H
