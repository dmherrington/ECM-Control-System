#ifndef SETTINGS_LINEAR_PROFILE_H
#define SETTINGS_LINEAR_PROFILE_H

#include <QJsonArray>
#include <QJsonObject>

class SettingsLinearProfile
{
public:
    SettingsLinearProfile();

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    int getDepthofCut() const;
    int getCutSpeed() const;

public:
    void setDepthofCut(const int &distance);
    void setCutSpeed(const int &speed);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SettingsLinearProfile &rhs)
    {
        this->depthOfCut = rhs.depthOfCut;
        this->cutSpeed = rhs.cutSpeed;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SettingsLinearProfile &rhs)
    {
        if(this->depthOfCut != rhs.depthOfCut){
            return false;
        }
        if(this->cutSpeed != rhs.cutSpeed){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SettingsLinearProfile &rhs) {
        return !(*this == rhs);
    }

private:
    int depthOfCut = 100;
    int cutSpeed = 100;
};

#endif // SETTINGS_LINEAR_PROFILE_H
