#ifndef SETTINGS_VIBRATION_PROFILE_H
#define SETTINGS_VIBRATION_PROFILE_H

#include <QJsonArray>
#include <QJsonObject>

class SettingsVibrationProfile
{
public:
    SettingsVibrationProfile();

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    int getRetractDistance() const;
    int getRetractPeriod() const;
    int getPause() const;
    int getStepSize() const;

public:
    void setRetractDistance(const int &distance);
    void setRetractPeriod(const int &period);
    void setPause(const int &time);
    void setStepSize(const int &distance);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SettingsVibrationProfile &rhs)
    {
        this->retractDistance = rhs.retractDistance;
        this->retractPeriod = rhs.retractPeriod;
        this->pause = rhs.pause;
        this->stepSize = rhs.stepSize;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SettingsVibrationProfile &rhs)
    {
        if(this->retractDistance != rhs.retractDistance){
            return false;
        }
        if(this->retractPeriod != rhs.retractPeriod){
            return false;
        }
        if(this->pause != rhs.pause){
            return false;
        }
        if(this->stepSize != rhs.stepSize){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SettingsVibrationProfile &rhs) {
        return !(*this == rhs);
    }

private:
    int retractDistance = 100;
    int retractPeriod = 100;
    int pause = 100;
    int stepSize = 100;
};

#endif // SETTINGS_VIBRATION_PROFILE_H
