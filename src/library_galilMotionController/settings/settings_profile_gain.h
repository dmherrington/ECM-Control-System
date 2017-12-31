#ifndef SETTINGS_PROFILE_GAIN_H
#define SETTINGS_PROFILE_GAIN_H

enum class GainType{
    PGain,
    IGain,
    DGain
};

class SettingsProfileGain
{
public:
    SettingsProfileGain();

    SettingsProfileGain(const SettingsProfileGain &copy);

    ~SettingsProfileGain() = default;

public:
    double getGainValue(const GainType &type) const;

    void setGainValue(const GainType &type, const double value);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SettingsProfileGain &rhs)
    {
        this->proportional = rhs.proportional;
        this->integral = rhs.integral;
        this->derivative = rhs.derivative;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SettingsProfileGain &rhs)
    {
        if(this->proportional != rhs.proportional){
            return false;
        }
        if(this->integral != rhs.integral){
            return false;
        }
        if(this->derivative != rhs.derivative){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SettingsProfileGain &rhs) {
        return !(*this == rhs);
    }

private:
    double proportional = 0.0;
    double integral = 0.0;
    double derivative = 0.0;
};

#endif // SETTINGS_PROFILE_GAIN_H
