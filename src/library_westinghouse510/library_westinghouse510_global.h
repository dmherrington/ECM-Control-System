#ifndef LIBRARY_WESTINGHOUSE510_GLOBAL_H
#define LIBRARY_WESTINGHOUSE510_GLOBAL_H

#include <QtCore/qglobal.h>
#include "westinghouse_version.h"

#if defined(LIBRARY_WESTINGHOUSE510_LIBRARY)
#  define LIBRARY_WESTINGHOUSE510SHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBRARY_WESTINGHOUSE510SHARED_EXPORT Q_DECL_IMPORT
#endif

//#ifdef _MSC_VER
//#  if defined(LIBRARY_WESTINGHOUSE510_LIBRARY)
//#    define LIBRARY_WESTINGHOUSE510SHARED_EXPORT __declspec(dllexport)
//#  else
//#    define LIBRARY_WESTINGHOUSE510SHARED_EXPORT __declspec(dllexport)
//#  endif
//#else
//#  define LIBRARY_WESTINGHOUSE510SHARED_EXPORT
//#endif

#endif // LIBRARY_WESTINGHOUSE510_GLOBAL_H
