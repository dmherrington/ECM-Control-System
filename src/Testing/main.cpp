#include <QCoreApplication>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <sys/timeb.h>
#include <time.h>

#include <QString>
#include <QStringList>
#include <QRegExp>

#include "common/environment_time.h"
#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MunkPowerSupply powerSupply;
    powerSupply.openSerialPort("COM9");
    registers_Munk::SegmentTimeDetailed detailedMSG;
    registers_Munk::SegmentTimeDataDetailed firstRegister(10.2,50,data_Munk::SegmentMode::FORWARD,200*1000);
    registers_Munk::SegmentTimeDataDetailed secondRegister(10.2,102,data_Munk::SegmentMode::DEAD,100*1000);
    detailedMSG.appendRegisterData(firstRegister);
    detailedMSG.appendRegisterData(secondRegister);
    powerSupply.generateAndTransmitMessage(detailedMSG);


//    common::EnvironmentTime currentTime;
//    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK, currentTime);

//    char* ECMPath = getenv("ECM_ROOT");
//    std::string loggingPath = "";
//    QFile* sensorLoggingFile;

//    if(ECMPath){
//        std::string rootPath(ECMPath);
//        QDir loggingDirectory(QString::fromStdString(rootPath + "/MachiningLogs/Part_Number/" + currentTime.dateString() + "/"));

//        std::string finalPath = "Serial_Number.txt";

//        loggingDirectory.mkpath(QString::fromStdString(rootPath + "/MachiningLogs/Part_Number/" + currentTime.dateString() + "/"));
//        loggingPath = loggingDirectory.absolutePath().toStdString() + "/" + finalPath;
//        QFileInfo fileInfo(QString::fromStdString(loggingPath));
//        if(fileInfo.exists())
//        {
//            std::cout<<"The file exists"<<std::endl;
//        }
//        else
//        {
//            sensorLoggingFile = new QFile(QString::fromStdString(loggingPath));

//        }
////        while(!loggingDirectory.mkdir(QString::fromStdString(finalPath)))
////        {
////            std::cout<<"Let us warn the user that the file already exists"<<std::endl;
////        }
//    }

    //First let us construct the tuple describing the measurement
//    common::TupleSensorString sensorTuple("Device Name",
//                                          "Channel Name",
//                                          "Sensor Name");

//    common_data::SensorState newSensorMeasurement;
//    newSensorMeasurement.setObservationTime(currentTime);
//    newSensorMeasurement.ConstructSensor(common_data::SENSOR_VOLTAGE,"Voltage Top");
//    ((common_data::SensorVoltage*)newSensorMeasurement.getSensorData().get())->SetVoltage(10.0,common_data::VoltageUnit::UNIT_VOLTAGE_VOLTS);

//    ECMLogging loggingTest;
//    loggingTest.SetSensorLogFile(sensorTuple,sensorLoggingFile);
//    loggingTest.WriteLogSensorState(sensorTuple,newSensorMeasurement);

//    uint8_t byte = 131;
//    uint8_t exceptionMask = 127<<0;
//    uint8_t exceptionValue = (byte & (~exceptionMask));
//    if(exceptionValue == 128)
//    {
//        //we have a problem
//    }
//    std::cout<<"The exception value is: "<<exceptionValue<<std::endl;
//    uint8_t RWMask = 128<<0;
//    uint8_t RWValue = (byte & (~RWMask));
//    std::cout<<"The read write value is: "<<RWValue<<std::endl;

//    GalilMotionController* newGalil = new GalilMotionController();
//    MunkPowerSupply* newMunk = new MunkPowerSupply();

//    Sensoray* newInterface = new Sensoray();
//    comms_Sensoray::SensorayTCPConfiguration sensorayConfig;

//    newInterface->openConnection(sensorayConfig);

//    Westinghouse510* pump = new Westinghouse510(newInterface,03);
//    registers_WestinghousePump::Register_OperationSignal newOps;
//    newOps.setSlaveAddress(03);
//    newOps.shouldReverse(false);
//    newOps.setReadorWrite(data_WestinghousePump::RWType::WRITE);
//    common::comms::SerialConfiguration newSerialConfig;
//    newInterface->openSerialPortConnection(newSerialConfig);
//    QByteArray array;
//    array.append(0x03);
//    array.append(0x03);
//    array.append(0x0C);
//    array.append(0x10);
//    array.append(0x00);
//    array.append(0x01);
//    array.append(0x86);
//    array.append(0x9F);

//    newInterface->writeToSerialPort(array);

//    while(true)
//    {
//        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

//        newOps.shouldRun(false);
//        newInterface->writeToSerialPort(newOps.getFullMessage());

//        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

//        newOps.shouldRun(true);
//        newInterface->writeToSerialPort(newOps.getFullMessage());
//    }

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

//    comms_Rigol::RigolCommsMarshaler* marshal = new comms_Rigol::RigolCommsMarshaler();
//    comms_Rigol::TCPConfiguration newConfig;
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
