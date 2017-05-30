#include "abstract_parameter.h"

namespace DataParameter {

AbstractParameter::AbstractParameter():
    parameterCode(0),slaveAddress(0),readOrwrite(Data::ReadWriteType::WRITE),highChecksum(0),lowChecksum(0)
{

}

AbstractParameter::AbstractParameter(const int &code):
    parameterCode(code),slaveAddress(0),readOrwrite(Data::ReadWriteType::WRITE),highChecksum(0),lowChecksum(0)
{

}

} //end of namespace DataParameter
