#include "request_stop_code.h"

RequestStopCode::RequestStopCode(const MotorAxis &axis):
    AbstractRequest(RequestTypes::STOP_CODE), codeAxis(axis)
{

}

RequestStopCode::RequestStopCode(const RequestStopCode &copy):
    AbstractRequest(copy)
{
    this->codeAxis = copy.codeAxis;
}

AbstractRequest* RequestStopCode::getClone() const
{
    return (new RequestStopCode(*this));
}

void RequestStopCode::getClone(AbstractRequest** state) const
{
    *state = new RequestStopCode(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void RequestStopCode::setAxis(const MotorAxis &axis)
{
    codeAxis = axis;
}

//!
//! \brief getAxis
//! \return
//!
MotorAxis RequestStopCode::getAxis() const
{
    return codeAxis;
}

std::string RequestStopCode::getRequestString() const
{
    std::string str = "";
    if(codeAxis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(RequestToString(this->getRequestType()));
        str.append(" ");
        str.append(AxisToString(codeAxis));
    }
    return str;
}

std::vector<AbstractStatusPtr> RequestStopCode::getStatus() const
{
    std::vector<AbstractStatusPtr> rtn;
    //as the galil only currently reports a single axis here, we will make the parse easy for now
    QString result = QString::fromStdString(buffer);
    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    result = list.at(0);
    result = result.trimmed();
    if(codeAxis == MotorAxis::ALL)
    {
        //we will not currently support this
    }
    else{
        Status_StopCodePtr status = std::make_shared<Status_StopCode>();
        status->setAxis(codeAxis);
        status->setTime(latestUpdate);
        status->setStopCode(result.toInt());
        rtn.push_back(status);
    }
    return rtn;
}
