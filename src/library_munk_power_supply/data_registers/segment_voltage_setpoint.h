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


namespace registers_Munk{

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
    SegmentVoltageSetpoint(const data_Munk::TypeSupplyOutput &outputNum, const data_Munk::SegmentMode &levelMode);

    //!
    //! \brief SegmentVoltageSetpoint
    //! \param obj
    //!
    SegmentVoltageSetpoint(const SegmentVoltageSetpoint &copy);

public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual registers_Munk::ParameterType getParameterType() const;

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    AbstractParameter* getClone() const override
    {
        return (new SegmentVoltageSetpoint(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new SegmentVoltageSetpoint(*this);
    }

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
    SegmentVoltageSetpoint& operator = (const SegmentVoltageSetpoint &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->supplyOutput = rhs.supplyOutput;
        this->mode = rhs.mode;
        this->data = rhs.data;
        return *this;
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
    data_Munk::TypeSupplyOutput supplyOutput;

    //!
    //! \brief mode
    //!
    data_Munk::SegmentMode mode;

    //!
    //! \brief data
    //!
    std::map<data_Munk::SegmentLevel, SegmentVoltageData> data;
};

} //end of namepsace registers_Munk


#endif // SEGMENT_VOLTAGE_SETPOINT_H
