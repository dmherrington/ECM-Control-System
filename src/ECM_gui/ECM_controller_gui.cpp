#include "ECM_controller_gui.h"
#include "ui_ECM_controller_gui.h"

static const common::Devices TimeDevice = common::SYSTEMCLOCK;


ECMControllerGUI::ECMControllerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ECMControllerGUI),
    m_SensorDisplays(&m_PlotCollection)
{
    qRegisterMetaType<data::SensorState>("SensorState");
    qRegisterMetaType<common::TupleSensorString>("TupleSensorString");

    ui->setupUi(this);

    common::EnvironmentTime startTime;
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,startTime);

    QDate tmp_Date(startTime.year, startTime.month, startTime.dayOfMonth);
    QTime tmp_Time(startTime.hour, startTime.minute, startTime.second, startTime.millisecond );

    qRegisterMetaType<QCustomPlot::RefreshPriority>("QCustomPlot::RefreshPriority");

    m_additionalSensorDisplay = new AdditionalSensorDisplay(&m_PlotCollection);
    m_additionalSensorDisplay->setWindowTitle("ECM Sensors");

    //give collection of plots
    ui->centralCustomPlot->SupplyPlotCollection(&m_PlotCollection);
    ui->centralCustomPlot->setOriginTime(QDateTime(tmp_Date, tmp_Time));

    common::TupleSensorString tupleSensor;
    tupleSensor.sourceName = "TestSource";
    tupleSensor.sensorName = "TestSensor";
    ECMPlotIdentifierPtr newPlot = std::make_shared<ECMPlotIdentifier>(tupleSensor, "Sensed_Voltage");
    ui->centralCustomPlot->AddPlot(newPlot);

    testMunk = new MunkPowerSupply();
    connect(testMunk,SIGNAL(signal_NewSensorData(common::TupleSensorString,data::SensorState)),this,SLOT(slot_NewSensorData(common::TupleSensorString,data::SensorState)));
}

ECMControllerGUI::~ECMControllerGUI()
{
    delete ui;
}

void ECMControllerGUI::slot_NewSensorData(const common::TupleSensorString sensor, const data::SensorState state)
{
    m_PlotCollection.UpdateSensorPlots(sensor, state);
    QList<std::shared_ptr<data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(sensor);
    plots = m_PlotCollection.getPlots(sensor);
    ui->centralCustomPlot->RedrawDataSource(plots);
}

void ECMControllerGUI::on_pushButton_released()
{
    common::TupleSensorString tupleSensor;
    tupleSensor.sourceName = "TestSource";
    tupleSensor.sensorName = "TestSensor";

    common::EnvironmentTime time;
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,time);

    data::SensorState stateSensor;
    stateSensor.ConstructSensor(data::SENSOR_VOLTAGE , "Sensor_Voltage");

    stateSensor.validityTime->setTime(time);
    double r = ((double) rand() / (RAND_MAX));
    ((data::SensorVoltage*)stateSensor.getSensorData().get())->SetVoltage(r*10.0,data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
    slot_NewSensorData(tupleSensor,stateSensor);
}
