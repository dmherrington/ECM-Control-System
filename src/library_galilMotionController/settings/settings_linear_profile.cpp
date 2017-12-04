#include "settings_linear_profile.h"

SettingsLinearProfile::SettingsLinearProfile()
{

}

void SettingsLinearProfile::read(const QJsonObject &json)
{
    QJsonArray segmentDataArray = json["linearProfile"].toArray();
    QJsonObject arrayObject = segmentDataArray[0].toObject();
    this->setDepthofCut(arrayObject["depthOfCut"].toInt());
    this->setCutSpeed(arrayObject["cutSpeed"].toInt());
}
void SettingsLinearProfile::write(QJsonObject &json) const
{
    QJsonArray segmentDataArray;
    QJsonObject segmentObject;
    segmentObject["depthOfCut"] = depthOfCut;
    segmentObject["cutSpeed"] = cutSpeed;
    segmentDataArray.append(segmentObject);

    json["linearProfile"] = segmentDataArray;
}
void SettingsLinearProfile::setDepthofCut(const int &distance)
{
    this->depthOfCut = distance;
}
void SettingsLinearProfile::setCutSpeed(const int &speed)
{
    this->cutSpeed = speed;
}
int SettingsLinearProfile::getDepthofCut() const
{
    return depthOfCut;
}
int SettingsLinearProfile::getCutSpeed() const
{
    return cutSpeed;
}
