#ifndef STATE_ECM_TYPES_H
#define STATE_ECM_TYPES_H

#include <string>
#include <vector>
#include <stdexcept>

/**
\* @file  state_ecm_touchoff.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*  This state class defines the machine in the idle state. The machine should transition to this state when the motor was disabled
\* via standard user command or at the completion of machining.
\*  While in this state, we can accept commands to download/upload programs from galil, load parameters and settigns from files,
\* save files, etc.
\*/

namespace ECM{
namespace API {

enum class ECMState{
    STATE_ECM_IDLE = 0, /**< */
    STATE_ECM_MOTION_PROFILE_INITIALIZATION = 1, /**< */
    STATE_ECM_PROFILE_MACHINE = 2, /**< */
    STATE_ECM_PROFILE_MACHINE_ABORT = 3, /**< */
    STATE_ECM_PROFILE_MACHINE_COMPLETE = 4, /**< */
    STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION = 5, /**< */
    STATE_ECM_PROFILE_MACHINE_FAILED = 6, /**< */
    STATE_ECM_PROFILE_MACHINE_PROCESS = 7, /**< */
    STATE_ECM_SETUP_MACHINE = 10, /**< */
    STATE_ECM_SETUP_MACHINE_COMPLETE = 11, /**< */
    STATE_ECM_SETUP_MACHINE_FAILED = 12, /**< */
    STATE_ECM_SETUP_MACHINE_HOME = 13, /**< */
    STATE_ECM_SETUP_MACHINE_PUMP = 14, /**< */
    STATE_ECM_SETUP_MACHINE_TOUCHOFF = 15, /**< */
    STATE_ECM_UPLOAD = 20, /**< */
    STATE_ECM_UPLOAD_COMPLETE = 21, /**< */
    STATE_ECM_UPLOAD_FAILED = 22, /**< */
    STATE_ECM_UPLOAD_MOTION_PROFILE = 23, /**< */
    STATE_ECM_UPLOAD_MOTION_VARIABLES = 24, /**< */
    STATE_ECM_UPLOAD_POWER_PULSE_MODE = 25, /**< */
    STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS = 26, /**< */
    STATE_ECM_UPLOAD_PUMP_PARAMETERS = 27, /**< */
    STATE_UNKNOWN = 100 /**< */
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
    case ECMState::STATE_ECM_MOTION_PROFILE_INITIALIZATION:
        return "Machine Initialization";

    case ECMState::STATE_ECM_PROFILE_MACHINE:
        return "Profile Machining";
    case ECMState::STATE_ECM_PROFILE_MACHINE_ABORT:
        return "Profile Machining Cease";
    case ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE:
        return "Profile Machining Complete";
    case ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION:
        return "Profile Machining Complete Execution";
    case ECMState::STATE_ECM_PROFILE_MACHINE_FAILED:
        return "Profile Machining Failed";
    case ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS:
        return "Profile Machining Process";

    case ECMState::STATE_ECM_SETUP_MACHINE:
        return "Machine Setup";
    case ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE:
        return "Machine Setup Complete";
    case ECMState::STATE_ECM_SETUP_MACHINE_FAILED:
        return "Machine Setup Failed";
    case ECMState::STATE_ECM_SETUP_MACHINE_HOME:
        return "Machine Setup Home";
    case ECMState::STATE_ECM_SETUP_MACHINE_PUMP:
        return "Machine Setup Pump";
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF:
        return "Machine Setup Touchoff";

    case ECMState::STATE_ECM_UPLOAD:
        return "Machine Initialization";
    case ECMState::STATE_ECM_UPLOAD_COMPLETE:
        return "Machine Upload Complete";
    case ECMState::STATE_ECM_UPLOAD_FAILED:
        return "Machine Upload Failed";
    case ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE:
        return "Machine Upload Motion Profile";
    case ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES:
        return "Machine Upload Motion Variables";
    case ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE:
        return "Machine Upload Pulse Mode";
    case ECMState::STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS:
        return "Machine Upload Power Register";
    case ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS:
        return "Machine Upload Pump Parameters";


    case ECMState::STATE_UNKNOWN:
        return "Unknown";
    default:
        throw std::runtime_error("Unknown ECM state type seen");
    }
}

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_TYPES_H
