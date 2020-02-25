#include "axis_settings.h"

AxisSettings::AxisSettings()
{

}

AxisSettings::AxisSettings(const AxisSettings &copy)
{
    this->m_AvailaleAxes = copy.m_AvailaleAxes;
    this->m_IgnoredFaults = copy.m_IgnoredFaults;
    this->m_IgnoredMotion = copy.m_IgnoredMotion;
}

void AxisSettings::updateAvilableAxes(const std::vector<MotorAxis> &obj)
{
    this->m_AvailaleAxes = obj;
}

void AxisSettings::updateIgnoredFaults(const std::vector<MotorAxis> &obj)
{
    this->m_IgnoredFaults = obj;
}

void AxisSettings::updateIgnoredMotion(const std::vector<MotorAxis> &obj)
{
    this->m_IgnoredMotion = obj;
}

std::vector<MotorAxis> AxisSettings::getAvailableAxes() const
{
    return m_AvailaleAxes;
}

bool AxisSettings::shouldFaultBeIgnored(const MotorAxis &axis) const
{
    for(size_t i = 0; i < m_IgnoredFaults.size(); i++)
    {
        if(m_IgnoredFaults.at(i) == axis)
            return true;
    }
    return false;
}

bool AxisSettings::shouldMotionBeIgnored(const MotorAxis &axis) const
{
    for(size_t i = 0; i < m_IgnoredMotion.size(); i++)
    {
        if(m_IgnoredMotion.at(i) == axis)
            return true;
    }
    return false;
}

bool AxisSettings::isAvailableAxis(const MotorAxis &axis) const
{
    bool validAxis = false;
    for(size_t i = 0; i < m_AvailaleAxes.size(); i++)
    {
        if(m_AvailaleAxes.at(i) == axis)
        {
            validAxis = true;
            break;
        }
    }

    return validAxis;
}
