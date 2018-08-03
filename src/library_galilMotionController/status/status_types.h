#ifndef GALIL_STATUS_TYPES_H
#define GALIL_STATUS_TYPES_H

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
    STATUS_POSITION = 0,
    STATUS_AXISMOTION = 1,
    STATUS_MOTOREN = 2,
    STATUS_STOPCODE = 3,
    STATUS_SWITCH = 4,
    STATUS_TELLINPUTS = 5,
    STATUS_LABELLIST = 6,
    STATUS_VARIABLEVALUE = 7,
    STATUS_VARIABLELIST = 8
};




#endif // GALIL_STATUS_TYPES_H
