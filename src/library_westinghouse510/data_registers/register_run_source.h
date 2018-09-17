#ifndef REGISTER_RUN_SOURCE_H
#define REGISTER_RUN_SOURCE_H

#include "abstract_register.h"

namespace registers_WestinghousePump{


class LIBRARY_WESTINGHOUSE510SHARED_EXPORT Register_RunSource : public AbstractWestinghouseRegister
{

public:
    enum class SourceSetting : uint8_t
    {
        SOURCE_KEYPAD = 0,
        SOURCE_EXTERNAL_TERMINAL = 1,
        SOURCE_RS485 = 2,
        SOURCE_PLC = 3
    };

public:
    Register_RunSource(const SourceSetting &runSource = SourceSetting::SOURCE_RS485);

    Register_RunSource(const Register_RunSource &copy);

    ~Register_RunSource() = default;

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
    void setRunSource(const SourceSetting &runSource);

    SourceSetting getRunSource() const;

    //!
    //! \brief getClone
    //! \return
    //!
    AbstractWestinghouseRegister* getClone() const override
    {
        return (new Register_RunSource(*this));
    }

    //!
    //! \brief getClone
    //! \param parameter
    //!
    void getClone(AbstractWestinghouseRegister** parameter) const override
    {
        *parameter = new Register_RunSource(*this);
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_RunSource& operator = (const Register_RunSource &rhs)
    {
        AbstractWestinghouseRegister::operator =(rhs);
        this->source = rhs.source;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_RunSource &rhs)
    {
        if(!AbstractWestinghouseRegister::operator ==(rhs)){
            return false;
        }
        if(this->source != rhs.source){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Register_RunSource &rhs) {
        return !(*this == rhs);
    }

protected:
    SourceSetting source;
};


} //end of namespace registers_WestinghousePump
#endif // REGISTER_RUN_SOURCE_H
