#ifndef REGISTER_LOOPBACK_H
#define REGISTER_LOOPBACK_H

#include "abstract_register.h"

namespace registers_WestinghousePump{


class LIBRARY_WESTINGHOUSE510SHARED_EXPORT Register_Loopback : public AbstractWestinghouseRegister
{

public:
    Register_Loopback();

    Register_Loopback(const Register_Loopback &copy);

    ~Register_Loopback() override = default;

    //!
    //! \brief getDescription
    //! \return
    //!
    std::string getDescription() const override;

    //!
    //! \brief getRegisterType
    //! \return
    //!
    WestinhouseRegisterTypes getRegisterType() const override;

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
    AbstractWestinghouseRegister* getClone() const override
    {
        return (new Register_Loopback(*this));
    }

    //!
    //! \brief getClone
    //! \param parameter
    //!
    void getClone(AbstractWestinghouseRegister** parameter) const override
    {
        *parameter = new Register_Loopback(*this);
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_Loopback& operator = (const Register_Loopback &rhs)
    {
        AbstractWestinghouseRegister::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_Loopback &rhs)
    {
        if(!AbstractWestinghouseRegister::operator ==(rhs)){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Register_Loopback &rhs) {
        return !(*this == rhs);
    }

protected:
    uint8_t dataHi = 165;
    uint8_t dataLo = 55;
};

} //end of namespace registers_WestinghousePump

#endif // REGISTER_LOOPBACK_H
