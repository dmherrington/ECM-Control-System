#ifndef SEGMENT_CURRENT_SETPOINT_H
#define SEGMENT_CURRENT_SETPOINT_H

#include <QString>
#include <QTextStream>

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "abstract_parameter.h"

#include "data/type_supply_output.h"
#include "data/type_segment_level.h"
#include "data/type_current_set.h"

#include "data_registers/segment_current_data.h"


namespace registers_Munk{

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
    SegmentCurrentSetpoint(const data_Munk::TypeSupplyOutput &outputNum, const data_Munk::SegmentMode &levelMode);

    //!
    //! \brief SegmentCurrentSetpoint
    //! \param copyObj
    //!
    SegmentCurrentSetpoint(const SegmentCurrentSetpoint &copy);
public:

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

private:
    std::string getLoggingData() const;

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

public:

    friend QTextStream& operator <<(QTextStream &outStream, const SegmentCurrentSetpoint &data)
    {
        return outStream<<QString::fromStdString(data.getLoggingData());
    }

    friend std::ostream& operator<< (std::ostream &stream, const SegmentCurrentSetpoint &data)
    {
        return stream<<data.getLoggingData();
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
    std::map<data_Munk::SegmentLevel, SegmentCurrentData> data;
};

} //end of namepsace registers_Munk


#endif // SEGMENT_CURRENT_SETPOINT_H
