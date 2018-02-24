#-------------------------------------------------
#
# Project created by QtCreator 2017-09-16T14:40:18
#
#-------------------------------------------------

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

lessThan(QT_MAJOR_VERSION, 5): QT += gui

unix:QMAKE_CXXFLAGS += -std=gnu++0x


TARGET = graphing
TEMPLATE = lib

DEFINES += GRAPHING_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += graphing.cpp \
    plot_handler.cpp \
    qcustomplot.cpp \
    time_plot.cpp

HEADERS += graphing.h\
        graphing_global.h \
    plot_handler.h \
    qcustomplot.h \
    time_plot.h \
    plot_data.h


# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/graphing.lib release/graphing.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/graphing.lib debug/graphing.dll
INSTALLS += lib

#Header file copy
headers.path    = $$(ECM_ROOT)/include/graphing
headers.files   += $$HEADERS
INSTALLS       += headers

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common
