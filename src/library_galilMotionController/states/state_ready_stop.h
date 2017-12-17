#ifndef STATE_READY_STOP_H
#define STATE_READY_STOP_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_ReadyStop);

class State_Idle;
class State_EStop;

class State_ReadyStop : public AbstractStateGalil
{
public:
    State_ReadyStop();

public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommand* command) override;

    void OnEnter() override;

    void OnEnter(const AbstractCommand *command);
};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_READY_STOP_H
