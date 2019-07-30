#include "abstract_request.h"

namespace PLC {

AbstractRequest::AbstractRequest()
{

}

AbstractRequest::AbstractRequest(const AbstractRequest &copy)
{
    this->descriptor = copy.descriptor;
    this->latestUpdate = copy.latestUpdate;
}

void AbstractRequest::setTupleDescription(const common::TupleECMData &tuple)
{
    this->descriptor = tuple;
}

common::TupleECMData AbstractRequest::getTupleDescription() const
{
    return this->descriptor;
}


} //end of namespace PLC
