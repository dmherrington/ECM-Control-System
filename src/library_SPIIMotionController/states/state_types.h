#ifndef STATE_TYPES_H
#define STATE_TYPES_H

#include <string>
#include <vector>
#include <stdexcept>


namespace ECM{
namespace SPII {

enum class SPIIState{
    STATE_ESTOP = 1, /**< */
    STATE_HOME_POSITIONING = 2, /**< */
    STATE_HOMING_ROUTINE = 3, /**< */
    STATE_IDLE = 4, /**< */
    STATE_JOGGING = 5, /**< */
    STATE_MANUAL_POSITIONING = 6, /**< */
    STATE_MOTION_STOP = 7, /**< */
    STATE_READY = 8, /**< */
    STATE_READY_STOP = 9, /**< */
    STATE_SCRIPT_EXECUTION = 10, /**< */
    STATE_TOUCHOFF = 11, /**< */
    STATE_UNKNOWN = 12 /**< */
};

//!
//! \brief CommandToString
//! \param type
//! \return
//!
inline std::string ECMStateToString(const SPIIState &type) {
    switch (type) {
    case SPIIState::STATE_ESTOP:
        return "Emergency Stop";
    case SPIIState::STATE_HOME_POSITIONING:
        return "Moving Home";
    case SPIIState::STATE_HOMING_ROUTINE:
        return "Finding Home";
    case SPIIState::STATE_IDLE:
        return "Idle";
    case SPIIState::STATE_JOGGING:
        return "Jogging";
    case SPIIState::STATE_MANUAL_POSITIONING:
        return "Manual";
    case SPIIState::STATE_READY:
        return "Ready";
    case SPIIState::STATE_READY_STOP:
        return "Ready Stop";
    case SPIIState::STATE_SCRIPT_EXECUTION:
        return "Script Execution";
    case SPIIState::STATE_MOTION_STOP:
        return "Stopping";
    case SPIIState::STATE_TOUCHOFF:
        return "Touchoff";
    case SPIIState::STATE_UNKNOWN:
        return "Unknown";
    default:
        throw std::runtime_error("Unknown Galil state type seen");
    }
}

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_TYPES_H
