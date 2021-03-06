#ifndef MUNK_ABSTRACT_REGISTERS_H
#define MUNK_ABSTRACT_REGISTERS_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "type_definition.h"
#include "common/common.h"
#include "common/class_forward.h"

#include "data/type_read_write.h"


namespace registers_Munk{

ECM_CLASS_FORWARD(AbstractParameter);

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

    //!
    //! \brief AbstractParameter
    //! \param copy
    //!
    AbstractParameter(const AbstractParameter &copy);

    virtual ~AbstractParameter() = default;
public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual registers_Munk::ParameterType getParameterType() const
    {
        return this->parameterType;
    }

    virtual int getParameterCode() const
    {
        return this->parameterCode;
    }

    //!
    //! \brief getByteArray
    //! \return
    //!
    virtual QByteArray getByteArray() const = 0;

    //!
    //! \brief getExpectedResponse
    //! \return
    //!
    virtual QByteArray getExpectedResponse() const = 0;

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const  = 0;

    /**
     * @brief getClone
     * @return
     */
    virtual AbstractParameter* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractParameter** state) const = 0;

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
    void setReadorWrite(const data_Munk::MunkRWType &type);

    //!
    //! \brief getFullMessage
    //! \return
    //!
    QByteArray getFullMessage() const;

    //!
    //! \brief getFullExpectedResonse
    //! \return
    //!
    QByteArray getFullExpectedResonse() const;


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
    AbstractParameter& operator = (const AbstractParameter &rhs)
    {
        this->parameterType = rhs.parameterType;
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
    bool operator == (const AbstractParameter &rhs)
    {
        if(this->parameterType != rhs.parameterType){
            return false;
        }
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
    unsigned int CRC16(const QByteArray &array) const;

protected:

    //!
    //! \brief parameterType
    //!
    registers_Munk::ParameterType parameterType;

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
    data_Munk::MunkRWType readOrwrite;

    //!
    //! \brief highChecksum
    //!
    mutable uint8_t highChecksum;

    //!
    //! \brief lowChecksum
    //!
    mutable uint8_t lowChecksum;
};

} //end of namespace registers_Munk


#endif // MUNK_ABSTRACT_REGISTERS_H
