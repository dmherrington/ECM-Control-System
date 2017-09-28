#ifndef SEGMENT_VOLTAGE_SETPOINT_H
#define SEGMENT_VOLTAGE_SETPOINT_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "abstract_parameter.h"

#include "data/type_supply_output.h"
#include "data/type_segment_level.h"

#include "data_registers/segment_voltage_data.h"

namespace DataParameter
{
//!
//! \brief The SegmentVoltageSetpoint class
//!
class SegmentVoltageSetpoint : public AbstractParameter
{

public:
    //!
    //! \brief SegmentVoltageSetpoint
    //! \param levelValue
    //! \param levelMode
    //!
    SegmentVoltageSetpoint(const Data::TypeSupplyOutput &outputNum, const Data::SegmentMode &levelMode);

    //!
    //! \brief SegmentVoltageSetpoint
    //! \param obj
    //!
    SegmentVoltageSetpoint(const SegmentVoltageSetpoint &obj);

public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual DataParameter::ParameterType getParameterType() const;

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    //!
    //! \brief getByteArray
    //! \return
    //!
    virtual QByteArray getByteArray() const;

    //!
    //! \brief getExpectedResponse
    //! \return
    //!
    QByteArray getExpectedResponse() const override;
public:

    //!
    //! \brief appendData
    //! \param voltageSetpoint
    //!
    void appendData(const SegmentVoltageData &voltageSetpoint);

    void initializeData();

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SegmentVoltageSetpoint &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->supplyOutput = rhs.supplyOutput;
        this->mode = rhs.mode;
        this->data = rhs.data;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SegmentVoltageSetpoint &rhs)
    {
        if(!AbstractParameter::operator ==(rhs)){
            return false;
        }
        if(this->supplyOutput != rhs.supplyOutput){
            return false;
        }
        if(this->mode != rhs.mode){
            return false;
        }
//        if(this->data != rhs.data){
//            return false;
//        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SegmentVoltageSetpoint &rhs) {
        return !(*this == rhs);
    }

private:
    //!
    //! \brief supplyOutput
    //!
    Data::TypeSupplyOutput supplyOutput;

    //!
    //! \brief mode
    //!
    Data::SegmentMode mode;

    //!
    //! \brief data
    //!
    std::map<Data::SegmentLevel, SegmentVoltageData> data;
};

} //end of namespace DataParameter

#endif // SEGMENT_VOLTAGE_SETPOINT_H
