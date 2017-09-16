#include "segment_time_detailed.h"

namespace DataParameter{

SegmentTimeDetailed::SegmentTimeDetailed()
{
    initializeData();
}

SegmentTimeDetailed::SegmentTimeDetailed(const int &address)
{
    initializeData();
    this->setSlaveAddress(address);
}

SegmentTimeDetailed::SegmentTimeDetailed(const SegmentTimeDetailed &obj)
{
    this->operator =(obj);
}

void SegmentTimeDetailed::setSlaveAddress(const int &address)
{
    this->slaveAddress = address;
}

int SegmentTimeDetailed::getSlaveAddress() const
{
    return this->slaveAddress;
}

void SegmentTimeDetailed::appendRegisterData(const SegmentTimeDataDetailed &data)
{
    this->detailedRegisterData.push_back(data);
}

void SegmentTimeDetailed::updateRegisterData(const int &registerIndex, const SegmentTimeDataDetailed &data)
{
    this->detailedRegisterData.at(registerIndex).updateData(data);
}

std::vector<DataParameter::SegmentTimeDataDetailed> SegmentTimeDetailed::getRegisterData() const
{
    return this->detailedRegisterData;
}

void SegmentTimeDetailed::initializeData()
{
    this->detailedRegisterData.clear();
}

} //end of namespace DataRegister
