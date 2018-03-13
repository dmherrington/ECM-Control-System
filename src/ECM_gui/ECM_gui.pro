#-------------------------------------------------
#
# Project created by QtCreator 2018-02-25T10:47:35
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
}

lessThan(QT_MAJOR_VERSION, 5) {
    CONFIG += designer
}

unix:QMAKE_CXXFLAGS += -std=gnu++0x

CONFIG += plugin

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
    plot_central.cpp

HEADERS += \
        ECM_controller_gui.h \
    additional_sensor_display.h \
    ECM_plot_collection.h \
    ECM_plot_identifier.h \
    SensorDisplay/collection_displays.h \
    SensorDisplay/display_base_plot_instantaneous.h \
    SensorDisplay/display_voltage.h \
    SensorDisplay/I_sensor_display.h \
    plot_central.h

FORMS += \
        ECM_controller_gui.ui \
    additional_sensor_display.ui \
    SensorDisplay/display_base_plot_instantaneous.ui

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
