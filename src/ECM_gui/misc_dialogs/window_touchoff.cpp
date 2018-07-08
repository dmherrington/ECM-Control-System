#include "window_touchoff.h"
#include "ui_window_touchoff.h"

Window_Touchoff::Window_Touchoff(GalilMotionController *obj, QWidget *parent) :
    QMainWindow(parent),
    m_MotionController(obj),
    ui(new Ui::Window_Touchoff)
{
    ui->setupUi(this);

    connect(m_MotionController,SIGNAL(signal_GalilUpdatedProfileState(MotionProfileState)),this,SLOT(slot_UpdateMotionProfileState(MotionProfileState)));
}

Window_Touchoff::~Window_Touchoff()
{
    delete ui;
}

bool Window_Touchoff::isWindowHidden() const
{
    return windowHidden;
}

void Window_Touchoff::readSettings()
{
    QSettings settings("Touchoff Window", "ECM Application");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

void Window_Touchoff::closeEvent(QCloseEvent *event)
{
    QSettings settings("Touchoff Window", "ECM Application");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void Window_Touchoff::hideEvent(QHideEvent *event)
{
    windowHidden = true;
}

void Window_Touchoff::showEvent(QShowEvent *event)
{
    windowHidden = false;
}

void Window_Touchoff::on_actionClose_triggered()
{
    this->hide();
}

void Window_Touchoff::on_pushButton_ExecuteTouchoff_released()
{
    CommandExecuteProfile command(MotionProfile::ProfileType::TOUCHOFF,"touchof");
    m_MotionController->executeCommand(&command);
}

void Window_Touchoff::slot_UpdateMotionProfileState(const MotionProfileState &state)
{
    if(state.getProfileState()->getType() == MotionProfile::ProfileType::TOUCHOFF)
    {
        ProfileState_Touchoff* castState = (ProfileState_Touchoff*)state.getProfileState().get();
        ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));

        switch (castState->getCurrentCode()) {
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::INCOMPLETE:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
            ui->widget_TouchoffComplete->setColor(QColor(255));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
            ui->widget_TouchoffComplete->setColor(QColor(255,255,0));
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
            ui->widget_TouchoffComplete->setColor(QColor(0,255,0));
        default:
            break;
        }
    }
}

void Window_Touchoff::on_pushButton_TouchoffRef_released()
{
    uint64_t position = m_MotionController->stateInterface->getAxisStatus(MotorAxis::Z)->position.get().getPosition();
    ui->doubleSpinBox_TouchoffRef->setValue(position/10.0);
    Command_Variable command("touchref",position);
    m_MotionController->executeCommand(&command);
}

void Window_Touchoff::on_pushButton_RunTouchoff_released()
{
    CommandExecuteProfile command(MotionProfile::ProfileType::TOUCHOFF,"touchof");
    m_MotionController->executeCommand(&command);
}
