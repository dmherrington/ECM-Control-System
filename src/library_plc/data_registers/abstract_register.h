#ifndef ABSTRACT_PLC_REGISTER_H
#define ABSTRACT_PLC_REGISTER_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "../library_PLC_global.h"

#include "common/common.h"
#include "../data/type_read_write.h"
#include "available_registers.h"

#include "common/modbus_register.h"

namespace registers_PLC{

//typedef unsigned int WORD;

//!
//! \brief The AbstractParameter class
//!
class AbstractPLCRegister
{
public:
    //!
    //! \brief AbstractParameter
    //!
    AbstractPLCRegister();

    //!
    //! \brief AbstractParameter
    //! \param code
    //!
    AbstractPLCRegister(const unsigned int &code);

    //!
    //! \brief AbstractParameter
    //! \param copy
    //!
    AbstractPLCRegister(const AbstractPLCRegister &copy);

    virtual ~AbstractPLCRegister() = default;
public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual PLCRegisterTypes getRegisterType() const = 0;

    virtual unsigned int getRegisterCode() const
    {
        return this->parameterCode;
    }

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

    /**
     * @brief getClone
     * @return
     */
    virtual AbstractPLCRegister* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractPLCRegister** state) const = 0;

    /**
     *
     */
    template <class T>
    const T *as() const
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T *as()
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<T *>(this);
    }
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
    void setReadorWrite(const data_PLC::RWType &type);

    //!
    //! \brief getFullMessage
    //! \return
    //!
    QByteArray getFullMessage() const;

    //!
    //! \brief parseFromArray
    //! \param msg
    //!
    virtual void parseFromArray(const QByteArray &msg) = 0;

    //!
    //! \brief getModbusRegister
    //! \return
    //!
    ModbusRegister getModbusRegister() const;

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
    AbstractPLCRegister& operator = (const AbstractPLCRegister &rhs)
    {
        this->parameterCode = rhs.parameterCode;
        this->slaveAddress = rhs.slaveAddress;
        this->readOrwrite = rhs.readOrwrite;
        this->highChecksum = rhs.highChecksum;
        this->lowChecksum = rhs.lowChecksum;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AbstractPLCRegister &rhs)
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
    bool operator != (const AbstractPLCRegister &rhs) {
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
    unsigned int parameterCode; //this value is indirectly set

    //!
    //! \brief slaveAddress
    //!
    uint8_t slaveAddress;

    //!
    //! \brief readOrwrite
    //!
    data_PLC::RWType readOrwrite;

    //!
    //! \brief highChecksum
    //!
    mutable uint8_t highChecksum;

    //!
    //! \brief lowChecksum
    //!
    mutable uint8_t lowChecksum;
};

} //end of namespace registers_PLCPump


#endif // ABSTRACT_PLC_REGISTER_H
