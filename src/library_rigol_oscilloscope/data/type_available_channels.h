#ifndef TYPE_AVAILABLE_CHANNELS_H
#define TYPE_AVAILABLE_CHANNELS_H

#include <string>
#include <stdexcept>

namespace rigol{
namespace data {

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
    case AvailableChannels::CHANNEL_1:
        return "CHANnel2";
    case AvailableChannels::CHANNEL_1:
        return "CHANnel3";
    case AvailableChannels::CHANNEL_1:
        return "CHANnel4";
    default:
        throw std::runtime_error("Unknown channel seen");
    }
}

} //end of namespace data
} //end of namespace rigol

#endif // TYPE_AVAILABLE_CHANNELS_H
