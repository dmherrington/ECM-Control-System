#ifndef STATE_IDLE_H
#define STATE_IDLE_H

#include "states/state_abstract_spii.h"

/**
\* @file  state_idle.h
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
namespace SPII {

class State_Ready;
class State_EStop;

class State_Idle : public AbstractStateSPII
{
public:
    State_Idle();

public:
    AbstractStateSPII* getClone() const override;

    void getClone(AbstractStateSPII** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommandPtr command) override;

    void Update() override;

    void OnEnter() override;

    void OnEnter(const AbstractCommandPtr command);
};

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_IDLE_H
