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

void MunkPowerSupply::generateCurrentSetpointMessage(const std::map<Data::RegisterDataObject, Data::SegmentLevel> &map, const Data::SegmentMode &mode, std::vector<DataParameter::SegmentCurrentSetpoint> &IMsgs)
{

}

void MunkPowerSupply::generateVoltageSetpointMessage(const std::map<Data::RegisterDataObject, Data::SegmentLevel> &map, const Data::SegmentMode &mode, std::map<Data::SegmentLevel, DataParameter::SegmentVoltageSetpoint> &Levels)
{
    for  (std::map<Data::RegisterDataObject, Data::SegmentLevel>::const_iterator it=map.begin(); it!=map.end(); ++it)
    {
        DataParameter::SegmentVoltageSetpoint voltageSetpoint(it->second,mode);
        voltageSetpoint.updateVoltageSetpoint(it->first.voltage);
        VMsgs.push_back(voltageSetpoint);
    }
}

void MunkPowerSupply::generateCurrentSetpointMessage(const std::map<Data::RegisterDataObject, Data::SegmentLevel> &map, const Data::SegmentMode &mode, std::vector<DataParameter::SegmentVoltageSetpoint> &VMsgs, std::vector<DataParameter::SegmentCurrentSetpoint> &IMsgs)
{
    std::vector<DataParameter::SegmentVoltageSetpoint> rtnVector;

    for (std::map<Data::RegisterDataObject, Data::SegmentLevel>::const_iterator it=map.begin(); it!=map.end(); ++it)
    {
        DataParameter::SegmentVoltageSetpoint voltageSetpoint(it->second,mode);
        voltageSetpoint.updateVoltageSetpoint(it->first.voltage);
        VMsgs.push_back(voltageSetpoint);

        DataParameter::SegmentCurrentSetpoint currentSetpoint(it->second,mode);
        currentSetpoint.updateCurrentSetpoint(it->first.current);
        IMsgs.push_back(currentSetpoint);
    }
}

void MunkPowerSupply::generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
{
    std::vector<DataParameter::SegmentTimeDataDetailed> detailedData = detailedSegmentData.getRegisterData();

    //allow us to loop through all of the possible data segments
    for(int i = 0; i < detailedSegmentData.getRegisterData().size(), i++)
    {

    }
    structSetpoints fwdMap;
    structSetpoints revMap;

    DataParameter::SegmentCurrentSetpoint fwdIData(detailedSegmentData.get)
    DataParameter::SegmentCurrentSetpoint revIData;

    DataParameter::SegmentVoltageSetpoint fwdVData;
    DataParameter::SegmentVoltageSetpoint revVData;


    std::vector<std::string> fwdLevelVector = Data::getListOfSegmentLevel();
    int fwdLevelCounter = 0;
    std::vector<std::string> revLevelVector = Data::getListOfSegmentLevel();
    int revLevelCounter = 0;


    for(int i = 0; i < detailedData.size(); i++)
    {
        DataParameter::SegmentTimeDataDetailed parameter = detailedData.at(i);
        Data::SegmentMode mode = parameter.getSegmentMode();

        if(mode == Data::SegmentMode::FORWARD)
        {
            Data::SegmentLevel newLevel = Data::SegmentLevelFromString(fwdLevelVector.at(fwdLevelCounter));
            std::pair<std::map<Data::RegisterDataObject,Data::SegmentLevel>::iterator,bool> ret;
            DataParameter::SegmentVoltageSetpoint voltageSet(newLevel,mode);
            voltageSet.
            voltageSet.updateVoltageSetpoint();
            ret = fwdMap.insert(std::pair<Data::SegmentLevel,structSetpoints>(parameter.getRegisterDataObject(),newLevel));

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
    std::vector<DataParameter::SegmentVoltageSetpoint> voltageSetpointFWD;
    std::vector<DataParameter::SegmentCurrentSetpoint> currentSetpointFWD;

    std::vector<DataParameter::SegmentVoltageSetpoint> voltageSetpointREV;
    std::vector<DataParameter::SegmentCurrentSetpoint> currentSetpointREV;


    generateSetpointMessages(fwdMap, Data::SegmentMode::FORWARD, voltageSetpointFWD, currentSetpointFWD);
    generateSetpointMessages(revMap, Data::SegmentMode::REVERSE, voltageSetpointREV, currentSetpointREV);

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

