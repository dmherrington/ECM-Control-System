#include "munk_power_supply.h"

MunkPowerSupply::MunkPowerSupply()
{
    DataParameter::SegmentTimeGeneral* segmentTime = new DataParameter::SegmentTimeGeneral(2);
    segmentTime->setSlaveAddress(1);

    DataParameter::SegmentTimeDetailed detailedData;

    DataParameter::SegmentTimeDataDetailed detailedOne(10,10,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedOne);
    DataParameter::SegmentTimeDataDetailed detailedTwo(20,10,Data::SegmentMode::REVERSE,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedTwo);
    DataParameter::SegmentTimeDataDetailed detailedThree(30,10,Data::SegmentMode::REVERSE,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedThree);
    DataParameter::SegmentTimeDataDetailed detailedFour(40,10,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedFour);
    DataParameter::SegmentTimeDataDetailed detailedFive(50,10,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedFive);
    DataParameter::SegmentTimeDataDetailed detailedSix(60,10,Data::SegmentMode::REVERSE,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedSix);
    DataParameter::SegmentTimeDataDetailed detailedSeven(70,10,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedSeven);
    DataParameter::SegmentTimeDataDetailed detailedEight(80,10,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedEight);

    generateMessages(detailedData);

}

std::vector<DataParameter::SegmentVoltageSetpoint> MunkPowerSupply::generateVSetpointMessages(const std::map<Data::RegisterDataObject, Data::SegmentLevel> &map, const Data::SegmentMode &mode)
{
    for (std::map<Data::RegisterDataObject, Data::SegmentLevel>::const_iterator it=map.begin(); it!=map.end(); ++it)
    {
        DataParameter::SegmentVoltageSetpoint voltageSetpoint(it->second,mode);
        voltageSetpoint.updateVoltageSetpoint(it->first.voltage);
    }
}

std::vector<DataParameter::SegmentCurrentSetpoint> MunkPowerSupply::generateISetpointMessages(const std::map<Data::RegisterDataObject, Data::SegmentLevel> &map, const Data::SegmentMode &mode)
{
    for (std::map<Data::RegisterDataObject, Data::SegmentLevel>::const_iterator it=map.begin(); it!=map.end(); ++it)
    {
        DataParameter::SegmentCurrentSetpoint currentSetpoint(it->second,mode);
        currentSetpoint.updateCurrentSetpoint(it->first.current);
    }
}

void MunkPowerSupply::generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
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
        DataParameter::SegmentTimeDataDetailed parameter = detailedData.at(i);
        Data::SegmentMode mode = parameter.getSegmentMode();

        if(mode == Data::SegmentMode::FORWARD)
        {
            Data::SegmentLevel newLevel = Data::SegmentLevelFromString(fwdLevelVector.at(fwdLevelCounter));
            std::pair<std::map<Data::RegisterDataObject,Data::SegmentLevel>::iterator,bool> ret;
            ret = fwdMap.insert(std::pair<Data::RegisterDataObject,Data::SegmentLevel>(parameter.getRegisterDataObject(),newLevel));

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
            ret = revMap.insert(std::pair<Data::RegisterDataObject,Data::SegmentLevel>(parameter.getRegisterDataObject(),newLevel));

            if (ret.second==false) {
              std::cout << "The element had already existed in the reverse queue."<<std::endl;
            }else
            {
                revLevelCounter++;
            }
        }else{
            //Ken: Figure out what to do this in case
        }
    }

    //next we have to generate the appropriate setpoint messages
    std::vector<DataParameter::SegmentVoltageSetpoint> voltageMSGSFWD = generateVSetpointMessages(fwdMap, Data::SegmentMode::FORWARD);
    std::vector<DataParameter::SegmentVoltageSetpoint> voltageMSGSREV = generateVSetpointMessages(revMap, Data::SegmentMode::REVERSE);

    std::vector<DataParameter::SegmentCurrentSetpoint> currentMSGSFWD = generateISetpointMessages(fwdMap, Data::SegmentMode::FORWARD);
    std::vector<DataParameter::SegmentCurrentSetpoint> currentMSGSREV = generateISetpointMessages(revMap, Data::SegmentMode::REVERSE);

    //if the size of either map is greater than eight than the request is invalid for the parameters requested
    //otherwise, let us continue processing them

    for(int j = 0; j < detailedData.size(); j++)
    {
        DataParameter::SegmentTimeDataDetailed parameter = detailedData.at(j);

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
        generalSegment.appendRegisterData(generalData);
    }
}

