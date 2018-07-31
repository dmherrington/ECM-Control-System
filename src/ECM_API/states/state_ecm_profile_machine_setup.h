#ifndef STATE_ECM_PROFILE_MACHINE_SETUP_H
#define STATE_ECM_PROFILE_MACHINE_SETUP_H

\#include "states/state_abstract_ecm_process.h"

namespace ECM{
namespace API {

class ECMState_PumpSetup;
class ECMState_TouchoffDisable;
class ECMState_Setup;

ECM_CLASS_FORWARD(ECMState_MachineSetup);

//Forward declare the class states available to transition to from this one
class ECMState_TouchoffDisable;
class ECMState_Setup;

class ECMState_MachineSetup : public AbstractStateECMProcess
{
public:
    ECMState_MachineSetup();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommand* command) override;

    void Update() override;

    void OnEnter() override;

    void OnExit() override;

    void OnEnter(const AbstractCommand *command);
};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_SCRIPT_EXECUTION_H
