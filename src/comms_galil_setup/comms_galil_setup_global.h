#ifndef COMMS_GALIL_SETUP_GLOBAL_H
#define COMMS_GALIL_SETUP_GLOBAL_H

#ifdef _MSC_VER
#  if defined(COMMS_GALIL_SETUP_LIBRARY)
#    define COMMS_GALIL_SETUPSHARED_EXPORT  __declspec(dllexport)
#  else
#    define COMMS_GALIL_SETUPSHARED_EXPORT  __declspec(dllimport)
#  endif
#else
#  define COMMS_GALIL_SETUPSHARED_EXPORT
#endif

#include <stdint.h>

#endif // COMMS_GALIL_SETUP_GLOBAL_H
