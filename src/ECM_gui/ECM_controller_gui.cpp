#include "ECM_controller_gui.h"
#include "ui_ECM_controller_gui.h"

static const common::Devices TimeDevice = common::SYSTEMCLOCK;


ECMControllerGUI::ECMControllerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ECMControllerGUI),
    m_SensorDisplays(&m_PlotCollection)
{
    //Required registration of MetaTyples from the MotionController interface
    qRegisterMetaType<common::TuplePositionalString>("TuplePositionalString");
    qRegisterMetaType<common_data::MachinePositionalState>("MachinePositionalState");

    qRegisterMetaType<common::TupleSensorString>("TupleSensorString");
    qRegisterMetaType<common_data::SensorState>("SensorState");

    qRegisterMetaType<QCustomPlot::RefreshPriority>("QCustomPlot::RefreshPriority");

    ui->setupUi(this);

    common::EnvironmentTime startTime;
    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,startTime);

    QDate tmp_Date(startTime.year, startTime.month, startTime.dayOfMonth);
    QTime tmp_Time(startTime.hour, startTime.minute, startTime.second, startTime.millisecond);


    m_additionalSensorDisplay = new AdditionalSensorDisplay(&m_PlotCollection);
    m_additionalSensorDisplay->setWindowTitle("ECM Sensors");
    m_additionalSensorDisplay->SetOriginTime(QDateTime(tmp_Date, tmp_Time));

    if(m_additionalSensorDisplay->isHidden())
        m_additionalSensorDisplay->show();

//    m_additionalSensorDisplay->SetOriginTime();
//    m_additionalSensorDisplay->UpdateNonPlottedData(); //this actually updates the data
//    m_additionalSensorDisplay->UpdatePlottedData(); //this actually updates the rendering of the data

    //give collection of plots
    ui->widget_primaryPlot->SupplyPlotCollection(&m_PlotCollection);
    ui->widget_primaryPlot->setOriginTime(QDateTime(tmp_Date, tmp_Time));

    ui->widget_LEDHomeIndicated->setDiameter(5);
    ui->widget_LEDEStop_DIO->setDiameter(5);
    ui->widget_LEDTouchoff_DIO->setDiameter(5);
    ui->widget_LEDTouchoffEstablished->setDiameter(5);

    m_API = new ECM_API();
    m_API->m_Log->setLoggingStartTime(startTime);

    connect(m_API->m_Rigol, SIGNAL(signal_RigolPlottable(common::TupleSensorString,bool)), this, SLOT(slot_NewlyAvailableRigolData(common::TupleSensorString,bool)));
    connect(m_API->m_Rigol, SIGNAL(signal_RigolNewSensorValue(common::TupleSensorString,common_data::SensorState)), this, SLOT(slot_NewSensorData(common::TupleSensorString,common_data::SensorState)));

    connect(m_API->m_Galil, SIGNAL(signal_MCNewMotionState(std::string)), this, SLOT(slot_MCNewMotionState(std::string)));
    this->slot_MCNewMotionState(m_API->m_Galil->getCurrentMCState());
    slot_MCNewDigitalInput(m_API->m_Galil->getCurrent_MCDIO());
    connect(m_API->m_Galil, SIGNAL(signal_MCNewDigitalInput(StatusInputs)), this, SLOT(slot_MCNewDigitalInput(StatusInputs)));
    connect(m_API->m_Galil, SIGNAL(signal_MCNewPosition(common::TuplePositionalString,common_data::MachinePositionalState)), this, SLOT(slot_NewPositionalData(common::TuplePositionalString,common_data::MachinePositionalState)));

    m_WindowMunk = new Window_MunkPowerSupply(m_API->m_Munk);
    m_WindowMunk->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);
    connect(m_WindowMunk,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowPump = new Window_PumpControl(m_API->m_Pump);
    m_WindowPump->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);

    m_WindowRigol = new Window_RigolControl(m_API->m_Rigol);
    m_WindowRigol->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);
    connect(m_WindowRigol,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowTouchoff = new Window_Touchoff(m_API->m_Galil);
    m_WindowTouchoff->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint);

    m_DialogConnections = new Dialog_Connections(m_API);
    m_DialogConnections->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);

    connect(m_API->m_Galil,SIGNAL(signal_GalilHomeIndicated(bool)),this,SLOT(slot_UpdateHomeIndicated(bool)));


    std::vector<common::TupleECMData> plottables = m_API->m_Galil->getPlottables();
    for(unsigned int i = 0; i < plottables.size(); i++)
    {
        slot_AddPlottable(plottables.at(i));
    }
    //readSettings();

