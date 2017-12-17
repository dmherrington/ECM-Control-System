#include "galil_interface.h"

GalilInterface::GalilInterface()
{
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

GalilStatus* GalilInterface::getAxisStatus(const MotorAxis &axis)
{
    if(mStatus.count(axis))
        return mStatus.at(axis);
    else
        return nullptr;
}

void GalilInterface::transmitMessage(const AbstractCommand *cmd)
{

}

void GalilInterface::transmitMessage(const std::string &msg)
{

}

