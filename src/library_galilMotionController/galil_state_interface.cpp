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


void GalilStateInterface::setConnected(const bool &val)
{
    this->connected = val;
}

void GalilStateInterface::setHomeInidcated(const bool &val)
{
    this->indicatedHome = val;
    if(m_CB)
        m_CB->cbi_GalilHomeIndicated(this->indicatedHome);
}

bool GalilStateInterface::isConnected() const
{
    return this->connected;
}

bool GalilStateInterface::isHomeInidcated() const
{
    return this->indicatedHome;
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

bool GalilStateInterface::isMotorEnabled() const
{
    bool isArmed = false;

    std::map<MotorAxis,GalilStatus*>::const_iterator it;

    for (it=mStatus.begin(); it!=mStatus.end(); ++it)
    {
        GalilStatus* axisStatus = it->second;
        if(axisStatus->isMotorEnabled())
        {
            isArmed = true;
            break;
        }
    }

    return isArmed;
}

bool GalilStateInterface::isEStopEngaged() const
{
    return statusInputs.get().getResult(GalilPins::GALIL_PIN_ESTOP);
}


