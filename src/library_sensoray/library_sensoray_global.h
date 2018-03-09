#ifndef LIBRARY_SENSORAY_GLOBAL_H
#define LIBRARY_SENSORAY_GLOBAL_H

#ifdef _MSC_VER
#  if defined(LIBRARY_SENSORAY_LIBRARY)
#    define LIBRARY_SENSORAYSHARED_EXPORT __declspec(dllexport)
#  else
#    define LIBRARY_SENSORAYSHARED_EXPORT __declspec(dllexport)
#  endif
#else
#  define LIBRARY_SENSORAYSHARED_EXPORT
#endif

#endif // LIBRARY_SENSORAY_GLOBAL_H
