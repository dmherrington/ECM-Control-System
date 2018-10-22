#ifndef REGISTER_TB_COUNT_H
#define REGISTER_TB_COUNT_H

#include "abstract_parameter.h"

namespace registers_Munk{


class Register_TBCount : public AbstractParameter
{
public:
    //!
    //! \brief Register_TBCount
    //!
    Register_TBCount();


    //!
    //! \brief Register_TBCount
    //! \param copy
    //!
    Register_TBCount(const Register_TBCount &copy);

public:
    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    AbstractParameter* getClone() const override
    {
        return (new Register_TBCount(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new Register_TBCount(*this);
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
    Register_TBCount& operator = (const Register_TBCount &rhs)
    {
        AbstractParameter::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_TBCount &rhs)
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
    bool operator != (const Register_TBCount &rhs) {
        return !(*this == rhs);
    }

private:

};

} //end of namespace registers_Munk

#endif // REGISTER_TB_COUNT_H