//    common::TuplePositionalString tuplePosition;
//    tuplePosition.axisName = "Z Position";
//    this->slot_AddPlottable(tuplePosition);

//    common::TupleSensorString tupleSensor;
//    tupleSensor.sourceName = "TestSource";
//    tupleSensor.sensorName = "TestSensor";
//    ECMPlotIdentifierPtr newPlot = std::make_shared<ECMPlotIdentifier>(tupleSensor, "Sensed_Voltage");
//    ui->widget_primaryPlot->AddPlot(newPlot);
//    ui->widget_primaryPlot->ToggleLegend();

//    common_data::SensorState newSensorMeasurement;
//    newSensorMeasurement.ConstructSensor(common_data::SENSOR_VOLTAGE,"Voltage Top");
//    ((common_data::SensorVoltage*)newSensorMeasurement.getSensorData().get())->SetVoltage(5.0,common_data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
//    newSensorMeasurement.setObservationTime(startTime);
//    this->slot_NewSensorData(tupleSensor,newSensorMeasurement);

//    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//    common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,startTime);
//    newSensorMeasurement.setObservationTime(startTime);
//    this->slot_NewSensorData(tupleSensor,newSensorMeasurement);

}

ECMControllerGUI::~ECMControllerGUI()
{
    delete ui;
}

void ECMControllerGUI::slot_AddPlottable(const common::TupleECMData &data)
{
    common::TupleGeneric* tuple = data.getData();
    QAction *newAction = ui->menuView->addAction(tuple->HumanName(),this, SLOT(slot_DisplayActionTriggered()));
    newAction->setObjectName(tuple->HumanName());
    newAction->setText(tuple->HumanName());
    newAction->setCheckable(true);
    newAction->setChecked(false);
    m_PlottingActionMap.insert(data, newAction);
}

void ECMControllerGUI::slot_RemovePlottable(const common::TupleECMData &data)
{
    QMap<common::TupleECMData, QAction*>::iterator it = m_PlottingActionMap.find(data);
    if(it != m_PlottingActionMap.end())
    {
        ui->menuView->removeAction(it.value());
    }
}

void ECMControllerGUI::slot_DisplayActionTriggered()
{
    //find the item that was selected
    QAction* selectedObject = (QAction*)sender();

    common::TupleECMData key;
    bool found = false;
    for(int i = 0 ; i < m_PlottingActionMap.size() ; i++)
    {
        if(m_PlottingActionMap.values()[i] == selectedObject)
        {
            key = m_PlottingActionMap.keys()[i];
            found = true;
            break;
        }
    }

    if(found == false) //somehow this got out of sync? Ken determine if this condition is even possible
    {
        return;
    }

    if(selectedObject->isChecked())
    {
        ECMPlotIdentifierPtr addPlot = std::make_shared<ECMPlotIdentifier>(key);
        ui->widget_primaryPlot->AddPlot(addPlot, key.getData()->HumanName().toStdString(),false);
        QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(key);
        ui->widget_primaryPlot->RedrawDataSource(plots);
    }else{
        ECMPlotIdentifierPtr removePlot = std::make_shared<ECMPlotIdentifier>(key);
        //ui->widget_primaryPlot->RemoveGraphData(removePlot);
    }
}

void ECMControllerGUI::slot_NewProfileVariableData(const common::TupleProfileVariableString &variable, const common_data::MotionProfileVariableState &state)
{
    m_PlotCollection.UpdateProfileVariablePlots(variable, state);
    QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(variable);
    plots = m_PlotCollection.getPlots(variable);
    ui->widget_primaryPlot->RedrawDataSource(plots);
}

void ECMControllerGUI::slot_NewSensorData(const common::TupleSensorString &sensor, const common_data::SensorState &state)
{
    CreateSensorDisplays(sensor,state.getSensorType());

    m_PlotCollection.UpdateSensorPlots(sensor, state);
    m_SensorDisplays.UpdateNonPlottedData(sensor,state);
    m_additionalSensorDisplay->UpdateNonPlottedData(sensor,state);

    QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(sensor);
    ui->widget_primaryPlot->RedrawDataSource(plots);
    m_SensorDisplays.PlottedDataUpdated(sensor); //this seems to be uneeded based on the call after this
    m_additionalSensorDisplay->UpdatePlottedData(sensor);

    m_API->m_Log->WriteLogSensorState(sensor,state);
}

