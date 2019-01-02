#ifndef MOTION_COMMAND_TOUCHOFF_CONFIG_H
#define MOTION_COMMAND_TOUCHOFF_CONFIG_H

#include <QJsonObject>
#include <QJsonArray>

#include "commands/command_variable.h"

class MotionCommand_TouchoffConfig
{
public:
    MotionCommand_TouchoffConfig();

    MotionCommand_TouchoffConfig(const MotionCommand_TouchoffConfig &copy);

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:
    void setTouchoffUtilization(const bool &usage);
    void setTouchoffUtilizePreviousPosition(const bool &usage);
    void setTouchoffRef(const double &distance);
    void setTouchoffGap(const double &distance);

public:
    bool shouldTouchoffBeUtilized() const;
    bool shouldTouchoffUtilizePreviousPosition() const;
    double getTouchoffRef() const;
    double getTouchoffGap() const;

public:
    Command_Variable getTouchoffRefCommand() const;
    Command_Variable getTouchoffGapCommand() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    MotionCommand_TouchoffConfig& operator = (const MotionCommand_TouchoffConfig &rhs)
    {
        this->utilizeTouchoff = rhs.utilizeTouchoff;
        this->utilizeExistingPosition = rhs.utilizeExistingPosition;
        this->touchoffRef = rhs.touchoffRef;
        this->touchoffGap = rhs.touchoffGap;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const MotionCommand_TouchoffConfig &rhs)
    {
        if(this->utilizeTouchoff != rhs.utilizeTouchoff){
            return false;
        }
        if(this->utilizeExistingPosition != rhs.utilizeExistingPosition){
            return false;
        }
        if(this->touchoffRef != rhs.touchoffRef){
            return false;
        }
        if(this->touchoffGap != rhs.touchoffGap){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const MotionCommand_TouchoffConfig &rhs) {
        return !(*this == rhs);
    }

private:
    bool utilizeTouchoff = false;
    bool utilizeExistingPosition = false;
    double touchoffRef = 0.0;
    double touchoffGap = 0.0;
};

#endif // MOTION_COMMAND_TOUCHOFF_CONFIG_H
