#include "munk_power_supply.h"

MunkPowerSupply::MunkPowerSupply()
{
    DataParameter::SegmentTimeDetailed detailedData(1);

    DataParameter::SegmentTimeDataDetailed detailedOne(10,10,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedOne);
    DataParameter::SegmentTimeDataDetailed detailedTwo(10,10,Data::SegmentMode::REVERSE,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedTwo);
    DataParameter::SegmentTimeDataDetailed detailedThree(10,10,Data::SegmentMode::REVERSE,Data::SegmentPower::ONE_HUNDRED,100);
    detailedData.appendRegisterData(detailedThree);
    DataParameter::SegmentTimeDataDetailed detailedFour(10,10,Data::SegmentMode::FORWARD,Data::SegmentPower::ONE_HUNDRED,100);
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


void MunkPowerSupply::generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData)
{
    //SegmentTime Parameter holding data
    DataParameter::SegmentTimeGeneral generalSegment;

    //maps holding containers to determine what is unique
    std::map<Data::RegisterDataObject,Data::SegmentLevel> fwdMap;
    std::map<Data::RegisterDataObject,Data::SegmentLevel> revMap;

    std::vector<DataParameter::SegmentTimeDataDetailed> detailedData = detailedSegmentData.getRegisterData();

    //this restricts it to only assume 1 output supply for now
    DataParameter::SegmentCurrentSetpoint fwdISetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::FORWARD);
    DataParameter::SegmentCurrentSetpoint revISetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::REVERSE);

    DataParameter::SegmentVoltageSetpoint fwdVSetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::FORWARD);
    DataParameter::SegmentVoltageSetpoint revVSetpoint(Data::TypeSupplyOutput::OUTPUT1,Data::SegmentMode::REVERSE);


    std::vector<std::string> fwdLevelVector = Data::getListOfSegmentLevel();
    int fwdLevelCounter = 0;
    std::vector<std::string> revLevelVector = Data::getListOfSegmentLevel();
    int revLevelCounter = 0;

    //allow us to loop through all of the possible data segments
    for(int i = 0; i < detailedData.size(); i++)
    {
        DataParameter::SegmentTimeDataDetailed detail = detailedData.at(i);
        //determine the mode of the segment
        Data::SegmentMode mode = detail.getSegmentMode();

        if(mode == Data::SegmentMode::FORWARD)
        {
            if(fwdMap.count(detail.getRegisterDataObject()) > 0)
            {
                //the element had already existed in the forward queue and therefore we do nothing
                std::cout<<"The voltage " <<detail.getRegisterDataObject().voltage <<" and current "<<detail.getRegisterDataObject().current<<" had already existed."<<std::endl;
            }
            else{
                if(fwdLevelCounter >= 8)
                    return;
                //assign a new level to this combination
                Data::SegmentLevel newLevel = Data::SegmentLevelFromString(fwdLevelVector.at(fwdLevelCounter));
                fwdMap.insert(std::pair<Data::RegisterDataObject,Data::SegmentLevel>(detail.getRegisterDataObject(),newLevel));

                DataParameter::SegmentVoltageData vData(newLevel,mode);
                vData.updateVoltageSetpoint(detail.getRegisterDataObject().voltage);
                fwdVSetpoint.appendData(vData);
                DataParameter::SegmentCurrentData iData(newLevel,mode);
                iData.updateCurrentSetpoint(detail.getRegisterDataObject().current);
                fwdISetpoint.appendData(iData);
                fwdLevelCounter++;
            }
            Data::SegmentLevel level = fwdMap.at(detail.getRegisterDataObject());
            DataParameter::SegmentTimeDataGeneral generalData(level,mode,detail.getSegmentPower(),detail.getTimeValue());
            generalSegment.appendRegisterData(generalData);
        }
        else if(mode == Data::SegmentMode::REVERSE)
        {
            if(revMap.count(detail.getRegisterDataObject()) > 0)
            {
                //the element had already existed in the forward queue and therefore we do nothing
                std::cout<<"The voltage " <<detail.getRegisterDataObject().voltage <<" and current "<<detail.getRegisterDataObject().current<<" had already existed."<<std::endl;
            }
            else
            {
                if(revLevelCounter >= 8)
                    return;

                //assign a new level to this combination
                Data::SegmentLevel newLevel = Data::SegmentLevelFromString(revLevelVector.at(revLevelCounter));
                revMap.insert(std::pair<Data::RegisterDataObject,Data::SegmentLevel>(detail.getRegisterDataObject(),newLevel));

                DataParameter::SegmentVoltageData vData(newLevel,mode);
                vData.updateVoltageSetpoint(detail.getRegisterDataObject().voltage);
                revVSetpoint.appendData(vData);
                DataParameter::SegmentCurrentData iData(newLevel,mode);
                iData.updateCurrentSetpoint(detail.getRegisterDataObject().current);
                revISetpoint.appendData(iData);
                revLevelCounter++;
            }
            Data::SegmentLevel level = revMap.at(detail.getRegisterDataObject());
            DataParameter::SegmentTimeDataGeneral generalData(level,mode,detail.getSegmentPower(),detail.getTimeValue());
            generalSegment.appendRegisterData(generalData);
        }
        else{
            //Ken: Figure out what to do this in case
        }
    }

    std::cout<<"It is complete"<<std::endl;

    //if the size of either map is greater than eight than the request is invalid for the parameters requested
    //otherwise, let us continue processing them
}

