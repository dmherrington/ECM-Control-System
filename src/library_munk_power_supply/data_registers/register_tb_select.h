#ifndef REGISTER_TB_SELECT_H
#define REGISTER_TB_SELECT_H


#include "abstract_parameter.h"

namespace registers_Munk{


class Register_TBSelect : public AbstractParameter
{
public:
    //!
    //! \brief Register_TBCount
    //!
    Register_TBSelect(const unsigned int &board = 01);


    //!
    //! \brief Register_TBSelect
    //! \param copy
    //!
    Register_TBSelect(const Register_TBSelect &copy);

public:
    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    AbstractParameter* getClone() const override
    {
        return (new Register_TBSelect(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new Register_TBSelect(*this);
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

    void setBoardNumber(const unsigned int &board);

    unsigned int getBoardNumber() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_TBSelect& operator = (const Register_TBSelect &rhs)
    {
        AbstractParameter::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_TBSelect &rhs)
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
    bool operator != (const Register_TBSelect &rhs) {
        return !(*this == rhs);
    }

private:

    unsigned int boardNumber;
};

} //end of namespace registers_Munk

#endif // REGISTER_TB_SELECT_H
