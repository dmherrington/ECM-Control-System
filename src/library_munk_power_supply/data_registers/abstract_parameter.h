#ifndef ABSTRACT_PARAMETER_H
#define ABSTRACT_PARAMETER_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "type_definition.h"
#include "common/common.h"

#include <data/type_read_write.h>

namespace DataParameter{

typedef unsigned int WORD;

//!
//! \brief The AbstractParameter class
//!
class AbstractParameter
{
public:
    //!
    //! \brief AbstractParameter
    //!
    AbstractParameter();

    //!
    //! \brief AbstractParameter
    //! \param code
    //!
    AbstractParameter(const int &code);

public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual DataParameter::ParameterType getParameterType() const = 0;

    //!
    //! \brief getByteArray
    //! \return
    //!
    virtual QByteArray getByteArray() const = 0;

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const  = 0;

public:
    //!
    //! \brief setSlaveAddress
    //! \param address
    //!
    void setSlaveAddress(const uint8_t &address);

    //!
    //! \brief setReadorWrite
    //! \param type
    //!
    void setReadorWrite(const Data::ReadWriteType &type);

    //!
    //! \brief getFullMessage
    //! \return
    //!
    QByteArray getFullMessage();

private:
    //!
    //! \brief getPrefixByteArray
    //! \return
    //!
    QByteArray getPrefixByteArray();

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const AbstractParameter &rhs)
    {
        this->parameterCode = rhs.parameterCode;
        this->slaveAddress = rhs.slaveAddress;
        this->readOrwrite = rhs.readOrwrite;
        this->highChecksum = rhs.highChecksum;
        this->lowChecksum = rhs.lowChecksum;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
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

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AbstractParameter &rhs) {
        return !(*this == rhs);
    }

private:
    //!
    //! \brief CRC16
    //! \param array
    //! \return
    //!
    unsigned int CRC16(const QByteArray &array);

protected:
    //!
    //! \brief parameterCode
    //!
    int parameterCode; //this value is indirectly set

    //!
    //! \brief slaveAddress
    //!
    int slaveAddress;

    //!
    //! \brief readOrwrite
    //!
    Data::ReadWriteType readOrwrite;

    //!
    //! \brief highChecksum
    //!
    uint8_t highChecksum;

    //!
    //! \brief lowChecksum
    //!
    uint8_t lowChecksum;
};

} //end of namespace DataParameter
#endif // ABSTRACT_PARAMETER_H
