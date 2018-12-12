#include "ECM_controller_gui.h"
#include "ui_ECM_controller_gui.h"

static const common::Devices TimeDevice = common::SYSTEMCLOCK;


ECMControllerGUI::ECMControllerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ECMControllerGUI),
    m_SensorDisplays(&m_PlotCollection)
{

    /*
     * Let us first setup the operational timers as related to
     * operation and the configuration.
     */
    elapsedConfigurationTimer = new QTimer(this);
    elapsedConfigurationTimer->setInterval(1000);

    elapsedOperationTimer = new QTimer(this);
    elapsedOperationTimer->setInterval(1000);

    //Connect the timeouts to the appropriate items within the front panel
    connect(elapsedOperationTimer, SIGNAL(timeout()), this, SLOT(slot_OnUpdateElapsedOperationTime()));
    connect(elapsedConfigurationTimer, SIGNAL(timeout()), this, SLOT(slot_OnUpdateElapsedConfigurationTime()));

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
    connect(m_additionalSensorDisplay,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));


    //give collection of plots
    ui->widget_primaryPlot->SupplyPlotCollection(&m_PlotCollection);
    ui->widget_primaryPlot->setOriginTime(QDateTime(tmp_Date, tmp_Time));
    connect(ui->widget_primaryPlot,SIGNAL(signal_ClearPlottingData()),this,SLOT(on_actionClear_All_Data_triggered()));

    ui->widget_primaryPlotVoltage->SupplyPlotCollection(&m_PlotCollection);
    ui->widget_primaryPlotVoltage->setOriginTime(QDateTime(tmp_Date, tmp_Time));

    ui->widget_primaryPlotCurrent->SupplyPlotCollection(&m_PlotCollection);
    ui->widget_primaryPlotCurrent->setOriginTime(QDateTime(tmp_Date, tmp_Time));

    ui->widget_LEDCommunication->setDiameter(5);
    ui->widget_LEDESTOP->setDiameter(5);
    ui->widget_LEDHomed->setDiameter(5);
    ui->widget_LEDTouchoff->setDiameter(5);

    m_API = new ECM_API();
    m_API->m_Log->setLoggingStartTime(startTime);

    connect(m_API, SIGNAL(signal_ExecutingCollection(ExecutionProperties)),
            this, SLOT(slot_ExecutingConfiguration(ExecutionProperties)));

    connect(m_API, SIGNAL(signal_ExecutingOperation(ExecuteOperationProperties)),
            this, SLOT(slot_ExecutingOperation(ExecuteOperationProperties)));

    connect(m_API, SIGNAL(signal_NewOuterState(std::string)),
            this, SLOT(slot_OnNewOuterMachineState(std::string)));

    connect(m_API, SIGNAL(signal_InPauseEvent()),
            this, SLOT());

    //API Connections
    connect(m_API->m_Rigol, SIGNAL(signal_RigolPlottable(common::TupleSensorString,bool)), this, SLOT(slot_NewlyAvailableRigolData(common::TupleSensorString,bool)));
    connect(m_API->m_Rigol, SIGNAL(signal_RigolNewSensorValue(common::TupleSensorString,common_data::SensorState)), this, SLOT(slot_NewSensorData(common::TupleSensorString,common_data::SensorState)));

    //Galil Connections
    connect(m_API->m_Galil, SIGNAL(signal_MCNewDigitalInput(StatusInputs)), this, SLOT(slot_MCNewDigitalInput(StatusInputs)));
    connect(m_API->m_Galil, SIGNAL(signal_MCNewPosition(common::TuplePositionalString,common_data::MachinePositionalState,bool)), this, SLOT(slot_NewPositionalData(common::TuplePositionalString,common_data::MachinePositionalState,bool)));
    connect(m_API->m_Galil, SIGNAL(signal_MCNewProfileVariableValue(common::TupleProfileVariableString,common_data::MotionProfileVariableState)), this, SLOT(slot_NewProfileVariableData(common::TupleProfileVariableString,common_data::MotionProfileVariableState)));
    connect(m_API->m_Galil, SIGNAL(signal_ErrorCommandCode(CommandType,std::string)), this, SLOT(slot_MCCommandError(CommandType,std::string)));
    connect(m_API->m_Galil,SIGNAL(signal_GalilHomeIndicated(bool)),this,SLOT(slot_UpdateHomeIndicated(bool)));
    connect(m_API->m_Galil,SIGNAL(signal_GalilTouchoffIndicated(bool)),this,SLOT(slot_UpdateTouchoff(bool)));
    connect(m_API->m_Galil, SIGNAL(signal_MCNewMotionState(QString)), this, SLOT(slot_MCNewMotionState(QString)));
    this->slot_MCNewMotionState(QString::fromStdString(m_API->m_Galil->getCurrentMCState()));

    m_WindowCustomMotionCommands = new Window_CustomMotionCommands(m_API->m_Galil);
    m_WindowCustomMotionCommands->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowCustomMotionCommands,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowRigol = new Window_RigolControl(m_API->m_Rigol);
    m_WindowRigol->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowRigol,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowConnections = new Window_DeviceConnections(m_API);
    m_WindowConnections->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowConnections,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)), this, SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));
    connect(m_WindowConnections,SIGNAL(signal_DeviceConnectionComplete(bool)),this,SLOT(slot_DeviceConnectionUpdate(bool)));

    m_WindowProfileConfiguration = new Window_ProfileConfiguration(m_API);
    m_WindowProfileConfiguration->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowProfileConfiguration, SIGNAL(signal_ExecuteProfileCollection(ECMCommand_ExecuteCollection)), this, SLOT(on_ExecuteProfileCollection(ECMCommand_ExecuteCollection)));
    connect(m_WindowProfileConfiguration, SIGNAL(signal_LoadedConfigurationCollection(std::string)), this, SLOT(slot_OnLoadedConfigurationCollection(std::string)));

    m_WindowMotionControl = new Window_MotionControl(m_API->m_Galil);
    m_WindowMotionControl->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowMotionControl,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)), this, SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowPumpControl = new Window_PumpControl(m_API->m_Pump);
    m_WindowPumpControl->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowPumpControl,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)), this, SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowTouchoffControl = new Window_Touchoff(m_API->m_Galil);
    m_WindowTouchoffControl->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowTouchoffControl,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)), this, SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    std::vector<common::TupleECMData> plottables = m_API->m_Galil->getPlottables();
    for(unsigned int i = 0; i < plottables.size(); i++)
    {
        if(plottables.at(i).getType() == common::TupleECMData::DataTypes::POSITION) //if it is a position object we want to default plot this
        {
            ECMPlotIdentifierPtr addPlot = std::make_shared<ECMPlotIdentifier>(plottables.at(i));
            ui->widget_primaryPlot->AddPlot(addPlot, plottables.at(i).getData()->HumanName().toStdString(),false, true);
            QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(plottables.at(i));
            ui->widget_primaryPlot->RedrawDataSource(plots);

            //slot_AddPlottable(plottables.at(i),true);
        }
        else
            slot_AddPlottable(plottables.at(i));
    }

    //Create the state machine object and initialize to the idle state
    stateMachine = new hsm::StateMachine();
    stateMachine->Initialize<ECM::API::ECMState_Idle>(m_API);

    readSettings();

    setupUploadCallbacks();

    m_WindowConnections->connectToAllDevices();

    ProgressStateMachineStates();
}

