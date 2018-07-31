#include "state_ecm_profile_machine_process.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineProcess::ECMState_ProfileMachineProcess():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS;
}

void ECMState_ProfileMachineProcess::OnExit()
{
    Owner().statusVariableValues->removeVariableNotifier("touchst",this);
}

AbstractStateECMProcess* ECMState_ProfileMachineProcess::getClone() const
{
    return (new ECMState_ProfileMachineProcess(*this));
}

void ECMState_ProfileMachineProcess::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineProcess(*this);
}

hsm::Transition ECMState_ProfileMachineProcess::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //Owner().issueGalilRemovePollingRequest("touchst"); this should be done onExit

        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_READY:
        {
            return hsm::SiblingTransition<ECMState_PumpSetup>();
            break;
        }
        case ECMState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<ECMState_TouchoffDisable>(currentCommand);
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from STATE_TOUCHOFF."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_ProfileMachineProcess::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
    }
}

void ECMState_ProfileMachineProcess::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_TOUCHOFF));
    //this shouldn't really happen as how are we supposed to know the actual touchoff command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = ECMState::STATE_READY;
}

void ECMState_ProfileMachineProcess::OnEnter(const AbstractCommand* command)
{
    if(command != nullptr)
    {
        Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_TOUCHOFF));

        Request_TellVariablePtr request = std::make_shared<Request_TellVariable>("Touchoff Status","touchst");
        Owner().issueGalilAddPollingRequest(request);
        this->handleCommand(command);
    }
    else{
        this->OnEnter();
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_motion_stop.h"
#include "states/state_estop.h"
