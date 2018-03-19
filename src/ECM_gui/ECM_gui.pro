#-------------------------------------------------
#
# Project created by QtCreator 2018-02-25T10:47:35
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += network

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
        main.cpp \
        ECM_controller_gui.cpp \
    additional_sensor_display.cpp \
    ECM_plot_collection.cpp \
    ECM_plot_identifier.cpp \
    SensorDisplay/collection_displays.cpp \
    SensorDisplay/display_base_plot_instantaneous.cpp \
    SensorDisplay/display_voltage.cpp \
    plot_central.cpp \
    misc_dialogs/dialog_custom_commands.cpp \
    LED.cpp \
    munk_dialog/widget_segment_time_data.cpp \
    munk_dialog/widget_segment_time_display.cpp \
    munk_dialog/window_munk_power_supply.cpp \
    misc_dialogs/window_touchoff.cpp \
    misc_dialogs/dialog_connections.cpp \
    rigol_dialog/window_rigol_control.cpp \
    pump_dialog/window_pump_control.cpp

HEADERS += \
        ECM_controller_gui.h \
    additional_sensor_display.h \
    ECM_plot_collection.h \
    ECM_plot_identifier.h \
    SensorDisplay/collection_displays.h \
    SensorDisplay/display_base_plot_instantaneous.h \
    SensorDisplay/display_voltage.h \
    SensorDisplay/I_sensor_display.h \
    plot_central.h \
    misc_dialogs/dialog_custom_commands.h \
    LED.h \
    munk_dialog/widget_segment_time_data.h \
    munk_dialog/widget_segment_time_display.h \
    munk_dialog/window_munk_power_supply.h \
    misc_dialogs/window_touchoff.h \
    misc_dialogs/dialog_connections.h \
    rigol_dialog/window_pump_control2.h \
    rigol_dialog/window_rigol_control.h \
    pump_dialog/window_pump_control.h

FORMS += \
        ECM_controller_gui.ui \
    additional_sensor_display.ui \
    SensorDisplay/display_base_plot_instantaneous.ui \
    misc_dialogs/dialog_custom_commands.ui \
    munk_dialog/widget_segment_time_data.ui \
    munk_dialog/widget_segment_time_display.ui \
    munk_dialog/window_munk_power_supply.ui \
    misc_dialogs/window_touchoff.ui \
    misc_dialogs/dialog_connections.ui \
    rigol_dialog/window_rigol_control.ui \
    pump_dialog/window_pump_control.ui

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include
INCLUDEPATH += $$(ECM_ROOT)/tools/galil/include/
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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_westinghouse510/release/ -llibrary_westinghouse510
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_westinghouse510/debug/ -llibrary_westinghouse510
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_westinghouse510/ -llibrary_westinghouse510

INCLUDEPATH += $$PWD/../library_westinghouse510
DEPENDPATH += $$PWD/../library_westinghouse510


unix:!macx|win32: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclib
unix:!macx|win32: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclibo

INCLUDEPATH += $$PWD/../../tools/galil/lib/dynamic/x86
DEPENDPATH += $$PWD/../../tools/galil/lib/dynamic/x86

win32: LIBS += -L$(ECM_ROOT)/tools/galil/dll/x86/ -lgclib -lgclibo
else:unix: LIBS += -L$(ECM_ROOT)/tools/galil/dll/x86/ -lgclib -lgclibo

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_galilMotionController/release/ -llibrary_galilMotionController
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_galilMotionController/debug/ -llibrary_galilMotionController
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_galilMotionController/ -llibrary_galilMotionController

INCLUDEPATH += $$PWD/../library_galilMotionController
DEPENDPATH += $$PWD/../library_galilMotionController



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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ECM_API/release/ -lECM_API
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ECM_API/debug/ -lECM_API
else:unix:!macx: LIBS += -L$$OUT_PWD/../ECM_API/ -lECM_API

INCLUDEPATH += $$PWD/../ECM_API
DEPENDPATH += $$PWD/../ECM_API
