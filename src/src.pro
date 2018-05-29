TEMPLATE = subdirs

SUBDIRS += \
    common \
    data \
    ECM_API \
    ECM_GUI \
    graphing \
    library_galilMotionController \
    library_munk_power_supply \
    library_rigol_oscilloscope \
    library_sensoray \
    library_westinghouse510 \
    Testing

data.depends = common
graphing.depends = data
library_galilMotionController.depends = graphing
library_munk_power_supply.depends = library_galilMotionController
library_rigol_oscilloscope.depends = library_munk_power_supply
library_sensoray.depends = library_rigol_oscilloscope
library_westinghouse510.depends = library_sensoray
ECM_API.depends = library_westinghouse510
ECM_GUI.depends = ECM_API
