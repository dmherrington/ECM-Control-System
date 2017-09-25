#include "plot_handler.h"

namespace graphing {

PlotHandler::PlotHandler(QWidget *parent) :
    TimePlot(parent)
{
    this->xAxis->setLabel("Time (ms)");
    this->yAxis->setLabel("Voltage (volts)");
    this->yAxis2->setLabel("Current (amps)");

    voltageGraph = this->addGraph(this->xAxis, this->yAxis);
    voltageGraph->setName("VOLTAGE");
    currentGraph = this->addGraph(this->xAxis, this->yAxis2);
    currentGraph->setName("CURRENT");

    voltageGraph->setPen(QPen(Qt::blue)); // line color blue for first graph
    voltageGraph->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    currentGraph->setPen(QPen(Qt::red)); // line color red for second graph
    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
        x[i] = i;
        y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
        y1[i] = qExp(-i/150.0);              // exponential envelope
    }
    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    this->yAxis2->setVisible(true);
    this->yAxis2->setTickLabels(true);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(this->yAxis, SIGNAL(rangeChanged(QCPRange)), this->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    voltageGraph->setData(x, y0);
    currentGraph->setData(x, y1);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    voltageGraph->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    currentGraph->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    //this->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}

//!
//! \brief Destructor
//!
PlotHandler::~PlotHandler()
{

}

void PlotHandler::updateData(const QVector<double> &timeVector, const QVector<double> &voltageVector, const QVector<double> &currentVector)
{

    double maxV = 0.0;
    for(unsigned int i = 0; i < voltageVector.size(); i++)
    {
        if(voltageVector[i] > maxV)
            maxV = voltageVector[i];
    }

    currentGraph->setData(timeVector,currentVector);
    voltageGraph->setData(timeVector,voltageVector);

    this->xAxis->setRange(0,timeVector.back());
    this->yAxis->setRange(0, maxV + 1.0);
    currentGraph->rescaleAxes(true);

    this->replot();
}

} //end of namespace graphing
