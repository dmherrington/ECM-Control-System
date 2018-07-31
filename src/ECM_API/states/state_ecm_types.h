#ifndef STATE_ECM_TYPES_H
#define STATE_ECM_TYPES_H

#include <string>
#include <vector>
#include <stdexcept>


namespace ECM{
namespace API {

enum class ECMState{
    STATE_ECM_IDLE = 0, /**< */
    STATE_ECM_POWERSUPPLY_SETUP = 1, /**< */
    STATE_ECM_PROFILE_MACHINE = 2, /**< */
    STATE_ECM_PROFILE_MACHINE_CEASE = 3, /**< */
    STATE_ECM_PROFILE_MACHINE_PROCESS = 4, /**< */
    STATE_ECM_PROFILE_MACHINE_SETUP = 5, /**< */
    STATE_ECM_PUMP_SETUP = 6, /**< */
    STATE_ECM_INITIALIZATION = 7, /**< */
    STATE_ECM_TOUCHOFF = 8, /**< */
    STATE_ECM_TOUCHOFF_DISABLE = 9, /**< */
    STATE_ECM_TOUCHOFF_ENABLE = 10, /**< */
    STATE_ECM_TOUCHOFF_EXECUTE = 11, /**< */
    STATE_UNKNOWN = 12 /**< */
};

//!
//! \brief CommandToString
//! \param type
//! \return
//!
inline std::string ECMStateToString(const ECMState &type) {
    switch (type) {
    case ECMState::STATE_ECM_IDLE:
        return "Idle";
    case ECMState::STATE_ECM_POWERSUPPLY_SETUP:
        return "Powersupply Setup";
    case ECMState::STATE_ECM_PROFILE_MACHINE:
        return "Machine";
    case ECMState::STATE_ECM_PROFILE_MACHINE_CEASE:
        return "Machine Cease";
    case ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS:
        return "Machine Process";
    case ECMState::STATE_ECM_PROFILE_MACHINE_SETUP:
        return "Machine Setup";
    case ECMState::STATE_ECM_PUMP_SETUP:
        return "Pump Setup";
    case ECMState::STATE_ECM_INITIALIZATION:
        return "Machine Initialization";
    case ECMState::STATE_ECM_TOUCHOFF:
        return "Touchoff";
    case ECMState::STATE_ECM_TOUCHOFF_DISABLE:
        return "Touchoff Disable";
    case ECMState::STATE_ECM_TOUCHOFF_ENABLE:
        return "Touchoff Enable";
    case ECMState::STATE_ECM_TOUCHOFF_EXECUTE:
        return "Touchoff Execute";
    case ECMState::STATE_UNKNOWN:
        return "Unknown";
    default:
        throw std::runtime_error("Unknown ECM state type seen");
    }
}

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_TYPES_H
