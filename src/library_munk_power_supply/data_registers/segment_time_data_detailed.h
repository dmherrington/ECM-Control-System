#ifndef SEGMENT_TIME_DATA_DETAILED_H
#define SEGMENT_TIME_DATA_DETAILED_H

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>
#include <data/register_data_object.h>

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
    SegmentTimeDataDetailed(const int &voltage, const int &current, const Data::SegmentMode &mode, const Data::SegmentPower &power, const uint8_t &time);

public:
    //!
    //! \brief setSegmentVoltage
    //! \param voltage
    //!
    void setSegmentVoltage(const int &voltage);

    //!
    //! \brief setSegmentCurrent
    //! \param current
    //!
    void setSegmentCurrent(const int &current);

    //!
    //! \brief setSegmentMode
    //! \param mode
    //!
    void setSegmentMode(const Data::SegmentMode &mode);

    //!
    //! \brief setSegmentPower
    //! \param power
    //!
    void setSegmentPower(const Data::SegmentPower &power);

    //!
    //! \brief setTimeValue
    //! \param time
    //!
    void setTimeValue(const uint8_t &time);

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
    //! \brief getRegisterDataObject
    //! \return
    //!
    Data::RegisterDataObject getRegisterDataObject() const;

    //!
    //! \brief getSegmentMode
    //! \return
    //!
    Data::SegmentMode getSegmentMode() const;

    //!
    //! \brief getSegmentPower
    //! \return
    //!
    Data::SegmentPower getSegmentPower() const;

    //!
    //! \brief getTimeValue
    //! \return
    //!
    uint8_t getTimeValue() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SegmentTimeDataDetailed &rhs)
    {
        this->dataObject = rhs.dataObject;
        this->segmentMode = rhs.segmentMode;
        this->segmentPower = rhs.segmentPower;
        this->timeValue = rhs.timeValue;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SegmentTimeDataDetailed &rhs) const {

        if(this->dataObject != rhs.dataObject){
            return false;
        }
        if(this->segmentMode != rhs.segmentMode){
            return false;
        }
        if(this->segmentPower != rhs.segmentPower){
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
    //! \brief dataObject
    //!
    Data::RegisterDataObject dataObject;

    //!
    //! \brief segmentMode
    //!
    Data::SegmentMode segmentMode;

    //!
    //! \brief segmentPower
    //!
    Data::SegmentPower segmentPower;

    //!
    //! \brief timeValue
    //!
    uint8_t timeValue; //this time is denoted in us

};

} //end of namespace DataParameter


#endif // SEGMENT_TIME_DATA_DETAILED_H
