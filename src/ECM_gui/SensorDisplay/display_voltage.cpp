#include "display_voltage.h"

#include "Sensors/sensor_voltage.h"

DisplayVoltage::DisplayVoltage(common::TupleSensorString sensor, const ECMPlotCollection *sourceCollection, QWidget *parent) :
    DisplayBasePlotInstantaneous(sensor,sourceCollection, parent)
{
}

DisplayVoltage::~DisplayVoltage()
{
}


void DisplayVoltage::setPlotData(const QList<std::shared_ptr<data::observation::IPlotComparable>> &plotList)
{
    DisplayBasePlotInstantaneous::setPlotData(plotList);
    //data::observation::TimeDataReference tdr_x(plotList.at(0), "x");
    //m_Expression = plotList.at(0);
    m_Expression = "";
    AddExpressionPlot(m_Expression, Qt::blue);

    ChangeInstantaniousName(0, "Voltage");

}


