#ifndef DISPLAY_VOLTAGE_H
#define DISPLAY_VOLTAGE_H

#include "display_base_plot_instantaneous.h"


class DisplayVoltage : public DisplayBasePlotInstantaneous
{
    Q_OBJECT

public:

    /**
     * @brief DisplayVoltage Constructor for the Voltage Display widget
     * @param sensor Tuple that defines the sensor that is being displayed
     * @param parent
     */
    explicit DisplayVoltage(ECMCore::TupleSensorString sensor, const ECMPlotCollection *sourceCollection, QWidget *parent = 0);
    ~DisplayVoltage();


     virtual void setPlotData(const QList<std::shared_ptr<ExpressionEngine::IPlotComparable> > &plotList);

private:

    ExpressionEngine::MathExpression m_Expression;
};

#endif // DISPLAY_VOLTAGE_H
