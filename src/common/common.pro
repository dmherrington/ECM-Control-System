#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T13:39:43
#
#-------------------------------------------------

QT       -= gui
QT += core
QT += serialport
QT += network

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
    tuple_sensor_string.cpp \
    tuple_ecm_data.cpp \
    comms/serial_configuration.cpp \
    comms/tcp_configuration.cpp \
    tuple_machine_string.cpp \
    tuple_profile_variable_string.cpp \
    tuple_positional_string.cpp \
    tuple_general_descriptor.cpp \
    modbus_register.cpp

HEADERS += common.h\
        common_global.h \
    threadmanager.h \
    timer.h \
    environment_time.h \
    class_forward.h \
    data_get_set_notifier.h \
    tuple_generic.h \
    threaded_scheduler.h \
    tuple_sensor_string.h \
    tuple_ecm_data.h \
    comms/abstract_communication.h \
    comms/communication_update.h \
    comms/communication_connection.h \
    comms/link_configuration.h \
    comms/serial_configuration.h \
    comms/tcp_configuration.h \
    ecm_devices.h \
    tuple_machine_string.h \
    tuple_profile_variable_string.h \
    tuple_positional_string.h \
    axis_definitions.h \
    hash_keys.h \
    tuple_general_descriptor.h \
    modbus_register.h

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

#Header file copy
INSTALL_PREFIX = $$(ECM_ROOT)/include/$$TARGET
INSTALL_HEADERS = $$HEADERS
include(../headerinstall.pri)
