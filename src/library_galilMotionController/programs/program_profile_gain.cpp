#include "program_profile_gain.h"

ProgramProfileGain::ProgramProfileGain()
{

}

ProgramProfileGain::ProgramProfileGain(const ProgramProfileGain &copy)
{
    this->proportional = copy.proportional;
    this->integral = copy.integral;
    this->derivative = copy.derivative;
}

void ProgramProfileGain::read(const QJsonObject &json)
{
    //Parse the json object the same way that we had packed it up when saving
    QJsonObject gainsObject  = json["Gains"].toObject();
    this->setGainValue(GainType::PGain, gainsObject["PGain"].toDouble());
    this->setGainValue(GainType::IGain, gainsObject["IGain"].toDouble());
    this->setGainValue(GainType::DGain, gainsObject["DGain"].toDouble());
}

void ProgramProfileGain::write(QJsonObject &json) const
{
    QJsonObject gainsObject;
    gainsObject["PGain"] = proportional;
    gainsObject["IGain"] = integral;
    gainsObject["DGain"] = derivative;

    json["Gains"] = gainsObject;
}

double ProgramProfileGain::getGainValue(const GainType &type) const
{
    double gainValue = 0.0;

    switch (type) {
    case GainType::PGain:
        gainValue = proportional;
        break;
    case GainType::IGain:
        gainValue = integral;
        break;
    case GainType::DGain:
        gainValue = derivative;
        break;
    default:
        break;
    }
    return gainValue;
}

void ProgramProfileGain::setGainValue(const GainType &type, const double value)
{
    switch (type) {
    case GainType::PGain:
        this->proportional = value;
        break;
    case GainType::IGain:
        this->integral = value;
        break;
    case GainType::DGain:
        this->derivative = value;
        break;
    default:
        break;
    }
}
