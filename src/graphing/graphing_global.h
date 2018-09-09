#ifndef GRAPHING_GLOBAL_H
#define GRAPHING_GLOBAL_H

#include "graphing_version.h"

#ifdef _MSC_VER
#  if defined(GRAPHING_LIBRARY)
#    define GRAPHINGSHARED_EXPORT __declspec(dllexport)
#  else
#    define GRAPHINGSHARED_EXPORT __declspec(dllexport)
#  endif
#else
#  define GRAPHINGSHARED_EXPORT
#endif


#endif // GRAPHING_GLOBAL_H
