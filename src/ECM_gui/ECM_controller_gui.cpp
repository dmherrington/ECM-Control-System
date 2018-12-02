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

    //Create the state machine object and initialize to the idle state
    stateMachine = new hsm::StateMachine();
    stateMachine->Initialize<ECM::API::ECMState_Idle>(m_API);

    //API Connections
    connect(m_API->m_Rigol, SIGNAL(signal_RigolPlottable(common::TupleSensorString,bool)), this, SLOT(slot_NewlyAvailableRigolData(common::TupleSensorString,bool)));
    connect(m_API->m_Rigol, SIGNAL(signal_RigolNewSensorValue(common::TupleSensorString,common_data::SensorState)), this, SLOT(slot_NewSensorData(common::TupleSensorString,common_data::SensorState)));
    connect(m_API, SIGNAL(signal_MCNewMotionState(std::string)), this, SLOT(slot_MCNewMotionState(std::string)));
    //Updates required per API
    this->slot_MCNewMotionState(m_API->m_Galil->getCurrentMCState());
    slot_MCNewDigitalInput(m_API->m_Galil->getCurrent_MCDIO());

    //Galil Connections
    connect(m_API->m_Galil, SIGNAL(signal_MCNewDigitalInput(StatusInputs)), this, SLOT(slot_MCNewDigitalInput(StatusInputs)));
    connect(m_API->m_Galil, SIGNAL(signal_MCNewPosition(common::TuplePositionalString,common_data::MachinePositionalState,bool)), this, SLOT(slot_NewPositionalData(common::TuplePositionalString,common_data::MachinePositionalState,bool)));
    connect(m_API->m_Galil, SIGNAL(signal_MCNewProfileVariableValue(common::TupleProfileVariableString,common_data::MotionProfileVariableState)), this, SLOT(slot_NewProfileVariableData(common::TupleProfileVariableString,common_data::MotionProfileVariableState)));
    connect(m_API->m_Galil, SIGNAL(signal_GalilUpdatedProfileState(MotionProfileState)), this, SLOT(slot_UpdatedMotionProfileState(MotionProfileState)));
    connect(m_API->m_Galil, SIGNAL(signal_ErrorCommandCode(CommandType,std::string)), this, SLOT(slot_MCCommandError(CommandType,std::string)));
    connect(m_API->m_Galil, SIGNAL(signal_MCNewProgramLabelList(ProgramLabelList)), this, SLOT(slot_MCNewProgramLabels(ProgramLabelList)));
    connect(m_API->m_Galil,SIGNAL(signal_GalilHomeIndicated(bool)),this,SLOT(slot_UpdateHomeIndicated(bool)));

    m_WindowCustomMotionCommands = new Window_CustomMotionCommands(m_API->m_Galil);
    m_WindowCustomMotionCommands->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowCustomMotionCommands,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowMotionProfile = new Window_MotionProfile(m_API->m_Galil);
    m_WindowMotionProfile->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowMotionProfile,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowRigol = new Window_RigolControl(m_API->m_Rigol);
    m_WindowRigol->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowRigol,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowConnections = new Window_DeviceConnections(m_API);
    m_WindowConnections->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowConnections,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)), this, SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    m_WindowProfileConfiguration = new Window_ProfileConfiguration(m_API);
    connect(m_WindowProfileConfiguration, SIGNAL(signal_ExecuteProfileCollection(ECMCommand_ExecuteCollection)), this, SLOT(on_ExecuteProfileCollection(ECMCommand_ExecuteCollection)));
    connect(m_WindowProfileConfiguration, SIGNAL(signal_LoadProfileCollection(ECMCommand_ProfileCollection)), this, SLOT(slot_LoadProfileCollection(ECMCommand_ProfileCollection)));


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

    readSettings();

    m_MotionControl = new Widget_MotionControl(m_API->m_Galil);
    m_WindowProfileConfiguration->show();
    //m_WindowConnections->connectToAllDevices();

    setupUploadCallbacks();

    ProgressStateMachineStates();
}

ECMControllerGUI::~ECMControllerGUI()
{
    delete ui;
}

