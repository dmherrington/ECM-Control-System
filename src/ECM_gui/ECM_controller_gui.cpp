#include "ECM_controller_gui.h"
#include "ui_ECM_controller_gui.h"

static const common::Devices TimeDevice = common::SYSTEMCLOCK;


ECMControllerGUI::ECMControllerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ECMControllerGUI),
    m_SensorDisplays(&m_PlotCollection)
{
    qRegisterMetaType<common_data::SensorState>("SensorState");
    qRegisterMetaType<common::TupleSensorString>("TupleSensorString");

    ui->setupUi(this);

    m_API = new ECM_API();

    connect(m_API->m_Rigol, SIGNAL(signal_RigolPlottable(common::TupleSensorString,bool)), this, SLOT(slot_NewlyAvailableRigolData(common::TupleSensorString,bool)));

    m_WindowMunk = new Window_MunkPowerSupply(m_API->m_Munk);
    m_WindowMunk->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);

    m_WindowPump = new Window_PumpControl(m_API->m_Pump);
    m_WindowPump->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);

    m_WindowRigol = new Window_RigolControl(m_API->m_Rigol);
    m_WindowRigol->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);

    m_WindowTouchoff = new Window_Touchoff(m_API->m_Galil);
    m_WindowTouchoff->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);

    m_DialogConnections = new Dialog_Connections(m_API);
    m_DialogConnections->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);

    connect(m_API->m_Galil,SIGNAL(signal_GalilHomeIndicated(bool)),this,SLOT(slot_UpdateHomeIndicated(bool)));

    readSettings();

    common::EnvironmentTime startTime;
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,startTime);

    QDate tmp_Date(startTime.year, startTime.month, startTime.dayOfMonth);
    QTime tmp_Time(startTime.hour, startTime.minute, startTime.second, startTime.millisecond );

    qRegisterMetaType<QCustomPlot::RefreshPriority>("QCustomPlot::RefreshPriority");

    m_additionalSensorDisplay = new AdditionalSensorDisplay(&m_PlotCollection);
    m_additionalSensorDisplay->setWindowTitle("ECM Sensors");

    if(m_additionalSensorDisplay->isHidden())
        m_additionalSensorDisplay->show();

//    m_additionalSensorDisplay->SetOriginTime();
//    m_additionalSensorDisplay->UpdateNonPlottedData(); //this actually updates the data
//    m_additionalSensorDisplay->UpdatePlottedData(); //this actually updates the rendering of the data

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

void ECMControllerGUI::slot_NewSensorData(const common::TupleSensorString sensor, const common_data::SensorState state)
{
    m_PlotCollection.UpdateSensorPlots(sensor, state);
    QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(sensor);
    plots = m_PlotCollection.getPlots(sensor);
//    ui->centralCustomPlot->RedrawDataSource(plots);
}

void ECMControllerGUI::slot_UpdateHomeIndicated(const bool &value)
{
    if(value)
        ui->widget_LEDHomeIndicated->setColor(QColor(0,255,0));
    else
        ui->widget_LEDHomeIndicated->setColor(QColor(255,0,0));
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
    bool munkHidden = settings.value("munkDisplayed", false).toBool();
    bool pumpHidden = settings.value("pumpDisplayed", false).toBool();
    bool rigolHidden = settings.value("rigolDisplayed", false).toBool();
    bool touchoffHidden = settings.value("touchoffDisplayed", false).toBool();

    if(!munkHidden)
        m_WindowMunk->show();

    if(!pumpHidden)
        m_WindowPump->show();

    if(!munkHidden)
        m_WindowRigol->show();

    if(!pumpHidden)
        m_WindowTouchoff->show();

    resize(size);
    move(pos);
}

