#-------------------------------------------------
#
# Project created by QtCreator 2017-11-13T09:04:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Window_GalilMotionController
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
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

#include Dependicies
INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$PWD/../../tools/galil/include/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclib
else:unix:!macx: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclibo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclibo
else:unix:!macx: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclib

INCLUDEPATH += $$PWD/../../tools/galil/lib/dynamic/x86
DEPENDPATH += $$PWD/../../tools/galil/lib/dynamic/x86
