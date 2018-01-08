﻿#include "state_ready.h"

namespace ECM{
namespace Galil {

State_Ready::State_Ready():
    AbstractStateGalil()
{
    std::cout<<"We are in the constructor of State_Ready"<<std::endl;
    this->currentState = ECMState::STATE_READY;
    this->desiredState = ECMState::STATE_READY;
}

AbstractStateGalil* State_Ready::getClone() const
{
    return (new State_Ready(*this));
}

void State_Ready::getClone(AbstractStateGalil** state) const
{
    *state = new State_Ready(*this);
}

hsm::Transition State_Ready::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_MANUAL_POSITIONING:
        {
            rtn = hsm::SiblingTransition<State_ManualPositioning>(currentCommand);
            break;
        }
        case ECMState::STATE_JOGGING:
        {
            rtn = hsm::SiblingTransition<State_Jogging>(currentCommand);
            break;
        }
        case ECMState::STATE_HOME_POSITIONING:
        {
            rtn = hsm::SiblingTransition<State_HomePositioning>(currentCommand);
            break;
        }
        case ECMState::STATE_TOUCHOFF:
        {
            rtn = hsm::SiblingTransition<State_Touchoff>(currentCommand);
            break;
        }
        case ECMState::STATE_SCRIPT_EXECUTION:
        {
            rtn = hsm::SiblingTransition<State_ScriptExecution>(currentCommand);
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>(currentCommand);
            break;
        }

        default:
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }

    return rtn;
}

void State_Ready::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();
    switch (currentCommand) {
    case CommandType::ABSOLUTE_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_MANUAL_POSITIONING;
        this->currentCommand = command;
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_MANUAL_POSITIONING;
        this->currentCommand = command;
        break;
    }
    case CommandType::JOG_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_JOGGING;
        this->currentCommand = command;
        break;
    }
    case CommandType::EXECUTE_PROGRAM:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_SCRIPT_EXECUTION;
        this->currentCommand = command;
        break;
    }
    case CommandType::MOTOR_OFF:
    case CommandType::STOP:
    {
        desiredState = ECMState::STATE_READY_STOP;
        break;
    }
    case CommandType::MOTOR_ON:
    {
        //While this state is responsive to this command, the motor should already be completely armed when it has arrived to this state.
        //First check to see if the motor is already armed, and if not, arm it
        if(!Owner().getAxisStatus(MotorAxis::Z)->isMotorRunning())
        {
            //If the motor is not currently armed, issue the command to arm it
            const CommandMotorEnable* castCommand = command->as<CommandMotorEnable>();
            Owner().commsMarshaler->sendGalilCommand<CommandMotorEnable>(*castCommand);
            //Since we have used the command we should now delete it
            delete command;
            command = nullptr;
        }
        break;
    }
    case CommandType::CLEAR_BIT:
    case CommandType::SET_BIT:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    default:
        break;
    }
}

void State_Ready::Update()
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

void State_Ready::OnEnter()
{
    //The first thing we should do when entering this state is to engage the motor
    //Let us check to see if the motor is already armed, if not, follow through with the command

//    CommandMotorEnable cmd;
//    cmd.setEnableAxis(MotorAxis::Z);
//    GalilStatus* status = Owner().getAxisStatus(MotorAxis::Z);
//    if(!status->isMotorRunning())
//        Owner().transmitMessage(cmd.getCommandString());
}

void State_Ready::OnEnter(const AbstractCommand* command)
{
    this->OnEnter();

    if(command != nullptr)
    {
        //The command isnt null so we should handle it
        this->handleCommand(command);
    }
    else{
        //There was no actual command, therefore, there is nothing else to do at this point
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_home_positioning.h"
#include "states/state_jogging.h"
#include "states/state_manual_positioning.h"
#include "states/state_script_execution.h"
#include "states/state_touchoff.h"
#include "states/state_estop.h"

