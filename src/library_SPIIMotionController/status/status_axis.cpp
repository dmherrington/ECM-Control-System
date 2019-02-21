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

void Status_PerAxis::setMotorMoving(const bool &moving)
{

}

bool Status_PerAxis::isMotorMoving() const
{

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

void Status_Axis::updateAxisStatus(const Status_Axis &status)
{

}

Status_Axis* Status_Axis::getAxisStatus(const MotorAxis &axis)
{

}

} //end of namespace SPII
