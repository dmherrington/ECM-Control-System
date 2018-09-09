#ifndef LIBRARY_MUNK_POWER_SUPPLY_GLOBAL_H
#define LIBRARY_MUNK_POWER_SUPPLY_GLOBAL_H

#include "munk_version.h"

#ifdef _MSC_VER
#  if defined(LIBRARY_MUNK_POWER_SUPPLY_LIBRARY)
#    define LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT __declspec(dllexport)
#  else
#    define LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT __declspec(dllexport)
#  endif
#else
#  define LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT
#endif

#endif // LIBRARY_MUNK_POWER_SUPPLY_GLOBAL_H
