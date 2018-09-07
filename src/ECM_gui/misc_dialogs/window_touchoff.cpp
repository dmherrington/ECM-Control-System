#include "window_touchoff.h"
#include "ui_window_touchoff.h"

Window_Touchoff::Window_Touchoff(GalilMotionController *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_TOUCHOFF,"Touchoff",parent),
    ui(new Ui::Window_Touchoff),
    m_MotionController(obj)
{
    ui->setupUi(this);

    connect(m_MotionController,SIGNAL(signal_GalilUpdatedProfileState(MotionProfileState)),this,SLOT(slot_UpdateMotionProfileState(MotionProfileState)));

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
    CommandExecuteProfilePtr commandTouchoffExecute = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::TOUCHOFF,"touchof");
    m_MotionController->executeCommand(commandTouchoffExecute);
}

void Window_Touchoff::slot_UpdateMotionProfileState(const MotionProfileState &state)
{
    if(state.getProfileState()->getType() == MotionProfile::ProfileType::TOUCHOFF)
    {
        ProfileState_Touchoff* castState = (ProfileState_Touchoff*)state.getProfileState().get();
        ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));

        switch (castState->getCurrentCode()) {
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
            ui->widget_TouchoffComplete->setColor(QColor(255,0,0));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
            ui->widget_TouchoffComplete->setColor(QColor(255,255,0));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
            ui->widget_TouchoffComplete->setColor(QColor(0,255,0));
            break;
        default:
            break;
        }
    }
}

void Window_Touchoff::on_pushButton_TouchoffRef_released()
{
    uint64_t position = m_MotionController->stateInterface->getAxisStatus(MotorAxis::Z)->position.get().getPosition();
    ui->doubleSpinBox_TouchoffRef->setValue(position/10.0);
    Command_VariablePtr commandTouchoffRef = std::make_shared<Command_Variable>("touchref",position);
    m_MotionController->executeCommand(commandTouchoffRef);
}

void Window_Touchoff::on_pushButton_TouchoffGap_released()
{
    int desiredGap = ui->doubleSpinBox_InitialGap->value() * 10.0;
    Command_VariablePtr commandTouchoffGap = std::make_shared<Command_Variable>("initgap",desiredGap);
    m_MotionController->executeCommand(commandTouchoffGap);
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
