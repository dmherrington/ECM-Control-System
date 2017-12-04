#ifndef SETTINGS_MANUAL_PROFILE_H
#define SETTINGS_MANUAL_PROFILE_H

#include <QJsonArray>
#include <QJsonObject>

class SettingsManualProfile
{
public:
    SettingsManualProfile();

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
public:
    unsigned int getJogSpeed() const;
    unsigned int getRelativeMove() const;
public:
    void setJogSpeed(const unsigned int &speed);
    void setRelativeMove(const unsigned int &distance);
private:
    unsigned int jogSpeed = 100;
    unsigned int relativeMove = 10000;

};

#endif // SETTINGS_MANUAL_PROFILE_H
