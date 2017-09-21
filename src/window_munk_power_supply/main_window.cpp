#include "main_window.h"
#include "ui_main_window.h"

#include "widget_segment_time_data.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
    ui->horizontalLayout->setAlignment(Qt::AlignLeft);

    QCPGraph* voltageGraph = ui->graphWidget->addGraph(ui->graphWidget->xAxis, ui->graphWidget->yAxis);
    QCPGraph* currentGraph = ui->graphWidget->addGraph(ui->graphWidget->xAxis, ui->graphWidget->yAxis2);

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
    ui->graphWidget->yAxis2->setVisible(true);
    ui->graphWidget->yAxis2->setTickLabels(true);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->graphWidget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->graphWidget->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    voltageGraph->setData(x, y0);
    currentGraph->setData(x, y1);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    voltageGraph->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    currentGraph->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    //ui->graphWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    WidgetSegmentTimeData* newData3 = new WidgetSegmentTimeData();
    ui->horizontalLayout->addWidget(newData3);
}
