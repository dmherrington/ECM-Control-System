#ifndef STATE_ECM_PROFILE_HANDLING_H
#define STATE_ECM_PROFILE_HANDLING_H

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

ECM_CLASS_FORWARD(ECMState_ProfileHandling);

class ECMState_ProfileHandling : public AbstractStateECMProcess
{
public:
    ECMState_Idle();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    void OnEnter() override;
    void Update() override;
    void OnExit() override;

public:
    hsm::Transition GetTransition() override;

public:
    void OnEnter(const ECMCommand_ExecuteCollection &collection, const bool &previouslyInitialized = false);

};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_PROFILE_HANDLING_H
