#include "spii_state_interface.h"

GalilStateInterface::GalilStateInterface(const std::vector<MotorAxis> &availableAxis):
    m_CB(nullptr), statusVariableValues(nullptr)
{
    galilProgram = new GalilCurrentProgram();
    statusVariableValues = new ProgramVariableValueList();

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
    try{
        return mStatus.at(axis);
    }catch(std::out_of_range &oor)
    {
        std::cout<<"We tried to get an Axis Status that does not exist yet."<<std::endl;
        return nullptr;
    }
}

void GalilStateInterface::setHomeInidcated(const bool &val)
{
    this->indicatedHome = val;
    if(m_CB)
        m_CB->cbi_GalilHomeIndicated(this->indicatedHome);
}

bool GalilStateInterface::isHomeInidcated() const
{
    return this->indicatedHome;
}


void GalilStateInterface::setTouchoffIndicated(const bool &val)
{
    this->indicatedTouchoff = val;
    if(m_CB)
        m_CB->cbi_GalilTouchoffIndicated(this->indicatedTouchoff);
}

bool GalilStateInterface::isTouchoffIndicated() const
{
    return this->indicatedTouchoff;
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


