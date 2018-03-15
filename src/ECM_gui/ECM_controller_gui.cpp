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
    m_WindowMunk = new Window_MunkPowerSupply();
    m_WindowMunk->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);

    readSettings();

    common::EnvironmentTime startTime;
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,startTime);

    QDate tmp_Date(startTime.year, startTime.month, startTime.dayOfMonth);
    QTime tmp_Time(startTime.hour, startTime.minute, startTime.second, startTime.millisecond );

    qRegisterMetaType<QCustomPlot::RefreshPriority>("QCustomPlot::RefreshPriority");

    m_additionalSensorDisplay = new AdditionalSensorDisplay(&m_PlotCollection);
    m_additionalSensorDisplay->setWindowTitle("ECM Sensors");

    //give collection of plots
//    ui->centralCustomPlot->SupplyPlotCollection(&m_PlotCollection);
//    ui->centralCustomPlot->setOriginTime(QDateTime(tmp_Date, tmp_Time));

    common::TupleSensorString tupleSensor;
    tupleSensor.sourceName = "TestSource";
    tupleSensor.sensorName = "TestSensor";
    ECMPlotIdentifierPtr newPlot = std::make_shared<ECMPlotIdentifier>(tupleSensor, "Sensed_Voltage");
//    ui->centralCustomPlot->AddPlot(newPlot);



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
//    ui->centralCustomPlot->RedrawDataSource(plots);
}

//void ECMControllerGUI::on_pushButton_released()
//{
//    common::TupleSensorString tupleSensor;
//    tupleSensor.sourceName = "TestSource";
//    tupleSensor.sensorName = "TestSensor";

//    common::EnvironmentTime time;
//    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,time);

//    data::SensorState stateSensor;
//    stateSensor.ConstructSensor(data::SENSOR_VOLTAGE , "Sensor_Voltage");

//    stateSensor.validityTime->setTime(time);
//    double r = ((double) rand() / (RAND_MAX));
//    ((data::SensorVoltage*)stateSensor.getSensorData().get())->SetVoltage(r*10.0,data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
//    slot_NewSensorData(tupleSensor,stateSensor);
//}
void ECMControllerGUI::readSettings()
{
    QSettings settings("Trolltech", "Application Example");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    bool munkHidden = settings.value("size", false).toBool();
    if(!munkHidden)
        m_WindowMunk->show();

    resize(size);
    move(pos);
}

void ECMControllerGUI::closeEvent(QCloseEvent *event)
{
    QSettings settings("Trolltech", "Application Example");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("munkDisplayed",m_WindowMunk->isHidden());

    //m_WindowMunk->closeEvent(event);
    m_WindowMunk->close();
    event->accept();
}

bool ECMControllerGUI::maybeSave()
{
//    if (textEdit->document()->isModified()) {
//        QMessageBox::StandardButton ret;
//        ret = QMessageBox::warning(this, tr("Application"),
//                     tr("The document has been modified.\n"
//                        "Do you want to save your changes?"),
//                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//        if (ret == QMessageBox::Save)
//            return save();
//        else if (ret == QMessageBox::Cancel)
//            return false;
//    }
//    return true;
}

void ECMControllerGUI::on_pushButton_MotorEnable_released()
{

}

void ECMControllerGUI::on_spinBox_CutDepth_editingFinished()
{

}

void ECMControllerGUI::on_spinBox_CutSpeed_editingFinished()
{

}

void ECMControllerGUI::on_spinBox_RetractDistance_editingFinished()
{

}

void ECMControllerGUI::on_spinBox_RetractPeriod_editingFinished()
{

}

void ECMControllerGUI::on_spinBox_Pause_editingFinished()
{

}

void ECMControllerGUI::on_spinBox_StepSize_editingFinished()
{

}

void ECMControllerGUI::on_pushButton_IncreaseJog_released()
{

}

void ECMControllerGUI::on_pushButton_DecreaseJog_released()
{

}

void ECMControllerGUI::on_pushButton_IncreaseRelativeMove_released()
{

}

void ECMControllerGUI::on_pushButton_DecreaseRelativeMove_released()
{

}

void ECMControllerGUI::on_pushButton_MotorDisable_released()
{

}

void ECMControllerGUI::on_pushButton_SetHome_released()
{

}

void ECMControllerGUI::on_pushButton_MoveHome_released()
{

}

void ECMControllerGUI::on_pushButton_released()
{

}

void ECMControllerGUI::on_pushButton_RunProfile_released()
{

}

void ECMControllerGUI::on_pushButton_UploadProgram_released()
{

}

void ECMControllerGUI::on_pushButton_DownloadProgram_released()
{

}

void ECMControllerGUI::on_pushButton_EstablishTouchoff_released()
{

}
