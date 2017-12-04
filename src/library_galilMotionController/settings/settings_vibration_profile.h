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

private:
    int retractDistance = 100;
    int retractPeriod = 100;
    int pause = 100;
    int stepSize = 100;
};

#endif // SETTINGS_VIBRATION_PROFILE_H
