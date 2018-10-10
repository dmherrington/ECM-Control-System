#include "request_tell_variable.h"

Request_TellVariable::Request_TellVariable(const std::string &humName, const std::string &varName, const std::string &unit):
    AbstractRequest(RequestTypes::TELL_VARIABLE), humanName(humName), variableName(varName), unitName(unit)
{

}


Request_TellVariable::Request_TellVariable(const Request_TellVariable &copy):
    AbstractRequest(copy)
{
    this->humanName = copy.humanName;
    this->variableName = copy.variableName;
    this->unitName = copy.unitName;
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

void Request_TellVariable::setUnitName(const std::string &unit)
{
    this->unitName = unit;
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

std::string Request_TellVariable::getUnitName() const
{
    return this->unitName;
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

    if(list.size() > 0)
    {
        result = list.at(0);
        result = result.trimmed();

        Status_VariableValuePtr status = std::make_shared<Status_VariableValue>(result.toDouble());
        status->setVariableName(this->variableName);
        status->setVariableUnit(this->unitName);
        status->setTime(latestUpdate);
        rtn.push_back(status);
    }

    return rtn;
}
