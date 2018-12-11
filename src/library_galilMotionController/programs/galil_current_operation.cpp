#include "galil_current_operation.h"

GalilCurrentOperation::GalilCurrentOperation():
    GalilCurrentProgram()
{

}

GalilCurrentOperation::GalilCurrentOperation(const GalilCurrentOperation &copy):
    GalilCurrentProgram(copy)
{
    this->operationIndex = copy.operationIndex;
    this->operationName = copy.operationName;
    this->profileName = copy.profileName;
}

void GalilCurrentOperation::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray MCDataArray;
    QJsonObject dataObject;

    dataObject["profileName"] = QString::fromStdString(this->getProfileName());
    dataObject["programScript"] = QString::fromStdString(this->getProgram());
    this->labelList.writeToJSON(dataObject);
    this->variableList.writeToJSON(dataObject);
    MCDataArray.append(dataObject);

    saveObject["MotionControlData"] = MCDataArray;
}

void GalilCurrentOperation::readFromJSON(const QJsonObject &openObject)
{
    QJsonArray MCDataArray = openObject["MotionControlData"].toArray();
    QJsonObject MCObject = MCDataArray[0].toObject();

    this->setProfileName(MCObject["profileName"].toString().toStdString());
    this->setProgram(MCObject["programScript"].toString().toStdString());
    this->labelList.readFromJSON(MCObject);
    this->variableList.readFromJSON(MCObject);
}

void GalilCurrentOperation::setOperationIndex(const unsigned int &index)
{
    this->operationIndex = index;
}
void GalilCurrentOperation::setOperationName(const std::string &name)
{
    this->operationName = name;
}
void GalilCurrentOperation::setProfileName(const std::string &name)
{
    this->profileName = name;
}

unsigned int GalilCurrentOperation::getOperationIndex() const
{
    return this->operationIndex;
}
std::string GalilCurrentOperation::getOperationName() const
{
    return this->operationName;
}
std::string GalilCurrentOperation::getProfileName() const
{
    return this->profileName;
}
