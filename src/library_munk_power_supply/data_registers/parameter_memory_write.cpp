#include "parameter_memory_write.h"

namespace DataParameter{


ParameterMemoryWrite::ParameterMemoryWrite()
{

}

ParameterType ParameterMemoryWrite::getParameterType() const
{
    return ParameterType::MEMORYWRITE;
}

std::string ParameterMemoryWrite::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray ParameterMemoryWrite::getByteArray() const
{
    QByteArray byteArray;
    uint32_t ba = 0;
    byteArray.append(ba);
    return byteArray;
}

} //end of namespace ParameterMemoryWrite
