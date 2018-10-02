#ifndef STATE_TOUCHOFF_H
#define STATE_TOUCHOFF_H

#include "data/profiles/profile_state_touchoff.h"

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

class State_Ready;
class State_MotionStop;
class State_EStop;

ECM_CLASS_FORWARD(State_Touchoff);

class State_Touchoff : public AbstractStateGalil
{
public:
    State_Touchoff();

    void OnExit() override;

public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommandPtr command) override;

    void Update() override;

    void OnEnter() override;

    void OnEnter(const AbstractCommandPtr command);

private:
    void stateSetup();

private:
    bool touchoffExecuting = false;
};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_TOUCHOFF_H
