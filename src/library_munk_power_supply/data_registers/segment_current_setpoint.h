#ifndef SEGMENT_CURRENT_SETPOINT_H
#define SEGMENT_CURRENT_SETPOINT_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "abstract_parameter.h"

#include "data/type_supply_output.h"
#include "data/type_segment_level.h"
#include "data/type_current_set.h"

#include "data_registers/segment_current_data.h"

namespace DataParameter
{

//!
//! \brief The SegmentCurrentSetpoint class
//!
class SegmentCurrentSetpoint : public AbstractParameter
{
public:
    //!
    //! \brief SegmentCurrentSetpoint
    //! \param levelValue
    //! \param levelMode
    //!
    SegmentCurrentSetpoint(const Data::TypeSupplyOutput &outputNum, const Data::SegmentMode &levelMode);

    //!
    //! \brief SegmentCurrentSetpoint
    //! \param copyObj
    //!
    SegmentCurrentSetpoint(const SegmentCurrentSetpoint &copy);
public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual DataParameter::ParameterType getParameterType() const;

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

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;


    AbstractParameter* getClone() const override
    {
        return (new SegmentCurrentSetpoint(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new SegmentCurrentSetpoint(*this);
    }

public:
    void appendData(const SegmentCurrentData &currentSetpoint);

    void initializeData();

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    SegmentCurrentSetpoint& operator = (const SegmentCurrentSetpoint &rhs)
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
    bool operator == (const SegmentCurrentSetpoint &rhs)
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
    bool operator != (const SegmentCurrentSetpoint &rhs) {
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
    std::map<Data::SegmentLevel, SegmentCurrentData> data;
};

} //end of namespace DataParameter

#endif // SEGMENT_CURRENT_SETPOINT_H
