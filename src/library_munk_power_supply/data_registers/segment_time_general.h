#ifndef SEGMENT_TIMES_H
#define SEGMENT_TIMES_H

#include <string>
#include <vector>

#include "abstract_parameter.h"
#include "segment_time_data_general.h"

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>

namespace DataParameter
{
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
    //! \param numSegments
    //!
    SegmentTimeGeneral(const int &numSegments);

    //!
    //! \brief SegmentTimeGeneral
    //! \param obj
    //!
    SegmentTimeGeneral(const SegmentTimeGeneral &obj);

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
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

public:
    //!
    //! \brief setStartingRegister
    //! \param startSegment
    //!
    void setStartingRegister(const uint8_t &startSegment);

    //!
    //! \brief setNumberofSequentialRegisters
    //! \param seqSegment
    //!
    void setNumberofSequentialRegisters(const uint8_t &seqSegment);

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
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SegmentTimeGeneral &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->numSeqSegments = rhs.numSeqSegments;
        this->registerData = rhs.registerData;
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
        if(this->numSeqSegments != rhs.numSeqSegments){
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

private:
    //!
    //! \brief numSeqSegments
    //!
    uint8_t numSeqSegments;

    //!
    //! \brief registerData
    //!
    std::vector<DataParameter::SegmentTimeDataGeneral> registerData;
};

} //end of namespace MunkPowerSupply
#endif // SEGMENT_TIMES_H
