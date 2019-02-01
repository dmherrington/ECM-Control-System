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
    m_PositionStatus.insert(std::pair<MotorAxis,Status_PositionPerAxis>(status.getAxis(),status));
}

Status_PositionPerAxis* Status_Position::getAxisPosition(const MotorAxis &axis)
{

}

} //end of namespace SPII

