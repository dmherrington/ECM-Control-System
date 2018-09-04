#ifndef SEGMENT_TIME_DATA_GENERAL_H
#define SEGMENT_TIME_DATA_GENERAL_H

#include <math.h>

#include <QString>
#include <QTextStream>

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>


namespace registers_Munk{

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
    SegmentTimeDataGeneral(const data_Munk::SegmentLevel &level, const data_Munk::SegmentMode &mode, const uint32_t &time);

public:
    //!
    //! \brief setSegmentLevel
    //! \param level
    //!
    void setSegmentLevel(const data_Munk::SegmentLevel &level);

    //!
    //! \brief setSegmentMode
    //! \param mode
    //!
    void setSegmentMode(const data_Munk::SegmentMode &mode);

    //!
    //! \brief setSegmentPower
    //! \param power
    //!
    void setSegmentPower(const data_Munk::SegmentPower &power);

    //!
    //! \brief setTimeValue
    //! \param time
    //!
    void setTimeValue(const uint32_t &time);

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
    std::string getLoggingString() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    SegmentTimeDataGeneral& operator = (const SegmentTimeDataGeneral &rhs)
    {
        this->segmentLevel = rhs.segmentLevel;
        this->segmentMode = rhs.segmentMode;
        this->segmentPower = rhs.segmentPower;
        this->timeValue = rhs.timeValue;
        return *this;
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


public:

    friend QTextStream& operator <<(QTextStream &outStream, const SegmentTimeDataGeneral &data)
    {
        return outStream<<QString::fromStdString(data.getLoggingString());
    }

    friend std::ostream& operator<< (std::ostream &stream, const SegmentTimeDataGeneral &data)
    {
        return stream<<data.getLoggingString();
    }

private:
    //!
    //! \brief segmentLevel
    //!
    data_Munk::SegmentLevel segmentLevel;

    //!
    //! \brief segmentMode
    //!
    data_Munk::SegmentMode segmentMode;

    //!
    //! \brief segmentPower
    //!
    data_Munk::SegmentPower segmentPower;

    //!
    //! \brief timeValue
    //!
    uint32_t timeValue; //this time is denoted in us

};

} //end of namepsace registers_Munk


#endif // SEGMENT_TIME_DATA_H
