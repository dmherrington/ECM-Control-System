#include "configuration_touchoff.h"

Configuration_Touchoff::Configuration_Touchoff()
{

}

Configuration_Touchoff::Configuration_Touchoff(const Configuration_Touchoff &copy)
{
    this->utilizeTouchoff = copy.utilizeTouchoff;
    this->utilizeExistingPosition = copy.utilizeExistingPosition;
    this->touchoffRef = copy.touchoffRef;
    this->touchoffGap = copy.touchoffGap;
}

void Configuration_Touchoff::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray segmentDataArray;

    QJsonObject segmentObject;
    segmentObject["touchoffExecute"] = this->shouldTouchoffBeUtilized();
    segmentObject["touchoffRefPrevious"]    = this->shouldTouchoffUtilizePreviousPosition();

    segmentObject["touchoffRefX"] = this->getTouchoffRef().at(MotorAxis::X);
    segmentObject["touchoffRefY"] = this->getTouchoffRef().at(MotorAxis::Y);
    segmentObject["touchoffRefZ"] = this->getTouchoffRef().at(MotorAxis::Z);

    segmentObject["touchoffGapX"] = this->getTouchoffGap().at(MotorAxis::X);
    segmentObject["touchoffGapY"] = this->getTouchoffGap().at(MotorAxis::Y);
    segmentObject["touchoffGapZ"] = this->getTouchoffGap().at(MotorAxis::Z);

    segmentDataArray.append(segmentObject);

    saveObject["touchoffData"] = segmentDataArray;
}

void Configuration_Touchoff::readFromJSON(const QJsonObject &openObject)
{
    QJsonArray touchoffDataArray = openObject["touchoffData"].toArray();
    QJsonObject touchoffObject = touchoffDataArray[0].toObject();

    setTouchoffUtilization(touchoffObject["touchoffExecute"].toBool());
    setTouchoffUtilizePreviousPosition(touchoffObject["touchoffRefPrevious"].toBool());

    std::map<MotorAxis,double> touchoffMap;
    touchoffMap.insert(std::pair<MotorAxis, double>(MotorAxis::X, touchoffObject["touchoffRefX"].toDouble()));
    touchoffMap.insert(std::pair<MotorAxis, double>(MotorAxis::Y, touchoffObject["touchoffRefY"].toDouble()));
    touchoffMap.insert(std::pair<MotorAxis, double>(MotorAxis::Z, touchoffObject["touchoffRefZ"].toDouble()));

    std::map<MotorAxis,double> touchoffGapMap;
    touchoffGapMap.insert(std::pair<MotorAxis, double>(MotorAxis::X, touchoffObject["touchoffGapX"].toDouble()));
    touchoffGapMap.insert(std::pair<MotorAxis, double>(MotorAxis::Y, touchoffObject["touchoffGapY"].toDouble()));
    touchoffGapMap.insert(std::pair<MotorAxis, double>(MotorAxis::Z, touchoffObject["touchoffGapZ"].toDouble()));

    setTouchoffRef(touchoffMap);
    setTouchoffGap(touchoffGapMap);

}

void Configuration_Touchoff::setTouchoffUtilization(const bool &usage)
{
    this->utilizeTouchoff = usage;
}
void Configuration_Touchoff::setTouchoffUtilizePreviousPosition(const bool &usage)
{
    this->utilizeExistingPosition = usage;
}
void Configuration_Touchoff::setTouchoffRef(const std::map<MotorAxis,double> &distance)
{
    this->touchoffRef = distance;
}
void Configuration_Touchoff::setTouchoffGap(const std::map<MotorAxis,double> &distance)
{
    this->touchoffGap = distance;
}

bool Configuration_Touchoff::shouldTouchoffBeUtilized() const
{
    return this->utilizeTouchoff;
}
bool Configuration_Touchoff::shouldTouchoffUtilizePreviousPosition() const
{
    return this->utilizeExistingPosition;
}

std::map<MotorAxis,double> Configuration_Touchoff::getTouchoffRef() const
{
    return this->touchoffRef;
}
std::map<MotorAxis,double> Configuration_Touchoff::getTouchoffGap() const
{
    return this->touchoffGap;
}

Command_VariableArray Configuration_Touchoff::getTouchoffRefCommand() const
{
    Command_VariableArray newVariable;
    newVariable.setVariableName("");

    std::vector<double> refVector;
    std::map<MotorAxis,double>::const_iterator it;
    for(it = touchoffRef.begin(); it != touchoffRef.end(); ++it)
    {
        refVector.push_back(it->second);
    }

    newVariable.setVariableValue(refVector);

    return newVariable;
}
Command_VariableArray Configuration_Touchoff::getTouchoffGapCommand() const
{
    Command_VariableArray newVariable;
    newVariable.setVariableName("");

    std::vector<double> gapVector;
    std::map<MotorAxis,double>::const_iterator it;
    for(it = touchoffGap.begin(); it != touchoffGap.end(); ++it)
    {
        gapVector.push_back(it->second);
    }

    newVariable.setVariableValue(gapVector);

    return newVariable;
}
