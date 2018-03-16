#include "display_voltage.h"

DisplayVoltage::DisplayVoltage(common::TupleSensorString sensor, const ECMPlotCollection *sourceCollection, QWidget *parent) :
    DisplayBasePlotInstantaneous(sensor,sourceCollection, parent)
{
}

DisplayVoltage::~DisplayVoltage()
{
}


void DisplayVoltage::setPlotData(const QList<std::shared_ptr<common_data::observation::IPlotComparable>> &plotList)
{
    DisplayBasePlotInstantaneous::setPlotData(plotList);
    //common_data::observation::TimeDataReference tdr_x(plotList.at(0), "x");
    //m_Expression = plotList.at(0);
    m_Expression = "";
    AddExpressionPlot(m_Expression, Qt::blue);

    ChangeInstantaniousName(0, "Voltage");

}


