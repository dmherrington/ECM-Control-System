#-------------------------------------------------
#
# Project created by QtCreator 2018-02-25T10:47:35
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += network
QT       += widgets

unix {
DEFINES += OSTYPE_LINUX
}
win32 {
DEFINES += OSTYPE_WINDOWS
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
}

lessThan(QT_MAJOR_VERSION, 5) {
    CONFIG += designer
}

unix:QMAKE_CXXFLAGS += -std=gnu++0x

TARGET = ECM_gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QCUSTOMPLOT_USE_LIBRARY

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    misc_dialogs/code_edit_widget.cpp \
    misc_dialogs/table_widget_operation_descriptor.cpp \
    misc_dialogs/widget_device_fault.cpp \
    misc_dialogs/widget_profile_parameters.cpp \
    misc_dialogs/window_custom_motion_commands.cpp \
    misc_dialogs/window_device_connections.cpp \
    misc_dialogs/window_profile_configuration.cpp \
    munk_dialog/widget_munk_power_supply.cpp \
    munk_dialog/widget_segment_time_data.cpp \
    munk_dialog/widget_segment_time_display.cpp \
    pump_dialog/widget_pump_control.cpp \
    rigol_dialog/widget_rigol_radio.cpp \
    rigol_dialog/window_rigol_control.cpp \
    SensorDisplay/collection_displays.cpp \
    SensorDisplay/display_ampere_area.cpp \
    SensorDisplay/display_base_plot_instantaneous.cpp \
    SensorDisplay/display_voltage.cpp \
    additional_sensor_display.cpp \
    ECM_controller_gui.cpp \
    ECM_plot_collection.cpp \
    ECM_plot_identifier.cpp \
    general_dialog_window.cpp \
    LED.cpp \
    main.cpp \
    plot_central.cpp \
    pump_dialog/window_pump_control.cpp \
    misc_dialogs/widget_pause_parameters.cpp \
    acs_dialog/dialog_execution_paused.cpp \
    acs_dialog/widget_scripting_variables.cpp \
    acs_dialog/widget_touchoff.cpp \
    acs_dialog/window_motion_control.cpp \
    acs_dialog/window_touchoff.cpp \
    acs_dialog/widget_buffer_editor.cpp \
    acs_dialog/window_buffer_manager.cpp \
    acs_dialog/widget_buffer_descriptor.cpp \
    motion_dialog/widget_front_panel_motion_control.cpp \
    motion_dialog/widget_front_panel_touchoff.cpp \
    motion_dialog/widget_front_panel_axis_motion_control.cpp \
    motion_dialog/widget_axis_vertical_control.cpp \
    motion_dialog/widget_axis_horizontal_control.cpp \
    acs_dialog/widget_variable_descriptor.cpp \
    misc_dialogs/widget_detailed_notification.cpp \
    misc_dialogs/window_notifications.cpp \
    misc_dialogs/widget_notification.cpp

HEADERS += \
    misc_dialogs/code_edit_widget.h \
    misc_dialogs/table_widget_operation_descriptor.h \
    misc_dialogs/widget_device_fault.h \
    misc_dialogs/widget_profile_parameters.h \
    misc_dialogs/window_custom_motion_commands.h \
    misc_dialogs/window_device_connections.h \
    misc_dialogs/window_profile_configuration.h \
    munk_dialog/widget_munk_power_supply.h \
    munk_dialog/widget_segment_time_data.h \
    munk_dialog/widget_segment_time_display.h \
    pump_dialog/widget_pump_control.h \
    rigol_dialog/widget_rigol_radio.h \
    rigol_dialog/window_rigol_control.h \
    SensorDisplay/collection_displays.h \
    SensorDisplay/display_ampere_area.h \
    SensorDisplay/display_base_plot_instantaneous.h \
    SensorDisplay/display_voltage.h \
    SensorDisplay/I_sensor_display.h \
    additional_sensor_display.h \
    ECM_controller_gui.h \
    ECM_plot_collection.h \
    ECM_plot_identifier.h \
    general_dialog_window.h \
    gui_verison.h \
    LED.h \
    plot_central.h \
    pump_dialog/window_pump_control.h \
    misc_dialogs/widget_abstract_profile.h \
    misc_dialogs/widget_pause_parameters.h \
    acs_dialog/dialog_execution_paused.h \
    acs_dialog/widget_scripting_variables.h \
    acs_dialog/widget_touchoff.h \
    acs_dialog/window_motion_control.h \
    acs_dialog/window_touchoff.h \
    acs_dialog/widget_buffer_editor.h \
    acs_dialog/window_buffer_manager.h \
    acs_dialog/widget_buffer_descriptor.h \
    motion_dialog/widget_front_panel_motion_control.h \
    motion_dialog/widget_front_panel_touchoff.h \
    motion_dialog/widget_front_panel_axis_motion_control.h \
    motion_dialog/widget_axis_vertical_control.h \
    motion_dialog/widget_axis_horizontal_control.h \
    motion_dialog/widget_abstract_axis_control.h \
    acs_dialog/widget_variable_descriptor.h \
    misc_dialogs/widget_detailed_notification.h \
    misc_dialogs/window_notifications.h \
    misc_dialogs/widget_notification.h

