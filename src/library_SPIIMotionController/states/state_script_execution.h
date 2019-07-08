#ifndef STATE_SCRIPT_EXECUTION_H
#define STATE_SCRIPT_EXECUTION_H

#include "data/profiles/profile_state_machining.h"
#include "states/state_abstract_spii.h"

namespace ECM{
namespace SPII {

class State_Ready;
class State_MotionStop;
class State_EStop;

ECM_CLASS_FORWARD(State_ScriptExecution);

//Forward declare the class states available to transition to from this one
class State_MotionStop;
class State_EStop;

class State_ScriptExecution : public AbstractStateSPII
{
public:
    State_ScriptExecution();

public:
    AbstractStateSPII* getClone() const override;

    void getClone(AbstractStateSPII** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommandPtr command) override;

    void Update() override;

    void OnEnter() override;

    void OnExit() override;

    void OnEnter(const AbstractCommandPtr command);

private:
    std::vector<common::TupleProfileVariableString> currentScriptRequests;
    std::string scriptProfileName = "";

private:
    bool profileExecuting = false;
};

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_SCRIPT_EXECUTION_H
