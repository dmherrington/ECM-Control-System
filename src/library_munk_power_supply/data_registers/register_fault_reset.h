#ifndef REGISTER_FAULT_RESET_H
#define REGISTER_FAULT_RESET_H

#include "abstract_parameter.h"
namespace registers_Munk{


class Register_FaultReset : public AbstractParameter
{
public:
    //!
    //! \brief Register_FaultReset
    //!
    Register_FaultReset();


    //!
    //! \brief Register_FaultReset
    //! \param copy
    //!
    Register_FaultReset(const Register_FaultReset &copy);

public:
    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    AbstractParameter* getClone() const override
    {
        return (new Register_FaultReset(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new Register_FaultReset(*this);
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
    Register_FaultReset& operator = (const Register_FaultReset &rhs)
    {
        AbstractParameter::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_FaultReset &rhs)
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
    bool operator != (const Register_FaultReset &rhs) {
        return !(*this == rhs);
    }

private:

};

} //end of namespace registers_Munk

#endif // REGISTER_FAULT_RESET_H
