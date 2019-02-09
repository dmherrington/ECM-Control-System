#include "status_position.h"

namespace SPII{

Status_PositionPerAxis::Status_PositionPerAxis():
    AbstractStatus(StatusTypes::STATUS_POSITION)
{
    this->currentAxis = MotorAxis::Z;
    this->position = 0;
}

Status_PositionPerAxis::Status_PositionPerAxis(const Status_PositionPerAxis &copy):
    AbstractStatus(copy)
{
    this->currentAxis = copy.currentAxis;
    this->position = copy.position;
}

void Status_PositionPerAxis::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

void Status_PositionPerAxis::setPosition(const int &pos)
{
    this->position = pos;
}

MotorAxis Status_PositionPerAxis::getAxis() const
{
    return this->currentAxis;
}

int Status_PositionPerAxis::getPosition() const
{
    return position;
}

void Status_Position::updatePositionStatus(const Status_PositionPerAxis &status)
{
    if(m_PositionStatus.count(status.getAxis()) > 0)
    {
        m_PositionStatus.at(status.getAxis()).set(status);
    }
    else
    {
        DataGetSetNotifier<Status_PositionPerAxis> newStatus(status);
        m_PositionStatus.insert(std::pair<MotorAxis,DataGetSetNotifier<Status_PositionPerAxis>>(newStatus.getAxis(),newStatus));
    }
}

Status_PositionPerAxis* Status_Position::getAxisPosition(const MotorAxis &axis)
{
    if(m_PositionStatus.count(axis) > 0)
    {
        return &m_PositionStatus.at(axis).get();
    }
    else
    {
        return nullptr;
    }
}

} //end of namespace SPII

