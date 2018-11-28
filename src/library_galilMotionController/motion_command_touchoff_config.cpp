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
