#include "request_tell_variable.h"

Request_TellVariable::Request_TellVariable(const std::string &humName, const std::string &varName):
    AbstractRequest(RequestTypes::TELL_VARIABLE), humanName(humName), variableName(varName)
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

/*!
 * \brief Request_TellVariable::setHumanName
 * \param name
 */
void Request_TellVariable::setHumanName(const std::string &name)
{
    this->humanName = name;
}

/*!
 * \brief Request_TellVariable::setVariableName
 * \param name
 */
void Request_TellVariable::setVariableName(const std::string &name)
{
    this->variableName = name;
}

/*!
 * \brief Request_TellVariable::getHumanName
 * \return
 */
std::string Request_TellVariable::getHumanName() const
{
    return this->humanName;
}

/*!
 * \brief getVariableName
 * \return
 */
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

    Status_VariableValuePtr status = std::make_shared<Status_VariableValue>(this->getTupleDescription(),result.toDouble());
    status->setTime(latestUpdate);
    rtn.push_back(status);
    return rtn;
}