void ECMControllerGUI::slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state)
{
    ui->lineEdit_MachinePosition->setText(QString::number(state.getPositionalState()->getAxisPosition()));

    m_PlotCollection.UpdatePositionalStatePlots(tuple,state);
//    m_SensorDisplays.UpdateNonPlottedData(tuple,state);
//    m_additionalSensorDisplay->UpdateNonPlottedData(tuple,state);

    QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(tuple);
    ui->widget_primaryPlot->RedrawDataSource(plots);
//    m_SensorDisplays.PlottedDataUpdated(state); //this seems to be uneeded based on the call after this
//    m_additionalSensorDisplay->UpdatePlottedData(state);

    //The OLD way of storing the data is here
//    common::TupleSensorString tupleSensor;
//    tupleSensor.sourceName = "TestSource";
//    tupleSensor.sensorName = "TestSensor";

//    common_data::SensorState newSensorMeasurement;
//    newSensorMeasurement.ConstructSensor(common_data::SENSOR_VOLTAGE,"Voltage Top");
//    ((common_data::SensorVoltage*)newSensorMeasurement.getSensorData().get())->SetVoltage(rand()%100,common_data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
//    newSensorMeasurement.setObservationTime(state.getObservationTime());

//    CreateSensorDisplays(tupleSensor,newSensorMeasurement.getSensorType());

//    m_PlotCollection.UpdateSensorPlots(tupleSensor, newSensorMeasurement);
//    m_SensorDisplays.UpdateNonPlottedData(tupleSensor,newSensorMeasurement);
//    m_additionalSensorDisplay->UpdateNonPlottedData(tupleSensor,newSensorMeasurement);

//    QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(tupleSensor);
//    ui->widget_primaryPlot->RedrawDataSource(plots);
//    m_SensorDisplays.PlottedDataUpdated(tupleSensor); //this seems to be uneeded based on the call after this
//    m_additionalSensorDisplay->UpdatePlottedData(tupleSensor);
}


void ECMControllerGUI::slot_MCNewMotionState(const std::string &state)
{
    ui->lineEdit_GalilState->setText("State: " + QString::fromStdString(state));
}

void ECMControllerGUI::slot_MCNewDigitalInput(const StatusInputs &status)
{
    if(status.getResult(GalilPins::GALIL_PIN_ESTOP))
        ui->widget_LEDEStop_DIO->setColor(QColor(255,0,0));
    else
        ui->widget_LEDEStop_DIO->setColor(QColor(0,0,0));

    if(status.getResult(GalilPins::GALIL_PIN_TOUCHOFF))
        ui->widget_LEDTouchoff_DIO->setColor(QColor(255,0,0));
    else
        ui->widget_LEDTouchoff_DIO->setColor(QColor(0,0,0));
}

