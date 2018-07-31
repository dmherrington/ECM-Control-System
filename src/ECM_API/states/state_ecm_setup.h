#ifndef STATE_ECM_SETUP_H
#define STATE_ECM_SETUP_H

#include "states/state_abstract_ecm_process.h"

namespace ECM{
namespace API {

ECM_CLASS_FORWARD(ECMState_Setup);

class ECMState_Idle;
class ECMState_PowerSupplySetup;

class ECMState_Setup : public AbstractStateECMProcess
{
public:
    ECMState_Setup();

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

#endif // STATE_ECM_SETUP_H
