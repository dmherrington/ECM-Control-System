#-------------------------------------------------
#
# Project created by QtCreator 2018-08-01T10:35:03
#
#-------------------------------------------------

QT       -= gui
QT += core
QT += serialport

TARGET = library_qModBus
TEMPLATE = lib

DEFINES += LIBRARY_QMODBUS_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        library_qmodbus.cpp \
    communications/protocol_qmodbus.cpp \
    communications/qmodbus_link.cpp \
    communications/qmodbus_comms_marshaler.cpp \
    communications/qmodbus_session.cpp \
    ../../tools/libmodbus/src/modbus.c \
    ../../tools/libmodbus/src/modbus-data.c \
    ../../tools/libmodbus/src/modbus-rtu.c

HEADERS += \
        library_qmodbus.h \
        library_qmodbus_global.h \ 
    communications/comms_events.h \
    communications/i_link.h \
    communications/i_link_events.h \
    communications/i_protocol.h \
    communications/i_protocol_qmodbus_events.h \
    communications/protocol_qmodbus.h \
    communications/qmodbus_comms_marshaler.h \
    communications/qmodbus_link.h \
    communications/qmodbus_session.h
# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/library_qModBus.lib release/library_qModBus.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/library_qModBus.lib debug/library_qModBus.dll
INSTALLS += lib

#Header file copy
INSTALL_PREFIX = $$(ECM_ROOT)/include/$$TARGET
INSTALL_HEADERS = $$HEADERS
include(../headerinstall.pri)

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include

INCLUDEPATH += $$(ECM_ROOT)/tools/libmodbus
INCLUDEPATH += $$(ECM_ROOT)/tools/libmodbus/src

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../data/release/ -ldata
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../data/debug/ -ldata
else:unix:!macx: LIBS += -L$$OUT_PWD/../data/ -ldata

INCLUDEPATH += $$PWD/../data
DEPENDPATH += $$PWD/../data

win32 {
    DEFINES += _TTY_WIN_  WINVER=0x0501
    LIBS += -lsetupapi -lws2_32
}
