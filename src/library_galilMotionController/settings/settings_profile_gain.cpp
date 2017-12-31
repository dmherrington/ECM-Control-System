#include "settings_profile_gain.h"

SettingsProfileGain::SettingsProfileGain()
{

}

SettingsProfileGain::SettingsProfileGain(const SettingsProfileGain &copy)
{
    this->proportional = copy.proportional;
    this->integral = copy.integral;
    this->derivative = copy.derivative;
}


double SettingsProfileGain::getGainValue(const GainType &type) const
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
}

void SettingsProfileGain::setGainValue(const GainType &type, const double value)
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
