#ifndef STATE_JOGGING_H
#define STATE_JOGGING_H

#include "states/state_abstract_galil.h"
#include "commands/command_motion_start.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_Jogging);

class State_MotionStop;
class State_EStop;

class State_Jogging : public AbstractStateGalil
{
public:
    State_Jogging();
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

#endif // STATE_JOGGING_H
