#ifndef STATE_HOME_POSITIONING_H
#define STATE_HOME_POSITIONING_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_HomePositioning);

class State_HomePositioning : public AbstractStateGalil
{
public:
    State_HomePositioning(const GalilSettings &settings);

public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    void handleCommand(const AbstractCommand* command) override;

};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_HOME_POSITIONING_H
