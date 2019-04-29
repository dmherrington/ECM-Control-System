#ifndef REGISTER_SUPPLY_IDENTIFIER_H
#define REGISTER_SUPPLY_IDENTIFIER_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "type_definition.h"
#include "common/common.h"

#include "abstract_parameter.h"

#include "data/type_read_write.h"
#include "data/type_fault_status_registers.h"


namespace registers_Munk{

class Register_SupplyIdentifier : public AbstractParameter
{
public:
    Register_SupplyIdentifier();

    Register_SupplyIdentifier(const Register_SupplyIdentifier &copy);

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
        return (new Register_SupplyIdentifier(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new Register_SupplyIdentifier(*this);
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
    Register_SupplyIdentifier& operator = (const Register_SupplyIdentifier &rhs)
    {
        AbstractParameter::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_SupplyIdentifier &rhs)
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
    bool operator != (const Register_SupplyIdentifier &rhs) {
        return !(*this == rhs);
    }

};

} //end of namepsace registers_Munk

#endif // REGISTER_SUPPLY_IDENTIFIER_H
