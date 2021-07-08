#ifndef LIBRARY_QMODBUS_GLOBAL_H
#define LIBRARY_QMODBUS_GLOBAL_H

#include <QtCore/qglobal.h>
#include "qmodbus_version.h"

#ifdef _MSC_VER
#  if defined(LIBRARY_QMODBUS_LIBRARY)
#    define LIBRARY_QMODBUSSHARED_EXPORT __declspec(dllexport)
#  else
#    define LIBRARY_QMODBUSSHARED_EXPORT __declspec(dllexport)
#  endif
#else
#  define LIBRARY_QMODBUSSHARED_EXPORT
#endif

#endif // LIBRARY_QMODBUS_GLOBAL_H
