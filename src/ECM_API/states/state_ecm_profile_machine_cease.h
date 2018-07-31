#ifndef STATE_ECM_PROFILE_MACHINE_CEASE_H
#define STATE_ECM_PROFILE_MACHINE_CEASE_H

#include "states/state_abstract_ecm_process.h"

namespace ECM{
namespace API {

ECM_CLASS_FORWARD(ECMState_ProfileMachineCease);

class ECMState_Touchoff;

class ECMState_ProfileMachineCease : public AbstractStateECMProcess
{
public:
    ECMState_ProfileMachineCease();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommand* command) override;

};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_PROFILE_MACHINE_CEASE_H
