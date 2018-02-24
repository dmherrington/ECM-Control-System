#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T13:39:43
#
#-------------------------------------------------

QT       -= gui
QT += core

TARGET = common
TEMPLATE = lib

DEFINES += COMMON_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += common.cpp \
    environment_time.cpp \
    tuple_sensor.cpp \
    tuple_measurement.cpp

HEADERS += common.h\
        common_global.h \
    threadmanager.h \
    timer.h \
    environment_time.h \
    class_forward.h \
    data_get_set_notifier.h \
    tuple_generic.h \
    tuple_sensor.h \
    tuple_measurement.h \
    threaded_scheduler.h

#Header file copy
headers.path    = $$(ECM_ROOT)/include/common
headers.files   += $$HEADERS
INSTALLS       += headers

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/common.lib release/common.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/common.lib debug/common.dll
INSTALLS += lib

INCLUDEPATH += $$PWD/../
