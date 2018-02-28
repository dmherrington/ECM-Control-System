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

#include "library_rigol_oscilloscope/rigol_oscilliscope.h"
#include "clock_testing.h"

#include "s24xx.h"


// Forward declaration.
static void IoLoop( HSESSION sess );

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Testing of the Sensoray device
    HSESSION sess;
    S24XXERR err = ERR_NONE;
    if ( !s24xx_ApiOpen() )
        printf( "Error: Failed to open session interface\n" );

    // Create session object and open the telnet session.
    else if ( !s24xx_SessionOpen( &sess, &err, 2426, "192.168.1.101", 23, 2000 ) )
        s24xx_ErrorText( err ) ;

    // Run i/o loop and then close the api.
    else
    {
        IoLoop( sess ); 	// Run the i/o processing loop.

        s24xx_SessionClose( sess );		// Terminate telnet connection.
        s24xx_ApiClose();				// Free API resources.
    }

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

//////////////////////////////////////
// Main I/O processing loop.

static void IoLoop(HSESSION sess )
{
    S2426_ADC_SAMPLE samp[8];
    int	iters;
    S24XXERR err = ERR_NONE;
    u8	dioChan;
    u32	EncoderCounts;			// Snapshot of encoder counts and acquisition time.
    u32	EncoderTimestamp;
    u8	dinDebounced;			// Snapshot of debounced dins.

    // Set session timeout to 5 seconds. Don't reset i/o upon timeout.
//	s24xx_SetTimeout( sess, &err, 5, UNITS_SECONDS, ACTION_NONE );

    // Set encoder mode.
    s2426_WriteEncoderMode( sess, &err, QUADRATURE_X4, ENC_PRELOAD_DISABLE );

    // Activate pwm mode for dout channels 12-15, using arbitrary timing values.
    for ( dioChan = 12; dioChan < 16; dioChan++ )
    {
        s2426_SetDoutMode( sess, &err, dioChan, DOUT2426_MODE_PWM );
        s2426_WritePwm( sess, &err, dioChan, (u16)( ( 23 * ( dioChan + 1 ) ) & 255 ), (u16)( ( 39 * ( dioChan + 1 ) ) & 511 ) );
    }

    // Execute the i/o processing loop a few times, approximately ten times per second.
    for (iters = 0; iters < 10000; iters++)
    {
        // Read encoder counts.
        s2426_ReadEncoderCounts( sess, &err, &EncoderCounts, &EncoderTimestamp );

        // Write counts to digital outputs.
        s2426_WriteDout( sess, &err, (u16)iters );

        // Read a/d converter.
        s2426_ReadAdc( sess, &err, samp, TRUE );

        // Write counts to dac.
        s2426_WriteAout( sess, &err, (s16)iters, TRUE );

        // Read debounced digital inputs.
        s2426_ReadDin( sess, &err, &dinDebounced, NULL );

        // Abort if error detected.
        if ( err != ERR_NONE )
        {
            printf( "Error: %s\n", s24xx_ErrorText( err ) );
            break;
        }

        // Wait one "tick" time. In a realtime application this should use an ipc mechanism with realtime behavior.
        Sleep(1);
    }
}
