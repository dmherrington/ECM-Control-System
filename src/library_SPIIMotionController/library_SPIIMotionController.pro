#-------------------------------------------------
#
# Project created by QtCreator 2019-01-29T19:40:58
#
#-------------------------------------------------

QT       -= gui
QT += core
QT += serialport
QT += network

TARGET = library_SPIIMotionController
TEMPLATE = lib

DEFINES += LIBRARY_SPIIMOTIONCONTROLLER_LIBRARY

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
        spii_motion_controller.cpp \
    communications/comms_marshaler.cpp \
    communications/protocol_SPII.cpp \
    communications/SPII_link.cpp \
    states/state_estop.cpp \
    states/state_home_positioning.cpp \
    states/state_idle.cpp \
    states/state_jogging.cpp \
    states/state_manual_positioning.cpp \
    states/state_motion_stop.cpp \
    states/state_ready.cpp \
    states/state_ready_stop.cpp \
    states/state_script_execution.cpp \
    states/state_stop.cpp \
    states/state_touchoff.cpp \
    status/abstract_status.cpp \
    status/status_inputs.cpp \
    status/status_position.cpp \
    status/status_motor.cpp \
    status/status_axis.cpp \
    states/state_abstract_spii.cpp \
    spii_state_interface.cpp \
    buffers/spii_buffer_manager.cpp \
    buffers/buffer_data.cpp

HEADERS += \
        spii_motion_controller.h \
        library_spiimotioncontroller_global.h \ 
    spii_version.h \
    communications/comms_events.h \
    communications/comms_marshaler.h \
    communications/i_link.h \
    communications/i_link_events.h \
    communications/i_protocol.h \
    communications/i_protocol_SPII_events.h \
    communications/protocol_SPII.h \
    communications/SPII_link.h \
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
    states/state_stop.h \
    states/state_touchoff.h \
    states/state_types.h \
    status/abstract_status.h \
    status/status_components.h \
    status/status_inputs.h \
    status/status_position.h \
    status/status_switch.h \
    status/status_types.h \
    states/state_abstract_spii.h \
    status/status_axis.h \
    status/status_motor.h \
    spii_state_interface.h \
    buffers/spii_buffer_manager.h \
    buffers/buffer_data.h

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/library_SPIIMotionController.lib release/library_SPIIMotionController.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/library_SPIIMotionController.lib debug/library_SPIIMotionController.dll
INSTALLS += lib

#Header file copy
INSTALL_PREFIX = $$(ECM_ROOT)/include/$$TARGET
INSTALL_HEADERS = $$HEADERS
include(../headerinstall.pri)

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common

unix:!macx|win32: LIBS += -L$$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP/ -lACSCL_x86

INCLUDEPATH += $$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP
DEPENDPATH += $$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP
