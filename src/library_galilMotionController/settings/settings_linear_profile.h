#ifndef SETTINGS_LINEAR_PROFILE_H
#define SETTINGS_LINEAR_PROFILE_H

#include <QJsonArray>
#include <QJsonObject>

class SettingsLinearProfile
{
public:
    SettingsLinearProfile();

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    int getDepthofCut() const;
    int getCutSpeed() const;

public:
    void setDepthofCut(const int &distance);
    void setCutSpeed(const int &speed);

private:
    int depthOfCut = 100;
    int cutSpeed = 100;
};

#endif // SETTINGS_LINEAR_PROFILE_H
