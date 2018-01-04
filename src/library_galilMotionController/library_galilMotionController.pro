#-------------------------------------------------
#
# Project created by QtCreator 2017-11-28T08:42:57
#
#-------------------------------------------------

QT       -= gui

TARGET = library_galilMotionController
TEMPLATE = lib

DEFINES += LIBRARY_GALILMOTIONCONTROLLER_LIBRARY

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
        galil_motion_controller.cpp \
        commands/command_absolute_move.cpp \
        commands/command_jog.cpp \
        commands/command_motor_disable.cpp \
        commands/command_motor_enable.cpp \
        commands/command_relative_move.cpp \
        commands/command_stop.cpp \
        galil_parse_greturn.cpp \
    settings/galil_settings.cpp \
    commands/command_set_bit.cpp \
    galil_poll_status.cpp \
    commands/command_clear_bit.cpp \
    commands/command_execute_program.cpp \
    states/state_idle.cpp \
    states/state_ready.cpp \
    states/state_jogging.cpp \
    states/state_manual_positioning.cpp \
    states/state_home_positioning.cpp \
    states/state_touchoff.cpp \
    states/state_script_execution.cpp \
    states/state_estop.cpp \
    states/state_abstract_galil.cpp \
    status/galil_status.cpp \
    states/state_motion_stop.cpp \
    states/state_ready_stop.cpp \
    requests/request_stop_code.cpp \
    requests/request_tell_position.cpp \
    requests/abstract_request.cpp \
    requests/request_tell_switches.cpp \
    requests/request_list_variables.cpp \
    requests/request_list_labels.cpp \
    status/status_switch.cpp \
    status/status_position.cpp \
    status/status_stop_code.cpp \
    galil_state_interface.cpp \
    requests/handle_requests.cpp \
    programs/program_interface.cpp \
    requests/request_tell_inputs.cpp \
    commands/command_estop.cpp \
    status/status_inputs.cpp \
    settings/settings_pinout.cpp \
    settings/settings_profile_variable.cpp \
    settings/settings_profile_gain.cpp \
    settings/settings_generic_profile.cpp \
    communications/comms_marshaler.cpp \
    communications/galil_link.cpp \
    communications/protocol_galil.cpp

HEADERS += \
        axis_definitions.h \
        galil_motion_controller.h \
        galil_parse_greturn.h \
        galil_poll_status.h \
        galil_state_interface.h \
        library_galilmotioncontroller_global.h \
        type_direction.h \
        commands/abstract_command.h \
        commands/abstract_move_command.h \
        commands/command_absolute_move.h \
        commands/command_clear_bit.h \
        commands/command_components.h \
        commands/command_estop.h \
        commands/command_execute_program.h \
        commands/command_jog.h \
        commands/command_motor_disable.h \
        commands/command_motor_enable.h \
        commands/command_relative_move.h \
        commands/command_set_bit.h \
        commands/command_stop.h \
        commands/command_types.h \
        programs/program_interface.h \
        requests/abstract_request.h \
        requests/request_components.h \
        requests/request_list_labels.h \
        requests/request_list_variables.h \
        requests/request_stop_code.h \
        requests/request_tell_inputs.h \
        requests/request_tell_position.h \
        requests/request_tell_switches.h \
        requests/request_types.h \
        settings/galil_settings.h \
        settings/settings_pinout.h \
        settings/settings_profile_variable.h \
        settings/settings_profile_gain.h \
        settings/settings_generic_profile.h \
        states/hsm.h \
        states/state_abstract_galil.h \
        states/state_components.h \
        states/state_estop.h \
        states/state_home_positioning.h \
        states/state_idle.h \
        states/state_jogging.h \
        states/state_manual_positioning.h \
        states/state_motion_stop.h \
        states/state_ready.h \
        states/state_ready_stop.h \
        states/state_script_execution.h \
        states/state_touchoff.h \
        states/state_types.h \
        status/galil_status.h \
        status/status_components.h \
        status/status_inputs.h \
        status/status_position.h \
        status/status_stop_code.h \
        status/status_switch.h \
        communications/comms_events.h \
        communications/comms_marshaler.h \
        communications/galil_link.h \
        communications/i_link.h \
        communications/i_link_events.h \
        communications/i_protocol.h \
        communications/i_protocol_galil_events.h \
        communications/protocol_galil.h


# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/library_galilMotionController.lib release/library_galilMotionController.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/library_galilMotionController.lib debug/library_galilMotionController.dll
INSTALLS += lib

#Header file copy
headers_base.path    = $$(ECM_ROOT)/include/library_galilMotionController
headers_base.files   += \
        axis_definitions.h \
        galil_motion_controller.h \
        galil_parse_greturn.h \
        galil_poll_status.h \
        galil_state_interface.h \
        library_galilmotioncontroller_global.h \
        type_direction.h
INSTALLS       += headers_base

#Header file copy
headers_communications.path    = $$(ECM_ROOT)/include/library_galilMotionController/communications
headers_communications.files   += \
        communications/comms_events.h \
        communications/comms_marshaler.h \
        communications/galil_link.h \
        communications/i_link.h \
        communications/i_link_events.h \
        communications/i_protocol.h \
        communications/i_protocol_events.h \
        communications/i_protocol_galil_events.h \
        communications/protocol_galil.h
INSTALLS       += headers_communications

#Header file copy
headers_commands.path    = $$(ECM_ROOT)/include/library_galilMotionController/commands
headers_commands.files   += \
        commands/abstract_command.h \
        commands/abstract_move_command.h \
        commands/command_absolute_move.h \
        commands/command_clear_bit.h \
        commands/command_components.h \
        commands/command_estop.h \
        commands/command_execute_program.h \
        commands/command_jog.h \
        commands/command_motor_disable.h \
        commands/command_motor_enable.h \
        commands/command_relative_move.h \
        commands/command_set_bit.h \
        commands/command_stop.h \
        commands/command_types.h
INSTALLS       += headers_commands

#Header file copy
headers_programs.path    = $$(ECM_ROOT)/include/library_galilMotionController/programs
headers_programs.files   += \
        programs/program_interface.h
INSTALLS       += headers_programs

#Header file copy
headers_requests.path    = $$(ECM_ROOT)/include/library_galilMotionController/requests
headers_requests.files   += \
        requests/abstract_request.h \
        requests/request_components.h \
        requests/request_list_labels.h \
        requests/request_list_variables.h \
        requests/request_stop_code.h \
        requests/request_tell_inputs.h \
        requests/request_tell_position.h \
        requests/request_tell_switches.h \
        requests/request_types.h
INSTALLS       += headers_requests

#Header file copy
headers_settings.path    = $$(ECM_ROOT)/include/library_galilMotionController/settings
headers_settings.files   += \
        settings/galil_settings.h \
        settings/settings_pinout.h \
        settings/settings_profile_variable.h \
        settings/settings_profile_gain.h \
        settings/settings_generic_profile.h
INSTALLS       += headers_settings

#Header file copy
headers_states.path    = $$(ECM_ROOT)/include/library_galilMotionController/states
headers_states.files   += \
        states/hsm.h \
        states/state_abstract_galil.h \
        states/state_components.h \
        states/state_estop.h \
        states/state_home_positioning.h \
        states/state_idle.h \
        states/state_jogging.h \
        states/state_manual_positioning.h \
        states/state_motion_stop.h \
        states/state_ready.h \
        states/state_ready_stop.h \
        states/state_script_execution.h \
        states/state_touchoff.h \
        states/state_types.h
INSTALLS       += headers_states

#Header file copy
headers_status.path    = $$(ECM_ROOT)/include/library_galilMotionController/status
headers_status.files   += \
        status/galil_status.h \
        status/status_components.h \
        status/status_inputs.h \
        status/status_position.h \
        status/status_stop_code.h \
        status/status_switch.h
INSTALLS       += headers_status

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/tools/galil/include/

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

unix:!macx|win32: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclib
unix:!macx|win32: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclibo

INCLUDEPATH += $$PWD/../../tools/galil/lib/dynamic/x86
DEPENDPATH += $$PWD/../../tools/galil/lib/dynamic/x86

win32: LIBS += -L$(ECM_ROOT)/tools/galil/dll/x86/ -lgclib -lgclibo
else:unix: LIBS += -L$(ECM_ROOT)/tools/galil/dll/x86/ -lgclib -lgclibo

