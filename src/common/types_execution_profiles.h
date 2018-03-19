#ifndef TYPES_EXECUTION_PROFILES_H
#define TYPES_EXECUTION_PROFILES_H

#include <stdexcept>

enum class ProfileType
{
    HOMING,
    TOUCHOFF,
    PROFILE
};

enum class HOMINGProfileCodes
{
    INCOMPLETE = 0,
    COMPLETE = 1
};

enum class TOUCHOFFProfileCodes
{
    SEARCHING = 0,
    FINISHED = 1,
    ERROR_INCONSISTENT = 2,
    ERROR_TOUCHING = 3,
    INCOMPLETE
};

//!
//! \brief TOUCHOFFCodesToString
//! \param code
//! \return
//!
inline std::string TOUCHOFFCodesToString(const TOUCHOFFProfileCodes &code) {
    switch (code) {
    case TOUCHOFFProfileCodes::SEARCHING:
        return "Touchoff Searching.";
    case TOUCHOFFProfileCodes::FINISHED:
        return "Touchoff Finished.";
    case TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        return "Touchoff Error: Inconsistent values.";
    case TOUCHOFFProfileCodes::ERROR_TOUCHING:
        return "Touchoff Error: Already touching.";
    case TOUCHOFFProfileCodes::INCOMPLETE:
        return "Touchoff Incomplete";
    default:
        throw std::runtime_error("Unknown touchoff profile code seen");
    }
}

//!
//! \brief TOUCHOFFCodesToString
//! \param code
//! \return
//!
inline std::string HOMINGCodesToString(const HOMINGProfileCodes &code) {
    switch (code) {
    case HOMINGProfileCodes::INCOMPLETE:
        return "Home Routine Incomplete.";
    case HOMINGProfileCodes::COMPLETE:
        return "Home Routine Finished.";
    default:
        throw std::runtime_error("Unknown touchoff profile code seen");
    }
}

#endif // TYPES_EXECUTION_PROFILES_H
