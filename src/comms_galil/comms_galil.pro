#-------------------------------------------------
#
# Project created by QtCreator 2017-12-21T11:08:16
#
#-------------------------------------------------

QT       -= gui
QT += core serialport

TARGET = comms_galil
TEMPLATE = lib

DEFINES += COMMS_GALIL_LIBRARY

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
        comms_galil.cpp

HEADERS += \
        comms_galil.h \
        comms_galil_global.h  

#Header file copy
headers.path    = $$(ECM_ROOT)/include/comms_galil
headers.files   += $$HEADERS
INSTALLS       += headers

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(MACE_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/comms_galil.lib release/comms_galil.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/comms_galil.lib debug/comms_galil.dll
INSTALLS += lib

INCLUDEPATH += $$PWD/../

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../comms_galil_setup/release/ -lcomms_galil_setup
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../comms_galil_setup/debug/ -lcomms_galil_setup
else:unix:!macx: LIBS += -L$$OUT_PWD/../comms_galil_setup/ -lcomms_galil_setup

INCLUDEPATH += $$PWD/../comms_galil_setup
DEPENDPATH += $$PWD/../comms_galil_setup
