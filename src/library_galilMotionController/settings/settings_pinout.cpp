#include "settings_pinout.h"

SettingsPinout::SettingsPinout()
{

}

void SettingsPinout::read(const QJsonObject &json)
{
    QJsonArray segmentDataArray = json["manualProfile"].toArray();
    QJsonObject arrayObject = segmentDataArray[0].toObject();
    this->setJogSpeed(arrayObject["jogSpeed"].toInt());
    this->setRelativeMove(arrayObject["relativeMove"].toInt());
}
void SettingsPinout::write(QJsonObject &json) const
{
    QJsonArray segmentDataArray;
    QJsonObject segmentObject;
    segmentObject["jogSpeed"] = (int)jogSpeed;
    segmentObject["relativeMove"] = (int)relativeMove;
    segmentDataArray.append(segmentObject);

    json["manualProfile"] = segmentDataArray;
}
