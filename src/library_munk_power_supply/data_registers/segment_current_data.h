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

namespace DataParameter
{

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
    SegmentCurrentData(const Data::SegmentLevel &levelValue, const Data::SegmentMode &levelMode);

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
    void updateCurrentFactor(const Data::CurrentFactorType &value);

    //!
    //! \brief updatePrescalePower
    //! \param value
    //!
    void updatePrescalePower(const Data::SegmentVIPower &value);

    //!
    //! \brief updateCurrentSetpoint
    //! \param value
    //!
    Data::DataFaultCodes updateCurrentSetpoint(const int &value);

public:
    //!
    //! \brief getSegmentLevel
    //! \return
    //!
    Data::SegmentLevel getSegmentLevel() const;

    //!
    //! \brief getSegmentMode
    //! \return
    //!
    Data::SegmentMode getSegmentMode() const;

    //!
    //! \brief getCurrentFactor
    //! \return
    //!
    Data::CurrentFactorType getCurrentFactor() const;

    //!
    //! \brief getCurrentPrescale
    //! \return
    //!
    Data::SegmentVIPower getCurrentPrescale() const;

    //!
    //! \brief getCurrent
    //! \return
    //!
    int getCurrent() const;

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
    Data::SegmentLevel level;

    //!
    //! \brief mode
    //!
    Data::SegmentMode mode;

    //!
    //! \brief currentFactor
    //!
    Data::CurrentFactorType currentFactor;

    //!
    //! \brief prescale
    //!
    Data::SegmentVIPower prescale;

    //!
    //! \brief current
    //!
    int current;
};

} //end of namespace DataParameter

#endif // SEGMENT_CURRENT_SETPOINT_H
