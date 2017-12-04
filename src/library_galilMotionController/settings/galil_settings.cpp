#include "galil_settings.h"

GalilSettings::GalilSettings()
{

}

void GalilSettings::loadSettings(const QString &settingsFilePath)
{
    QFile settingsFile(settingsFilePath);

    if (!settingsFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
    }

    QByteArray loadData = settingsFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(loadData);
    QJsonObject jsonObj = loadDoc.object();
    linearProfile.read(jsonObj);
}

void GalilSettings::saveSettings(const QString &settingsFilePath)
{
    QFile saveFile(settingsFilePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    QJsonObject saveObject;
    linearProfile.write(saveObject);
    QJsonDocument saveDoc(saveObject);

    saveFile.write(saveDoc.toJson());
}
