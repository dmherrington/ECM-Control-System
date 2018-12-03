#ifndef STATE_ECM_PROFILE_MACHINE_CEASE_H
#define STATE_ECM_PROFILE_MACHINE_CEASE_H

#include "state_ecm_profile_machine_base.h"

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

ECM_CLASS_FORWARD(ECMState_ProfileMachineCease);

class ECMState_ProfileMachineComplete;
class ECMState_ProfileMachineFailed;

class ECMState_ProfileMachineCease : public ECMState_ProfileMachineBase
{
public:
    ECMState_ProfileMachineCease();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void OnEnter() override;
    void Update() override;
    void OnExit() override;

public:
    void OnEnter(const ECMCommand_ProfileConfiguration &configuration);

};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_PROFILE_MACHINE_CEASE_H
