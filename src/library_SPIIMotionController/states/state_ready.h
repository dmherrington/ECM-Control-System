#ifndef STATE_READY_H
#define STATE_READY_H

#include "states/state_abstract_spii.h"

namespace ECM{
namespace SPII {

class State_Idle;
class State_EStop;
class State_HomePositioning;
class State_HomingRoutine;
class State_Jogging;
class State_ManualPositioning;
class State_ScriptExecution;
class State_Touchoff;
class State_ReadyStop;

class State_Ready : public AbstractStateSPII
{
public:
    State_Ready();

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
    unsigned int disableCount = 0;

};

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_READY_H
