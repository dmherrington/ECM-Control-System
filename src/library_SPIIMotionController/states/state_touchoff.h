#ifndef STATE_TOUCHOFF_H
#define STATE_TOUCHOFF_H

#include "data/profiles/profile_state_touchoff.h"

#include "states/state_abstract_spii.h"

namespace ECM{
namespace SPII {

class State_Ready;
class State_MotionStop;
class State_EStop;

ECM_CLASS_FORWARD(State_Touchoff);

class State_Touchoff : public AbstractStateSPII
{
public:
    State_Touchoff();

    void OnExit() override;

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

private:
    void stateSetup();

private:
    bool touchoffExecuting = false;

    MotorAxis touchoffAxis = MotorAxis::Z;
};

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_TOUCHOFF_H
