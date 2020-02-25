#ifndef AXISSETTINGS_H
#define AXISSETTINGS_H

#include <vector>

#include "axis_definitions.h"

class AxisSettings
{
public:
    AxisSettings();

    AxisSettings(const AxisSettings &copy);

    void updateAvilableAxes(const std::vector<MotorAxis> &obj);

    void updateIgnoredFaults(const std::vector<MotorAxis> &obj);

    void updateIgnoredMotion(const std::vector<MotorAxis> &obj);

    std::vector<MotorAxis> getAvailableAxes() const;

    bool shouldFaultBeIgnored(const MotorAxis &axis) const;

    bool shouldMotionBeIgnored(const MotorAxis &axis) const;

    bool isAvailableAxis(const MotorAxis &axis) const;

public:
    AxisSettings& operator = (const AxisSettings &rhs)
    {
        this->m_AvailaleAxes = rhs.m_AvailaleAxes;
        this->m_IgnoredFaults = rhs.m_IgnoredFaults;
        this->m_IgnoredMotion = rhs.m_IgnoredMotion;
        return *this;
    }

    bool operator == (const AxisSettings &rhs) {
        if(this->m_AvailaleAxes != rhs.m_AvailaleAxes){
            return false;
        }
        if(this->m_IgnoredFaults != rhs.m_IgnoredFaults){
            return false;
        }
        if(this->m_IgnoredMotion != rhs.m_IgnoredMotion){
            return false;
        }
        return true;
    }

    bool operator != (const AxisSettings &rhs) {
        return !(*this == rhs);
    }


private:

    std::vector<MotorAxis> m_AvailaleAxes;

    std::vector<MotorAxis> m_IgnoredFaults;

    std::vector<MotorAxis> m_IgnoredMotion;
};

#endif // AXISSETTINGS_H
