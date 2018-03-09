#ifndef DATA_GLOBAL_H
#define DATA_GLOBAL_H

#ifndef Export
#  ifdef WIN32
#    if DATA_LIBRARY
#      define Export __declspec(dllexport)
#    else
#      define Export __declspec(dllimport)
#    endif
#  else
#    define Export
#  endif
#endif

#endif // DATA_GLOBAL_H
