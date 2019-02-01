#ifndef STATE_STOP_H
#define STATE_STOP_H

#include "states/state_abstract_spii.h"

namespace ECM{
namespace SPII {

ECM_CLASS_FORWARD(State_Stop);

class State_Idle;

class State_Stop : public AbstractStateSPII
{
public:
    State_Stop();

public:
    AbstractStateSPII* getClone() const override;

    void getClone(AbstractStateSPII** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommand* command) override;

};

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_STOP_H
