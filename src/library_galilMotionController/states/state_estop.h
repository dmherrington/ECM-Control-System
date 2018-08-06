#ifndef STATE_ESTOP_H
#define STATE_ESTOP_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_EStop);

class State_Idle;

class State_EStop : public AbstractStateGalil
{
public:
    State_EStop();

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
};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_ESTOP_H
