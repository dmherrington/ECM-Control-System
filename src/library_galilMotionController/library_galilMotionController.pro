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
    command_jog.cpp \
    command_relative_move.cpp \
    command_absolute_move.cpp \
    command_motor_enable.cpp \
    command_motor_disable.cpp

HEADERS += \
        galil_motion_controller.h \
        library_galilmotioncontroller_global.h \ 
    command_jog.h \
    abstract_command.h \
    command_relative_move.h \
    abstract_move_command.h \
    command_absolute_move.h \
    type_direction.h \
    command_types.h \
    command_motor_enable.h \
    command_motor_disable.h \
    axis_definitions.h

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
headers.path    = $$(ECM_ROOT)/include/library_galilMotionController
headers.files   += $$HEADERS
INSTALLS       += headers
