#ifndef LIBRARY_GALILMOTIONCONTROLLER_GLOBAL_H
#define LIBRARY_GALILMOTIONCONTROLLER_GLOBAL_H

#include "galil_version.h"

#ifdef _MSC_VER
#  if defined(LIBRARY_GALILMOTIONCONTROLLER_LIBRARY)
#    define GMC_SHARED_EXPORT __declspec(dllexport)
#  else
#    define GMC_SHARED_EXPORT __declspec(dllexport)
#  endif
#else
#  define GMC_SHARED_EXPORT
#endif

#endif // LIBRARY_GALILMOTIONCONTROLLER_GLOBAL_H
