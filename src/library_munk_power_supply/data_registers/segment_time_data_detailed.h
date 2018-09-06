#ifndef SEGMENT_TIME_DATA_DETAILED_H
#define SEGMENT_TIME_DATA_DETAILED_H

#include <QFile>
#include <QJsonObject>
#include <QTextStream>

#include <math.h>

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>
#include <data/register_data_object.h>
#include <data/type_supply_output.h>


namespace registers_Munk{

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
    SegmentTimeDataDetailed(const double &voltage, const double &current, const data_Munk::SegmentMode &mode, const uint32_t &time);


    SegmentTimeDataDetailed(const SegmentTimeDataDetailed &copy);

public:

    //!
    //! \brief setSupplyOutput
    //! \param outputNumber
    //!
    void setSupplyOutput(const data_Munk::TypeSupplyOutput &outputNumber);

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
    void setSegmentMode(const data_Munk::SegmentMode &mode);

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
    data_Munk::TypeSupplyOutput getSupplyOutputNumber() const;

    //!
    //! \brief getRegisterDataObject
    //! \return
    //!
    data_Munk::RegisterDataObject getRegisterDataObject() const;


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
    //! \brief getGraphingVoltage
    //! \return
    //!
    double getGraphingVoltage() const;

    //!
    //! \brief getGraphingCurrent
    //! \return
    //!
    double getGraphingCurrent() const;

    //!
    //! \brief getSegmentMode
    //! \return
    //!
    data_Munk::SegmentMode getSegmentMode() const;

    //!
    //! \brief getTimeValue
    //! \return
    //!
    uint32_t getTimeValue() const;

public:
    void read(const QJsonObject &json)
    {
        setSupplyOutput(data_Munk::TypeSupplyOutputString(json["supplyOutput"].toString().toStdString()));
        setSegmentMode(data_Munk::SegmentModeFromString(json["segmentMode"].toString().toStdString()));
        setSegmentVoltage(json["voltage"].toDouble());
        setSegmentCurrent(json["current"].toDouble());
        setTimeValue(json["time"].toDouble());
    }

    void write(QJsonObject &json) const
    {
        json["supplyOutput"] = QString::fromStdString(data_Munk::TypeSupplyOutputToString(supplyOutput));
        json["segmentMode"] = QString::fromStdString(data_Munk::SegmentModeToString(segmentMode));
        json["voltage"] = dataObject.voltage;
        json["current"] = dataObject.current;
        json["time"] = (int)timeValue;
    }

    std::string getLoggingString() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    SegmentTimeDataDetailed& operator = (const SegmentTimeDataDetailed &rhs)
    {
        this->supplyOutput = rhs.supplyOutput;
        this->dataObject = rhs.dataObject;
        this->segmentMode = rhs.segmentMode;
        this->timeValue = rhs.timeValue;
        return *this;
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

public:
    friend QTextStream& operator <<(QTextStream &outStream, const SegmentTimeDataDetailed &data)
    {
        return outStream<<QString::fromStdString(data.getLoggingString());
    }

    friend std::ostream& operator<< (std::ostream &stream, const SegmentTimeDataDetailed &data)
    {
        return stream<<data.getLoggingString();
    }

    //Private member variables of the class
private:
    //!
    //! \brief supplyOutput
    //!
    data_Munk::TypeSupplyOutput supplyOutput;

    //!
    //! \brief dataObject
    //!
    data_Munk::RegisterDataObject dataObject;

    //!
    //! \brief segmentMode
    //!
    data_Munk::SegmentMode segmentMode;

    //!
    //! \brief timeValue
    //!
    uint32_t timeValue; //this time is denoted in us

};


} //end of namepsace registers_Munk



#endif // SEGMENT_TIME_DATA_DETAILED_H
