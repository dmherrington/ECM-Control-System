#include "request_tell_position.h"

RequestTellPosition::RequestTellPosition(const MotorAxis &axis):
    AbstractRequest(RequestTypes::TELL_POSITION,20), tellAxis(axis)
{

}

RequestTellPosition::RequestTellPosition(const RequestTellPosition &copy):
    AbstractRequest(copy)
{
    this->tellAxis = copy.tellAxis;
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

std::string RequestTellPosition::getRequestString() const
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

std::vector<AbstractStatusPtr> RequestTellPosition::getStatus() const
{
    std::vector<AbstractStatusPtr> rtn;
    //as the galil only currently reports a single axis here, we will make the parse easy for now
    QString result = QString::fromStdString(buffer);
    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    result = list.at(0);
    result = result.trimmed();
    if(tellAxis == MotorAxis::ALL)
    {
        //we will not currently support this
    }
    else{
        Status_PositionPtr position = std::make_shared<Status_Position>();
        position->setAxis(tellAxis);
        position->setTime(latestUpdate);
        position->setPosition(result.toInt());
       rtn.push_back(position);
    }

    return rtn;
}


