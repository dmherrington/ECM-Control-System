#ifndef STATE_ECM_TOUCHOFF_DISABLE_H
#define STATE_ECM_TOUCHOFF_DISABLE_H

#include "states/state_abstract_ecm_process.h"

namespace ECM{
namespace API {

ECM_CLASS_FORWARD(ECMState_TouchoffDisable);

class ECMState_PumpSetup;
class ECMState_Setup;

class ECMState_TouchoffDisable : public AbstractStateECMProcess
{
public:
    ECMState_TouchoffDisable();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void Update() override;

    void OnEnter() override;
};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_TOUCHOFF_DISABLE_H
