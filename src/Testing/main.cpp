#include <QCoreApplication>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <sys/timeb.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include <QString>
#include <QStringList>
#include <QRegExp>


#include "library_westinghouse510/data_registers/register_operation_signal.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    westinghousePump::registers::Register_OperationSignal newSignal;
    newSignal.setSlaveAddress(1);
    newSignal.shouldRun(true);
    QByteArray ba = newSignal.getFullMessage();
    std::cout<<"The new message is:"<<std::endl;
//    Sensoray newInterface;
//    newInterface.openConnection("192.168.1.101",23);
    // Testing of the Sensoray device
//    HSESSION sess;
//    S24XXERR err = ERR_NONE;
//    if ( !s24xx_ApiOpen() )
//        printf( "Error: Failed to open session interface\n" );

//    // Create session object and open the telnet session.
//    else if ( !s24xx_SessionOpen( &sess, &err, 2426, "192.168.1.101", 23, 2000 ) )
//        s24xx_ErrorText( err ) ;

//    // Run i/o loop and then close the api.
//    else
//    {
//        IoLoop( sess ); 	// Run the i/o processing loop.

//        s24xx_SessionClose( sess );		// Terminate telnet connection.
//        s24xx_ApiClose();				// Free API resources.
//    }

//    rigol::comms::RigolCommsMarshaler* marshal = new rigol::comms::RigolCommsMarshaler();
//    rigol::comms::TCPConfiguration newConfig;
//    marshal->ConnectToLink(newConfig);
//    QByteArray newArray;
//    newArray.append("*IDN?");
//    marshal->EmitByteArray(newArray);

//    RigolOscilliscope* rigolInterface = new RigolOscilliscope();
//    rigolInterface->openConnection("192.168.1.17",5555);
//    rigolInterface->openConnection("127.0.0.1",5555);


//    rigol::commands::MeasureCommand_Item measureArea;
//    measureArea.setChannel(rigol::data::AvailableChannels::CHANNEL_1);
//    measureArea.setMeasurementType(rigol::data::MeasurementTypes::MEASURE_MAREA);
//    rigolInterface->addPollingMeasurement(measureArea);

//    rigol::commands::MeasureCommand_Item measureVtop;
//    measureVtop.setChannel(rigol::data::AvailableChannels::CHANNEL_2);
//    measureVtop.setMeasurementType(rigol::data::MeasurementTypes::MEASURE_VTOP);
//    rigolInterface->addPollingMeasurement(measureVtop);

//    rigolInterface->executeMeasurementPolling(true);

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
