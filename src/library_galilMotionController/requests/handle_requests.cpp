#include "galil_motion_controller.h"

void galilMotionController::handleRequests(const AbstractRequest *request)
{
    switch (request->getRequestType()) {
    case RequestTypes::LIST_LABELS:
    {
        break;
    }
    case RequestTypes::LIST_VARIABLES:
    {
        break;
    }
    case RequestTypes::STOP_CODE:
    {
        break;
    }
    case RequestTypes::TELL_POSITION:
    {
        char buf[0];
        request->getBuffer(buf);
        GSize read_bytes = 0; //bytes read in GCommand
        GReturn rtn = GCommand(galil,request->getRequestString().c_str(),buf,sizeof(buf),&read_bytes);
        if(rtn == G_NO_ERROR)
        {
            //we are good to update the status of the machine and call any updates required within the state machine
            //stateInterface
        }
        if(rtn == G_BAD_RESPONSE_QUESTION_MARK)
        {
            std::string newCommand = "TC 1";
            GReturn rtn = GCommand(mConnection,newCommand.c_str(),buf,sizeof(buf),&read_bytes);
            std::cout<<"Trying to figure out why there is an error"<<std::endl;
        }
        break;
    }
    case RequestTypes::TELL_SWITCHES:
    {
        break;
    }
    default:
        break;
    }
}