void ECMControllerGUI::slot_UpdateHomeIndicated(const bool &value)
{
    if(value)
        ui->widget_LEDHomeIndicated->setColor(QColor(0,255,0));
    else
        ui->widget_LEDHomeIndicated->setColor(QColor(255,0,0));
}


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

    if(!rigolHidden)
        m_WindowRigol->show();

    if(!touchoffHidden)
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

    m_DialogConnections->close();
    m_additionalSensorDisplay->close();

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
    Command_Variable command("backsp",ui->spinBox_RetractSpeed->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_spinBox_PlungeSpeed_editingFinished()
{
    Command_Variable command("forsp",ui->spinBox_PlungeSpeed->value());
    m_API->m_Galil->executeCommand(&command);
}

void ECMControllerGUI::on_doubleSpinBox_CutSpeed_editingFinished()
{
    Command_Variable command("speed",ui->doubleSpinBox_CutSpeed->value());
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
    std::cout<<"Pushbutton increase jog pressed."<<std::endl;
    int jogRate = abs(ui->spinBox_Jog->value()) * (-1);
    CommandJog beginJog(MotorAxis::Z,jogRate);
    m_API->m_Galil->executeCommand(&beginJog);
}

void ECMControllerGUI::on_pushButton_IncreaseJog_released()
{
    std::cout<<"Pushbutton increase jog released."<<std::endl;
    CommandStop stop(MotorAxis::Z);
    m_API->m_Galil->executeCommand(&stop);
}

void ECMControllerGUI::on_pushButton_DecreaseJog_pressed()
{
    std::cout<<"Pushbutton decrease jog released pressed."<<std::endl;
    int jogRate = abs(ui->spinBox_Jog->value());
    CommandJog beginJog(MotorAxis::Z,jogRate);
    m_API->m_Galil->executeCommand(&beginJog);
}

void ECMControllerGUI::on_pushButton_DecreaseJog_released()
{
    std::cout<<"Pushbutton decrease jog released."<<std::endl;
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
    //While executing this type of command
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

void ECMControllerGUI::slot_NewlyAvailableRigolData(const common::TupleSensorString &sensor, const bool &val)
{
    if(val)
    {
        this->slot_AddPlottable(sensor);
        m_additionalSensorDisplay->AddUsableSensor(sensor);
    }
}

//!
//! \brief Create sensor displays
//!
void ECMControllerGUI::CreateSensorDisplays(const common::TupleSensorString &sensor, const common_data::SensorTypes &type)
{
    //if already created sensor object, do nothing.
    if(m_CreatedSensors.contains(sensor) && m_CreatedSensors[sensor] == true)
        return;
    //m_API->m_Log->SetSensorLogFile(sensor);
    MarshalCreateSensorDisplay(sensor, type);
}

void ECMControllerGUI::MarshalCreateSensorDisplay(const common::TupleSensorString &sensor, const common_data::SensorTypes &type)
{
    //invoke this method on the thread that owns this object.
    if (this->thread() != QThread::currentThread())
    {
        QMetaObject::invokeMethod(this, "MarshalCreateSensorDisplay", Qt::BlockingQueuedConnection, Q_ARG(const common::TupleSensorString&, sensor), Q_ARG(const common_data::SensorTypes&, type));
        return;
    }
    if(m_SensorDisplays.CreateSensor(sensor,type) != NULL)
    {
        //set sensor display frame to created sensor
        if(m_DisplaySensor == true)
        {
            if(m_ActiveSensor == sensor)
            {

            }
        }
    }
    else
    {
        return;
    }

    m_additionalSensorDisplay->NewDock(sensor, type);
    m_additionalSensorDisplay->ChangePlotMode(graphing::PlotHandler::PLOT_WINDOW_ONLY);

    m_CreatedSensors.insert(sensor, true);
}


void ECMControllerGUI::on_actionClose_triggered()
{

}

void ECMControllerGUI::on_actionConnections_triggered(bool checked)
{
    if(checked)
        m_DialogConnections->show();
    else
        m_DialogConnections->hide();
}

void ECMControllerGUI::on_actionPump_triggered(bool checked)
{
    if(checked)
        m_WindowPump->show();
    else
        m_WindowPump->hide();
}

void ECMControllerGUI::on_actionPower_Supply_triggered(bool checked)
{
    if(checked)
        m_WindowMunk->show();
    else
        m_WindowMunk->hide();
}

void ECMControllerGUI::on_actionOscilliscope_triggered(bool checked)
{
    if(checked)
        m_WindowRigol->show();
    else
        m_WindowRigol->hide();
}

void ECMControllerGUI::slot_onConnectionWindowVisibilityChanged(const bool &visible)
{
    ui->actionConnections->setChecked(visible);
}

void ECMControllerGUI::slot_onOscilliscopeWindowVisibilityChanged(const bool &visible)
{
    ui->actionOscilliscope->setChecked(visible);
}

void ECMControllerGUI::slot_onPumpWindowVisibilityChanged(const bool &visible)
{
    ui->actionPump->setChecked(visible);
}

void ECMControllerGUI::slot_onPowerSupplyVisibilityWindowChanged(const bool &visible)
{
    ui->actionPower_Supply->setChecked(visible);
}

void ECMControllerGUI::slot_ChangedWindowVisibility(const GeneralDialogWindow::DialogWindowTypes &type, const bool visibility)
{
    switch (type) {
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_OSCILLISCOPE:
        ui->actionOscilliscope->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_POWERSUPPLY:
        ui->actionOscilliscope->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_PUMP:
        ui->actionOscilliscope->setChecked(visibility);
        break;
    default:
        std::cout<<"On slot_ChangedWindowVisibility called with unrecognized dialog window type."<<std::endl;
        break;
    }
}


void ECMControllerGUI::on_actionTouchoff_triggered(bool checked)
{
    if(checked)
        m_WindowTouchoff->show();
    else
        m_WindowTouchoff->hide();
}
