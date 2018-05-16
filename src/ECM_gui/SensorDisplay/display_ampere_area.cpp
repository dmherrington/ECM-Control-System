#include "display_ampere_area.h"

DisplayAmpereArea::DisplayAmpereArea(common::TupleSensorString sensor, const ECMPlotCollection *sourceCollection, QWidget *parent) :
    DisplayBasePlotInstantaneous(sensor,sourceCollection, parent)
{
}

DisplayAmpereArea::~DisplayAmpereArea()
{

}


void DisplayAmpereArea::setPlotData(const ECMPlotIdentifierPtr &plot)
{
    QList<std::shared_ptr<common_data::observation::IPlotComparable>> plotList;
    plotList.append(plot);
    DisplayBasePlotInstantaneous::setPlotData(plotList);
    common_data::observation::TimeDataReference tdr_x(plot, "x");
    m_Expression = plot;
    AddExpressionPlot(plot, Qt::blue);

    ChangeInstantaniousName(0, "Ampere Area");

}
