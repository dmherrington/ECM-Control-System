#ifndef DISPLAY_AMPERE_AREA_H
#define DISPLAY_AMPERE_AREA_H

#include "display_base_plot_instantaneous.h"

#include "sensors/sensor_voltage.h"

class DisplayAmpereArea : public DisplayBasePlotInstantaneous
{
    Q_OBJECT

public:

    /**
     * @brief DisplayVoltage Constructor for the Voltage Display widget
     * @param sensor Tuple that defines the sensor that is being displayed
     * @param parent
     */
    explicit DisplayAmpereArea(common::TupleSensorString sensor, const ECMPlotCollection *sourceCollection, QWidget *parent = 0);
    ~DisplayAmpereArea();


     void setPlotData(const ECMPlotIdentifierPtr &plot);

private:
    std::shared_ptr<common_data::observation::IPlotComparable> m_Expression;
};

#endif // DISPLAY_AMPERE_AREA_H
