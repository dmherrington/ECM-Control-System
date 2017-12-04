#include "settings_manual_profile.h"

SettingsManualProfile::SettingsManualProfile()
{

}

void SettingsManualProfile::read(const QJsonObject &json)
{
    QJsonArray segmentDataArray = json["manualProfile"].toArray();
    QJsonObject arrayObject = segmentDataArray[0].toObject();
    this->setJogSpeed(arrayObject["jogSpeed"].toInt());
    this->setRelativeMove(arrayObject["relativeMove"].toInt());
}
void SettingsManualProfile::write(QJsonObject &json) const
{
    QJsonArray segmentDataArray;
    QJsonObject segmentObject;
    segmentObject["jogSpeed"] = (int)jogSpeed;
    segmentObject["relativeMove"] = (int)relativeMove;
    segmentDataArray.append(segmentObject);

    json["manualProfile"] = segmentDataArray;
}
void SettingsManualProfile::setJogSpeed(const unsigned int &speed)
{
    this->jogSpeed = speed;
}
void SettingsManualProfile::setRelativeMove(const unsigned int &distance)
{
    this->relativeMove = distance;
}

unsigned int SettingsManualProfile::getJogSpeed() const
{
    return jogSpeed;
}
unsigned int SettingsManualProfile::getRelativeMove() const
{
    return relativeMove;
}
