#ifndef GALIL_SETTINGS_H
#define GALIL_SETTINGS_H

#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>

#include "settings/settings_linear_profile.h"
#include "settings/settings_manual_profile.h"
#include "settings/settings_vibration_profile.h"

class GalilSettings
{
public:
    GalilSettings();
    void loadSettings(const QString &settingsFilePath);
    void saveSettings(const QString &settingsFilePath);

    ~GalilSettings() = default;

public:
    SettingsLinearProfile linearProfile;
    SettingsManualProfile manualProfile;
    SettingsVibrationProfile vibrationProfile;

};

#endif // GALIL_SETTINGS_H
