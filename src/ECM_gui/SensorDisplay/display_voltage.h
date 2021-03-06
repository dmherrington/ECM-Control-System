#ifndef DISPLAY_VOLTAGE_H
#define DISPLAY_VOLTAGE_H

#include "display_base_plot_instantaneous.h"

#include "sensors/sensor_voltage.h"

class DisplayVoltage : public DisplayBasePlotInstantaneous
{
    Q_OBJECT

public:

    /**
     * @brief DisplayVoltage Constructor for the Voltage Display widget
     * @param sensor Tuple that defines the sensor that is being displayed
     * @param parent
     */
    explicit DisplayVoltage(common::TupleSensorString sensor, const ECMPlotCollection *sourceCollection, QWidget *parent = 0);
    ~DisplayVoltage();


     void setPlotData(const ECMPlotIdentifierPtr &plot);

private:
    std::shared_ptr<common_data::observation::IPlotComparable> m_Expression;
};

#endif // DISPLAY_VOLTAGE_H
