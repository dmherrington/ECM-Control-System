#ifndef REGISTER_OPERATION_SIGNAL_H
#define REGISTER_OPERATION_SIGNAL_H

#include "abstract_register.h"

namespace registers_WestinghousePump{

class Register_OperationSignal : public AbstractWestinghouseRegister
{
public:
    Register_OperationSignal();

    Register_OperationSignal(const Register_OperationSignal &copy);

    ~Register_OperationSignal() = default;

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
    void shouldRun(const bool &value);

    void shouldReverse(const bool &value);

    void shouldFault(const bool &value);

    void shouldReset(const bool &value);

public:
    bool isRun() const;

    bool isReverse() const;

    bool isFault() const;

    bool isReset() const;

    //!
    //! \brief getClone
    //! \return
    //!
    AbstractWestinghouseRegister* getClone() const override
    {
        return (new Register_OperationSignal(*this));
    }

    //!
    //! \brief getClone
    //! \param parameter
    //!
    void getClone(AbstractWestinghouseRegister** parameter) const override
    {
        *parameter = new Register_OperationSignal(*this);
    }

private:
    bool checkMask(const uint16_t &value, const unsigned int &mask) const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_OperationSignal& operator = (const Register_OperationSignal &rhs)
    {
        AbstractWestinghouseRegister::operator =(rhs);
        this->_run = rhs._run;
        this->_reverse = rhs._reverse;
        this->_fault = rhs._fault;
        this->_reset = rhs._reset;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_OperationSignal &rhs)
    {
        if(!AbstractWestinghouseRegister::operator ==(rhs)){
            return false;
        }
        if(this->_run != rhs._run){
            return false;
        }
        if(this->_reverse != rhs._reverse){
            return false;
        }
        if(this->_fault != rhs._fault){
            return false;
        }
        if(this->_reset != rhs._reset){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Register_OperationSignal &rhs) {
        return !(*this == rhs);
    }

private:
    bool _run = false;
    bool _reverse = false;
    bool _fault = false;
    bool _reset = false;
};

} //end of namespace registers_WestinghousePump 

#endif // REGISTER_OPERATION_SIGNAL_H
