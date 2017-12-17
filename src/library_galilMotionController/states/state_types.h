#ifndef STATE_TYPES_H
#define STATE_TYPES_H

#include <string>
#include <vector>
#include <stdexcept>


namespace ECM{
namespace Galil {

enum class ECMState{
    STATE_ESTOP = 1, /**< */
    STATE_HOME_POSITIONING = 2, /**< */
    STATE_IDLE = 3, /**< */
    STATE_JOGGING = 4, /**< */
    STATE_MANUAL_POSITIONING = 5, /**< */
    STATE_MOTION_STOP = 6, /**< */
    STATE_READY = 7, /**< */
    STATE_READY_STOP = 8, /**< */
    STATE_SCRIPT_EXECUTION = 9, /**< */
    STATE_TOUCHOFF = 10, /**< */
    STATE_UNKNOWN = 11 /**< */
};

//!
//! \brief CommandToString
//! \param type
//! \return
//!
inline std::string ECMStateToString(const ECMState &type) {
    switch (type) {
    case ECMState::STATE_ESTOP:
        return "Emergency Stop";
    case ECMState::STATE_HOME_POSITIONING:
        return "Moving Home";
    case ECMState::STATE_IDLE:
        return "Idle";
    case ECMState::STATE_JOGGING:
        return "Jogging";
    case ECMState::STATE_MANUAL_POSITIONING:
        return "Manual";
    case ECMState::STATE_READY:
        return "Ready";
    case ECMState::STATE_SCRIPT_EXECUTION:
        return "Script Execution";
    case ECMState::STATE_MOTION_STOP:
        return "Stopping";
    case ECMState::STATE_TOUCHOFF:
        return "Touchoff";
    case ECMState::STATE_UNKNOWN:
        return "Unknown";
    default:
        throw std::runtime_error("Unknown state type seen");
    }
}

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_TYPES_H
