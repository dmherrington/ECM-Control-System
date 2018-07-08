#include "request_tell_inputs.h"

RequestTellInputs::RequestTellInputs():
    AbstractRequest(RequestTypes::TELL_INPUTS,8)
{

}

RequestTellInputs::RequestTellInputs(const RequestTellInputs &copy):
    AbstractRequest(RequestTypes::TELL_INPUTS,5)
{

}

AbstractRequest* RequestTellInputs::getClone() const
{
    return (new RequestTellInputs(*this));
}

void RequestTellInputs::getClone(AbstractRequest** req) const
{
    *req = new RequestTellInputs(*this);
}

std::string RequestTellInputs::getRequestString() const
{
    std::string str = "";

    str.append(RequestToString(this->getRequestType()));
    str.append("");
    return str;
}

std::vector<AbstractStatusPtr> RequestTellInputs::getStatus() const
{
    std::vector<AbstractStatusPtr> rtn;
    //as the galil only currently reports a single axis here, we will make the parse easy for now
    QString result = QString::fromStdString(buffer);
    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    if(list.size() > 0)
    {
        result = list.at(0);
        result = result.trimmed();
        StatusInputsPtr inputs = std::make_shared<StatusInputs>();
        inputs->setInputCode(result.toInt());
        inputs->setTime(latestUpdate);
        rtn.push_back(inputs);
    }
    return rtn;
}