void ECMControllerGUI::setupUploadCallbacks()
{
    m_API->m_Galil->AddLambda_FinishedUploadingScript(this,[this](const bool &completed, const GalilCurrentProgram &program){
        UNUSED(completed);UNUSED(program);
        this->ProgressStateMachineStates();
    });
    m_API->m_Galil->AddLambda_FinishedUploadingVariables(this,[this](const bool success, const ProgramVariableList &variableList){
        UNUSED(success);UNUSED(variableList);
        this->ProgressStateMachineStates();
    });
    m_API->m_Galil->AddLambda_NewMotionProfileState(this,[this](const MotionProfileState &profileState){

        this->ProgressStateMachineStates();
    });

    m_API->m_Munk->AddLambda_FinishedUploadingSegments(this,[this](const bool success, const DeviceInterface_PowerSupply::FINISH_CODE &finishCode){
        UNUSED(success);UNUSED(finishCode);
        this->ProgressStateMachineStates();
    });

    m_API->m_Munk->AddLambda_FinishedUploadingPulseMode(this,[this](const bool success, const DeviceInterface_PowerSupply::FINISH_CODE &finishCode){
        UNUSED(success);UNUSED(finishCode);
        this->ProgressStateMachineStates();
    });

    m_API->m_Pump->AddLambda_FinishedUploadingParameters(this,[this](const bool success, const DeviceInterface_Pump::FINISH_CODE &finishCode){
        UNUSED(success);UNUSED(finishCode);
        this->ProgressStateMachineStates();
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
}

void ECMControllerGUI::slot_MCNewMotionState(const std::string &state)
{
    ui->lineEdit_GalilState->setText("State: " + QString::fromStdString(state));
}

void ECMControllerGUI::slot_MCNewDigitalInput(const StatusInputs &status)
{
    if(status.getResult(GalilPins::GALIL_PIN_ESTOP))
        ui->widget_LEDESTOP->setColor(QColor(255,0,0));
    else
        ui->widget_LEDESTOP->setColor(QColor(0,0,0));
}

void ECMControllerGUI::slot_MCNewProgramLabels(const ProgramLabelList &labels)
{
    //ui->comboBox_ProgramProfiles->clear();

    std::map<std::string,int> programLabels = labels.getLabelMap();
    std::map<std::string,int>::iterator it = programLabels.begin();
    for(;it!=programLabels.end();++it)
    {
        //ui->comboBox_ProgramProfiles->addItem(QString::fromStdString(it->first));
    }
}

void ECMControllerGUI::slot_UpdateHomeIndicated(const bool &value)
{
    if(value)
        ui->widget_LEDHomed->setColor(QColor(0,255,0));
    else
        ui->widget_LEDHomed->setColor(QColor(255,0,0));
}


void ECMControllerGUI::readSettings()
{
    QSettings settings("Trolltech", "Application Example");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();

    bool sensorHidden = settings.value("sensorDisplayed", false).toBool();
    bool rigolHidden = settings.value("rigolDisplayed", false).toBool();
    bool motionProfileHidden = settings.value("motionProfileDisplayed", false).toBool();
    bool customMotionCommands = settings.value("customMotionDisplayed", false).toBool();

    if(!sensorHidden)
        m_additionalSensorDisplay->show();

    if(!rigolHidden)
        m_WindowRigol->show();

    if(!motionProfileHidden)
        m_WindowMotionProfile->show();

    if(!customMotionCommands)
        m_WindowCustomMotionCommands->show();

    resize(size);
    move(pos);
}

void ECMControllerGUI::closeEvent(QCloseEvent *event)
{
    if(!m_API->m_Galil->stateInterface->isMotorEnabled())
    {
        QSettings settings("Trolltech", "Application Example");
        settings.setValue("pos", pos());
        settings.setValue("size", size());

        settings.setValue("sensorDisplayed",m_additionalSensorDisplay->isWindowHidden());
        settings.setValue("rigolDisplayed",m_WindowRigol->isWindowHidden());
        settings.setValue("motionProfileDisplayed",m_WindowMotionProfile->isWindowHidden());
        settings.setValue("customMotionDisplayed",m_WindowCustomMotionCommands->isWindowHidden());

        m_additionalSensorDisplay->close();
        m_WindowRigol->close();
        m_WindowMotionProfile->close();
        m_WindowCustomMotionCommands->close();
        m_WindowConnections->close();

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
    int jogMoveSpeed = m_MotionControl->getCurrentJogSpeed();
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

void ECMControllerGUI::on_actionMotion_Profile_triggered(bool checked)
{
    if(checked)
        m_WindowMotionProfile->show();
    else
        m_WindowMotionProfile->hide();
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
    if(checked)
        m_additionalSensorDisplay->show();
    else
        m_additionalSensorDisplay->hide();
}

void ECMControllerGUI::slot_ChangedWindowVisibility(const GeneralDialogWindow::DialogWindowTypes &type, const bool visibility)
{
    switch (type) {
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_CONNECTIONS:
        ui->actionConnections->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_OSCILLISCOPE:
        ui->actionOscilliscope->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_MOTION_PROFILE:
        ui->actionMotion_Profile->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_CUSTOM_MOTION_COMMANDS:
        ui->actionCustom_Motion_Commands->setChecked(visibility);
        break;
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_SENSOR_DISPLAY:
        ui->actionOpen_Sensors_Window->setChecked(visibility);
        break;
    default:
        std::cout<<"On slot_ChangedWindowVisibility called with unrecognized dialog window type."<<std::endl;
        break;
    }
}

void ECMControllerGUI::on_pushButton_RunExplicitProfile_released()
{

//    //first check that we can log where we want to
//    QString partNumber = ui->lineEdit_PartNumber->text();
//    QString serialNumber = ui->lineEdit_SerialNumber->text();
//    QString profileName = ui->comboBox_ProgramProfiles->currentText();

//    bool validPath = m_API->m_Log->checkLoggingPath(partNumber.toStdString(),serialNumber.toStdString());

//    bool clearContents = true;

//    if(!validPath)
//    {
//        QMessageBox msgBox;
//        msgBox.setIcon(QMessageBox::Question);
//        msgBox.setText("The provided Part/Serial number combination already exists.");
//        msgBox.setInformativeText("Do you want to overwrite or append the existing contents?");
//        QAbstractButton* pButtonAppend = msgBox.addButton(tr("Append"), QMessageBox::AcceptRole);
//        QAbstractButton* pButtonOverwrite = msgBox.addButton(tr("Overwrite"), QMessageBox::AcceptRole);
//        QAbstractButton* pButtonCancel = msgBox.addButton(tr("Cancel"), QMessageBox::AcceptRole);

//        //        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//        //        msgBox.setDefaultButton(QMessageBox::Yes);
//        msgBox.exec();

//        if(msgBox.clickedButton() == pButtonCancel)
//        {
//            /*
//             * There is nothing to do at this point with the profile and we should wait
//             * for user to update the appropriate part and serial numbers and wait for
//             * them to try again.
//             */
//            return;
//        }
//        else if(msgBox.clickedButton() == pButtonOverwrite)
//        {

//        }
//        else if(msgBox.clickedButton() == pButtonAppend)
//        {
//            clearContents = false;
//        }
//        else
//            return;
//    }

//    //If the pump isn't initialized, we have to pause and wait before executing it
//    if(!m_API->m_Pump->isPumpInitialized())
//    {
//        connect(m_API->m_Pump, &Westinghouse510::signal_PumpInitialized, this,
//                [this,partNumber,serialNumber,profileName,clearContents]()
//        {
//            disconnect(m_API->m_Pump,SIGNAL(signal_PumpInitialized()), this, nullptr);

//            this->setupMachiningSequence(partNumber.toStdString(), serialNumber.toStdString(),
//                                         profileName.toStdString(), clearContents);
//        });

//        //If the pump isnt running, let us issue a command to start the pump
//        if(!m_API->m_Pump->isPumpRunning())
//        {
//            registers_WestinghousePump::Register_OperationSignal newOps;
//            newOps.shouldRun(true);
//            m_API->m_Pump->setPumpOperations(newOps);
//        }
//    }
//    else
//    {
//        this->setupMachiningSequence(partNumber.toStdString(), serialNumber.toStdString(),
//                                     profileName.toStdString(), clearContents);
//    }
}


void ECMControllerGUI::setupMachiningSequence(const std::string &partNumber, const std::string &serialNumber, const std::string &profileName,const bool &clearContents)
{
    common::EnvironmentTime startTime = m_API->executeMachiningProcess(partNumber, serialNumber,
                                                                            profileName, "", clearContents);
    QDate tmp_Date(startTime.year, startTime.month, startTime.dayOfMonth);

    QTime tmp_Time(startTime.hour, startTime.minute, startTime.second, startTime.millisecond);

    //Update plot properties of the current start time
    ui->widget_primaryPlot->setOriginTime(QDateTime(tmp_Date, tmp_Time));
    ui->widget_primaryPlotCurrent->setOriginTime(QDateTime(tmp_Date, tmp_Time));
    ui->widget_primaryPlotVoltage->setOriginTime(QDateTime(tmp_Date, tmp_Time));
    m_additionalSensorDisplay->SetOriginTime(QDateTime(tmp_Date, tmp_Time));

    //Clear all of the exisitng data that may be on the plots
    m_PlotCollection.ClearAllData();

}

void ECMControllerGUI::on_pushButton_Stop_released()
{
    m_API->action_StopMachine();
}

void ECMControllerGUI::on_actionClear_All_Data_triggered()
{
    m_PlotCollection.ClearAllData();
}

void ECMControllerGUI::slot_UpdatedMotionProfileState(const MotionProfileState &state)
{
    switch (state.getProfileState()->getType()) {
    case MotionProfile::ProfileType::TOUCHOFF:
    {
        ProfileState_Touchoff* castState = (ProfileState_Touchoff*)state.getProfileState().get();
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
    default:
        break;
    }
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

    executeCollection.setPartNumber(partNumber.toStdString());
    executeCollection.setSerialNumber(serialNumber.toStdString());
    executeCollection.setOverwriteLogs(clearContents);

    ECM::API::AbstractStateECMProcess* currentOuterState = static_cast<ECM::API::AbstractStateECMProcess*>(stateMachine->getCurrentOuterState());
    currentOuterState->executeCollection(collection);
    ProgressStateMachineStates();
}

void ECMControllerGUI::slot_LoadProfileCollection(const ECMCommand_ProfileCollection &collection)
{
    ECM::API::AbstractStateECMProcess* currentOuterState = static_cast<ECM::API::AbstractStateECMProcess*>(stateMachine->getCurrentOuterState());
    currentOuterState->initializeFromCollection(collection);
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

