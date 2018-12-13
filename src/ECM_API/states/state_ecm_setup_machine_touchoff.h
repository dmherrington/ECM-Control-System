#ifndef STATE_ECM_SETUP_MACHINE_TOUCHOFF_H
#define STATE_ECM_SETUP_MACHINE_TOUCHOFF_H

#include "common/class_forward.h"
#include "common/hsm.h"

#include "../ecm_api.h"

#include "state_abstract_ecm_process.h"

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

ECM_CLASS_FORWARD(ECMState_SetupMachineTouchoff);

class ECMState_Idle;

class ECMState_SetupMachineTouchoffConnect;
class ECMState_SetupMachineTouchoffCompleted;
class ECMState_SetupMachineTouchoffFailed;

class ECMState_SetupMachinePump;

class ECMState_SetupMachineTouchoff : public AbstractStateECMProcess
{
public:
    ECMState_SetupMachineTouchoff();

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

private:
    ECMCommand_ProfileConfiguration m_Config;
};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_SETUP_MACHINE_TOUCHOFF_H
