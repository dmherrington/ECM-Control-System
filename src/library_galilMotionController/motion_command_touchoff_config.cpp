#include "motion_command_touchoff_config.h"

MotionCommand_TouchoffConfig::MotionCommand_TouchoffConfig()
{

}

MotionCommand_TouchoffConfig::MotionCommand_TouchoffConfig(const MotionCommand_TouchoffConfig &copy)
{
    this->utilizeTouchoff = copy.utilizeTouchoff;
    this->touchoffRef = copy.touchoffRef;
    this->touchoffGap = copy.touchoffGap;
}

void MotionCommand_TouchoffConfig::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray segmentDataArray;

    QJsonObject segmentObject;
    segmentObject["touchoffRef"] = this->getTouchoffRef();
    segmentObject["touchoffGap"] = this->getTouchoffGap();
    segmentObject["touchoffExecute"] = this->shouldTouchoffBeUtilized();
    segmentDataArray.append(segmentObject);

    saveObject["touchoffData"] = segmentDataArray;
}

void MotionCommand_TouchoffConfig::readFromJSON(const QJsonObject &openObject)
{
    QJsonArray touchoffDataArray = openObject["touchoffData"].toArray();
    QJsonObject touchoffObject = touchoffDataArray[0].toObject();

    setTouchoffRef(touchoffObject["touchoffRef"].toDouble());
    setTouchoffGap(touchoffObject["touchoffGap"].toDouble());
    setTouchoffUtilization(touchoffObject["touchoffExecute"].toBool());
}

void MotionCommand_TouchoffConfig::setTouchoffUtilization(const bool &usage)
{
    this->utilizeTouchoff = usage;
}
void MotionCommand_TouchoffConfig::setTouchoffRef(const double &distance)
{
    this->touchoffRef = distance;
}
void MotionCommand_TouchoffConfig::setTouchoffGap(const double &distance)
{
    this->touchoffGap = distance;
}

bool MotionCommand_TouchoffConfig::shouldTouchoffBeUtilized() const
{
    return this->utilizeTouchoff;
}
double MotionCommand_TouchoffConfig::getTouchoffRef() const
{
    return this->touchoffRef;
}
double MotionCommand_TouchoffConfig::getTouchoffGap() const
{
    return this->touchoffGap;
}

Command_Variable MotionCommand_TouchoffConfig::getTouchoffRefCommand() const
{
    Command_Variable newVariable("touchref",this->touchoffRef);
    return newVariable;
}
Command_Variable MotionCommand_TouchoffConfig::getTouchoffGapCommand() const
{
    Command_Variable newVariable("initgap",this->touchoffGap);
    return newVariable;
}
