#-------------------------------------------------
#
# Project created by QtCreator 2018-03-09T13:50:10
#
#-------------------------------------------------

QT       -= gui

TARGET = data
TEMPLATE = lib

DEFINES += DATA_LIBRARY

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
    Sensors/sensor.cpp \
    Sensors/sensor_voltage.cpp \
    sensor_collection.cpp \
    sensor_state.cpp \
    Dimensions/time_dimension.cpp \
    Dimensions/voltage_dimension.cpp \
    Observation/observation_collection.cpp \
    Observation/observation_scalar.cpp

HEADERS += \
        data_global.h \ 
    Sensors/sensor.h \
    Sensors/sensor_voltage.h \
    sensor_collection.h \
    sensor_state.h \
    Dimensions/dimension.h \
    Dimensions/time_dimension.h \
    Dimensions/voltage_dimension.h \
    Observation/I_observation.h \
    Observation/I_plot_comparable.h \
    Observation/I_time_data.h \
    Observation/number_systems.h \
    Observation/observation_collection.h \
    Observation/observation_scalar.h \
    Observation/time_data_reference.h \
    Observation/observation_ID_reference.h \
    Observation/cartesian_data.h \
    Observation/cartesian_evaluation_parameters.h

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/data.lib release/data.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/data.lib debug/data.dll
INSTALLS += lib

#Header file copy
headers_common_data.path    = $$(ECM_ROOT)/include/data
headers_common_data.files   += \
        data_global.h \
        sensor_collection.h \
        sensor_state.h
INSTALLS       += headers_common_data

#Header file copy
headers_data_dimensions.path    = $$(ECM_ROOT)/include/data/Dimensions
headers_data_dimensions.files   += \
    Dimensions/dimension.h \
    Dimensions/time_dimension.h \
    Dimensions/voltage_dimension.h
INSTALLS       += headers_data_dimensions

#Header file copy
headers_data_observations.path    = $$(ECM_ROOT)/include/data/Observation
headers_data_observations.files   += \
    Observation/cartesian_data.h \
    Observation/cartesian_evaluation_parameters.h \
    Observation/I_observation.h \
    Observation/I_plot_comparable.h \
    Observation/I_time_data.h \
    Observation/number_systems.h \
    Observation/observation_collection.h \
    Observation/observation_ID_reference.h \
    Observation/observation_scalar.h \
    Observation/time_data_reference.h
INSTALLS       += headers_data_observations

#Header file copy
headers_data_sensors.path    = $$(ECM_ROOT)/include/data/Sensors
headers_data_sensors.files   += \
    Sensors/sensor.h \
    Sensors/sensor_voltage.h
INSTALLS       += headers_data_sensors

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon
