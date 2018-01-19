#ifndef SETTINGS_PINOUT_H
#define SETTINGS_PINOUT_H

#include <QJsonArray>
#include <QJsonObject>
#include <map>

enum class GalilPins
{
    Pin_ESTOP,
    Pin_TOUCHOFF
};

class SettingsPinout
{
public:
    SettingsPinout();

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SettingsPinout &rhs)
    {
        this->mapPinout = rhs.mapPinout;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SettingsPinout &rhs)
    {
        if(this->mapPinout != rhs.mapPinout){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SettingsPinout &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<GalilPins,int> mapPinout;
};

#endif // SETTINGS_PINOUT_H