ECMControllerGUI::~ECMControllerGUI()
{
    delete ui;
}

void ECMControllerGUI::setupUploadCallbacks()
{
    m_API->m_Galil->AddLambda_FinishedUploadingScript(this,[this](const bool &completed, const GalilCurrentProgram &program){
        UNUSED(completed);UNUSED(program);UNUSED(this);
    });
    m_API->m_Galil->AddLambda_FinishedUploadingVariables(this,[this](const bool success, const ProgramVariableList &variableList){
        UNUSED(success);UNUSED(variableList);UNUSED(this);
    });
    m_API->m_Galil->AddLambda_NewMotionProfileState(this,[this](const MotionProfileState &profileState){
       UNUSED(profileState); UNUSED(this);
    });

    m_API->m_Munk->AddLambda_FinishedUploadingSegments(this,[this](const bool success, const DeviceInterface_PowerSupply::FINISH_CODE &finishCode){
        UNUSED(success);UNUSED(finishCode);UNUSED(this);
    });

    m_API->m_Munk->AddLambda_FinishedUploadingPulseMode(this,[this](const bool success, const DeviceInterface_PowerSupply::FINISH_CODE &finishCode){
        UNUSED(success);UNUSED(finishCode);UNUSED(this);
    });

    m_API->m_Pump->AddLambda_FinishedUploadingParameters(this,[this](const bool success, const DeviceInterface_Pump::FINISH_CODE &finishCode){
        UNUSED(success);UNUSED(finishCode);UNUSED(this);
    });

    m_API->m_Pump->AddLambda_FinishedPumpInitialization(this,[this](const bool completed){
        UNUSED(completed);UNUSED(this);
    });
}

