#ifndef ACQUIRE_COMMAND_TYPE_OPTIONS_H
#define ACQUIRE_COMMAND_TYPE_OPTIONS_H

#include <string>
#include <stdexcept>
#include <vector>

namespace rigol {
namespace data{

enum class AcquireCommand_TypeMode
{
    NORMAL,
    AVERAGE,
    PEAK,
    HRE
};

//!
//! \brief SegmentModeToString
//! \param type
//! \return
//!
inline std::string AcquireTypeModeToString(const AcquireCommand_TypeMode &type) {
    switch (type) {
    case AcquireCommand_TypeMode::NORMAL:
        return "NORMal";
    case AcquireCommand_TypeMode::AVERAGE:
        return "AVERages";
    case AcquireCommand_TypeMode::PEAK:
        return "PEAK";
    case AcquireCommand_TypeMode::HRE:
        return "HRESolution";
    default:
        throw std::runtime_error("Unknown acquisition type range seen");
    }
}

//!
//! \brief SegmentModeFromString
//! \param str
//! \return
//!
inline AcquireCommand_TypeMode AcquireTypeModeFromString(const std::string &str) {
    if(str == "NORMal")
        return AcquireCommand_TypeMode::NORMAL;
    if(str == "AVERages")
        return AcquireCommand_TypeMode::AVERAGE;
    if(str == "PEAK")
        return AcquireCommand_TypeMode::PEAK;
    if(str == "HRESolution")
        return AcquireCommand_TypeMode::HRE;
    throw std::runtime_error("Unknown acquisition type range string seen");
}

//!
//! \brief getListOfSegmentMode
//! \return
//!
inline std::vector<std::string> getListOfAcquireModeTypes()
{
    std::vector<std::string> str;
    str.push_back(AcquireTypeModeToString(AcquireCommand_TypeMode::NORMAL));
    str.push_back(AcquireTypeModeToString(AcquireCommand_TypeMode::AVERAGE));
    str.push_back(AcquireTypeModeToString(AcquireCommand_TypeMode::PEAK));
    str.push_back(AcquireTypeModeToString(AcquireCommand_TypeMode::HRE));
    return str;
}

} //end of namespace data
} //end of namespace rigol


#endif // ACQUIRE_COMMAND_TYPE_OPTIONS_H
