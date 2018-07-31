#ifndef STATE_ECM_PROFILE_MACHINE_PROCESS_H
#define STATE_ECM_PROFILE_MACHINE_PROCESS_H

#include "states/state_abstract_ecm_process.h"

namespace ECM{
namespace API {

class ECMState_PumpSetup;
class ECMState_TouchoffDisable;
class ECMState_Setup;

ECM_CLASS_FORWARD(ECMState_ProfileMachineProcess);

class ECMState_ProfileMachineProcess : public AbstractStateECMProcess
{
public:
    ECMState_ProfileMachineProcess();

    void OnExit() override;

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

private:
    void stateSetup();

};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_PROFILE_MACHINE_PROCESS_H
