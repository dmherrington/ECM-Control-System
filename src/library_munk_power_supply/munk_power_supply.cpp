#include "munk_power_supply.h"

MunkPowerSupply::MunkPowerSupply()
{
    DataParameter::SegmentTimeGeneral* segmentTime = new DataParameter::SegmentTimeGeneral(1,2);
    segmentTime->setSlaveAddress(1);

    DataParameter::SegmentTimeDataGeneral segmentOneData;
    segmentOneData.setSegmentLevel(Data::SegmentLevel::LEVEL1);
    segmentOneData.setSegmentMode(Data::SegmentMode::FORWARD);
    segmentOneData.setSegmentPower(Data::SegmentPower::TEN);
    segmentOneData.setTimeValue(20);

    DataParameter::SegmentTimeDataGeneral segmentTwoData;
    segmentTwoData.setSegmentLevel(Data::SegmentLevel::LEVEL1); //this should reflect and change to level 2 because you are dead
    segmentTwoData.setSegmentMode(Data::SegmentMode::DEAD);
    segmentTwoData.setSegmentPower(Data::SegmentPower::TEN);
    segmentTwoData.setTimeValue(50);

    segmentTime->updateRegisterData(0,segmentOneData);
    segmentTime->updateRegisterData(1,segmentTwoData);
    QByteArray ba = segmentTime->getFullMessage();

    qDebug() << ba.toHex().toUpper();
    std::cout<<"I am done maybe"<< std::endl;
}

