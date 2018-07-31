#ifndef STATE_ECM_PUMP_SETUP_H
#define STATE_ECM_PUMP_SETUP_H

#include "states/state_abstract_ecm_process.h"

namespace ECM{
namespace API {

class ECMState_Idle;

class ECMState_ProfileMachine;

class ECMState_PumpSetup : public AbstractStateECMProcess
{
public:
    ECMState_PumpSetup();

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

#endif // STATE_ECM_PUMP_SETUP_H
