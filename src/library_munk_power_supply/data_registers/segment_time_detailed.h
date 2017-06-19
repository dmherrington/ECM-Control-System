#ifndef SEGMENT_TIME_DETAILED_H
#define SEGMENT_TIME_DETAILED_H

#include <string>
#include <vector>

#include "abstract_parameter.h"
#include "segment_time_data_detailed.h"
#include "segment_time_general.h"

namespace DataParameter
{
//!
//! \brief The SegmentTimeDetailed class
//!
class SegmentTimeDetailed : public AbstractParameter
{
public:
    //!
    //! \brief SegmentTimeDetailed
    //!
    SegmentTimeDetailed();

    //!
    //! \brief SegmentTimeDetailed
    //! \param numSegments
    //!
    SegmentTimeDetailed(const int &numSegments);

    //!
    //! \brief SegmentTimeDetailed
    //! \param obj
    //!
    SegmentTimeDetailed(const SegmentTimeDetailed &obj);

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
    void appendRegisterData(const SegmentTimeDataDetailed &data);

    //!
    //! \brief updateRegisterData
    //! \param registerIndex
    //! \param data
    //!
    void updateRegisterData(const int &registerIndex, const SegmentTimeDataDetailed &data);

    //!
    //! \brief getRegisterData
    //! \return
    //!
    std::vector<DataParameter::SegmentTimeDataDetailed> getRegisterData() const;

    //!
    //! \brief initializeData
    //!
    void initializeData();

public:

    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SegmentTimeDetailed &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->numSeqSegments = rhs.numSeqSegments;
        this->detailedRegisterData = rhs.detailedRegisterData;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SegmentTimeDetailed &rhs) {
        if(!AbstractParameter::operator ==(rhs))
        {
            return false;
        }
        if(this->numSeqSegments != rhs.numSeqSegments){
            return false;
        }
        if(this->detailedRegisterData != rhs.detailedRegisterData){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SegmentTimeDetailed &rhs) {
        return !(*this == rhs);
    }

private:
    //!
    //! \brief numSeqSegments
    //!
    uint8_t numSeqSegments;

    //!
    //! \brief detailedRegisterData
    //!
    std::vector<DataParameter::SegmentTimeDataDetailed> detailedRegisterData;
};

} //end of namespace MunkPowerSupply

#endif // SEGMENT_TIME_DETAILED_H
