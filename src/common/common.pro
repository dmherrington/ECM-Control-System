#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T13:39:43
#
#-------------------------------------------------

QT       += gui
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
    axis_settings.cpp \
    commands/command_execute_touchoff.cpp \
    environment_time.cpp \
    tuple_sensor_string.cpp \
    tuple_ecm_data.cpp \
    comms/serial_configuration.cpp \
    comms/tcp_configuration.cpp \
    tuple_machine_string.cpp \
    tuple_profile_variable_string.cpp \
    tuple_positional_string.cpp \
    tuple_general_descriptor.cpp \
    modbus_register.cpp \
    commands/command_absolute_move.cpp \
    commands/command_clear_bit.cpp \
    commands/command_controller_gain.cpp \
    commands/command_download_program.cpp \
    commands/command_estop.cpp \
    commands/command_execute_profile.cpp \
    commands/command_jog.cpp \
    commands/command_motion_start.cpp \
    commands/command_motor_disable.cpp \
    commands/command_motor_enable.cpp \
    commands/command_relative_move.cpp \
    commands/command_set_bit.cpp \
    commands/command_speed.cpp \
    commands/command_stop.cpp \
    commands/command_upload_program.cpp \
    commands/command_variable.cpp \
    motion_profile.cpp \
    commands/abstract_axis_command.cpp \
    configs/configuration_touchoff.cpp \
    operation/operation_current.cpp \
    operation/operation_variable_list.cpp \
    operation/operation_label_list.cpp \
    commands/command_compile_buffer.cpp \
    commands/command_variable_array.cpp \
    commands/command_upload_operational_variables.cpp \
    commands/command_variable_integer.cpp

HEADERS += common.h\
    axis_settings.h \
    commands/command_execute_touchoff.h \
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
    modbus_register.h \
    common_version.h \
    hsm.h \
    abstract_device_interface.h \
    execution_properties.h \
    profile_operation_type.h \
    commands/abstract_command.h \
    commands/abstract_move_command.h \
    commands/command_absolute_move.h \
    commands/command_clear_bit.h \
    commands/command_components.h \
    commands/command_controller_gain.h \
    commands/command_download_program.h \
    commands/command_estop.h \
    commands/command_execute_profile.h \
    commands/command_jog.h \
    commands/command_motion_start.h \
    commands/command_motor_disable.h \
    commands/command_motor_enable.h \
    commands/command_relative_move.h \
    commands/command_set_bit.h \
    commands/command_speed.h \
    commands/command_stop.h \
    commands/command_types.h \
    commands/command_upload_program.h \
    commands/command_variable.h \
    type_direction.h \
    motion_profile.h \
    commands/abstract_axis_command.h \
    configs/configuration_touchoff.h \
    operation/operation_current.h \
    operation/operation_variable_list.h \
    operation/operation_label_list.h \
    commands/command_compile_buffer.h \
    operation/operation_items.h \
    commands/command_variable_array.h \
    commands/command_upload_operational_variables.h \
    notification_update.h \
    simplified_time.h \
    commands/command_variable_integer.h

#Header file copy
INSTALL_PREFIX = $$(ECM_ROOT)/include/$$TARGET
INSTALL_HEADERS = $$HEADERS
include(../headerinstall.pri)

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
