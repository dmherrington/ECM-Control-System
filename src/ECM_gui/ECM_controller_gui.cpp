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

    m_Galil = new GalilMotionController();
    m_Munk = new MunkPowerSupply();
    m_Sensoray = new Sensoray();
    m_Rigol = new RigolOscilliscope();
    m_Pump = new Westinghouse510(m_Sensoray,01);

    Window_PumpControl* m_DialogPump = new Window_PumpControl(m_Pump);
    m_DialogPump->show();

    m_WindowMunk = new Window_MunkPowerSupply(m_Munk);
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

void ECMControllerGUI::slot_NewSensorData(const common::TupleSensorString sensor, const common_data::SensorState state)
{
    m_PlotCollection.UpdateSensorPlots(sensor, state);
    QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(sensor);
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
    CommandMotorEnable command;
    command.setEnableAxis(MotorAxis::Z);
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_doubleSpinBox_CutDepth_editingFinished()
{
    Command_Variable command("maxdepth",ui->doubleSpinBox_CutDepth->value());
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_doubleSpinBox_RetractDistance_editingFinished()
{
    Command_Variable command("rtdist",ui->doubleSpinBox_RetractDistance->value());
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_doubleSpinBox_StepSize_editingFinished()
{
    Command_Variable command("step",ui->doubleSpinBox_StepSize->value());
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_RetractSpeed_editingFinished()
{
    Command_Variable command("backsp",ui->spinBox_CutSpeed->value());
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_PlungeSpeed_editingFinished()
{
    Command_Variable command("forsp",ui->spinBox_CutSpeed->value());
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_CutSpeed_editingFinished()
{
    Command_Variable command("speed",ui->spinBox_CutSpeed->value());
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_RetractPeriod_editingFinished()
{
    Command_Variable command("rtfq",ui->spinBox_RetractPeriod->value());
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_Pause_editingFinished()
{
    Command_Variable command("rtpause",ui->spinBox_Pause->value());
    m_Galil->executeCommand(&command);
}

/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITHIN THE MANUAL MOVE PANEL
/////////////////////////////////////////////////////////////////////////

void ECMControllerGUI::on_pushButton_IncreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value()) * (-1);
    CommandJog beginJog(MotorAxis::Z,jogRate);
    m_Galil->executeCommand(&beginJog);
}

void ECMControllerGUI::on_pushButton_IncreaseJog_released()
{
    CommandStop stop(MotorAxis::Z);
    m_Galil->executeCommand(&stop);
}

void ECMControllerGUI::on_pushButton_DecreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value());
    CommandJog beginJog(MotorAxis::Z,jogRate);
    m_Galil->executeCommand(&beginJog);
}

void ECMControllerGUI::on_pushButton_DecreaseJog_released()
{
    CommandStop stop(MotorAxis::Z);
    m_Galil->executeCommand(&stop);
}


void ECMControllerGUI::on_pushButton_IncreaseRelativeMove_released()
{
    int relativeDistance = abs(ui->spinBox_RelativeMove->value()) * (-1);
    CommandRelativeMove move(MotorAxis::Z, relativeDistance);
    m_Galil->executeCommand(&move);
}

void ECMControllerGUI::on_pushButton_DecreaseRelativeMove_released()
{
    int relativeDistance = abs(ui->spinBox_RelativeMove->value());
    CommandRelativeMove move(MotorAxis::Z, relativeDistance);
    m_Galil->executeCommand(&move);
}

void ECMControllerGUI::on_pushButton_MotorDisable_released()
{
    CommandMotorDisable command;
    command.setDisableAxis(MotorAxis::Z);
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_pushButton_ResetHome_released()
{
    CommandExecuteProfile command(CommandExecuteProfile::ProfileType::HOMING,"latch");
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_pushButton_MoveHome_released()
{
    CommandAbsoluteMove command(MotorAxis::Z,0);
    m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_pushButton_RunProfile_released()
{
    //get the profile name from the GUI
    //CommandExecuteProfile command(CommandExecuteProfile::ProfileType::PROFILE,"touchof");
    //m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_pushButton_UploadProgram_released()
{

}

void ECMControllerGUI::on_pushButton_DownloadProgram_released()
{

}

void ECMControllerGUI::on_pushButton_EstablishTouchoff_released()
{
    CommandExecuteProfile command(CommandExecuteProfile::ProfileType::TOUCHOFF,"touchof");
    m_Galil->executeCommand(&command);
}
