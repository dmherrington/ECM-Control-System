#-------------------------------------------------
#
# Project created by QtCreator 2017-12-21T11:12:45
#
#-------------------------------------------------
QT += serialport
QT       -= gui

TARGET = comms_galil_setup
TEMPLATE = lib

DEFINES += COMMS_GALIL_SETUP_LIBRARY

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
        comms_galil_setup.cpp \
    comms_galil_setup.cpp \
    comms_marshaler.cpp \
    galil_link.cpp \
    protocol_galil.cpp

HEADERS += \
        comms_galil_setup.h \
        comms_galil_setup_global.h \ 
    comms_events.h \
    comms_galil_setup.h \
    comms_galil_setup_global.h \
    comms_marshaler.h \
    i_link.h \
    i_link_events.h \
    i_protocol.h \
    i_protocol_events.h \
    link_configuration.h \
    protocol_configuration.h \
    i_protocol_galil_events.h \
    galil_link.h \
    protocol_galil.h

#Header file copy
headers.path    = $$(MACE_ROOT)/include/comms_galil_setup
headers.files   += $$HEADERS
INSTALLS       += headers

# Unix lib Install
unix:!symbian {
    target.path = $$(MACE_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(MACE_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/comms_galil_setup.lib release/comms_galil_setup.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/comms_galil_setup.lib debug/comms_galil_setup.dll
INSTALLS += lib

INCLUDEPATH += $$PWD/../

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common
