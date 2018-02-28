#include "display_voltage.h"

#include "Sensors/sensor_voltage.h"

DisplayVoltage::DisplayVoltage(ECMCore::TupleSensorString sensor, const ECMPlotCollection *sourceCollection, QWidget *parent) :
    DisplayBasePlotInstantaneous(sensor,sourceCollection, parent)
{
}

DisplayVoltage::~DisplayVoltage()
{
}


void DisplayVoltage::setPlotData(const QList<std::shared_ptr<ExpressionEngine::IPlotComparable> > &plotList)
{
    DisplayBasePlotInstantaneous::setPlotData(plotList);

    m_Expression = ExpressionEngine::MathExpression(ExpressionEngine::MathExpression::GeneralUnaryArithmeticOperands::NONE, plotList.at(0), m_sourceCollection);

    AddExpressionPlot(m_Expression, Qt::blue);

    ChangeInstantaniousName(0, "Voltage");

}


