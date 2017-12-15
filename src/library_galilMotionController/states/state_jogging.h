#ifndef STATE_JOGGING_H
#define STATE_JOGGING_H

#include "states/state_abstract_galil.h"

namespace ECM{
namespace Galil {

ECM_CLASS_FORWARD(State_Jogging);

class State_Jogging : public AbstractStateGalil
{
public:
    State_Jogging(const GalilSettings &settings);
public:
    AbstractStateGalil* getClone() const override;

    void getClone(AbstractStateGalil** state) const override;

public:
    void handleCommand(const AbstractCommand* command) override;

};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_JOGGING_H