void ECMControllerGUI::closeEvent(QCloseEvent *event)
{
    QSettings settings("Trolltech", "Application Example");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("munkDisplayed",m_WindowMunk->isWindowHidden());
    settings.setValue("pumpDisplayed",m_WindowPump->isWindowHidden());
    settings.setValue("rigolDisplayed",m_WindowRigol->isWindowHidden());
    settings.setValue("touchoffDisplayed",m_WindowTouchoff->isWindowHidden());

    m_WindowMunk->close();
    m_WindowPump->close();
    m_WindowRigol->close();
    m_WindowTouchoff->close();
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
    CommandMotorEnable command;
    command.setEnableAxis(MotorAxis::Z);
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_doubleSpinBox_CutDepth_editingFinished()
{
    Command_Variable command("maxdepth",ui->doubleSpinBox_CutDepth->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_doubleSpinBox_RetractDistance_editingFinished()
{
    Command_Variable command("rtdist",ui->doubleSpinBox_RetractDistance->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_doubleSpinBox_StepSize_editingFinished()
{
    Command_Variable command("step",ui->doubleSpinBox_StepSize->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_RetractSpeed_editingFinished()
{
    Command_Variable command("backsp",ui->spinBox_CutSpeed->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_PlungeSpeed_editingFinished()
{
    Command_Variable command("forsp",ui->spinBox_CutSpeed->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_CutSpeed_editingFinished()
{
    Command_Variable command("speed",ui->spinBox_CutSpeed->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_RetractPeriod_editingFinished()
{
    Command_Variable command("rtfq",ui->spinBox_RetractPeriod->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_Pause_editingFinished()
{
    Command_Variable command("rtpause",ui->spinBox_Pause->value());
    m_API->m_Galil->executeCommand(&command);
}

/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITHIN THE MANUAL MOVE PANEL
/////////////////////////////////////////////////////////////////////////

void ECMControllerGUI::on_pushButton_IncreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value()) * (-1);
    CommandJog beginJog(MotorAxis::Z,jogRate);
    m_API->m_Galil->executeCommand(&beginJog);
}

void ECMControllerGUI::on_pushButton_IncreaseJog_released()
{
    CommandStop stop(MotorAxis::Z);
    m_API->m_Galil->executeCommand(&stop);
}

void ECMControllerGUI::on_pushButton_DecreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value());
    CommandJog beginJog(MotorAxis::Z,jogRate);
    m_API->m_Galil->executeCommand(&beginJog);
}

void ECMControllerGUI::on_pushButton_DecreaseJog_released()
{
    CommandStop stop(MotorAxis::Z);
    m_API->m_Galil->executeCommand(&stop);
}


void ECMControllerGUI::on_pushButton_IncreaseRelativeMove_released()
{
    int relativeDistance = abs(ui->spinBox_RelativeMove->value()) * (-1);
    CommandRelativeMove move(MotorAxis::Z, relativeDistance);
    m_API->m_Galil->executeCommand(&move);
}

void ECMControllerGUI::on_pushButton_DecreaseRelativeMove_released()
{
    int relativeDistance = abs(ui->spinBox_RelativeMove->value());
    CommandRelativeMove move(MotorAxis::Z, relativeDistance);
    m_API->m_Galil->executeCommand(&move);
}

void ECMControllerGUI::on_pushButton_MotorDisable_released()
{
    CommandMotorDisable command;
    command.setDisableAxis(MotorAxis::Z);
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_pushButton_ResetHome_released()
{
    CommandExecuteProfile command(MotionProfile::ProfileType::HOMING,"latch");
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_pushButton_MoveHome_released()
{
    CommandAbsoluteMove command(MotorAxis::Z,0);
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_pushButton_RunProfile_released()
{
    //get the profile name from the GUI
    //CommandExecuteProfile command(CommandExecuteProfile::ProfileType::PROFILE,"touchof");
    //m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_pushButton_UploadProgram_released()
{

}

void ECMControllerGUI::on_pushButton_DownloadProgram_released()
{

}

void ECMControllerGUI::on_pushButton_EstablishTouchoff_released()
{
    m_WindowTouchoff->show();
}

void ECMControllerGUI::on_actionConnections_triggered()
{
    m_DialogConnections->show();
}

void ECMControllerGUI::on_actionPump_triggered()
{
    m_WindowPump->show();
}

void ECMControllerGUI::on_actionPower_Supply_triggered()
{
    m_WindowMunk->show();
}

void ECMControllerGUI::on_actionOscilliscope_triggered()
{
    m_WindowRigol->show();
}

void ECMControllerGUI::slot_NewlyAvailableRigolData(const common::TupleSensorString &sensor, const bool &val)
{
    if(val)
        m_additionalSensorDisplay->AddUsableSensor(sensor);
}
