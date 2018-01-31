#include <QCoreApplication>
#include <iostream>

#include <QString>
#include <QStringList>
#include <QRegExp>

#include "library_galilMotionController/communications/comms_marshaler.h"

//#include "library_galilMotionController/galil_motion_controller.h"
//#include "library_galilMotionController/states/state_components.h"
//#include "library_galilMotionController/galil_state_interface.h"
//#include "library_galilMotionController/galil_poll_status.h"

#include "comms_galil/comms_galil.h"

//using namespace hsm;

#include "library_galilMotionController/status/status_switch.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Status_Switch newStatus;
    newStatus.setSwitchCode(47);

    /*
//    CommsGalil* comms = new CommsGalil();
    CommandMotorEnablePtr cmd = std::make_shared<CommandMotorEnable>();
    cmd->setEnableAxis(MotorAxis::X);

    Comms::CommsMarshaler* newMarshaller = new Comms::CommsMarshaler();
    newMarshaller->sendAbstractGalilCommand(cmd);

    std::cout<<"This is a test"<<std::endl;
//    galilMotionController galil;



//    QString result = "#program=6";
//    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
//    for(int i =0; i < list.size(); i++)
//    {
//        QString value = list.at(i);
//        QStringList sublist = value.split("=");
//        std::cout<<"We are now here"<<std::endl;
//    }
    std::cout<<"We are here"<<std::endl;
//    GalilInterface* newInterface = new GalilInterface();
//    StateMachine stateMachine;
//    stateMachine.Initialize<ECM::Galil::State_Idle>(newInterface);
//    stateMachine.ProcessStateTransitions();
//    stateMachine.UpdateStates();

//    stateMachine.ProcessStateTransitions();
//    stateMachine.UpdateStates();

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

*/
    return a.exec();
}
