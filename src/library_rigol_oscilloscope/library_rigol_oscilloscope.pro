#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T11:35:44
#
#-------------------------------------------------

QT       -= gui
QT += core network

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
    rigol_poll_measurements.cpp \
    commands/acquire/acquire_command_average.cpp \
    commands/acquire/acquire_command_mdepth.cpp \
    commands/acquire/acquire_command_type.cpp \
    commands/acquire/acquire_command_srate.cpp \
    commands/measure/measure_command_item.cpp \
    rigol_oscilliscope.cpp \
    commands/measure/rigol_measurement_queue.cpp \
    commands/abstract_rigol_status.cpp \
    commands/measure/rigol_measurement_status.cpp

HEADERS += \
        library_rigol_oscilloscope_global.h \ 
    rigol_poll_measurements.h \
    commands/acquire/abstract_acquire_command.h \
    commands/acquire/acquire_command_average.h \
    commands/acquire/acquire_command_mdepth.h \
    commands/acquire/acquire_command_srate.h \
    commands/acquire/acquire_command_type.h \
    commands/measure/abstract_measure_command.h \
    commands/measure/measure_command_item.h \
    commands/abstract_rigol_command.h \
    communications/comms_events.h \
    communications/i_link.h \
    communications/i_link_events.h \
    communications/i_protocol.h \
    communications/i_protocol_rigol_events.h \
    communications/protocol_rigol.h \
    communications/rigol_comms_marshaler.h \
    communications/rigol_tcp_link.h \
    communications/tcp_configuration.h \
    data/type_acquire_commands.h \
    data/type_available_channels.h \
    data/type_available_commands.h \
    data/type_available_measurements.h \
    data/type_measure_commands.h \
    data/type_memory_depth.h \
    data/type_read_write.h \
    commands/acquire/acquire_command_type_options.h \
    rigol_oscilliscope.h \
    commands/measure/rigol_measurement_queue.h \
    commands/abstract_rigol_status.h \
    commands/measure/rigol_measurement_status.h \
    commands/acquire/acquire_components.h \
    commands/measure/measure_components.h \
    communications/rigol_link_configuration.h \
    rigol_version.h
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
INSTALL_PREFIX = $$(ECM_ROOT)/include/$$TARGET
INSTALL_HEADERS = $$HEADERS
include(../headerinstall.pri)

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include

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
