#include <QCoreApplication>
#include <iostream>

#include <QString>
#include <QStringList>
#include <QRegExp>

#include "library_rigol_oscilloscope/rigol_oscilliscope.h"
#include "clock_testing.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


//    rigol::comms::RigolCommsMarshaler* marshal = new rigol::comms::RigolCommsMarshaler();
//    rigol::comms::TCPConfiguration newConfig;
//    marshal->ConnectToLink(newConfig);
//    QByteArray newArray;
//    newArray.append("*IDN?");
//    marshal->EmitByteArray(newArray);

    RigolOscilliscope* rigolInterface = new RigolOscilliscope();
//    rigolInterface->openConnection("192.168.1.17",5555);
    rigolInterface->openConnection("127.0.0.1",5555);


    rigol::commands::MeasureCommand_Item measureArea;
    measureArea.setChannel(rigol::data::AvailableChannels::CHANNEL_1);
    measureArea.setMeasurementType(rigol::data::MeasurementTypes::MEASURE_MAREA);
    rigolInterface->addPollingMeasurement(measureArea);

    rigol::commands::MeasureCommand_Item measureVtop;
    measureVtop.setChannel(rigol::data::AvailableChannels::CHANNEL_2);
    measureVtop.setMeasurementType(rigol::data::MeasurementTypes::MEASURE_VTOP);
    rigolInterface->addPollingMeasurement(measureVtop);

    rigolInterface->executeMeasurementPolling(true);

//    Status_Switch newStatus;
//    newStatus.setSwitchCode(47);

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
