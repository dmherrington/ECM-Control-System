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
        commands/command_tell_position.cpp \
        commands/command_stop.cpp \
        galil_parse_greturn.cpp \
    settings/galil_settings.cpp \
    settings/settings_manual_profile.cpp \
    settings/settings_vibration_profile.cpp \
    settings/settings_linear_profile.cpp \
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
    states/state_stop.cpp \
    states/state_estop.cpp

HEADERS += \
        galil_motion_controller.h \
        library_galilmotioncontroller_global.h \ 
        type_direction.h \
        axis_definitions.h \
        commands/abstract_command.h \
        commands/abstract_move_command.h \
        commands/command_absolute_move.h \
        commands/command_jog.h \
        commands/command_motor_disable.h \
        commands/command_motor_enable.h \
        commands/command_relative_move.h \
        commands/command_types.h \
        commands/command_tell_position.h \
        commands/command_stop.h \
        galil_state_definition.h \
        galil_parse_greturn.h \
        settings/galil_settings.h \
        settings/settings_manual_profile.h \
        settings/settings_vibration_profile.h \
        settings/settings_linear_profile.h \
    commands/command_components.h \
    commands/command_set_bit.h \
    galil_poll_status.h \
    commands/command_clear_bit.h \
    commands/command_execute_program.h \
    states/abstract_command.h \
    states/state_idle.h \
    states/state_ready.h \
    states/state_jogging.h \
    states/state_manual_positioning.h \
    states/state_home_positioning.h \
    states/state_touchoff.h \
    states/state_script_execution.h \
    states/state_stop.h \
    states/state_estop.h \
    states/hsm.h

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
headers_base.path    = $$(ECM_ROOT)/include/library_galilMotionController/base
headers_base.files   += \
        galil_motion_controller.h \
        library_galilmotioncontroller_global.h \
        type_direction.h \
        axis_definitions.h \
        galil_state_machine.h \
INSTALLS       += headers_base

#Header file copy
headers_settings.path    = $$(ECM_ROOT)/include/library_galilMotionController/settings
headers_settings.files   += \
        settings/galil_settings.h \
        settings/settings_manual_profile.h \
        settings/settings_vibration_profile.h \
        settings/settings_linear_profile.h
INSTALLS       += headers_settings

#Header file copy
headers_commands.path    = $$(ECM_ROOT)/include/library_galilMotionController/commands
headers_commands.files   += \
        commands/abstract_command.h \
        commands/abstract_move_command.h \
        commands/command_absolute_move.h \
        commands/command_jog.h \
        commands/command_motor_disable.h \
        commands/command_motor_enable.h \
        commands/command_relative_move.h \
        commands/command_types.h
INSTALLS       += headers_commands

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/tools/galil/include/

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

unix:!macx|win32: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclib
unix:!macx|win32: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclibo

INCLUDEPATH += $$PWD/../../tools/galil/lib/dynamic/x86
DEPENDPATH += $$PWD/../../tools/galil/lib/dynamic/x86