void ECMControllerGUI::on_actionClose_triggered()
{
    QCloseEvent event;
    this->closeEvent(&event);
}

void ECMControllerGUI::slot_AddPlottable(const common::TupleECMData &data, const bool &plot)
{
    common::TupleGeneric* tuple = data.getData();
    QAction *newAction = ui->menuView->addAction(tuple->HumanName(),this, SLOT(slot_DisplayActionTriggered()));
    newAction->setObjectName(tuple->HumanName());
    newAction->setText(tuple->HumanName());
    newAction->setCheckable(true);
    newAction->setChecked(false);
    m_PlottingActionMap.insert(data, newAction);

    if(plot)
        newAction->trigger();
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

    for(int i = 0 ; i < m_PlottingActionMap.size() ; i++)
    {
        if((m_PlottingActionMap.values()[i]->isChecked()) && (m_PlottingActionMap.values()[i] != selectedObject))
        {
            //if the item is checked, and not the one that had the current action
            bool oldState = m_PlottingActionMap.values()[i]->blockSignals(true);
            m_PlottingActionMap.values()[i]->setChecked(false);
            key = m_PlottingActionMap.keys()[i];
            ECMPlotIdentifierPtr removePlot = std::make_shared<ECMPlotIdentifier>(key);
            ui->widget_primaryPlot->RemoveGraphData(removePlot);
            m_PlottingActionMap.values()[i]->blockSignals(oldState);
        }
        else if(m_PlottingActionMap.values()[i] == selectedObject)
        {
            key = m_PlottingActionMap.keys()[i];
            ECMPlotIdentifierPtr plot = std::make_shared<ECMPlotIdentifier>(key);
            if(selectedObject->isChecked())
            {
                bool invertAxis = false;
                bool useSecondaryAxis = true;
                if(key.getData()->HumanName().toStdString() == "ppos")
                {
                    useSecondaryAxis = true;
                    invertAxis = true;
                }
                ui->widget_primaryPlot->AddPlot(plot, key.getData()->HumanName().toStdString(), useSecondaryAxis, invertAxis);
                QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(key);
                ui->widget_primaryPlot->RedrawDataSource(plots);
            }
            else
            {
                ui->widget_primaryPlot->RemoveGraphData(plot);
            }
        }
    }
}

void ECMControllerGUI::slot_NewProfileVariableData(const common::TupleProfileVariableString &variable, const common_data::MotionProfileVariableState &state)
{
    common::TupleProfileVariableString tupleVariablePPOS("", "", "ppos");
    if(variable == tupleVariablePPOS)
    {
        double countPosition = state.getProfileStateVariable()->getVariableValue();
        state.getProfileStateVariable()->setVariableValue(countPosition/10.0);
        state.getProfileStateVariable()->setVariableUnit("um");
    }

    //First, write the data to the logs
    m_API->m_Log->WriteLogProfileVariableState(variable,state);

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

    //First, write the data to the logs
    m_API->m_Log->WriteLogSensorState(sensor,state);

    m_SensorDisplays.PlottedDataUpdated(sensor); //this seems to be uneeded based on the call after this
    m_additionalSensorDisplay->UpdatePlottedData(sensor);

    ui->widget_primaryPlot->RedrawDataSource(plots);
    ui->widget_primaryPlotVoltage->RedrawDataSource(plots);
    ui->widget_primaryPlotCurrent->RedrawDataSource(plots);

}

