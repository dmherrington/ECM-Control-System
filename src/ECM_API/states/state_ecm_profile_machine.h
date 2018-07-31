#ifndef STATE_ECM_PROFILE_MACHINE_H
#define STATE_ECM_PROFILE_MACHINE_H

#include "states/state_abstract_ecm_process.h"

namespace ECM{
namespace API {

ECM_CLASS_FORWARD(ECMState_ProfileMachine);

class ECMState_Idle;

class ECMState_ProfileMachineCease;
class ECMState_ProfileMachineProcess;
class ECMState_ProfileMachineSetup;

class ECMState_ProfileMachine : public AbstractStateECMProcess
{
public:
    ECMState_ProfileMachine();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommand* command) override;

    void Update() override;

    void OnEnter() override;

    void OnEnter(const AbstractCommand *command);
};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_PROFILE_MACHINE_H
