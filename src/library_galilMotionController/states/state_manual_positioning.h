#ifndef STATE_MANUAL_POSITIONING_H
#define STATE_MANUAL_POSITIONING_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_ManualPositioning);

class State_Stop;
class State_EStop;
class State_Ready;

class State_ManualPositioning : public AbstractStateGalil
{
public:
    State_ManualPositioning();

public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommand* command) override;

};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_MANUAL_POSITIONING_H
