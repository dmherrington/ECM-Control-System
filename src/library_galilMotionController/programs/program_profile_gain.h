#ifndef PROGRAM_PROFILE_GAIN_H
#define PROGRAM_PROFILE_GAIN_H

#include <string>

#include <QJsonArray>
#include <QJsonObject>

enum class GainType{
    PGain,
    IGain,
    DGain
};

class ProgramProfileGain
{
public:
    ProgramProfileGain();

    ProgramProfileGain(const ProgramProfileGain &copy);

    ~ProgramProfileGain() = default;

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    double getGainValue(const GainType &type) const;

    void setGainValue(const GainType &type, const double value);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ProgramProfileGain& operator = (const ProgramProfileGain &rhs)
    {
        this->proportional = rhs.proportional;
        this->integral = rhs.integral;
        this->derivative = rhs.derivative;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ProgramProfileGain &rhs)
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
    bool operator != (const ProgramProfileGain &rhs) {
        return !(*this == rhs);
    }

private:
    double proportional = 0.0;
    double integral = 0.0;
    double derivative = 0.0;
};

#endif // PROGRAM_PROFILE_GAIN_H
