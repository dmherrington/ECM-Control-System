#ifndef REGISTER_PH_H
#define REGISTER_PH_H

#include "abstract_register.h"

namespace registers_PLC{

class LIBRARY_PLCSHARED_EXPORT Register_pH : public AbstractPLCRegister
{
public:
    Register_pH();

    Register_pH(const Register_pH &copy);

    ~Register_pH() override = default;

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
        return (new Register_pH(*this));
    }

    //!
    //! \brief getClone
    //! \param parameter
    //!
    void getClone(AbstractPLCRegister** parameter) const override
    {
        *parameter = new Register_pH(*this);
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_pH& operator = (const Register_pH &rhs)
    {
        AbstractPLCRegister::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_pH &rhs)
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
    bool operator != (const Register_pH &rhs) {
        return !(*this == rhs);
    }

private:

};

} //end of namespace registers_PLC

#endif // REGISTER_PH_H
