#ifndef REGISTER_FLOW_RATE_H
#define REGISTER_FLOW_RATE_H

#include "abstract_register.h"

namespace westinghousePump{
namespace registers{

class Register_FlowRate : public AbstractRegister
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
    RegisterType getRegisterType() const override;

    //!
    //! \brief getByteArray
    //! \return
    //!
    QByteArray getByteArray() const override;

public:
    void setVolumetricFlow(const double &value);

    double getVolumetricFlow() const;

    //!
    //! \brief getClone
    //! \return
    //!
    AbstractRegister* getClone() const override
    {
        return (new Register_FlowRate(*this));
    }

    //!
    //! \brief getClone
    //! \param parameter
    //!
    void getClone(AbstractRegister** parameter) const override
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
        AbstractRegister::operator =(rhs);
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
        if(!AbstractRegister::operator ==(rhs)){
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

} //end of namespace registers
} //end of namespace westinghousePump

#endif // REGISTER_FLOW_RATE_H
