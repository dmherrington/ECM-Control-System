#ifndef POWER_SUPPLY_SETUP_CONFIG_H
#define POWER_SUPPLY_SETUP_CONFIG_H

#include <QJsonArray>
#include <QJsonObject>

#include "data_registers/segment_time_detailed.h"
#include "data_registers/register_pulse_mode.h"

class PowerSupply_SetupConfig
{
public:
    PowerSupply_SetupConfig();

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    PowerSupply_SetupConfig& operator = (const PowerSupply_SetupConfig &rhs)
    {
        this->m_MunkSegment = rhs.m_MunkSegment;
        this->m_MunkPulseMode = rhs.m_MunkPulseMode;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const PowerSupply_SetupConfig &rhs)
    {
        if(this->m_MunkSegment != rhs.m_MunkSegment){
            return false;
        }
        if(this->m_MunkPulseMode != rhs.m_MunkPulseMode){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const PowerSupply_SetupConfig &rhs) {
        return !(*this == rhs);
    }

public:
    registers_Munk::SegmentTimeDetailed m_MunkSegment;

    registers_Munk::Register_PulseMode m_MunkPulseMode;

};

#endif // POWER_SUPPLY_SETUP_CONFIG_H
