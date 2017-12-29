#ifndef SETTINGS_ABSTRACT_PROFILE_H
#define SETTINGS_ABSTRACT_PROFILE_H


class SettingsAbstractProfile
{
public:
    SettingsAbstractProfile();
public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    double getGainProportional() const;
    double getGainIntegral() const;
    double getGainDerivative() const;


public:
    void setGainProportional(const double &gain);
    void setGainIntegral(const double &gain);
    void setGainDerivative(const double &gain);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SettingsAbstractProfile &rhs)
    {
        this->gainP = rhs.gainP;
        this->gainI = rhs.gainI;
        this->gainD = rhs.gainD;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SettingsAbstractProfile &rhs)
    {
        if(this->gainP != rhs.gainP){
            return false;
        }
        if(this->gainI != rhs.gainI){
            return false;
        }
        if(this->gainD != rhs.gainD){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SettingsAbstractProfile &rhs) {
        return !(*this == rhs);
    }

private:
    double gainP = 100;
    double gainI = 100;
    double gainD = 100;
};

#endif // SETTINGS_ABSTRACT_PROFILE_H
