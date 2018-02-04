#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T11:35:44
#
#-------------------------------------------------

QT       -= gui
QT += network

TARGET = library_rigol_oscilloscope
TEMPLATE = lib

DEFINES += LIBRARY_RIGOL_OSCILLOSCOPE_LIBRARY

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
    communications/rigol_tcp_link.cpp \
    communications/tcp_configuration.cpp \
    communications/rigol_comms_marshaler.cpp \
    communications/protocol_rigol.cpp \
    commands/acquire/abstract_acquire_command.cpp \
    rigol_poll_measurements.cpp

HEADERS += \
        library_rigol_oscilloscope_global.h \ 
    communications/comms_events.h \
    communications/i_link.h \
    communications/i_link_events.h \
    communications/i_protocol.h \
    communications/i_protocol_rigol_events.h \
    communications/link_configuration.h \
    communications/protocol_rigol.h \
    communications/rigol_comms_marshaler.h \
    communications/rigol_tcp_link.h \
    communications/tcp_configuration.h \
    data/i_link.h \
    data/type_available_measurements.h \
    data/type_available_channels.h \
    commands/acquire/i_link.h \
    commands/measure/i_link.h \
    commands/acquire/abstract_acquire_command.h \
    data/type_acquire_commands.h \
    rigol_poll_measurements.h

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/library_rigol_oscilloscope.lib release/library_rigol_oscilloscope.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/library_rigol_oscilloscope.lib debug/library_rigol_oscilloscope.dll
INSTALLS += lib

#Header file copy
headers_communications.path    = $$(ECM_ROOT)/include/library_rigol_oscilloscope/communications
headers_communications.files   += \
    communications/comms_events.h \
    communications/i_link.h \
    communications/i_link_events.h \
    communications/i_protocol.h \
    communications/i_protocol_rigol_events.h \
    communications/link_configuration.h \
    communications/protocol_rigol.h \
    communications/rigol_comms_marshaler.h \
    communications/rigol_tcp_link.h \
    communications/tcp_configuration.h
INSTALLS       += headers_communications

INCLUDEPATH += $$PWD/../

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

