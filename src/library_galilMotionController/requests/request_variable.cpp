#include "request_tell_variable.h"

Request_TellVariable::Request_TellVariable(const std::string &name):
    AbstractRequest(RequestTypes::TELL_VARIABLE), variableName(name)
{

}


Request_TellVariable::Request_TellVariable(const Request_TellVariable &copy):
    AbstractRequest(copy)
{
    this->variableName = copy.variableName;
}

AbstractRequest* Request_TellVariable::getClone() const
{
    return (new Request_TellVariable(*this));
}

void Request_TellVariable::getClone(AbstractRequest** state) const
{
    *state = new Request_TellVariable(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void Request_TellVariable::setVariableName(const std::string &name)
{
    this->variableName = name;
}

//!
//! \brief getAxis
//! \return
//!
std::string Request_TellVariable::getVariableName() const
{
    return this->variableName;
}

std::string Request_TellVariable::getRequestString() const
{
    std::string str = "";
    str += variableName;
    str += "=?";
    return str;
}

std::vector<AbstractStatusPtr> Request_TellVariable::getStatus() const
{
    std::vector<AbstractStatusPtr> rtn;
    QString result = QString::fromStdString(buffer);
    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    result = list.at(0);
    result = result.trimmed();

    Status_VariableValuePtr status = std::make_shared<Status_VariableValue>(this->variableName,result.toDouble());
    status->setTime(latestUpdate);
    rtn.push_back(status);
    return rtn;
}
