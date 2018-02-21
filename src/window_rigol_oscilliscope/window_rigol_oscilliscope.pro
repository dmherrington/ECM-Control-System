#-------------------------------------------------
#
# Project created by QtCreator 2018-02-13T11:17:28
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = window_rigol_oscilliscope
TEMPLATE = app

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
        main.cpp \
        mainwindow.cpp \
    widget_channel_measurements.cpp

HEADERS += \
        mainwindow.h \
    widget_channel_measurements.h

FORMS += \
        mainwindow.ui \
    widget_channel_measurements.ui

#include Dependicies
INCLUDEPATH += $$PWD/../

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/release/ -llibrary_rigol_oscilloscope
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/debug/ -llibrary_rigol_oscilloscope
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/ -llibrary_rigol_oscilloscope

INCLUDEPATH += $$PWD/../library_rigol_oscilloscope
DEPENDPATH += $$PWD/../library_rigol_oscilloscope
