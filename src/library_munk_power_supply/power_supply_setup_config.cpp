#include "power_supply_setup_config.h"

PowerSupply_SetupConfig::PowerSupply_SetupConfig()
{

}
void PowerSupply_SetupConfig::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray munkDataArray;

    QJsonObject segmentObject;

    segmentObject["pulseMode"] = (int)this->m_MunkPulseMode.getTriggerCount();

    std::vector<registers_Munk::SegmentTimeDataDetailed> registerData = m_MunkSegment.getRegisterData();

    QJsonArray segmentDataArray;
    for(size_t i = 0; i < registerData.size(); i++)
    {
        QJsonObject segmentData;
        registerData.at(i).write(segmentData);
        segmentDataArray.append(segmentData);
    }

    segmentObject["segmentData"] = segmentDataArray;

    munkDataArray.append(segmentObject);

    saveObject["MunkSettings"] = munkDataArray;
}

void PowerSupply_SetupConfig::readFromJSON(const QJsonObject &openObject)
{
    QJsonArray powerSupplyDataArray = openObject["MunkSettings"].toArray();
    QJsonObject powerSupplyDataObject = powerSupplyDataArray[0].toObject();

    int numPulses = powerSupplyDataObject["pulseMode"].toInt();
    m_MunkPulseMode.setTriggerCount(numPulses);

    QJsonArray segmentDataArray = powerSupplyDataObject["segmentData"].toArray();
    for(size_t i = 0; i < segmentDataArray.size(); i++)
    {
        registers_Munk::SegmentTimeDataDetailed newRegister;
        newRegister.read(segmentDataArray.at(i).toObject());
        m_MunkSegment.appendRegisterData(newRegister);
    }
}
