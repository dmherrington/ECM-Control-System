#include "ecm_command_profile_pause.h"

ECMCommand_ProfilePause::ECMCommand_ProfilePause(const WaitType &waitType, const unsigned int &duration):
    ECMCommand_AbstractProfileConfig(ConfigType::PAUSE)
{
    this->pauseType = waitType;
    this->pauseDuration = duration;
}

ECMCommand_ProfilePause::ECMCommand_ProfilePause(const ECMCommand_ProfilePause &copy):
    ECMCommand_AbstractProfileConfig(copy)
{
    this->pauseType = copy.pauseType;
    this->pauseDuration = copy.pauseDuration;
    this->m_PumpParameters = copy.m_PumpParameters;
}


void ECMCommand_ProfilePause::writeToJSON(QJsonObject &obj)
{
    ECMCommand_AbstractProfileConfig::writeToJSON(obj);
    obj["pauseType"] = static_cast<int>(this->getPuauseType());
    obj["pauseDuration"] = static_cast<int>(this->getPauseDuration());

    m_PumpParameters.writeToJSON(obj);
}

void ECMCommand_ProfilePause::readFromJSON(const QJsonObject &obj)
{
    ECMCommand_AbstractProfileConfig::readFromJSON(obj);
    this->setPuauseType(static_cast<WaitType>(obj["pauseType"].toInt()));
    this->setPauseDuration(static_cast<unsigned int>(obj["pauseDuration"].toInt()));

    m_PumpParameters.readFromJSON(obj);
}

void ECMCommand_ProfilePause::setPauseDuration(const unsigned int &duration)
{
    this->pauseDuration = duration;
}

void ECMCommand_ProfilePause::setPuauseType(const WaitType &waitType)
{
    this->pauseType = waitType;
}

unsigned int ECMCommand_ProfilePause::getPauseDuration() const
{
    return this->pauseDuration;
}

ECMCommand_ProfilePause::WaitType ECMCommand_ProfilePause::getPuauseType() const
{
    return this->pauseType;
}
