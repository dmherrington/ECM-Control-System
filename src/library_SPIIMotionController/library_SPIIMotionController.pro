#-------------------------------------------------
#
# Project created by QtCreator 2019-01-29T19:40:58
#
#-------------------------------------------------

QT       -= gui

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
        spii_motion_controller.cpp

HEADERS += \
        spii_motion_controller.h \
        library_spiimotioncontroller_global.h 

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

unix:!macx|win32: LIBS += -L$$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP/ -lACSCL_x86

INCLUDEPATH += $$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP
DEPENDPATH += $$PWD/../../tools/SPiiPlusADKSuite_v2_6/ACSC/C_CPP
