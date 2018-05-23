#ifndef STATE_SCRIPT_EXECUTION_H
#define STATE_SCRIPT_EXECUTION_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

class State_Ready;
class State_MotionStop;
class State_EStop;

ECM_CLASS_FORWARD(State_ScriptExecution);

//Forward declare the class states available to transition to from this one
class State_MotionStop;
class State_EStop;

class State_ScriptExecution : public AbstractStateGalil
{
public:
    State_ScriptExecution();

public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommand* command) override;

    void Update() override;

    void OnEnter() override;

    void OnExit() override;

    void OnEnter(const AbstractCommand *command);
};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_SCRIPT_EXECUTION_H
