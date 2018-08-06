#ifndef STATE_READY_H
#define STATE_READY_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

class State_EStop;
class State_HomePositioning;
class State_Jogging;
class State_ManualPositioning;
class State_ScriptExecution;
class State_Touchoff;
class State_ReadyStop;

class State_Ready : public AbstractStateGalil
{
public:
    State_Ready();

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

#endif // STATE_READY_H
