#include "galil_state_interface.h"

GalilStateInterface::GalilStateInterface()
{
    std::vector<MotorAxis> axisVector =  GetAxisVector();
    for(unsigned int i = 0; i < axisVector.size(); i++)
    {
        mStatus[axisVector[i]] = new GalilStatus();
    }
}

GalilStateInterface::~GalilStateInterface()
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

GalilStatus* GalilStateInterface::getAxisStatus(const MotorAxis &axis)
{
    if(mStatus.count(axis))
        return mStatus.at(axis);
    else
        return nullptr;
}

void GalilStateInterface::transmitMessage(const AbstractRequest *req)
{

}

void GalilStateInterface::transmitMessage(const AbstractCommand *cmd)
{

}

void GalilStateInterface::transmitMessage(const std::string &msg)
{

}

