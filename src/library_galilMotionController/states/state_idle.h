#ifndef STATE_IDLE_H
#define STATE_IDLE_H

#include "states/state_abstract_galil.h"

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
namespace Galil {

ECM_CLASS_FORWARD(State_Idle);

class State_Idle : public AbstractStateGalil
{
public:
    State_Idle(const GalilSettings &settings);

    //State_Idle(const State_Idle &copy);

public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    void handleCommand(const AbstractCommand* command) override;

    void OnEnter() override;

    void OnEnter(const AbstractCommand* command);
};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_IDLE_H
