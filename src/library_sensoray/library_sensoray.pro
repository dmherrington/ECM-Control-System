#-------------------------------------------------
#
# Project created by QtCreator 2018-03-01T13:30:55
#
#-------------------------------------------------

QT       -= gui
QT += core network serialport

unix {
DEFINES += OSTYPE_LINUX
}
win32 {
DEFINES += OSTYPE_WINDOWS
}

TARGET = library_sensoray
TEMPLATE = lib

DEFINES += LIBRARY_SENSORAY_LIBRARY

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
        sensoray.cpp \
    communications/protocol_sensoray.cpp \
    communications/sensoray_comms_marshaler.cpp \
    communications/sensoray_tcp_configuration.cpp \
    communications/sensoray_link.cpp

HEADERS += \
        sensoray.h \
        library_sensoray_global.h \ 
    communications/comms_events.h \
    communications/i_link.h \
    communications/i_link_events.h \
    communications/i_protocol.h \
    communications/i_protocol_sensoray_events.h \
    communications/protocol_sensoray.h \
    communications/sensoray_comms_marshaler.h \
    communications/sensoray_tcp_configuration.h \
    communications/sensoray_session.h \
    communications/sensoray_serial_configuration.h \
    communications/sensoray_link.h

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/library_sensoray.lib release/library_sensoray.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/library_sensoray.lib debug/library_sensoray.dll
INSTALLS += lib

#Header file copy
headers_base.path    = $$(ECM_ROOT)/include/library_sensoray
headers_base.files   += \
        sensoray.h \
        library_sensoray_global.h
INSTALLS       += headers_base

#Header file copy
headers_communications.path    = $$(ECM_ROOT)/include/library_sensoray/communications
headers_communications.files   += \
    communications/comms_events.h \
    communications/i_link.h \
    communications/i_link_events.h \
    communications/i_protocol.h \
    communications/i_protocol_sensoray_events.h \
    communications/protocol_sensoray.h \
    communications/sensoray_comms_marshaler.h \
    communications/sensoray_link.h \
    communications/serial_configuration.h \
    communications/sensoray_session.h \
    communications/sensoray_tcp_configuration.h \
INSTALLS       += headers_communications


INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include
INCLUDEPATH += $$(ECM_ROOT)/tools/sensoray/lib/

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

#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../tools/sensoray/lib/ -ls24xx
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../tools/sensoray/lib/ -ls24xx
#else:unix:!macx: LIBS += -L$$PWD/../../tools/sensoray/lib/ -ls24xx

#INCLUDEPATH += $$PWD/../../tools/sensoray/lib
#DEPENDPATH += $$PWD/../../tools/sensoray/lib

#win32: LIBS += -L$$PWD/../../tools/sensoray/lib/s24xx.lib
#INCLUDEPATH += $$PWD/../../tools/sensoray
#DEPENDPATH += $$PWD/../../tools/sensoray


#INCLUDEPATH += $$PWD/../../tools/sensoray
#DEPENDPATH += $$PWD/../../tools/sensoray
#win32: LIBS += -ls24xx


unix:!macx|win32: LIBS += -L$$PWD/../../tools/sensoray/lib/ -ls24xx

INCLUDEPATH += $$PWD/../../tools/sensoray/include
DEPENDPATH += $$PWD/../../tools/sensoray/include
