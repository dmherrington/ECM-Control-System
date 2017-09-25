#ifndef SEGMENT_TIME_DATA_DETAILED_H
#define SEGMENT_TIME_DATA_DETAILED_H

#include <QJsonObject>

#include <math.h>

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>
#include <data/register_data_object.h>
#include <data/type_supply_output.h>

namespace DataParameter
{

//!
//! \brief The SegmentTimeDataDetailed class is the class that the user should implement when establishing
//! a segments data. The data contained in here shall be mapped later on to the correct levels and
//! establish the necessary current/voltage messages for interacting with the munk power supply.
//!
class SegmentTimeDataDetailed
{
public:
    //!
    //! \brief SegmentTimeDataDetailed
    //!
    SegmentTimeDataDetailed();

    //!
    //! \brief SegmentTimeDataDetailed
    //! \param voltage
    //! \param current
    //! \param mode
    //! \param power
    //! \param time
    //!
    SegmentTimeDataDetailed(const int &voltage, const int &current, const Data::SegmentMode &mode, const uint32_t &time);


    SegmentTimeDataDetailed(const SegmentTimeDataDetailed &copy);

public:

    //!
    //! \brief setSupplyOutput
    //! \param outputNumber
    //!
    void setSupplyOutput(const Data::TypeSupplyOutput &outputNumber);

    //!
    //! \brief setSegmentVoltage
    //! \param voltage
    //!
    void setSegmentVoltage(const double &voltage);

    //!
    //! \brief setSegmentCurrent
    //! \param current
    //!
    void setSegmentCurrent(const double &current);

    //!
    //! \brief setSegmentMode
    //! \param mode
    //!
    void setSegmentMode(const Data::SegmentMode &mode);

    //!
    //! \brief setTimeValue
    //! \param time
    //!
    void setTimeValue(const uint32_t &time); //even though this is in uS we can only process to precision of 100uS

    //!
    //! \brief resetData
    //!
    void resetData();

    //!
    //! \brief updateData
    //! \param data
    //!
    void updateData(const SegmentTimeDataDetailed &data);

public:
    //!
    //! \brief getSupplyOutputNumber
    //! \return
    //!
    Data::TypeSupplyOutput getSupplyOutputNumber() const;

    //!
    //! \brief getRegisterDataObject
    //! \return
    //!
    Data::RegisterDataObject getRegisterDataObject() const;


    //!
    //! \brief getSegmentVoltage
    //! \return
    //!
    double getSegmentVoltage() const;

    //!
    //! \brief getSegmentCurrent
    //! \return
    //!
    double getSegmentCurrent() const;

    //!
    //! \brief getSegmentMode
    //! \return
    //!
    Data::SegmentMode getSegmentMode() const;

    //!
    //! \brief getTimeValue
    //! \return
    //!
    uint32_t getTimeValue() const;

public:
    void read(const QJsonObject &json)
    {
        setSupplyOutput(Data::TypeSupplyOutputString(json["supplyOutput"].toString().toStdString()));
        setSegmentMode(Data::SegmentModeFromString(json["segmentMode"].toString().toStdString()));
        setSegmentVoltage(json["voltage"].toDouble());
        setSegmentCurrent(json["current"].toDouble());
        setTimeValue(json["time"].toDouble());
    }

    void write(QJsonObject &json) const
    {
        json["supplyOutput"] = QString::fromStdString(Data::TypeSupplyOutputToString(supplyOutput));
        json["segmentMode"] = QString::fromStdString(Data::SegmentModeToString(segmentMode));
        json["voltage"] = dataObject.voltage;
        json["current"] = dataObject.current;
        json["time"] = (int)timeValue;
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SegmentTimeDataDetailed &rhs)
    {
        this->supplyOutput = rhs.supplyOutput;
        this->dataObject = rhs.dataObject;
        this->segmentMode = rhs.segmentMode;
        this->timeValue = rhs.timeValue;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SegmentTimeDataDetailed &rhs) const {

        if(this->supplyOutput != rhs.supplyOutput){
            return false;
        }
        if(this->dataObject != rhs.dataObject){
            return false;
        }
        if(this->segmentMode != rhs.segmentMode){
            return false;
        }
        if(this->timeValue != rhs.timeValue){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SegmentTimeDataDetailed &rhs) const {
        return !(*this == rhs);
    }

    //Private member variables of the class
private:
    //!
    //! \brief supplyOutput
    //!
    Data::TypeSupplyOutput supplyOutput;

    //!
    //! \brief dataObject
    //!
    Data::RegisterDataObject dataObject;

    //!
    //! \brief segmentMode
    //!
    Data::SegmentMode segmentMode;

    //!
    //! \brief timeValue
    //!
    uint32_t timeValue; //this time is denoted in us

};


} //end of namespace DataParameter


#endif // SEGMENT_TIME_DATA_DETAILED_H
