#ifndef TYPE_AVAILABLE_CHANNELS_H
#define TYPE_AVAILABLE_CHANNELS_H

#include <string>
#include <stdexcept>
#include <vector>

namespace data_Rigol {

enum class AvailableChannels
{
    CHANNEL_1,
    CHANNEL_2,
    CHANNEL_3,
    CHANNEL_4
};

inline std::string AvailableChannelsToString(const AvailableChannels &channel) {
    switch (channel) {
    case AvailableChannels::CHANNEL_1:
        return "CHANnel1";
    case AvailableChannels::CHANNEL_2:
        return "CHANnel2";
    case AvailableChannels::CHANNEL_3:
        return "CHANnel3";
    case AvailableChannels::CHANNEL_4:
        return "CHANnel4";
    default:
        throw std::runtime_error("Unknown channel seen");
    }
}

inline std::string AvailableChannelsToDisplayString(const AvailableChannels &channel) {
    switch (channel) {
    case AvailableChannels::CHANNEL_1:
        return "CHANNEL 1";
    case AvailableChannels::CHANNEL_2:
        return "CHANNEL 2";
    case AvailableChannels::CHANNEL_3:
        return "CHANNEL 3";
    case AvailableChannels::CHANNEL_4:
        return "CHANNEL 4";
    default:
        throw std::runtime_error("Unknown channel seen");
    }
}

inline AvailableChannels AvailableChannelsDisplayToEnum(const std::string str) {
    if(str == "CHANNEL 1")
        return AvailableChannels::CHANNEL_1;
    if(str == "CHANNEL 2")
        return AvailableChannels::CHANNEL_2;
    if(str == "CHANNEL 3")
        return AvailableChannels::CHANNEL_3;
    if(str == "CHANNEL 4")
        return AvailableChannels::CHANNEL_4;
    throw std::runtime_error("Unknown available channel string seen");
}

inline std::vector<std::string> getListOfAvailableChannelsDisplayString()
{
    std::vector<std::string> str;
    str.push_back(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_1));
    str.push_back(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_2));
    str.push_back(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_3));
    str.push_back(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_4));
    return str;
}

inline std::vector<AvailableChannels> getListOfAvailableChannelsEnum()
{
    std::vector<AvailableChannels> str;
    str.push_back(AvailableChannels::CHANNEL_1);
    str.push_back(AvailableChannels::CHANNEL_2);
    str.push_back(AvailableChannels::CHANNEL_3);
    str.push_back(AvailableChannels::CHANNEL_4);
    return str;
}

} //end of namespace data_Rigol


#endif // TYPE_AVAILABLE_CHANNELS_H
