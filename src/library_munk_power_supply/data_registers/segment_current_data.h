#ifndef SEGMENT_CURRENT_DATA_H
#define SEGMENT_CURRENT_DATA_H

#include <QByteArray>

#include <string>
#include <vector>
#include <iostream>

#include "data/type_segment_level.h"
#include "data/type_segment_mode.h"
#include "data/type_current_factor.h"

#include "data/type_current_voltage_prescale.h"
#include "data/type_voltage_set.h"

#include "data/type_fault_codes_general.h"


namespace registers_Munk{

//!
//! \brief The SegmentCurrentSetpoint class
//!
class SegmentCurrentData
{
public:
    //!
    //! \brief SegmentCurrentSetpoint
    //! \param levelValue
    //! \param levelMode
    //!
    SegmentCurrentData(const data_Munk::SegmentLevel &levelValue, const data_Munk::SegmentMode &levelMode);

public:
    //!
    //! \brief getDataArray
    //! \return
    //!
    QByteArray getDataArray() const;

public:
    //!
    //! \brief updateCurrentFactor
    //! \param value
    //!
    void updateCurrentFactor(const data_Munk::CurrentFactorType &value);

    //!
    //! \brief updatePrescalePower
    //! \param value
    //!
    void updatePrescalePower(const data_Munk::SegmentVIPower &value);

    //!
    //! \brief updateCurrentSetpoint
    //! \param value
    //!
    data_Munk::DataFaultCodes updateCurrentSetpoint(const int &value);

public:
    //!
    //! \brief getSegmentLevel
    //! \return
    //!
    data_Munk::SegmentLevel getSegmentLevel() const;

    //!
    //! \brief getSegmentMode
    //! \return
    //!
    data_Munk::SegmentMode getSegmentMode() const;

    //!
    //! \brief getCurrentFactor
    //! \return
    //!
    data_Munk::CurrentFactorType getCurrentFactor() const;

    //!
    //! \brief getCurrentPrescale
    //! \return
    //!
    data_Munk::SegmentVIPower getCurrentPrescale() const;

    //!
    //! \brief getCurrent
    //! \return
    //!
    int getCurrent() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    SegmentCurrentData& operator = (const SegmentCurrentData &rhs)
    {
        this->level = rhs.level;
        this->mode = rhs.mode;
        this->prescale = rhs.prescale;
        this->current = rhs.current;
        this->currentFactor = rhs.currentFactor;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SegmentCurrentData &rhs)
    {
        if(this->level != rhs.level){
            return false;
        }
        if(this->mode != rhs.mode){
            return false;
        }
        if(this->prescale != rhs.prescale){
            return false;
        }
        if(this->current != rhs.current){
            return false;
        }
        if(this->currentFactor != rhs.currentFactor){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SegmentCurrentData &rhs) {
        return !(*this == rhs);
    }

private:
    //!
    //! \brief updateAmpsBitArray
    //! \param bitArray
    //! \return
    //!
    uint32_t updateAmpsBitArray(const uint32_t &bitArray) const;

    //!
    //! \brief updatePrescaleBitArray
    //! \param bitArray
    //! \return
    //!
    uint32_t updatePrescaleBitArray(const uint32_t &bitArray) const;

    //!
    //! \brief updateSetPointBitArray
    //! \param bitArray
    //! \return
    //!
    uint32_t updateSetPointBitArray(const uint32_t &bitArray) const;

private:
    //!
    //! \brief level
    //!
    data_Munk::SegmentLevel level;

    //!
    //! \brief mode
    //!
    data_Munk::SegmentMode mode;

    //!
    //! \brief currentFactor
    //!
    data_Munk::CurrentFactorType currentFactor;

    //!
    //! \brief prescale
    //!
    data_Munk::SegmentVIPower prescale;

    //!
    //! \brief current
    //!
    int current;
};

} //end of namepsace registers_Munk


#endif // SEGMENT_CURRENT_SETPOINT_H
