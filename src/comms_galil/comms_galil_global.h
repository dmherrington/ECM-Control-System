#ifndef COMMS_GALIL_GLOBAL_H
#define COMMS_GALIL_GLOBAL_H

#ifdef _MSC_VER
#  if defined(COMMS_GALIL_LIBRARY)
#    define COMMS_GALILSHARED_EXPORT __declspec(dllexport)
#  else
#    define COMMS_GALILSHARED_EXPORT __declspec(dllexport)
#  endif
#else
#  define COMMS_GALILSHARED_EXPORT
#endif

#endif // COMMS_GALIL_GLOBAL_H
