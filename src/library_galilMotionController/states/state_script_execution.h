#ifndef STATE_SCRIPT_EXECUTION_H
#define STATE_SCRIPT_EXECUTION_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_ScriptExecution);

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
