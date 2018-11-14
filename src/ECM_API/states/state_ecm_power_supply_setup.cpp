#include "state_ecm_power_supply_setup.h"

namespace ECM{
namespace API {

ECMState_PowerSupplySetup::ECMState_PowerSupplySetup():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_POWERSUPPLY_SETUP;
    this->desiredState = ECMState::STATE_ECM_POWERSUPPLY_SETUP;
}

void ECMState_PowerSupplySetup::OnExit()
{
    Owner().m_Munk->RemoveHost(this);
}

AbstractStateECMProcess* ECMState_PowerSupplySetup::getClone() const
{
    return (new ECMState_PowerSupplySetup(*this));
}

void ECMState_PowerSupplySetup::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_PowerSupplySetup(*this);
}

hsm::Transition ECMState_PowerSupplySetup::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_ECM_IDLE:
        {
            rtn = hsm::SiblingTransition<ECMState_Idle>();
            break;
        }
        case ECMState::STATE_ECM_TOUCHOFF:
        {
            rtn = hsm::SiblingTransition<ECMState_Touchoff>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_PowerSupplySetup::Update()
{

}

void ECMState_PowerSupplySetup::OnEnter()
{
    Owner().m_Munk->AddLambda_FinishedUploadingParameters(this, [this](const bool completed, const uint8_t finishCode){
        desiredState = ECMState::STATE_ECM_POWERSUPPLY_SETUP;
        if(!completed)
        {
            //for some reason a timeout has occured, should we handle this differently
            std::cout<<"A timeout has occured when trying to send a goto command."<<std::endl;
            desiredStateEnum = ArdupilotFlightState::STATE_FLIGHT_GUIDED_IDLE;
        }else if(finishCode != MAV_MISSION_ACCEPTED)
        {
            std::cout<<"The autopilot says there is an error with the goTo command."<<std::endl;
            desiredStateEnum = ArdupilotFlightState::STATE_FLIGHT_GUIDED_IDLE;
        }
        else if(completed && (finishCode == MAV_MISSION_ACCEPTED))
        {
            this->commandAccepted = true;
        }

    });
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_touchoff.h"
