#ifndef ABSTRACT_PARAMETER_H
#define ABSTRACT_PARAMETER_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "type_definition.h"
#include "common/common.h"

#include <data/type_read_write.h>

namespace DataParameter{

class AbstractParameter
{
public:
    AbstractParameter();

public:
    virtual DataParameter::ParameterType getParamterType() const = 0;

    virtual QByteArray getByteArray() const = 0;

    virtual QByteArray getCompletedMessage() const = 0;

    virtual std::string getDescription() const  = 0;

public:
    void operator = (const AbstractParameter &rhs)
    {
        this->slaveAddress = rhs.slaveAddress;
        this->readOrwrite = rhs.readOrwrite;
    }

    bool operator == (const AbstractParameter &rhs)
    {
        if(this->slaveAddress != rhs.slaveAddress){
            return false;
        }
        if(this->readOrwrite != rhs.readOrwrite){
            return false;
        }
        return true;
    }

    bool operator != (const AbstractParameter &rhs) {
        return !(*this == rhs);
    }

protected:
    int slaveAddress;
    Data::ReadWriteType readOrwrite;
};

} //end of namespace DataParameter
#endif // ABSTRACT_PARAMETER_H
