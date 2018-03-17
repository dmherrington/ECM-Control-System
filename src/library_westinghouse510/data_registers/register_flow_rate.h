#ifndef REGISTER_FLOW_RATE_H
#define REGISTER_FLOW_RATE_H

#include "abstract_register.h"

namespace registers_WestinghousePump{

class Register_FlowRate : public AbstractWestinghouseRegister
{
public:
    Register_FlowRate();

    Register_FlowRate(const Register_FlowRate &copy);

    ~Register_FlowRate() = default;

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
    void setVolumetricFlow(const double &value);

    double getVolumetricFlow() const;

    //!
    //! \brief getClone
    //! \return
    //!
    AbstractWestinghouseRegister* getClone() const override
    {
        return (new Register_FlowRate(*this));
    }

    //!
    //! \brief getClone
    //! \param parameter
    //!
    void getClone(AbstractWestinghouseRegister** parameter) const override
    {
        *parameter = new Register_FlowRate(*this);
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_FlowRate& operator = (const Register_FlowRate &rhs)
    {
        AbstractWestinghouseRegister::operator =(rhs);
        this->flowRate = rhs.flowRate;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_FlowRate &rhs)
    {
        if(!AbstractWestinghouseRegister::operator ==(rhs)){
            return false;
        }
        if(this->flowRate != rhs.flowRate){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Register_FlowRate &rhs) {
        return !(*this == rhs);
    }

private:
    double flowRate = 0.0;
};

} //end of namespace registers_WestinghousePump


#endif // REGISTER_FLOW_RATE_H
