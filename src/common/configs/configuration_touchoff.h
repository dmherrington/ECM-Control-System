#ifndef CONFIGURATION_TOUCHOFF_H
#define CONFIGURATION_TOUCHOFF_H

#include <map>

#include <QJsonObject>
#include <QJsonArray>

#include "../commands/command_variable_array.h"

class Configuration_Touchoff
{
public:
    Configuration_Touchoff();

    Configuration_Touchoff(const Configuration_Touchoff &copy);

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:
    void setTouchoffUtilization(const bool &usage);
    void setTouchoffUtilizePreviousPosition(const bool &usage);
    void setTouchoffRef(const std::map<MotorAxis,double> &distance);
    void setTouchoffGap(const std::map<MotorAxis,double> &distance);

public:
    bool shouldTouchoffBeUtilized() const;
    bool shouldTouchoffUtilizePreviousPosition() const;
    std::map<MotorAxis,double> getTouchoffRef() const;
    std::map<MotorAxis,double> getTouchoffGap() const;

public:
    Command_VariableArray getTouchoffRefCommand() const;
    Command_VariableArray getTouchoffGapCommand() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Configuration_Touchoff& operator = (const Configuration_Touchoff &rhs)
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
    bool operator == (const Configuration_Touchoff &rhs)
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
    bool operator != (const Configuration_Touchoff &rhs) {
        return !(*this == rhs);
    }

private:
    bool utilizeTouchoff = false;
    bool utilizeExistingPosition = false;
    std::map<MotorAxis,double> touchoffRef;
    std::map<MotorAxis,double> touchoffGap;
};


#endif // CONFIGURATION_TOUCHOFF_H
