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

MunkPowerSupply::generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
{
    std::map<Data::RegisterDataObject,Data::SegmentLevel> fwdMap;
    std::map<Data::RegisterDataObject,Data::SegmentLevel> revMap;

    std::vector<std::string> fwdLevelVector = Data::getListOfSegmentLevel();
    int fwdLevelCounter = 0;
    std::vector<std::string> revLevelVector = Data::getListOfSegmentLevel();
    int revLevelCounter = 0;

    std::vector<DataParameter::SegmentTimeDataDetailed> detailedData = detailedSegmentData.getRegisterData();

    for(int i = 0; i < detailedData.size(); i++)
    {
        DataParameter::SegmentTimeDataDetailed parameter = detailedData.at(i).segmentMode.getSegmentMode();
        Data::SegmentMode mode = parameter.getSegmentMode();

        if(mode == Data::SegmentMode::FORWARD)
        {
            Data::SegmentLevel newLevel = Data::SegmentLevelFromString(fwdLevelVector.at(fwdLevelCounter));
            std::pair<std::map<Data::RegisterDataObject,Data::SegmentLevel>::iterator,bool> ret;
            ret = fwdMap.insert(parameter.getRegisterDataObject(),newLevel);

            if (ret.second==false) {
              std::cout << "The element had already existed in the forward queue."<<std::endl;
            }
            else{
                //assign a new level to this combination
                fwdLevelCounter++;
            }
        }else if(mode == Data::SegmentMode::REVERSE)
        {
            Data::SegmentLevel newLevel = Data::SegmentLevelFromString(revLevelVector.at(revLevelCounter));
            std::pair<std::map<Data::RegisterDataObject,Data::SegmentLevel>::iterator,bool> ret;
            ret = revMap.insert(parameter.getRegisterDataObject(),newLevel);

            if (ret.second==false) {
              std::cout << "The element had already existed in the reverse queue."<<std::endl;
            }else
            {

            }
        }else{
            //Ken: Figure out what to do this in case
        }


        //now that we have figured out what levels we need and their appropriate voltage and currents
        //and generate the general data parameter messages
    }

    //if the size of either map is greater than eight than the request is invalid for the parameters requested
    //otherwise, let us continue processing them

    for(int j = 0; j < detailedData.size(); j++)
    {
        DataParameter::SegmentTimeDataDetailed parameter = detailedData.at(i).segmentMode.getSegmentMode();

        DataParameter::SegmentTimeGeneral generalSegment;
        DataParameter::SegmentTimeDataGeneral generalData;
        generalData.setSegmentMode(parameter.getSegmentMode());

        if(parameter.getSegmentMode() == Data::SegmentMode::FORWARD)
        {
            Data::RegisterDataObject tmpObj(parameter.getRegisterDataObject());
            generalData.setSegmentLevel(fwdMap.at(tmpObj));
        }
        else if(parameter.getSegmentMode() == Data::SegmentMode::REVERSE)
        {
            Data::RegisterDataObject tmpObj(parameter.getRegisterDataObject());
            generalData.setSegmentLevel(revMap.at(tmpObj));
        }
        generalData.setSegmentPower(parameter.getSegmentPower());
        generalData.setTimeValue(parameter.getTimeValue());

        //now we append the data to the segment object
        generalSegment.appendRegisterData(generalSegment);
    }
}

