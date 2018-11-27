#ifndef MOTION_COMMAND_TOUCHOFF_CONFIG_H
#define MOTION_COMMAND_TOUCHOFF_CONFIG_H

#include "commands/command_variable.h"

class MotionCommand_TouchoffConfig
{
public:
    MotionCommand_TouchoffConfig();

public:
    void setTouchoffRef(const double &distance);
    void setTouchoffGap(const double &distance);

public:
    double getTouchoffRef(const double &distance) const;
    double getTouchoffGap(const double &distance) const;

public:
    Command_Variable getTouchoffRefCommand() const;
    Command_Variable getTouchoffGapCommand() const;

private:
    double touchoffRef = 0.0;
    double touchoffGap = 0.0;
};

#endif // MOTION_COMMAND_TOUCHOFF_CONFIG_H
