#include "motion_command_touchoff_config.h"

MotionCommand_TouchoffConfig::MotionCommand_TouchoffConfig()
{

}


void MotionCommand_TouchoffConfig::setTouchoffRef(const double &distance)
{
    this->touchoffRef = distance;
}
void MotionCommand_TouchoffConfig::setTouchoffGap(const double &distance)
{
    this->touchoffGap = distance;
}

double MotionCommand_TouchoffConfig::getTouchoffRef(const double &distance) const
{
    return this->touchoffRef;
}
double MotionCommand_TouchoffConfig::getTouchoffGap(const double &distance) const
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
