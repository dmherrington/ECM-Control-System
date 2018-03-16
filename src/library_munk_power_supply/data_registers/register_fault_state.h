#ifndef REGISTER_STANDARD_FAULTS_H
#define REGISTER_STANDARD_FAULTS_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "type_definition.h"
#include "common/common.h"

#include "abstract_parameter.h"

#include <data/type_read_write.h>
#include "data/type_fault_status_registers.h"


namespace registers_Munk{

class RegisterFaultState : public AbstractParameter
{
public:
    RegisterFaultState(const data_Munk::FaultRegisterType &type);

    RegisterFaultState(const RegisterFaultState &copy);

public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual registers_Munk::ParameterType getParameterType() const;

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    AbstractParameter* getClone() const override
    {
        return (new RegisterFaultState(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new RegisterFaultState(*this);
    }

    //!
    //! \brief getByteArray
    //! \return
    //!
    virtual QByteArray getByteArray() const;

    //!
    //! \brief getExpectedResponse
    //! \return
    //!
    QByteArray getExpectedResponse() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    RegisterFaultState& operator = (const RegisterFaultState &rhs)
    {
        AbstractParameter::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const RegisterFaultState &rhs)
    {
        if(!AbstractParameter::operator ==(rhs)){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const RegisterFaultState &rhs) {
        return !(*this == rhs);
    }

};

} //end of namepsace registers_Munk


#endif // REGISTER_STANDARD_FAULTS_H
