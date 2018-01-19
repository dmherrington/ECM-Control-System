#ifndef GALIL_SETTINGS_H
#define GALIL_SETTINGS_H

#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>

class GalilSettings
{
public:
    GalilSettings();
    void loadSettings(const QString &settingsFilePath);
    void saveSettings(const QString &settingsFilePath);

    ~GalilSettings() = default;

public:

};

#endif // GALIL_SETTINGS_H
