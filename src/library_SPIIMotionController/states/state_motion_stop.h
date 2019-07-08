#ifndef STATE_STOP_H
#define STATE_STOP_H

#include "states/state_abstract_spii.h"

namespace ECM{
namespace SPII {

ECM_CLASS_FORWARD(State_MotionStop);

class State_Ready;
class State_EStop;

class State_MotionStop : public AbstractStateSPII
{
public:
    State_MotionStop();

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

#endif // STATE_STOP_H
