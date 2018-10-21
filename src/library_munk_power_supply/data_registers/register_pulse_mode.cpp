#include "register_pulse_mode.h"

namespace registers_Munk {

Register_PulseMode::Register_PulseMode():
    AbstractParameter()
{
    this->parameterCode = ParameterTypeToInt(ParameterType::PULSE_MODE);
    this->parameterType = ParameterType::PULSE_MODE;
    this->setReadorWrite(data_Munk::MunkRWType::WRITE);
}

Register_PulseMode::Register_PulseMode(const Register_PulseMode &copy):
    AbstractParameter(copy)
{
    this->pulseMode = copy.pulseMode;
    this->triggerCount = copy.triggerCount;
}

std::string Register_PulseMode::getDescription() const
{
    std::string str = "";
    return str;
}

void Register_PulseMode::setPulseMode(const data_Munk::TypePulseModes &mode)
{
    this->pulseMode = mode;
}

void Register_PulseMode::setTriggerCount(const uint8_t &count)
{
    this->triggerCount = count;
}

QByteArray Register_PulseMode::getByteArray() const
{
    QByteArray ba;
    int registerLength = 1;
    uint8_t HIGHSeqType = (uint8_t)((registerLength & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(registerLength & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    uint8_t numBytes = 2 * registerLength;

    ba.append((uint8_t)numBytes);

    uint8_t HIGHBType = (uint8_t)(static_cast<uint8_t>(this->pulseMode));
    uint8_t LOWBType = (uint8_t)(this->triggerCount);

    ba.append(LOWBType);
    ba.append(HIGHBType);

    return ba;
}

QByteArray Register_PulseMode::getExpectedResponse() const
{
    QByteArray ba;
    int messageLength = 2;
    uint8_t HIGHSeqType = (uint8_t)((messageLength & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(messageLength & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    return ba;
}

} //end of namespace registers_Munk
