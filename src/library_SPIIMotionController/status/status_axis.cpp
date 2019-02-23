#include "status_axis.h"

namespace SPII{

Status_PerAxis::Status_PerAxis():
    AbstractStatus(StatusTypes::STATUS_PER_AXIS)
{

}

Status_PerAxis::Status_PerAxis(const Status_PerAxis &copy):
    AbstractStatus(copy)
{

}

void Status_PerAxis::setAxis(const MotorAxis &axis)
{

}

MotorAxis Status_PerAxis::getAxis() const
{

}

bool Status_PerAxis::isAxisMoving() const
{
    return this->axisMoving;
}


void Status_PerAxis::updateAxisStatus(const int &value)
{
    if(value & ACSC_AST_LEAD)
        this->axisLeading = true;
    else
        this->axisLeading = false;

    if(value & ACSC_AST_DC)
        this->axisDataCollection = true;
    else
        this->axisDataCollection = false;

    if(value & ACSC_AST_PEG)
        this->axisPEG = true;
    else
        this->axisPEG = false;

    if(value & ACSC_AST_MOVE)
        this->axisMoving = true;
    else
        this->axisMoving = false;

    if(value & ACSC_AST_ACC)
        this->axisAccelerating = true;
    else
        this->axisAccelerating = false;

    if(value & ACSC_AST_SEGMENT)
        this->axisSegmentedMotion = true;
    else
        this->axisSegmentedMotion = false;

    if(value & ACSC_AST_VELLOCK)
        this->axisVelLock = true;
    else
        this->axisVelLock = false;

    if(value & ACSC_AST_POSLOCK)
        this->axisPosLock = true;
    else
        this->axisPosLock = false;
}




Status_Axis::Status_Axis():
    AbstractStatus(StatusTypes::STATUS_ALL_AXIS)
{

}

Status_Axis::Status_Axis(const Status_Axis &copy):
    AbstractStatus(copy)
{

}

Status_Axis::~Status_Axis()
{

}

bool Status_Axis::updateAxisStatus(const std::vector<Status_PerAxis> &status)
{
    bool axisChanged = false;
    for(size_t index = 0; index < status.size(); index++)
    {
        Status_PerAxis currentStatus = status.at(index);

        std::map<MotorAxis, DataGetSetNotifier<Status_PerAxis>*>::const_iterator iter = m_AxisStatus.find(currentStatus.getAxis());

        if(iter != m_AxisStatus.end()) //item is already in the map and therefore we just need to update it
        {
            if(m_AxisStatus.at(currentStatus.getAxis())->set(currentStatus))
            {
                if(!axisChanged)
                    axisChanged = true;
            }
        }
        else {
            DataGetSetNotifier<Status_PerAxis>* newStatus = new DataGetSetNotifier<Status_PerAxis>();
            newStatus->set(currentStatus);
            //insert it into the map
            m_AxisStatus.insert(std::pair<MotorAxis, DataGetSetNotifier<Status_PerAxis>*>(currentStatus.getAxis(), newStatus));
            axisChanged = true;
        }
    }
    return axisChanged;
}

Status_Axis* Status_Axis::getAxisStatus(const MotorAxis &axis)
{

}

} //end of namespace SPII
