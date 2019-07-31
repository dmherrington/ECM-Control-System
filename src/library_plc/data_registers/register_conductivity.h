#ifndef REGISTER_CONDUCTIVITY_H
#define REGISTER_CONDUCTIVITY_H

#include "abstract_register.h"

namespace registers_PLC{

class LIBRARY_PLCSHARED_EXPORT Register_Conductivity : public AbstractPLCRegister
{
public:
    Register_Conductivity();

    Register_Conductivity(const Register_Conductivity &copy);

    ~Register_Conductivity() override = default;

    //!
    //! \brief getDescription
    //! \return
    //!
    std::string getDescription() const override;

    //!
    //! \brief getRegisterType
    //! \return
    //!
    PLCRegisterTypes getRegisterType() const override;

    //!
    //! \brief getByteArray
    //! \return
    //!
    QByteArray getByteArray() const override;

    //!
    //! \brief parseFromArray
    //! \param msg
    //!
    void parseFromArray(const QByteArray &msg) override;

public:
    //!
    //! \brief getClone
    //! \return
    //!
    AbstractPLCRegister* getClone() const override
    {
        return (new Register_Conductivity(*this));
    }

    //!
    //! \brief getClone
    //! \param parameter
    //!
    void getClone(AbstractPLCRegister** parameter) const override
    {
        *parameter = new Register_Conductivity(*this);
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_Conductivity& operator = (const Register_Conductivity &rhs)
    {
        AbstractPLCRegister::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_Conductivity &rhs)
    {
        if(!AbstractPLCRegister::operator ==(rhs)){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Register_Conductivity &rhs) {
        return !(*this == rhs);
    }

private:

};

} //end of namespace registers_PLC

#endif // REGISTER_CONDUCTIVITY_H
