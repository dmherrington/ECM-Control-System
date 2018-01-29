#ifndef SEGMENT_VOLTAGE_DATA_H
#define SEGMENT_VOLTAGE_DATA_H

#include <QByteArray>

#include <string>
#include <vector>
#include <iostream>

#include "data/type_segment_level.h"
#include "data/type_segment_mode.h"

#include "data/type_fault_codes_general.h"

#include "data/type_current_voltage_prescale.h"
#include "data/type_voltage_set.h"

namespace DataParameter
{
//!
//! \brief The SegmentVoltageData class
//!
class SegmentVoltageData
{

public:

    //!
    //! \brief SegmentVoltageData
    //! \param levelValue
    //! \param levelMode
    //!
    SegmentVoltageData(const Data::SegmentLevel &levelValue, const Data::SegmentMode &levelMode);

public:
    //!
    //! \brief getDataArray
    //! \return
    //!
    QByteArray getDataArray() const;

public:
    //!
    //! \brief updatePrescalePower
    //! \param value
    //!
    void updatePrescalePower(const Data::SegmentVIPower &value);

    //!
    //! \brief updateVoltageSetpoint
    //! \param value
    //!
    Data::DataFaultCodes updateVoltageSetpoint(const double &value);

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
    //! \brief getCurrentPrescale
    //! \return
    //!
    Data::SegmentVIPower getVoltagePrescale() const;

    //!
    //! \brief getVoltage
    //! \return
    //!
    int getVoltage() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    SegmentVoltageData& operator = (const SegmentVoltageData &rhs)
    {
        this->level = rhs.level;
        this->mode = rhs.mode;
        this->prescale = rhs.prescale;
        this->voltage = rhs.voltage;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SegmentVoltageData &rhs)
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
        if(this->voltage != rhs.voltage){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SegmentVoltageData &rhs) {
        return !(*this == rhs);
    }

private:
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
    //! \brief prescale
    //!
    Data::SegmentVIPower prescale;

    //!
    //! \brief voltage
    //!
    int voltage;
};

} //end of namespace DataParameter

#endif // SEGMENT_VOLTAGE_SETPOINT_H
