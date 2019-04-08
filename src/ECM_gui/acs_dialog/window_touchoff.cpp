#include "window_touchoff.h"
#include "ui_window_touchoff.h"

Window_Touchoff::Window_Touchoff(SPIIMotionController *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_TOUCHOFF,"Touchoff",parent),
    ui(new Ui::Window_Touchoff),
    m_MotionController(obj)
{
    ui->setupUi(this);

    connect(m_MotionController,SIGNAL(signal_GalilUpdatedProfileState(MotionProfileState)),this,SLOT(slot_UpdateMotionProfileState(MotionProfileState)));

//    m_MotionController->m_StateInterface->m_MasterVariableValues->addVariableNotifier("touchref",this,[this]{
//        bool oldState = ui->doubleSpinBox_TouchoffRef->blockSignals(true);
//        double value = 0.0;
//        m_MotionController->m_StateInterface->m_MasterVariableValues->getVariableValue("touchref",value);
//        ui->doubleSpinBox_TouchoffRef->setValue(value);
//        ui->doubleSpinBox_TouchoffRef->blockSignals(oldState);
//    });

//    m_MotionController->m_StateInterface->m_MasterVariableValues->addVariableNotifier("initgap",this,[this]{
//        bool oldState = ui->doubleSpinBox_InitialGap->blockSignals(true);
//        double value = 0.0;
//        m_MotionController->m_StateInterface->m_MasterVariableValues->getVariableValue("initgap",value);
//        ui->doubleSpinBox_InitialGap->setValue(value);
//        ui->doubleSpinBox_InitialGap->blockSignals(oldState);
//    });

    GeneralDialogWindow::readWindowSettings();
}

Window_Touchoff::~Window_Touchoff()
{
    delete ui;
}

void Window_Touchoff::closeEvent(QCloseEvent *event)
{
    saveToFile(getPreviousSettingsPath());
    GeneralDialogWindow::closeEvent(event);
}

void Window_Touchoff::on_pushButton_ExecuteTouchoff_released()
{

    transmitTouchoffReference();

    transmitTouchoffGap();

    CommandExecuteProfilePtr commandTouchoffExecute = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::TOUCHOFF,"TOUCHOFF");
    m_MotionController->executeCommand(commandTouchoffExecute);
}

void Window_Touchoff::slot_UpdateMotionProfileState(const MotionProfileState &state)
{
    if(state.getProfileState()->getType() == MotionProfile::ProfileType::TOUCHOFF)
    {
        ProfileState_Touchoff* castState = (ProfileState_Touchoff*)state.getProfileState().get();

        switch (castState->getCurrentCode()) {
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
            ui->widget_TouchoffComplete->setColor(QColor(255,0,0));
            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
            ui->widget_TouchoffComplete->setColor(QColor(255,255,0));
            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
            ui->widget_TouchoffComplete->setColor(QColor(0,255,0));
            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED:
            ui->widget_TouchoffComplete->setColor(QColor(255,0,0));
            ui->lineEdit_TouchoffCode->setText("");
            break;
        default:
            break;
        }
    }
}

void Window_Touchoff::on_pushButton_TouchoffRef_released()
{
    ui->doubleSpinBox_TouchoffRefX->blockSignals(true);
    ui->doubleSpinBox_TouchoffRefY->blockSignals(true);
    ui->doubleSpinBox_TouchoffRefZ->blockSignals(true);

    Status_PositionPerAxis posX, posY, posZ;
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::X,posX);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Y,posY);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Z,posZ);

    ui->doubleSpinBox_TouchoffRefX->setValue(posX.getPosition());
    ui->doubleSpinBox_TouchoffRefY->setValue(posY.getPosition());
    ui->doubleSpinBox_TouchoffRefZ->setValue(posZ.getPosition());

    ui->doubleSpinBox_TouchoffRefX->blockSignals(false);
    ui->doubleSpinBox_TouchoffRefY->blockSignals(false);
    ui->doubleSpinBox_TouchoffRefZ->blockSignals(false);
}

void Window_Touchoff::on_pushButton_TouchoffGap_released()
{
    transmitTouchoffGap();
}

void Window_Touchoff::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_Touchoff::saveToFile(const QString &filePath)
{
    UNUSED(filePath);
}

void Window_Touchoff::openFromFile(const QString &filePath)
{
    UNUSED(filePath);
}

void Window_Touchoff::transmitTouchoffReference()
{
    Command_VariableArrayPtr command = std::make_shared<Command_VariableArray>();
    command->setVariableName("startTouchOffPosition");

    std::vector<double> refVector;
    refVector.push_back(ui->doubleSpinBox_TouchoffRefX->value());
    refVector.push_back(ui->doubleSpinBox_TouchoffRefY->value());
    refVector.push_back(ui->doubleSpinBox_TouchoffRefZ->value());

    command->setVariableValue(refVector);
}

void Window_Touchoff::transmitTouchoffGap()
{
    Command_VariableArrayPtr command = std::make_shared<Command_VariableArray>();
    command->setVariableName("startingGap");

    std::vector<double> refVector;
    refVector.push_back(ui->doubleSpinBox_InitialGapX->value());
    refVector.push_back(ui->doubleSpinBox_InitialGapY->value());
    refVector.push_back(ui->doubleSpinBox_InitialGapZ->value());

    command->setVariableValue(refVector);
}

void Window_Touchoff::on_doubleSpinBox_TouchoffRefX_editingFinished()
{
    Status_PositionPerAxis posX, posY, posZ;
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::X,posX);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Y,posY);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Z,posZ);

    ui->doubleSpinBox_TouchoffRefX->setValue(posX.getPosition());
    ui->doubleSpinBox_TouchoffRefY->setValue(posY.getPosition());
    ui->doubleSpinBox_TouchoffRefZ->setValue(posZ.getPosition());
}

void Window_Touchoff::on_doubleSpinBox_TouchoffRefY_editingFinished()
{
    Status_PositionPerAxis posX, posY, posZ;
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::X,posX);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Y,posY);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Z,posZ);

    ui->doubleSpinBox_TouchoffRefX->setValue(posX.getPosition());
    ui->doubleSpinBox_TouchoffRefY->setValue(posY.getPosition());
    ui->doubleSpinBox_TouchoffRefZ->setValue(posZ.getPosition());
}

void Window_Touchoff::on_doubleSpinBox_TouchoffRefZ_editingFinished()
{
    Status_PositionPerAxis posX, posY, posZ;
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::X,posX);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Y,posY);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Z,posZ);

    ui->doubleSpinBox_TouchoffRefX->setValue(posX.getPosition());
    ui->doubleSpinBox_TouchoffRefY->setValue(posY.getPosition());
    ui->doubleSpinBox_TouchoffRefZ->setValue(posZ.getPosition());
}

void Window_Touchoff::on_doubleSpinBox_InitialGapX_editingFinished()
{
    transmitTouchoffReference();
}

void Window_Touchoff::on_doubleSpinBox_InitialGapY_editingFinished()
{
    transmitTouchoffReference();
}

void Window_Touchoff::on_doubleSpinBox_InitialGapZ_editingFinished()
{
    transmitTouchoffReference();
}
