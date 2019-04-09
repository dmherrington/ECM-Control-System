#ifndef SPII_STATUS_TYPES_H
#define SPII_STATUS_TYPES_H

#include <vector>
#include <string>
#include <stdexcept>

/**
\* @file  status_types.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

enum class StatusTypes{
    STATUS_CUSTOM_REQUEST,
    STATUS_POSITION,
    STATUS_POSITION_PER_AXIS,
    STATUS_PER_MOTOR_AXIS,
    STATUS_ALL_MOTOR_AXIS,
    STATUS_PER_AXIS,
    STATUS_ALL_AXIS,
    STATUS_MOTOR_FAULTS_PER_AXIS,
    STATUS_MOTOR_FAULTS,
    STATUS_SYSTEM_FAULTS,
    STATUS_STOPCODE,
    STATUS_SWITCH,
    STATUS_TELLINPUTS,
    STATUS_LABELLIST,
    STATUS_VARIABLEVALUE,
    STATUS_VARIABLELIST,
    STATUS_BUFFERSTATE
};

#endif // GALIL_STATUS_TYPES_H