void ECMControllerGUI::slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state, const bool &valueChanged)
{
    m_PlotCollection.UpdatePositionalStatePlots(tuple,state);
    //    m_SensorDisplays.UpdateNonPlottedData(tuple,state);
    //    m_additionalSensorDisplay->UpdateNonPlottedData(tuple,state);

    QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(tuple);
    ui->widget_primaryPlot->RedrawDataSource(plots);
    //    m_SensorDisplays.PlottedDataUpdated(state); //this seems to be uneeded based on the call after this
    //    m_additionalSensorDisplay->UpdatePlottedData(state);

    if(valueChanged)
        m_API->m_Log->WriteLogMachinePositionalState(tuple,state);

    ProgressStateMachineStates();
}

void ECMControllerGUI::slot_MCNewMotionState(const QString &state)
{
    ui->lineEdit_GalilState->setText("State: " + state);
}

void ECMControllerGUI::slot_MCNewDigitalInput(const StatusInputs &status)
{
    if(status.getResult(GalilPins::GALIL_PIN_ESTOP))
        ui->widget_LEDESTOP->setColor(QColor(255,0,0));
    else
        ui->widget_LEDESTOP->setColor(QColor(0,0,0));
}

void ECMControllerGUI::readSettings()
{
    QSettings settings("ECMController", "Machine Automation");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();

    bool sensorDisplayHidden = settings.value("sensorDisplayed", false).toBool();
    bool windowProfileConfigurationHidden = settings.value("profileConfigurationDisplayed",false).toBool();
    bool motionControlDisplayHidden = settings.value("motionControlDisplayed", false).toBool();
    bool touchoffControlDisplayHidden = settings.value("touchoffControlDisplayed", false).toBool();
    bool pumpControlDisplayHidden = settings.value("pumpControlDisplayed", false).toBool();
    bool profileConfigurationDisplayHidden = settings.value("profileConfigurationDisplayed", false).toBool();
    bool rigolControlDisplayHidden = settings.value("rigolControlDisplayed", false).toBool();
    bool connectionDisplayHidden = settings.value("connectionsDisplayed", false).toBool();
    bool customMotionControlDisplayHidden = settings.value("customMotionDisplayed", false).toBool();

    if(!sensorDisplayHidden)
        m_additionalSensorDisplay->show();

    if(!windowProfileConfigurationHidden)
        m_WindowProfileConfiguration->show();

    if(!motionControlDisplayHidden)
        m_WindowMotionControl->show();

    if(!touchoffControlDisplayHidden)
        m_WindowTouchoffControl->show();

    if(!pumpControlDisplayHidden)
        m_WindowPumpControl->show();

    if(!profileConfigurationDisplayHidden)
        m_WindowCustomMotionCommands->show();

    if(!rigolControlDisplayHidden)
        m_WindowRigol->show();

    if(!connectionDisplayHidden)
        m_WindowConnections->show();

    if(!customMotionControlDisplayHidden)
        m_WindowCustomMotionCommands->show();

    resize(size);
    move(pos);
}

void ECMControllerGUI::closeEvent(QCloseEvent *event)
{
    if(!m_API->m_Galil->stateInterface->isMotorEnabled())
    {
        QSettings settings("ECMController", "Machine Automation");
        settings.setValue("pos", pos());
        settings.setValue("size", size());

        settings.setValue("sensorDisplayed",m_additionalSensorDisplay->isWindowHidden());
        settings.setValue("profileConfigurationDisplayed",m_WindowProfileConfiguration->isWindowHidden());
        settings.setValue("motionControlDisplayed",m_WindowMotionControl->isWindowHidden());
        settings.setValue("touchoffControlDisplayed",m_WindowTouchoffControl->isWindowHidden());
        settings.setValue("pumpControlDisplayed",m_WindowPumpControl->isWindowHidden());
        settings.setValue("profileConfigurationDisplayed",m_WindowCustomMotionCommands->isWindowHidden());
        settings.setValue("rigolControlDisplayed",m_WindowRigol->isWindowHidden());
        settings.setValue("connectionsDisplayed",m_WindowConnections->isWindowHidden());
        settings.setValue("customMotionDisplayed",m_WindowCustomMotionCommands->isWindowHidden());

        m_additionalSensorDisplay->close();
        m_WindowProfileConfiguration->close();
        m_WindowMotionControl->close();
        m_WindowTouchoffControl->close();
        m_WindowPumpControl->close();
        m_WindowCustomMotionCommands->close();
        m_WindowRigol->close();
        m_WindowConnections->close();
        m_WindowCustomMotionCommands->close();

        event->accept();
    }
    else //the motor is not currently disabled, and therefore we will block the application from closing
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("The motor is still currently enabled.");
        msgBox.setInformativeText("Please disable the motor properly before shutting down the program.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        UNUSED(ret);
        event->ignore();
    }
}

