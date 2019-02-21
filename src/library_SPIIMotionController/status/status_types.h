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

namespace SPII {

enum class StatusTypes{
    STATUS_CUSTOM_REQUEST = 0,
    STATUS_POSITION = 1,
    STATUS_POSITION_PER_AXIS = 2,
    STATUS_PER_MOTOR_AXIS = 3,
    STATUS_ALL_MOTOR_AXIS = 4,
    STATUS_PER_AXIS = 5,
    STATUS_ALL_AXIS = 6,
    STATUS_STOPCODE = 7,
    STATUS_SWITCH = 8,
    STATUS_TELLINPUTS = 9,
    STATUS_LABELLIST = 10,
    STATUS_VARIABLEVALUE = 11,
    STATUS_VARIABLELIST = 12
};

} //end of namespace SPII


#endif // GALIL_STATUS_TYPES_H
