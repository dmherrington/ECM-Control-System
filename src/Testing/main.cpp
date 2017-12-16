#include <QCoreApplication>
#include <iostream>

#include "library_galilMotionController/states/state_components.h"
#include "library_galilMotionController/galil_interface.h"


using namespace hsm;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GalilInterface* newInterface = new GalilInterface();
    StateMachine stateMachine;
    stateMachine.Initialize<ECM::Galil::State_Idle>(newInterface);
    stateMachine.ProcessStateTransitions();
    stateMachine.UpdateStates();

    stateMachine.ProcessStateTransitions();
    stateMachine.UpdateStates();

//       StateMachine stateMachine;
//       stateMachine.Initialize<test::test2::State1>();
//       std::cout<<"We are here 1"<<std::endl;
//       stateMachine.SetDebugInfo("TestHsm", TraceLevel::Basic);
//       std::cout<<"We are here 2"<<std::endl;
//       stateMachine.ProcessStateTransitions();
//       stateMachine.UpdateStates();

//       if(stateMachine.IsStarted())
//       {
//           std::cout<<"The state machine is moving"<<std::endl;
//       }

//       test::test2::State1* currentState = static_cast<test::test2::State1*>(stateMachine.getCurrentState());
//       std::cout<<"We are here 3"<<std::endl;
//       currentState->updateValue(3);
//       std::cout<<"We are here 4"<<std::endl;

//       stateMachine.ProcessStateTransitions();
//       stateMachine.UpdateStates();

    return a.exec();
}
