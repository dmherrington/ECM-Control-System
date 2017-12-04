#include "settings_vibration_profile.h"

SettingsVibrationProfile::SettingsVibrationProfile()
{

}

void SettingsVibrationProfile::read(const QJsonObject &json)
{
    QJsonArray segmentDataArray = json["vibrationProfile"].toArray();
    QJsonObject arrayObject = segmentDataArray[0].toObject();
    this->setRetractDistance(arrayObject["retractDistance"].toInt());
    this->setRetractPeriod(arrayObject["retractPeriod"].toInt());
    this->setPause(arrayObject["pause"].toInt());
    this->setStepSize(arrayObject["stepSize"].toInt());
}
void SettingsVibrationProfile::write(QJsonObject &json) const
{
    QJsonArray segmentDataArray;
    QJsonObject segmentObject;
    segmentObject["retractDistance"] = retractDistance;
    segmentObject["retractFrequency"] = retractPeriod;
    segmentObject["pause"] = pause;
    segmentObject["stepSize"] = stepSize;
    segmentDataArray.append(segmentObject);

    json["vibrationProfile"] = segmentDataArray;
}
void SettingsVibrationProfile::setRetractDistance(const int &distance)
{
    this->retractDistance = distance;
}
void SettingsVibrationProfile::setRetractPeriod(const int &period)
{
    this->retractPeriod = period;
}
void SettingsVibrationProfile::setPause(const int &time)
{
    this->pause = time;
}
void SettingsVibrationProfile::setStepSize(const int &distance)
{
    this->stepSize = distance;
}
int SettingsVibrationProfile::getRetractDistance() const
{
    return retractDistance;
}
int SettingsVibrationProfile::getRetractPeriod() const
{
    return retractPeriod;
}
int SettingsVibrationProfile::getPause() const
{
    return pause;
}
int SettingsVibrationProfile::getStepSize() const
{
    return stepSize;
}

