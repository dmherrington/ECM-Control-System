#ifndef STATE_SCRIPT_EXECUTION_H
#define STATE_SCRIPT_EXECUTION_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_ScriptExecution);

//Forward declare the class states available to transition to from this one
class State_Stop;
class State_EStop;
class State_Jogging;
class State_ManualPositioning;
class State_Touchoff;
class State_ScriptExecution;
class State_HomePositioning;

class State_ScriptExecution : public AbstractStateGalil
{
public:
    State_ScriptExecution(const GalilSettings &settings);

public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    void handleCommand(const AbstractCommand* command) override;

};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_SCRIPT_EXECUTION_H
