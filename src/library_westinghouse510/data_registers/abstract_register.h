#ifndef ABSTRACT_PARAMETER_H
#define ABSTRACT_PARAMETER_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "available_registers.h"
#include "common/common.h"

#include "data/type_read_write.h"

namespace westinghousePump{
namespace registers{

typedef unsigned int WORD;

//!
//! \brief The AbstractParameter class
//!
class AbstractRegister
{
public:
    //!
    //! \brief AbstractParameter
    //!
    AbstractRegister();

    //!
    //! \brief AbstractParameter
    //! \param code
    //!
    AbstractRegister(const int &code);

    //!
    //! \brief AbstractParameter
    //! \param copy
    //!
    AbstractRegister(const AbstractRegister &copy);

    virtual ~AbstractRegister() = default;
public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual RegisterType getRegisterType() const = 0;

    virtual int getRegisterCode() const
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
    virtual AbstractRegister* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractRegister** state) const = 0;

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
    void setReadorWrite(const data::ReadWriteType &type);

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
    AbstractRegister& operator = (const AbstractRegister &rhs)
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
    bool operator == (const AbstractRegister &rhs)
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
    bool operator != (const AbstractRegister &rhs) {
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
    int parameterCode; //this value is indirectly set

    //!
    //! \brief slaveAddress
    //!
    int slaveAddress;

    //!
    //! \brief readOrwrite
    //!
    data::ReadWriteType readOrwrite;

    //!
    //! \brief highChecksum
    //!
    mutable uint8_t highChecksum;

    //!
    //! \brief lowChecksum
    //!
    mutable uint8_t lowChecksum;
};

} //end of namespace registers
} //end of namespace westinghousePump

#endif // ABSTRACT_PARAMETER_H
