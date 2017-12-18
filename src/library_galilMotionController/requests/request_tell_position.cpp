#include "request_tell_position.h"

RequestTellPosition::RequestTellPosition()
{

}


RequestTellPosition::RequestTellPosition(const MotorAxis &axis):
    AbstractRequest(RequestTypes::TELL_POSITION), tellAxis(axis)
{

}

RequestTellPosition::RequestTellPosition(const RequestTellPosition &copy):
    AbstractRequest(copy)
{

}

AbstractRequest* RequestTellPosition::getClone() const
{
    return (new RequestTellPosition(*this));
}

void RequestTellPosition::getClone(AbstractRequest** state) const
{
    *state = new RequestTellPosition(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void RequestTellPosition::setAxis(const MotorAxis &axis)
{
    tellAxis = axis;
}

//!
//! \brief getAxis
//! \return
//!
MotorAxis RequestTellPosition::getAxis() const
{
    return tellAxis;
}

std::string RequestTellPosition::getCommandString() const
{
    std::string str = "";
    if(tellAxis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(RequestToString(this->getRequestType()));
        str.append("");
        str.append(AxisToString(tellAxis));
    }
    return str;
}


