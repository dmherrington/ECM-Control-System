#-------------------------------------------------
#
# Project created by QtCreator 2018-03-17T21:39:06
#
#-------------------------------------------------

QT       -= gui
QT       += serialport
QT       += network

unix {
DEFINES += OSTYPE_LINUX
}
win32 {
DEFINES += OSTYPE_WINDOWS
}

TARGET = ECM_API
TEMPLATE = lib

DEFINES += ECM_API_LIBRARY

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
        ecm_api.cpp \
    ecm_logging.cpp \
    states/state_abstract_ecm_process.cpp \
    states/state_ecm_profile_machine.cpp \
    states/state_ecm_profile_machine_process.cpp \
    states/state_ecm_idle.cpp \
    ecm_modules.cpp \
    states/state_ecm_upload_motion_profile.cpp \
    states/state_ecm_upload_pump_parameters.cpp \
    states/state_ecm_upload.cpp \
    states/state_ecm_upload_motion_variables.cpp \
    states/state_ecm_upload_complete.cpp \
    states/state_ecm_upload_failed.cpp \
    states/state_ecm_upload_power_register_segments.cpp \
    states/state_ecm_upload_power_pulse_mode.cpp \
    commands/ecm_command_profile_collection.cpp \
    commands/ecm_command_profile_configuration.cpp \
    states/state_test.cpp \
    commands/ecm_command_execute_collection.cpp \
    states/state_ecm_setup_machine_home.cpp \
    states/state_ecm_setup_machine_touchoff.cpp \
    states/state_ecm_setup_machine.cpp \
    states/state_ecm_setup_machine_pump.cpp \
    states/state_ecm_setup_machine_complete.cpp \
    states/state_ecm_setup_machine_failed.cpp \
    states/state_ecm_profile_machine_complete.cpp \
    states/state_ecm_profile_machine_failed.cpp \
    commands/ecm_command_execution_properties.cpp \
    states/state_ecm_profile_machine_complete_execution.cpp \
    states/state_ecm_profile_machine_abort.cpp \
    states/state_ecm_setup_machine_touchoff_disconnect.cpp \
    states/state_ecm_setup_machine_touchoff_connect.cpp \
    states/state_ecm_setup_machine_touchoff_position.cpp \
    states/state_ecm_setup_machine_touchoff_execute.cpp \
    states/state_ecm_setup_machine_touchoff_completed.cpp \
    states/state_ecm_setup_machine_touchoff_failed.cpp

HEADERS += \
        ecm_api.h \
        ecm_api_global.h \  
    ecm_logging.h \
    states/state_abstract_ecm_process.h \
    states/state_ecm_components.h \
    states/state_ecm_profile_machine.h \
    states/state_ecm_profile_machine_process.h \
    states/state_ecm_types.h \
    states/state_ecm_idle.h \
    ecm_api_version.h \
    ecm_modules.h \
    states/state_ecm_upload_motion_profile.h \
    states/state_ecm_upload_pump_parameters.h \
    states/state_ecm_upload.h \
    states/state_ecm_upload_motion_variables.h \
    states/state_ecm_upload_complete.h \
    states/state_ecm_upload_failed.h \
    states/state_ecm_upload_power_register_segments.h \
    states/state_ecm_upload_power_pulse_mode.h \
    commands/ecm_command_profile_collection.h \
    commands/ecm_command_profile_configuration.h \
    states/state_test.h \
    commands/ecm_command_execute_collection.h \
    commands/ecm_command_abstract_collection.h \
    states/state_ecm_setup_machine.h \
    states/state_ecm_setup_machine_pump.h \
    states/state_ecm_setup_machine_home.h \
    states/state_ecm_setup_machine_touchoff.h \
    states/state_ecm_setup_machine_complete.h \
    states/state_ecm_setup_machine_failed.h \
    states/state_ecm_setup_machine_failed.h \
    states/state_ecm_profile_machine_complete.h \
    states/state_ecm_profile_machine_failed.h \
    commands/ecm_command_execution_properties.h \
    states/state_ecm_profile_machine_base.h \
    states/state_ecm_profile_machine_complete_execution.h \
    states/state_ecm_profile_machine_abort.h \
    states/state_ecm_setup_machine_touchoff_disconnect.h \
    states/state_ecm_setup_machine_touchoff_connect.h \
    states/state_ecm_setup_machine_touchoff_position.h \
    states/state_ecm_setup_machine_touchoff_execute.h \
    states/state_ecm_setup_machine_touchoff_completed.h \
    states/state_ecm_setup_machine_touchoff_failed.h

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/ECM_API.lib release/ECM_API.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/ECM_API.lib debug/ECM_API.dll
INSTALLS += lib

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
