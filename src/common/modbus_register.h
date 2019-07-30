#ifndef MODBUS_REGISTER_H
#define MODBUS_REGISTER_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "common.h"

enum class ModbusRegister_RWType{
    READ = 03, /**< */
    WRITE = 06 /**< */
};

//!
//! \brief The AbstractParameter class
//!
class ModbusRegister
{
public:
    //!
    //! \brief AbstractParameter
    //!
    ModbusRegister();

    //!
    //! \brief AbstractParameter
    //! \param copy
    //!
    ModbusRegister(const ModbusRegister &copy);

    virtual ~ModbusRegister() = default;

public:

    //!
    //! \brief setRegisterAddress
    //! \param registerAddress
    //!
    void setRegisterAddress(const unsigned int &registerAddress);

    //!
    //! \brief getRegisterCode
    //! \return
    //!
    unsigned int getRegisterCode() const
    {
        return this->registerAddress;
    }

    //!
    //! \brief getByteArray
    //! \return
    //!
    virtual QByteArray getByteArray() const;

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
    void setReadorWrite(const ModbusRegister_RWType &type);

    //!
    //! \brief setData
    //! \param dataArray
    //!
    void setData(const QByteArray &dataArray);

    //!
    //! \brief getFullMessage
    //! \return
    //!
    QByteArray getFullMessage() const;

private:
    //!
    //! \brief getPrefixByteArray
    //! \return
    //!
    QByteArray getPrefixByteArray() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ModbusRegister& operator = (const ModbusRegister &rhs)
    {
        this->registerAddress = rhs.registerAddress;
        this->slaveAddress = rhs.slaveAddress;
        this->readOrwrite = rhs.readOrwrite;
        this->data = rhs.data;
        this->highChecksum = rhs.highChecksum;
        this->lowChecksum = rhs.lowChecksum;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ModbusRegister &rhs)
    {
        if(this->registerAddress != rhs.registerAddress){
            return false;
        }
        if(this->slaveAddress != rhs.slaveAddress){
            return false;
        }
        if(this->readOrwrite != rhs.readOrwrite){
            return false;
        }
        if(this->data != rhs.data){
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
    bool operator != (const ModbusRegister &rhs) {
        return !(*this == rhs);
    }

private:
    //!
    //! \brief CRC16
    //! \param array
    //! \return
    //!
    unsigned int CRC16(const QByteArray &array) const;

protected:
    //!
    //! \brief parameterCode
    //!
    unsigned int registerAddress; //this value is indirectly set

    //!
    //! \brief slaveAddress
    //!
    int slaveAddress;

    //!
    //! \brief readOrwrite
    //!
    ModbusRegister_RWType readOrwrite;

    //!
    //! \brief data
    //!
    QByteArray data;

    //!
    //! \brief highChecksum
    //!
    mutable uint8_t highChecksum;

    //!
    //! \brief lowChecksum
    //!
    mutable uint8_t lowChecksum;
};

#endif // MODBUS_REGISTER_H