/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITHIN THE MOTOR COMMAND PANELS
/////////////////////////////////////////////////////////////////////////

void ECMControllerGUI::on_pushButton_MotorEnable_released()
{
    CommandMotorEnablePtr command = std::make_shared<CommandMotorEnable>();
    command->setEnableAxis(MotorAxis::Z);
    m_API->m_Galil->executeCommand(command);
}

void ECMControllerGUI::on_pushButton_MotorDisable_released()
{
    CommandMotorDisablePtr command = std::make_shared<CommandMotorDisable>();
    m_API->m_Galil->executeCommand(command);
}

void ECMControllerGUI::on_pushButton_ResetHome_released()
{
    CommandExecuteProfilePtr command = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::HOMING,"latch");
    m_API->m_Galil->executeCommand(command);
}

void ECMControllerGUI::on_pushButton_MoveHome_released()
{
    //First set the move to home speed based on the jog value
    int jogMoveSpeed = m_WindowMotionControl->getCurrentJogSpeed();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(MotorAxis::Z, jogMoveSpeed);
    m_API->m_Galil->executeCommand(commandSpeed);

    //Next, transmit the move to home command
    CommandAbsoluteMovePtr command = std::make_shared<CommandAbsoluteMove>(MotorAxis::Z,0);
    m_API->m_Galil->executeCommand(command);
}


