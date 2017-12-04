#ifndef SETTINGS_MANUAL_PROFILE_H
#define SETTINGS_MANUAL_PROFILE_H

#include <QJsonArray>
#include <QJsonObject>

class SettingsManualProfile
{
public:
    SettingsManualProfile();

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
public:
    unsigned int getJogSpeed() const;
    unsigned int getRelativeMove() const;
public:
    void setJogSpeed(const unsigned int &speed);
    void setRelativeMove(const unsigned int &distance);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SettingsManualProfile &rhs)
    {
        this->jogSpeed = rhs.jogSpeed;
        this->relativeMove = rhs.relativeMove;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SettingsManualProfile &rhs)
    {
        if(this->jogSpeed != rhs.jogSpeed){
            return false;
        }
        if(this->relativeMove != rhs.relativeMove){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SettingsManualProfile &rhs) {
        return !(*this == rhs);
    }

private:
    unsigned int jogSpeed = 100;
    unsigned int relativeMove = 10000;

};

#endif // SETTINGS_MANUAL_PROFILE_H
