#ifndef STATE_ECM_PROFILE_MACHINE_SETUP_H
#define STATE_ECM_PROFILE_MACHINE_SETUP_H

#include "states/state_abstract_ecm_process.h"

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

namespace ECM{
namespace API {

class ECMState_PumpSetup;
class ECMState_TouchoffDisable;
class ECMState_Setup;

ECM_CLASS_FORWARD(ECMState_MachineSetup);

//Forward declare the class states available to transition to from this one
class ECMState_TouchoffDisable;
class ECMState_Setup;

class ECMState_MachineSetup : public AbstractStateECMProcess
{
public:
    ECMState_MachineSetup();

    void OnExit() override;

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void Update() override;

    void OnEnter() override;
};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_SCRIPT_EXECUTION_H
