TEMPLATE = subdirs

SUBDIRS += \
    common \
    data \
    ECM_API \
    ECM_GUI \
    graphing \
    library_munk_power_supply \
    library_rigol_oscilloscope \
    library_sensoray \
    library_westinghouse510 \
    library_qModBus \
    Testing \
    library_SPIIMotionController \
    window_munk_power_supply
data.depends = common
graphing.depends = data
library_SPIIMotionController.depends = graphing
library_munk_power_supply.depends = library_SPIIMotionController
library_rigol_oscilloscope.depends = library_munk_power_supply
library_sensoray.depends = library_rigol_oscilloscope
library_qModBus.depends = library_sensoray
library_westinghouse510.depends = library_qModBus
ECM_API.depends = library_westinghouse510
ECM_GUI.depends = ECM_API
