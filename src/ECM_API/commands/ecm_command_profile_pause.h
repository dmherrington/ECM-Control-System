#ifndef ECM_COMMAND_PROFILE_PAUSE_H
#define ECM_COMMAND_PROFILE_PAUSE_H

#include "ecm_command_abstract_profile_config.h"

#include "library_westinghouse510/command_pump_properties.h"

ECM_CLASS_FORWARD(ECMCommand_ProfilePause);

class ECMCommand_ProfilePause : public ECMCommand_AbstractProfileConfig
{
public:
    enum class WaitType
    {
        FINITE,
        INF
    };

public:
    ECMCommand_ProfilePause(const WaitType &waitType = WaitType::FINITE, const unsigned int &duration = 0);

    ECMCommand_ProfilePause(const ECMCommand_ProfilePause &copy);

    ~ECMCommand_ProfilePause() override;

public:
    void writeToJSON(QJsonObject &obj) override;

    void readFromJSON(const QJsonObject &obj) override;

public:
    void setPauseDuration(const unsigned int &duration);

    void setPauseType(const WaitType &waitType);

public:
    unsigned int getPauseDuration() const;

    WaitType getPauseType() const;


private:
    unsigned int pauseDuration;
    WaitType pauseType;

public:
    Command_PumpProperties m_PumpParameters;
};

#endif // ECM_COMMAND_PROFILE_PAUSE_H
