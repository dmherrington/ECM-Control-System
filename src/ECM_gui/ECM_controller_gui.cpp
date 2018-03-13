#include "ECM_controller_gui.h"
#include "ui_ECM_controller_gui.h"

static const common::Devices TimeDevice = common::SYSTEMCLOCK;


ECMControllerGUI::ECMControllerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ECMControllerGUI),
    m_SensorDisplays(&m_PlotCollection)
{
    ui->setupUi(this);

    qRegisterMetaType<QCustomPlot::RefreshPriority>("QCustomPlot::RefreshPriority");

    m_additionalSensorDisplay = new AdditionalSensorDisplay(&m_PlotCollection);
    m_additionalSensorDisplay->setWindowTitle("ECM Sensors");

    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i];  // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->centralCustomPlot->addGraph();
    ui->centralCustomPlot->graph(1)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->centralCustomPlot->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    ui->centralCustomPlot->graph(1)->setData(x, y);
    // give the axes some labels:
    ui->centralCustomPlot->xAxis->setLabel("x");
    ui->centralCustomPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->centralCustomPlot->xAxis->setRange(-1, 1);
    ui->centralCustomPlot->yAxis->setRange(0, 1);
    ui->centralCustomPlot->replot();
    //give collection of plots
//    ui->centralCustomPlot->SupplyPlotCollection(&m_PlotCollection);
//    ui->centralCustomPlot->AddPlot("testing");

//    data::SensorState stateSensor;
//    stateSensor.ConstructSensor(data::SENSOR_VOLTAGE , "Sensor_Voltage");

//    common::EnvironmentTime currTime;
//    common::EnvironmentTime::CurrentTime(TimeDevice, currTime);
//    stateSensor.validityTime->setTime(currTime);

//    ((data::SensorVoltage*)stateSensor.getSensorData().get())->SetVoltage(10.0,data::VoltageUnit::UNIT_VOLTAGE_VOLTS);

//    common::TupleSensorString tupleSensor;
//    tupleSensor.sourceName = "TestSource";
//    tupleSensor.sensorName = "TestSensor";

//    m_PlotCollection.UpdateSensorPlots(tupleSensor, stateSensor);

//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

//    common::EnvironmentTime::CurrentTime(TimeDevice, currTime);
//    stateSensor.validityTime->setTime(currTime);
//    ((data::SensorVoltage*)stateSensor.getSensorData().get())->SetVoltage(12.0,data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
//    m_PlotCollection.UpdateSensorPlots(tupleSensor, stateSensor);

//    QList<std::shared_ptr<data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(tupleSensor);
//    ui->centralCustomPlot->RedrawDataSource(plots);
//    QList<std::shared_ptr<ExpressionEngine::IPlotComparable> > plots = m_PlotCollection.getPlots(sensor);
//    ui->custyomPlot_i->RedrawDataSource(plots);
}

ECMControllerGUI::~ECMControllerGUI()
{
    delete ui;
}
