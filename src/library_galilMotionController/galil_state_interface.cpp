#include "galil_state_interface.h"

GalilStateInterface::GalilStateInterface(const std::vector<MotorAxis> &availableAxis)
{
    //we should perform some sort of check to ensure that the vector does not contain all
    //if we see one all, just iterate through all available axis and clear original ones
    //leading up to it
    for(unsigned int i = 0; i < availableAxis.size(); i++)
    {
        GalilStatus* newAxisStatus = new GalilStatus(availableAxis[i]);
        mStatus[availableAxis[i]] = newAxisStatus;

    }

    commsMarshaler = new Comms::CommsMarshaler();
    commsMarshaler->AddSubscriber(this);
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

StatusInputs* GalilStateInterface::getStatusInputs() const
{
    return this->statusInputs;
}

void GalilStateInterface::updatePosition(const std::vector<Status_Position> &data)
{
    for (unsigned int i = 0; i < data.size(); i++)
    {
        MotorAxis axis = data.at(i).getAxis();
        if(mStatus.count(axis) > 0)
            mStatus.at(axis)->setPosition(data.at(i));
    }
}

void GalilStateInterface::setConnected(const bool &val)
{
    this->connected = val;
}

bool GalilStateInterface::isConnected()
{
    return this->connected;
}

bool GalilStateInterface::isMotorInMotion() const
{
    bool isInMotion = false;

    std::map<MotorAxis,GalilStatus*>::const_iterator it;

    for (it=mStatus.begin(); it!=mStatus.end(); ++it)
    {
        GalilStatus* axisStatus = it->second;
        if(axisStatus->isAxisinMotion())
        {
            isInMotion = true;
            break;
        }
    }

    return isInMotion;
}

void GalilStateInterface::NewStatusPosition(const Status_Position &status)
{
    std::cout<<"State interface has seen a new position"<<std::endl;
}

void GalilStateInterface::NewStatusMotorEnabled(const Status_MotorEnabled &status)
{
    std::cout<<"State interface has seen a new motor enabled"<<std::endl;
}

void GalilStateInterface::NewStatusMotorInMotion(const Status_AxisInMotion &status)
{
    std::cout<<"State interface has seen a new motor in motion"<<std::endl;
}


