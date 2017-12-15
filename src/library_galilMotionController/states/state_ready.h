#ifndef STATE_READY_H
#define STATE_READY_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_Ready);

class State_Ready : public AbstractStateGalil
{
public:
    State_Ready(const GalilSettings &settings);

public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    void handleCommand(const AbstractCommand* command) override;

};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_READY_H
