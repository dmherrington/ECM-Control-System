#ifndef LIBRARY_PLC_GLOBAL_H
#define LIBRARY_PLC_GLOBAL_H

#include "plc_version.h"

#ifdef _MSC_VER
#  if defined(LIBRARY_PLC_LIBRARY)
#    define LIBRARY_PLCSHARED_EXPORT __declspec(dllexport)
#  else
#    define LIBRARY_PLCSHARED_EXPORT __declspec(dllexport)
#  endif
#else
#  define LIBRARY_PLCSHARED_EXPORT
#endif


#endif // LIBRARY_PLC_GLOBAL_H
