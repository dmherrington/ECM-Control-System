#include "status_motor.h"

Status_MotorPerAxis::Status_MotorPerAxis():
    AbstractStatus(StatusTypes::STATUS_PER_MOTOR_AXIS)
{

}

Status_MotorPerAxis::Status_MotorPerAxis(const Status_MotorPerAxis &copy):
    AbstractStatus (copy)
{

}

void Status_MotorPerAxis::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

MotorAxis Status_MotorPerAxis::getAxis() const
{
    return this->currentAxis;
}

void Status_MotorPerAxis::updateMotorAxisStatus(const int &value)
{
    if(value & ACSC_MST_ENABLE)
        this->isEnabled = true;
    else
        this->isEnabled = false;

    if(value & ACSC_MST_INPOS)
        this->hasReachedTarget = true;
    else
        this->hasReachedTarget = false;

    if(value & ACSC_MST_MOVE)
        this->isMoving = true;
    else
        this->isMoving = false;

    if(value & ACSC_MST_ACC)
        this->isAccelerating = true;
    else
        this->isAccelerating = false;
}

bool Status_MotorPerAxis::isMotorEnabled() const
{
    return this->isEnabled;
}
bool Status_MotorPerAxis::hasMotorReachedTarget() const
{
    return this->hasReachedTarget;
}
bool Status_MotorPerAxis::isMotorMoving() const
{
    return this->isMoving;
}
bool Status_MotorPerAxis::isMotorAccelerating() const
{
    return this->isAccelerating;
}



Status_Motor::Status_Motor():
    AbstractStatus(StatusTypes::STATUS_ALL_MOTOR_AXIS)
{

}

Status_Motor::Status_Motor(const Status_Motor &copy):
    AbstractStatus(copy)
{

}

Status_Motor::~Status_Motor()
{

}

bool Status_Motor::areAnyMotorsEnabled() const
{
    for (std::map<MotorAxis, DataGetSetNotifier<Status_MotorPerAxis>*>::const_iterator it=m_MotorStatus.begin(); it!=m_MotorStatus.end(); ++it)
    {
        if(it->second->get().isMotorEnabled())
            return true;
    }

    return false;
}

bool Status_Motor::updateMotorStatus(const std::vector<Status_MotorPerAxis> &status)
{

    bool motorChanged = false;
    for(size_t index = 0; index < status.size(); index++)
    {
        Status_MotorPerAxis currentStatus = status.at(index);

        std::map<MotorAxis, DataGetSetNotifier<Status_MotorPerAxis>*>::const_iterator iter = m_MotorStatus.find(currentStatus.getAxis());

        if(iter != m_MotorStatus.end()) //item is already in the map and therefore we just need to update it
        {
            if(m_MotorStatus.at(currentStatus.getAxis())->set(currentStatus))
            {
                if(!motorChanged)
                    motorChanged = true;
            }
        }
        else {
            DataGetSetNotifier<Status_MotorPerAxis>* newStatus = new DataGetSetNotifier<Status_MotorPerAxis>();
            newStatus->set(currentStatus);
            //insert it into the map
            m_MotorStatus.insert(std::pair<MotorAxis, DataGetSetNotifier<Status_MotorPerAxis>*>(currentStatus.getAxis(), newStatus));
            motorChanged = true;
        }
    }
    return motorChanged;
}



Status_MotorPerAxis* Status_Motor::getAxisStatus(const MotorAxis &axis)
{

}
