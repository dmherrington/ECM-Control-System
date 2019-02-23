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
    segmentObject["touchoffRef"] = this->getTouchoffRef();
    segmentObject["touchoffGap"] = this->getTouchoffGap();
    segmentDataArray.append(segmentObject);

    saveObject["touchoffData"] = segmentDataArray;
}

void Configuration_Touchoff::readFromJSON(const QJsonObject &openObject)
{
    QJsonArray touchoffDataArray = openObject["touchoffData"].toArray();
    QJsonObject touchoffObject = touchoffDataArray[0].toObject();

    setTouchoffUtilization(touchoffObject["touchoffExecute"].toBool());
    setTouchoffUtilizePreviousPosition(touchoffObject["touchoffRefPrevious"].toBool());
    setTouchoffRef(touchoffObject["touchoffRef"].toDouble());
    setTouchoffGap(touchoffObject["touchoffGap"].toDouble());

}

void Configuration_Touchoff::setTouchoffUtilization(const bool &usage)
{
    this->utilizeTouchoff = usage;
}
void Configuration_Touchoff::setTouchoffUtilizePreviousPosition(const bool &usage)
{
    this->utilizeExistingPosition = usage;
}
void Configuration_Touchoff::setTouchoffRef(const double &distance)
{
    this->touchoffRef = distance;
}
void Configuration_Touchoff::setTouchoffGap(const double &distance)
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

double Configuration_Touchoff::getTouchoffRef() const
{
    return this->touchoffRef;
}
double Configuration_Touchoff::getTouchoffGap() const
{
    return this->touchoffGap;
}

Command_Variable Configuration_Touchoff::getTouchoffRefCommand() const
{
    Command_Variable newVariable("touchref",this->touchoffRef);
    return newVariable;
}
Command_Variable Configuration_Touchoff::getTouchoffGapCommand() const
{
    Command_Variable newVariable("initgap",this->touchoffGap);
    return newVariable;
}
