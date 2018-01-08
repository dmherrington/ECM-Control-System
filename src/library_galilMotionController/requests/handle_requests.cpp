#include "galil_motion_controller.h"

void galilMotionController::cbi_GalilStatusRequestCommand(const AbstractRequest *request)
{
//    char buf[0];

//    switch (request->getRequestType()) {
//    case RequestTypes::STOP_CODE:
//    {
//        break;
//    }
//    case RequestTypes::TELL_POSITION:
//    {
//        const RequestTellPosition* castRequest = request->as<RequestTellPosition>();
//        castRequest->getBuffer(buf);
//        GSize read_bytes = 0; //bytes read in GCommand
//        GReturn rtn = G_NO_ERROR;
//        //GReturn rtn = GCommand(galil,castRequest->getRequestString().c_str(),buf,sizeof(buf),&read_bytes);
//        if(rtn == G_NO_ERROR)
//        {
//            //first let us parse the resulting data
//            //std::vector<Status_Position> position = castRequest->parseResponse(buf);
//            std::vector<Status_Position> position;
//            Data::EnvironmentTime time;
//            time.CurrentTime(Data::Devices::SYSTEMCLOCK,time);
//            Status_Position newPosition(MotorAxis::Z,time,10);
//            position.push_back(newPosition);
//            //next update the data within the interface
//            stateInterface->updatePosition(position);
//            if(stateInterface->getAxisStatus(MotorAxis::Z)->isMotorRunning())
//            {
//                stateMachine->UpdateStates();
//                stateMachine->ProcessStateTransitions();
//            }
//        }
//        if(rtn == G_BAD_RESPONSE_QUESTION_MARK)
//        {
//            char errorBuf[60];
//            std::string newCommand = "TC 1";
//            GReturn rtn = GCommand(galil,newCommand.c_str(),errorBuf,sizeof(errorBuf),&read_bytes);
//            std::cout<<"Trying to figure out why there is an error"<<std::endl;
//        }
//        break;
//    }
//    case RequestTypes::TELL_SWITCHES:
//    {
//        break;
//    }
//    default:
//        std::cout<<"The callback interface requested a command that is not currently supported."<<std::endl;
//        break;
//    }
}
