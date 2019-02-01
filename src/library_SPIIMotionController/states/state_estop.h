#ifndef STATE_ESTOP_H
#define STATE_ESTOP_H

#include "states/state_abstract_spii.h"

namespace ECM{
namespace SPII {

ECM_CLASS_FORWARD(State_EStop);

class State_Idle;

class State_EStop : public AbstractStateSPII
{
public:
    State_EStop();

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

#endif // STATE_ESTOP_H
