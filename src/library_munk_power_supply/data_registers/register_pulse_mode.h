#ifndef REGISTER_PULSE_MODE_H
#define REGISTER_PULSE_MODE_H

#include "abstract_parameter.h"

#include "data/type_pulse_mode.h"

namespace registers_Munk{


class Register_PulseMode : public AbstractParameter
{
public:
    //!
    //! \brief Register_FaultReset
    //!
    Register_PulseMode();


    //!
    //! \brief Register_FaultReset
    //! \param copy
    //!
    Register_PulseMode(const Register_PulseMode &copy);

public:
    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    AbstractParameter* getClone() const override
    {
        return (new Register_PulseMode(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new Register_PulseMode(*this);
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

    void setPulseMode(const data_Munk::TypePulseModes &mode);

    void setTriggerCount(const uint8_t &count);

    uint8_t getTriggerCount() const;

private:
    void updatePulseMode();
public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Register_PulseMode& operator = (const Register_PulseMode &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->pulseMode = rhs.pulseMode;
        this->triggerCount = rhs.triggerCount;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Register_PulseMode &rhs)
    {
        if(!AbstractParameter::operator ==(rhs)){
            return false;
        }
        if(this->pulseMode != rhs.pulseMode){
            return false;
        }
        if(this->triggerCount != rhs.triggerCount){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Register_PulseMode &rhs) {
        return !(*this == rhs);
    }

private:
    data_Munk::TypePulseModes pulseMode;
    uint8_t triggerCount;
};

} //end of namespace registers_Munk

#endif // REGISTER_PULSE_MODE_H
