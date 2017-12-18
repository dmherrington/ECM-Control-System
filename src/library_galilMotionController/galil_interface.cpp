#include "galil_interface.h"

GalilInterface::GalilInterface():
    galil(nullptr)
{
    galilPolling = new GalilPollState();
    galilPolling->connectCallback(this);

    std::vector<MotorAxis> axisVector =  GetAxisVector();
    for(unsigned int i = 0; i < axisVector.size(); i++)
    {
        mStatus[axisVector[i]] = new GalilStatus();
    }
}

GalilInterface::~GalilInterface()
{
    std::map<MotorAxis,GalilStatus*>::iterator it;

    for (it=mStatus.begin(); it!=mStatus.end(); ++it)
    {
        GalilStatus* axisStatus = it->second;
        delete axisStatus;
        axisStatus = nullptr;
    }
    mStatus.clear();
}

void GalilInterface::cbi_GalilStatusUpdatePosition()
{
    //First update the status variable

    //Call update on the state machine
    stateMachine->UpdateStates();
    //Determine if there are any transitions to be had
    stateMachine->ProcessStateTransitions();
}
void GalilInterface::cbi_GalilStatusUpdateSwitches()
{
    //Call update on the state machine
    stateMachine->UpdateStates();
    //Determine if there are any transitions to be had
    stateMachine->ProcessStateTransitions();
}
void GalilInterface::cbi_GalilStatusUpdateStopCodes()
{
    //Call update on the state machine
    stateMachine->UpdateStates();
    //Determine if there are any transitions to be had
    stateMachine->ProcessStateTransitions();
}

GalilStatus* GalilInterface::getAxisStatus(const MotorAxis &axis)
{
    if(mStatus.count(axis))
        return mStatus.at(axis);
    else
        return nullptr;
}

void GalilInterface::transmitMessage(const AbstractRequest *req)
{

}

void GalilInterface::transmitMessage(const AbstractCommand *cmd)
{

}

void GalilInterface::transmitMessage(const std::string &msg)
{

}

