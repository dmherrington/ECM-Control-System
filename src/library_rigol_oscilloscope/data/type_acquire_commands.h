#ifndef TYPE_ACQUIRE_COMMANDS_H
#define TYPE_ACQUIRE_COMMANDS_H

#include <string>
#include <stdexcept>
#include <vector>

namespace rigol {
namespace data{

enum class AcquireType
{
    ACQUIRE_AVERAGE,
    ACQUIRE_MDEPTH,
    ACQUIRE_TYPE,
    ACQUIRE_SRAT
};

//!
//! \brief SegmentModeToString
//! \param type
//! \return
//!
inline std::string AcquireTypeToString(const AcquireType &type) {
    switch (type) {
    case AcquireType::ACQUIRE_AVERAGE:
        return "AVERages";
    case AcquireType::ACQUIRE_MDEPTH:
        return "MDEPth";
    case AcquireType::ACQUIRE_TYPE:
        return "TYPE";
    case AcquireType::ACQUIRE_SRAT:
        return "SRATe";
    default:
        throw std::runtime_error("Unknown acquisition type seen");
    }
}

//!
//! \brief SegmentModeFromString
//! \param str
//! \return
//!
inline AcquireType AcquireTypeFromString(const std::string &str) {
    if(str == "AVERages")
        return AcquireType::ACQUIRE_AVERAGE;
    if(str == "MDEPth")
        return AcquireType::ACQUIRE_MDEPTH;
    if(str == "TYPE")
        return AcquireType::ACQUIRE_TYPE;
    if(str == "SRATe")
        return AcquireType::ACQUIRE_SRAT;
    throw std::runtime_error("Unknown acquisition type string seen");
}

//!
//! \brief getListOfSegmentMode
//! \return
//!
inline std::vector<std::string> getListOfAcquireTypes()
{
    std::vector<std::string> str;
    str.push_back(AcquireTypeToString(AcquireType::ACQUIRE_AVERAGE));
    str.push_back(AcquireTypeToString(AcquireType::ACQUIRE_MDEPTH));
    str.push_back(AcquireTypeToString(AcquireType::ACQUIRE_TYPE));
    str.push_back(AcquireTypeToString(AcquireType::ACQUIRE_SRAT));
    return str;
}

} //end of namespace data
} //end of namespace rigol

#endif // TYPE_ACQUIRE_COMMANDS_H
