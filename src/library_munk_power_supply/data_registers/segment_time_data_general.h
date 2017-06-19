#ifndef SEGMENT_TIME_DATA_GENERAL_H
#define SEGMENT_TIME_DATA_GENERAL_H

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>

namespace DataParameter
{

//!
//! \brief The SegmentTimeDataGeneral class
//!
class SegmentTimeDataGeneral
{
public:
    //!
    //! \brief SegmentTimeDataGeneral
    //!
    SegmentTimeDataGeneral();

    //!
    //! \brief SegmentTimeDataGeneral
    //! \param level
    //! \param mode
    //! \param power
    //! \param time
    //!
    SegmentTimeDataGeneral(const Data::SegmentLevel &level, const Data::SegmentMode &mode, const Data::SegmentPower &power, const uint8_t &time);

public:
    //!
    //! \brief setSegmentLevel
    //! \param level
    //!
    void setSegmentLevel(const Data::SegmentLevel &level);

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
    void updateData(const SegmentTimeDataGeneral &data);

public:    
    //!
    //! \brief getConstructedBitArray
    //! \return
    //!
    uint32_t getConstructedBitArray() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SegmentTimeDataGeneral &rhs)
    {
        this->segmentLevel = rhs.segmentLevel;
        this->segmentMode = rhs.segmentMode;
        this->segmentPower = rhs.segmentPower;
        this->timeValue = rhs.timeValue;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SegmentTimeDataGeneral &rhs) const {

        if(this->segmentLevel != rhs.segmentLevel){
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
    bool operator != (const SegmentTimeDataGeneral &rhs) const {
        return !(*this == rhs);
    }

private:
    //!
    //! \brief segmentLevel
    //!
    Data::SegmentLevel segmentLevel;

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
#endif // SEGMENT_TIME_DATA_H
