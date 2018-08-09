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
    STATUS_CUSTOM_REQUEST = 0,
    STATUS_POSITION = 1,
    STATUS_AXISMOTION = 2,
    STATUS_MOTOREN = 3,
    STATUS_STOPCODE = 4,
    STATUS_SWITCH = 5,
    STATUS_TELLINPUTS = 6,
    STATUS_LABELLIST = 7,
    STATUS_VARIABLEVALUE = 8,
    STATUS_VARIABLELIST = 9
};




#endif // GALIL_STATUS_TYPES_H