void ECMControllerGUI::slot_NewlyAvailableRigolData(const common::TupleSensorString &sensor, const bool &val)
{
    if(val)
    {
       common::TupleECMData sensorData(sensor);
       ECMPlotIdentifierPtr addPlot = std::make_shared<ECMPlotIdentifier>(sensorData);
        if(sensor.measurementName == "MARea")
        {
            ui->widget_primaryPlotCurrent->AddPlot(addPlot, sensorData.getData()->HumanName().toStdString(),false, false);
            QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(sensorData);
            ui->widget_primaryPlotCurrent->RedrawDataSource(plots);
        }
        else if(sensor.measurementName == "VTOP")
        {
            ui->widget_primaryPlotVoltage->AddPlot(addPlot, sensorData.getData()->HumanName().toStdString(),false, false);
            QList<std::shared_ptr<common_data::observation::IPlotComparable> > plots = m_PlotCollection.getPlots(sensorData);
            ui->widget_primaryPlotVoltage->RedrawDataSource(plots);
        }

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
    if(m_SensorDisplays.CreateSensor(sensor,type) != nullptr)
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

void ECMControllerGUI::on_actionPump_Window_triggered(bool checked)
{
    if(checked)
        m_WindowPumpControl->show();
    else
        m_WindowPumpControl->hide();
}

void ECMControllerGUI::on_actionTouchoff_Window_triggered(bool checked)
{
    if(checked)
        m_WindowTouchoffControl->show();
    else
        m_WindowTouchoffControl->hide();
}

void ECMControllerGUI::on_actionProfile_Configuration_triggered(bool checked)
{
    if(checked)
        m_WindowProfileConfiguration->show();
    else
        m_WindowProfileConfiguration->hide();
}

void ECMControllerGUI::on_actionMotion_Control_triggered(bool checked)
{
    if(checked)
        m_WindowMotionControl->show();
    else
        m_WindowMotionControl->hide();
}

void ECMControllerGUI::on_actionConnections_triggered(bool checked)
{
    if(checked)
        m_WindowConnections->show();
    else
        m_WindowConnections->hide();
}

void ECMControllerGUI::on_actionOscilliscope_triggered(bool checked)
{
    if(checked)
        m_WindowRigol->show();
    else
        m_WindowRigol->hide();
}

void ECMControllerGUI::on_actionCustom_Motion_Commands_triggered(bool checked)
{
    if(checked)
        m_WindowCustomMotionCommands->show();
    else
        m_WindowCustomMotionCommands->hide();
}

void ECMControllerGUI::on_actionOpen_Sensors_Window_triggered(bool checked)
{
//    if(checked)
//        m_additionalSensorDisplay->show();
//    else
//        m_additionalSensorDisplay->hide();
}

void ECMControllerGUI::slot_ChangedWindowVisibility(const GeneralDialogWindow::DialogWindowTypes &type, const bool visibility)
{
    switch (type) {
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_SENSOR_DISPLAY:
        ui->actionOpen_Sensors_Window->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_CONNECTIONS:
        ui->actionConnections->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_PUMP:
        ui->actionPump_Window->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_OSCILLISCOPE:
        ui->actionOscilliscope->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_TOUCHOFF:
        ui->actionTouchoff_Window->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_MOTION_PROFILE:
        ui->actionMotion_Profile->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_CUSTOM_MOTION_COMMANDS:
        ui->actionCustom_Motion_Commands->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_MOTION_CONTROL:
        ui->actionMotion_Control->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_OPERATION_CONFIGURATION:
        ui->actionProfile_Configuration->setChecked(visibility);
        break;
    default:
        std::cout<<"On slot_ChangedWindowVisibility called with unrecognized dialog window type."<<std::endl;
        break;
    }
}

void ECMControllerGUI::slot_OnLoadedConfigurationCollection(const std::string &filePath)
{
    ui->lineEdit_ConfigurationPath->setText(QString::fromStdString(filePath));
}

void ECMControllerGUI::slot_ExecutingConfiguration(const ExecutionProperties &props)
{
    if(props.getOperatingCondition() == ExecutionProperties::ExecutionCondition::BEGINNING)
    {
        ui->lineEdit_OperationIndexTotal->setText(QString::number(props.getMaxIndex()));
        ui->lineEdit_ConfigurationTime->setText(QString::number(0));
        elapsedConfigurationTimer->start();
    }
    else
    {
        elapsedConfigurationTimer->stop();
    }
}

void ECMControllerGUI::slot_ExecutingOperation(const ExecuteOperationProperties &props)
{
    if(props.getOperatingCondition() == ExecutionProperties::ExecutionCondition::BEGINNING)
    {
        ui->lineEdit_OperationName->setText(QString::fromStdString(props.getOperationName()));
        ui->lineEdit_OperationIndex->setText(QString::number(props.getCurrentIndex()));

        m_WindowProfileConfiguration->executingProfileIndex(props.getCurrentIndex());

        EnvironmentTime startTime = props.getTime();
        QDate tmp_Date(startTime.year, startTime.month, startTime.dayOfMonth);
        QTime tmp_Time(startTime.hour, startTime.minute, startTime.second, startTime.millisecond);

        //Clear all of the exisitng data that may be on the plots
        m_PlotCollection.ClearAllData();

        //Update plot properties of the current start time
        ui->widget_primaryPlot->setOriginTime(QDateTime(tmp_Date, tmp_Time));
        ui->widget_primaryPlotCurrent->setOriginTime(QDateTime(tmp_Date, tmp_Time));
        ui->widget_primaryPlotVoltage->setOriginTime(QDateTime(tmp_Date, tmp_Time));
        m_additionalSensorDisplay->SetOriginTime(QDateTime(tmp_Date, tmp_Time));

        this->configurationStart = startTime;
        ui->lineEdit_OperationTime->setText(QString::number(0));

        elapsedOperationTimer->start();
    }
    else
    {
        elapsedOperationTimer->stop();
    }

}


void ECMControllerGUI::on_pushButton_Stop_released()
{
    m_API->action_StopMachine();

    ECM::API::AbstractStateECMProcess* currentState = static_cast<ECM::API::AbstractStateECMProcess*>(stateMachine->getCurrentOuterState());
    currentState->stopProcess();

    ProgressStateMachineStates();
}

void ECMControllerGUI::on_actionClear_All_Data_triggered()
{
    m_PlotCollection.ClearAllData();
}

void ECMControllerGUI::slot_MCCommandError(const CommandType &type, const string &description)
{
    switch (type) {
    case CommandType::SET_VARIABLE:
    {
        //There was a problem setting a new variable, therefore let us reset the GUI to the current latest and greatest
        //this->slot_MCNEWProgramVariableList(m_API->m_Galil->stateInterface->galilProgram->getVariableList());
        break;
    }
    default:
        std::cout<<"There was an existing error not caught: "<<description<<std::endl;
        break;
    }
}

void ECMControllerGUI::on_ExecuteProfileCollection(const ECMCommand_ExecuteCollection &collection)
{
    ECMCommand_ExecuteCollection executeCollection(collection);

    //first check that we can log where we want to
    QString partNumber = ui->lineEdit_PartNumber->text();
    QString serialNumber = ui->lineEdit_SerialNumber->text();

    bool validPath = m_API->m_Log->checkLoggingPath(partNumber.toStdString(),serialNumber.toStdString());
    bool clearContents = true;

    if(!validPath)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText("The provided Part/Serial number combination already exists.");
        msgBox.setInformativeText("Do you want to overwrite or append the existing contents?");
        QAbstractButton* pButtonAppend = msgBox.addButton(tr("Append"), QMessageBox::AcceptRole);
        QAbstractButton* pButtonOverwrite = msgBox.addButton(tr("Overwrite"), QMessageBox::AcceptRole);
        QAbstractButton* pButtonCancel = msgBox.addButton(tr("Cancel"), QMessageBox::AcceptRole);
        msgBox.exec();

        if(msgBox.clickedButton() == pButtonCancel)
        {
            /*
                 * There is nothing to do at this point with the profile and we should wait
                 * for user to update the appropriate part and serial numbers and wait for
                 * them to try again.
                 */
            return;
        }
        else if(msgBox.clickedButton() == pButtonOverwrite)
        {
            clearContents = true;
        }
        else if(msgBox.clickedButton() == pButtonAppend)
        {
            clearContents = false;
        }
        else
            return;
    }

    //update the execution names per the GUI
    executeCollection.setPartNumber(partNumber.toStdString());
    executeCollection.setSerialNumber(serialNumber.toStdString());
    executeCollection.setOverwriteLogs(clearContents);

    ECM::API::AbstractStateECMProcess* currentOuterState = static_cast<ECM::API::AbstractStateECMProcess*>(stateMachine->getCurrentOuterState());
    currentOuterState->executeCollection(executeCollection);
    ProgressStateMachineStates();
}

void ECMControllerGUI::slot_OnNewOuterMachineState(const std::string &stateString)
{
    ui->lineEdit_OuterState->setText(QString::fromStdString(stateString));
}

void ECMControllerGUI::slot_OnExecutionPause(const std::string notificationText)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("The current machining process has entered a pause state.");
    msgBox.setInformativeText(QString::fromStdString(notificationText));
    QAbstractButton* pButtonOk = msgBox.addButton(tr("Ok"), QMessageBox::AcceptRole);
    QAbstractButton* pButtonCancel = msgBox.addButton(tr("Cancel"), QMessageBox::RejectRole);
    msgBox.exec();

    ECM::API::AbstractStateECMProcess* currentState = static_cast<ECM::API::AbstractStateECMProcess*>(stateMachine->getCurrentState());

    if(msgBox.clickedButton() == pButtonOk)
    {
        currentState->continueProcess();
    }
    else if(msgBox.clickedButton() == pButtonCancel)
    {
        currentState->stopProcess();
    }
    else
        currentState->stopProcess();

    ProgressStateMachineStates();
}

