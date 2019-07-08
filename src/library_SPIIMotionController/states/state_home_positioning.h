#ifndef STATE_HOME_POSITIONING_H
#define STATE_HOME_POSITIONING_H

#include "data/profiles/profile_state_homing.h"

#include "states/state_abstract_spii.h"

namespace ECM{
namespace SPII {

ECM_CLASS_FORWARD(State_HomePositioning);

class State_Ready;
class State_MotionStop;
class State_EStop;

class State_HomePositioning : public AbstractStateSPII
{
public:
    State_HomePositioning();

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
    bool homeExecuting = false;

};

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_HOME_POSITIONING_H
