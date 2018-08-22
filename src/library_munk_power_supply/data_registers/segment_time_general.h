#ifndef SEGMENT_TIMES_H
#define SEGMENT_TIMES_H

#include <string>
#include <vector>

#include "abstract_parameter.h"
#include "segment_time_data_general.h"

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>


namespace registers_Munk{

//!
//! \brief The SegmentTimeGeneral class
//!
class SegmentTimeGeneral : public AbstractParameter
{
public:

    //!
    //! \brief SegmentTimeGeneral
    //!
    SegmentTimeGeneral();

    //!
    //! \brief SegmentTimeGeneral
    //! \param obj
    //!
    SegmentTimeGeneral(const SegmentTimeGeneral &obj);

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
        return (new SegmentTimeGeneral(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new SegmentTimeGeneral(*this);
    }

public:
    //!
    //! \brief appendRegisterData
    //! \param data
    //!
    void appendRegisterData(const SegmentTimeDataGeneral &data);

    //!
    //! \brief updateRegisterData
    //! \param registerIndex
    //! \param data
    //!
    void updateRegisterData(const int &registerIndex, const SegmentTimeDataGeneral &data);

    //!
    //! \brief initializeData
    //!
    void initializeData();

public:

    std::string getLoggingString() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    SegmentTimeGeneral& operator = (const SegmentTimeGeneral &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->registerData = rhs.registerData;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SegmentTimeGeneral &rhs) {
        if(!AbstractParameter::operator ==(rhs))
        {
            return false;
        }
        if(this->registerData != rhs.registerData){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SegmentTimeGeneral &rhs) {
        return !(*this == rhs);
    }

public:

    friend QTextStream& operator <<(QTextStream &outStream, const SegmentTimeGeneral &data)
    {
        return outStream<<QString::fromStdString(data.getLoggingString());
    }

    friend std::ostream& operator<< (std::ostream &stream, const SegmentTimeGeneral &data)
    {
        return stream<<data.getLoggingString();
    }

private:
    //!
    //! \brief registerData
    //!
    std::vector<registers_Munk::SegmentTimeDataGeneral> registerData;
};

} //end of namepsace registers_Munk


#endif // SEGMENT_TIMES_H
