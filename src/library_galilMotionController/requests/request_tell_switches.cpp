#include "request_tell_switches.h"

RequestTellSwitches::RequestTellSwitches(const MotorAxis &axis):
    AbstractRequest(RequestTypes::TELL_SWITCHES), tellAxis(axis)
{

}


RequestTellSwitches::RequestTellSwitches(const RequestTellSwitches &copy):
    AbstractRequest(copy)
{
    this->tellAxis = copy.tellAxis;
}

void RequestTellSwitches::initializeStatusMap()
{

}

AbstractRequest* RequestTellSwitches::getClone() const
{
    return (new RequestTellSwitches(*this));
}

void RequestTellSwitches::getClone(AbstractRequest** state) const
{
    *state = new RequestTellSwitches(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void RequestTellSwitches::setAxis(const MotorAxis &axis)
{
    tellAxis = axis;
}

//!
//! \brief getAxis
//! \return
//!
MotorAxis RequestTellSwitches::getAxis() const
{
    return tellAxis;
}

std::string RequestTellSwitches::getRequestString() const
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

std::vector<AbstractStatusPtr> RequestTellSwitches::getStatus() const
{
    std::vector<AbstractStatusPtr> rtn;
    //as the galil only currently reports a single axis here, we will make the parse easy for now
    QString result = QString::fromStdString(buffer);
    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);

    if(list.size() > 0)
    {
        result = list.at(0);
        result = result.trimmed();
        if(tellAxis == MotorAxis::ALL)
        {
            //we will not currently support this
        }
        else{
            Status_SwitchPtr status = std::make_shared<Status_Switch>();
            status->setAxis(tellAxis);
            status->setTime(latestUpdate);
            status->setSwitchCode(result.toInt());
            rtn.push_back(status);
        }
    }

    return rtn;
}