//!
//! \brief Cause the state machine to update it's states
//!
void ECMControllerGUI::ProgressStateMachineStates()
{
    m_Mutex_StateMachine.lock();
    stateMachine->ProcessStateTransitions();
    stateMachine->UpdateStates();
    m_Mutex_StateMachine.unlock();
}

void ECMControllerGUI::slot_DeviceConnectionUpdate(const bool &connected)
{
    if(connected)
    {
        ui->widget_LEDCommunication->setColor(QColor(0,255,0));
    }else
    {
        ui->widget_LEDCommunication->setColor(QColor(255,0,0));
    }
}

void ECMControllerGUI::slot_UpdateTouchoff(const bool &value)
{
    if(value)
        ui->widget_LEDTouchoff->setColor(QColor(0,255,0));
    else
        ui->widget_LEDTouchoff->setColor(QColor(255,0,0));
}
void ECMControllerGUI::slot_UpdateHomeIndicated(const bool &value)
{
    if(value)
        ui->widget_LEDHomed->setColor(QColor(0,255,0));
    else
        ui->widget_LEDHomed->setColor(QColor(255,0,0));
}

void ECMControllerGUI::updateMCIndicators(const MotionProfileState &profileState)
{
    switch (profileState.getProfileState()->getType()) {
    case MotionProfile::ProfileType::TOUCHOFF:
    {
        ProfileState_Touchoff* castState = (ProfileState_Touchoff*)profileState.getProfileState().get();
        switch (castState->getCurrentCode()) {
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
            ui->widget_LEDTouchoff->setColor(QColor(255,0,0));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
            ui->widget_LEDTouchoff->setColor(QColor(255,255,0));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
            ui->widget_LEDTouchoff->setColor(QColor(0,255,0));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::CLEARED:
            ui->widget_LEDTouchoff->setColor(QColor(255,0,0));
            break;
        default:
            break;
        }
        break;
    }
    case MotionProfile::ProfileType::HOMING:
    {
        ProfileState_Homing* castState = (ProfileState_Homing*)profileState.getProfileState().get();
        switch (castState->getCurrentCode()) {
        case ProfileState_Homing::HOMINGProfileCodes::COMPLETE:
        {
            ui->widget_LEDHomed->setColor(QColor(0,255,0));
            break;
        }
        case ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE:
        {
            ui->widget_LEDHomed->setColor(QColor(255,0,0));
            break;
        }
        default:
            break;
        }

    }
    default:
        break;
    }
}

