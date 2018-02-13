#ifndef TYPE_MEMORY_DEPTH_H
#define TYPE_MEMORY_DEPTH_H

#include <string>
#include <vector>

namespace rigol {
namespace data{

enum class DepthSingleChannel
{
    DEPTH_AUTO,
    DEPTH_12000,
    DEPTH_120000,
    DEPTH_1200000,
    DEPTH_12000000,
    DEPTH_24000000
};

//!
//! \brief DepthSingleChannelToString
//! \param depth
//! \return
//!
inline std::string DepthSingleChannelToString(const DepthSingleChannel &depth) {
    switch (depth) {
    case DepthSingleChannel::DEPTH_AUTO:
        return "AUTO";
    case DepthSingleChannel::DEPTH_12000:
        return "12000";
    case DepthSingleChannel::DEPTH_120000:
        return "120000";
    case DepthSingleChannel::DEPTH_1200000:
        return "1200000";
    case DepthSingleChannel::DEPTH_12000000:
        return "12000000";
    case DepthSingleChannel::DEPTH_24000000:
        return "24000000";
    default:
        throw std::runtime_error("Unknown single channel memory depth seen");
    }
}

//!
//! \brief getListOfReadWriteType
//! \return
//!
inline std::vector<std::string> getListOfSingleChannelDepth()
{
    std::vector<std::string> str;
    str.push_back(DepthSingleChannelToString(DepthSingleChannel::DEPTH_AUTO));
    str.push_back(DepthSingleChannelToString(DepthSingleChannel::DEPTH_12000));
    str.push_back(DepthSingleChannelToString(DepthSingleChannel::DEPTH_120000));
    str.push_back(DepthSingleChannelToString(DepthSingleChannel::DEPTH_1200000));
    str.push_back(DepthSingleChannelToString(DepthSingleChannel::DEPTH_12000000));
    str.push_back(DepthSingleChannelToString(DepthSingleChannel::DEPTH_24000000));
    return str;
}


enum class DepthDualChannel
{
    DEPTH_AUTO,
    DEPTH_6000,
    DEPTH_60000,
    DEPTH_600000,
    DEPTH_6000000,
    DEPTH_12000000
};

//!
//! \brief DepthSingleChannelToString
//! \param depth
//! \return
//!
inline std::string DepthDualChannelToString(const DepthDualChannel &depth) {
    switch (depth) {
    case DepthDualChannel::DEPTH_AUTO:
        return "AUTO";
    case DepthDualChannel::DEPTH_6000:
        return "12000";
    case DepthDualChannel::DEPTH_60000:
        return "120000";
    case DepthDualChannel::DEPTH_600000:
        return "1200000";
    case DepthDualChannel::DEPTH_6000000:
        return "12000000";
    case DepthDualChannel::DEPTH_12000000:
        return "24000000";
    default:
        throw std::runtime_error("Unknown dual channel memory depth seen");
    }
}

//!
//! \brief getListOfReadWriteType
//! \return
//!
inline std::vector<std::string> getListOfDualChannelDepth()
{
    std::vector<std::string> str;
    str.push_back(DepthDualChannelToString(DepthDualChannel::DEPTH_AUTO));
    str.push_back(DepthDualChannelToString(DepthDualChannel::DEPTH_6000));
    str.push_back(DepthDualChannelToString(DepthDualChannel::DEPTH_60000));
    str.push_back(DepthDualChannelToString(DepthDualChannel::DEPTH_600000));
    str.push_back(DepthDualChannelToString(DepthDualChannel::DEPTH_6000000));
    str.push_back(DepthDualChannelToString(DepthDualChannel::DEPTH_12000000));
    return str;
}


enum class DepthQuadratureChannel
{
    DEPTH_AUTO,
    DEPTH_3000,
    DEPTH_30000,
    DEPTH_300000,
    DEPTH_3000000,
    DEPTH_6000000
};

//!
//! \brief DepthSingleChannelToString
//! \param depth
//! \return
//!
inline std::string DepthQuadratureChannelToString(const DepthQuadratureChannel &depth) {
    switch (depth) {
    case DepthQuadratureChannel::DEPTH_AUTO:
        return "AUTO";
    case DepthQuadratureChannel::DEPTH_3000:
        return "12000";
    case DepthQuadratureChannel::DEPTH_30000:
        return "120000";
    case DepthQuadratureChannel::DEPTH_300000:
        return "1200000";
    case DepthQuadratureChannel::DEPTH_3000000:
        return "12000000";
    case DepthQuadratureChannel::DEPTH_6000000:
        return "24000000";
    default:
        throw std::runtime_error("Unknown quadrature channel memory depth seen");
    }
}

//!
//! \brief getListOfReadWriteType
//! \return
//!
inline std::vector<std::string> getListOfQuadratureChannelDepth()
{
    std::vector<std::string> str;
    str.push_back(DepthQuadratureChannelToString(DepthQuadratureChannel::DEPTH_AUTO));
    str.push_back(DepthQuadratureChannelToString(DepthQuadratureChannel::DEPTH_3000));
    str.push_back(DepthQuadratureChannelToString(DepthQuadratureChannel::DEPTH_30000));
    str.push_back(DepthQuadratureChannelToString(DepthQuadratureChannel::DEPTH_300000));
    str.push_back(DepthQuadratureChannelToString(DepthQuadratureChannel::DEPTH_3000000));
    str.push_back(DepthQuadratureChannelToString(DepthQuadratureChannel::DEPTH_6000000));
    return str;
}

} //end of namespace data
} //end of namespace rigol

#endif // TYPE_MEMORY_DEPTH_H