FORMS += \
    misc_dialogs/table_widget_operation_descriptor.ui \
    misc_dialogs/window_custom_motion_commands.ui \
    misc_dialogs/widget_device_fault.ui \
    misc_dialogs/window_device_connections.ui \
    misc_dialogs/window_profile_configuration.ui \
    munk_dialog/widget_munk_power_supply.ui \
    misc_dialogs/widget_profile_parameters.ui \
    munk_dialog/widget_segment_time_data.ui \
    munk_dialog/widget_segment_time_display.ui \
    pump_dialog/widget_pump_control.ui \
    rigol_dialog/window_rigol_control.ui \
    rigol_dialog/widget_rigol_radio.ui \
    SensorDisplay/display_base_plot_instantaneous.ui \
    additional_sensor_display.ui \
    ECM_controller_gui.ui \
    pump_dialog/window_pump_control.ui \
    misc_dialogs/widget_pause_parameters.ui \
    acs_dialog/dialog_execution_paused.ui \
    acs_dialog/widget_scripting_variables.ui \
    acs_dialog/widget_touchoff.ui \
    acs_dialog/window_motion_control.ui \
    acs_dialog/window_touchoff.ui \
    acs_dialog/widget_buffer_editor.ui \
    acs_dialog/window_buffer_manager.ui \
    acs_dialog/widget_buffer_descriptor.ui \
    motion_dialog/widget_front_panel_motion_control.ui \
    motion_dialog/widget_front_panel_touchoff.ui \
    motion_dialog/widget_front_panel_axis_motion_control.ui \
    motion_dialog/widget_axis_vertical_control.ui \
    motion_dialog/widget_axis_horizontal_control.ui \
    acs_dialog/widget_variable_descriptor.ui \
    misc_dialogs/widget_detailed_notification.ui \
    misc_dialogs/window_notifications.ui \
    misc_dialogs/widget_notification.ui

#Header file copy
INSTALL_PREFIX = $$(ECM_ROOT)/include/$$TARGET
INSTALL_HEADERS = $$HEADERS
include(../headerinstall.pri)

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include
INCLUDEPATH += $$(ECM_ROOT)/tools/galil/include/
INCLUDEPATH += $$(ECM_ROOT)/tools/sensoray/lib/
INCLUDEPATH += $$(ECM_ROOT)/tools/libmodbus
INCLUDEPATH += $$(ECM_ROOT)/tools/libmodbus/src

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../graphing/release/ -lgraphing
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../graphing/debug/ -lgraphing
else:unix:!macx: LIBS += -L$$OUT_PWD/../graphing/ -lgraphing

INCLUDEPATH += $$PWD/../graphing
DEPENDPATH += $$PWD/../graphing

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_munk_power_supply/release/ -llibrary_munk_power_supply
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_munk_power_supply/debug/ -llibrary_munk_power_supply
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_munk_power_supply/ -llibrary_munk_power_supply

INCLUDEPATH += $$PWD/../library_munk_power_supply
DEPENDPATH += $$PWD/../library_munk_power_supply

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/release/ -llibrary_rigol_oscilloscope
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/debug/ -llibrary_rigol_oscilloscope
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/ -llibrary_rigol_oscilloscope

INCLUDEPATH += $$PWD/../library_rigol_oscilloscope
DEPENDPATH += $$PWD/../library_rigol_oscilloscope

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_qModBus/release/ -llibrary_qModBus
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_qModBus/debug/ -llibrary_qModBus
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_qModBus/ -llibrary_qModBus

INCLUDEPATH += $$PWD/../library_qModBus
DEPENDPATH += $$PWD/../library_qModBus

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_westinghouse510/release/ -llibrary_westinghouse510
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_westinghouse510/debug/ -llibrary_westinghouse510
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_westinghouse510/ -llibrary_westinghouse510

INCLUDEPATH += $$PWD/../library_westinghouse510
DEPENDPATH += $$PWD/../library_westinghouse510



win32: LIBS += -L$$PWD/../../tools/sensoray/lib/ -ls24xx

INCLUDEPATH += $$PWD/../../tools/sensoray
DEPENDPATH += $$PWD/../../tools/sensoray


unix:!macx: LIBS += -L$$PWD/../../tools/sensoray/lib/linux/x64/ -l24xx

INCLUDEPATH += $$PWD/../../tools/sensoray/lib/linux/x64
DEPENDPATH += $$PWD/../../tools/sensoray/lib/linux/x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../../tools/sensoray/lib/linux/x64/lib24xx.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_sensoray/release/ -llibrary_sensoray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_sensoray/debug/ -llibrary_sensoray
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_sensoray/ -llibrary_sensoray

INCLUDEPATH += $$PWD/../library_sensoray
DEPENDPATH += $$PWD/../library_sensoray


unix:!macx|win32: LIBS += -L$$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP/ -lACSCL_x86

INCLUDEPATH += $$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP
DEPENDPATH += $$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_SPIIMotionController/release/ -llibrary_SPIIMotionController
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_SPIIMotionController/debug/ -llibrary_SPIIMotionController
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_SPIIMotionController/ -llibrary_SPIIMotionController

INCLUDEPATH += $$PWD/../library_SPIIMotionController
DEPENDPATH += $$PWD/../library_SPIIMotionController

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ECM_API/release/ -lECM_API
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ECM_API/debug/ -lECM_API
else:unix:!macx: LIBS += -L$$OUT_PWD/../ECM_API/ -lECM_API

INCLUDEPATH += $$PWD/../ECM_API
DEPENDPATH += $$PWD/../ECM_API