void ECMControllerGUI::on_pushButton_RunAutomatedProfile_released()
{
    ECMCommand_ExecuteCollection executeCollection = m_WindowProfileConfiguration->getCurrentCollection();
    if(executeCollection.getActiveCollectionSize() > 0)
    {
        on_ExecuteProfileCollection(executeCollection);
    }
}

void ECMControllerGUI::on_pushButton_LoadAutomatedProfile_released()
{
    char* ECMPath = getenv("ECM_ROOT");
    std::string loadPath = "";

    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir initialDirectory(QString::fromStdString(rootPath + "/"));
        initialDirectory.mkpath(QString::fromStdString(rootPath + "/"));

        loadPath = initialDirectory.absolutePath().toStdString() + "/";
    }

    std::string extensionFilter = "Open JSON Files (*.json)";
    QString filePath = loadFileDialog(loadPath,extensionFilter);

    if(!filePath.isEmpty() && !filePath.isNull()){
        ui->lineEdit_ConfigurationPath->setText(filePath);
        m_WindowProfileConfiguration->openFromFile(filePath);
    }
}

QString ECMControllerGUI::loadFileDialog(const std::string &filePath, const std::string &nameFilter)
{
    QString fullFilePath = "";
    QFileDialog fileDialog(this, "Choose profile to open");
    QDir galilProgramDirectory(QString::fromStdString(filePath));
    fileDialog.setDirectory(galilProgramDirectory);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
//    QString nameFilter = "Open TXT Files (*.";
//    nameFilter += QString::fromStdString(suffix) + ")";
    fileDialog.setNameFilter(QString::fromStdString(nameFilter));
    //fileDialog.setDefaultSuffix(QString::fromStdString(suffix));
    fileDialog.exec();
    if(fileDialog.selectedFiles().size() > 0)
    {
        fullFilePath = fileDialog.selectedFiles().first();
    }
    return fullFilePath;
}

void ECMControllerGUI::slot_OnUpdateElapsedOperationTime()
{
    EnvironmentTime currentTime;
    EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK, currentTime);

    ui->lineEdit_OperationTime->setText(QString::number((currentTime - operationStart)/(1000*1000)));
}

void ECMControllerGUI::slot_OnUpdateElapsedConfigurationTime()
{
    EnvironmentTime currentTime;
    EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK, currentTime);

    ui->lineEdit_ConfigurationTime->setText(QString::number((currentTime - configurationStart)/(1000*1000)));
}
