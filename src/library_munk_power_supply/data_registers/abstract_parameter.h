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
    AbstractParameter(const int &code);

public:
    virtual DataParameter::ParameterType getParameterType() const = 0;

    virtual int getParameterCode() const
    {
        return this->parameterCode;
    }

    virtual QByteArray getByteArray() const = 0;

    virtual std::string getDescription() const  = 0;


public:
    QByteArray getFullMessage();

public:
    void operator = (const AbstractParameter &rhs)
    {
        this->parameterCode = rhs.parameterCode;
        this->slaveAddress = rhs.slaveAddress;
        this->readOrwrite = rhs.readOrwrite;
        this->highChecksum = rhs.highChecksum;
        this->lowChecksum = rhs.lowChecksum;
    }

    bool operator == (const AbstractParameter &rhs)
    {
        if(this->parameterCode != rhs.parameterCode){
            return false;
        }
        if(this->slaveAddress != rhs.slaveAddress){
            return false;
        }
        if(this->readOrwrite != rhs.readOrwrite){
            return false;
        }
        if(this->highChecksum != rhs.highChecksum){
            return false;
        }
        if(this->lowChecksum != rhs.lowChecksum){
            return false;
        }
        return true;
    }

    bool operator != (const AbstractParameter &rhs) {
        return !(*this == rhs);
    }

private:
    unsigned int CRC16(const QByteArray &array);

protected:
    int parameterCode; //this value is indirectly set
    int slaveAddress;
    Data::ReadWriteType readOrwrite;
    uint8_t highChecksum;
    uint8_t lowChecksum;
};

} //end of namespace DataParameter
#endif // ABSTRACT_PARAMETER_H
