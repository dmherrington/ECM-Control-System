#ifndef REGISTER_TB_TEMPERATURE_H
#define REGISTER_TB_TEMPERATURE_H

#include "abstract_parameter.h"

namespace registers_Munk{


class Register_TBTemperature : public AbstractParameter
{
public:
    //!
    //! \brief Register_TBTemperature
    //!
    Register_TBTemperature();


    //!
    //! \brief Register_TBTemperature
    //! \param copy
    //!
    Register_TBTemperature(const Register_TBTemperature &copy);

public:
    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    AbstractParameter* getClone() const override
    {
        return (new Register_TBTemperature(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new Register_TBTemperature(*this);
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


public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_TBTemperature& operator = (const Register_TBTemperature &rhs)
    {
        AbstractParameter::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_TBTemperature &rhs)
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
    bool operator != (const Register_TBTemperature &rhs) {
        return !(*this == rhs);
    }

private:

};

} //end of namespace registers_Munk


#endif // REGISTER_TB_TEMPERATURE_H
