#include "widget_touchoff.h"
#include "ui_widget_touchoff.h"

Widget_Touchoff::Widget_Touchoff(GalilMotionController* galilObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Touchoff)
{
    ui->setupUi(this);

    m_Galil = galilObject;

    connect(m_Galil,SIGNAL(signal_GalilUpdatedProfileState(MotionProfileState)),this,SLOT(slot_UpdateMotionProfileState(MotionProfileState)));
}

Widget_Touchoff::~Widget_Touchoff()
{
    delete ui;
}

void Widget_Touchoff::loadFromTouchoffConfig(const MotionCommand_TouchoffConfig &config)
{
    this->ui->doubleSpinBox_TouchoffRef->setValue(config.getTouchoffRef() / 10.0);
    this->ui->doubleSpinBox_InitialGap->setValue(config.getTouchoffGap() / 10.0);
    this->ui->checkBox_UtilizeTouchoff->setChecked(config.shouldTouchoffBeUtilized());
    this->ui->checkBox_ReferenceOldPosition->setChecked(config.shouldTouchoffUtilizePreviousPosition());
}

MotionCommand_TouchoffConfig Widget_Touchoff::getCurrentTouchoffConfig() const
{
    MotionCommand_TouchoffConfig currentConfig;
    currentConfig.setTouchoffRef(this->ui->doubleSpinBox_TouchoffRef->value() * 10.0);
    currentConfig.setTouchoffGap(this->ui->doubleSpinBox_InitialGap->value() * 10.0);
    currentConfig.setTouchoffUtilization(this->ui->checkBox_UtilizeTouchoff->isChecked());
    currentConfig.setTouchoffUtilizePreviousPosition(this->ui->checkBox_ReferenceOldPosition->isChecked());
    return currentConfig;
}

void Widget_Touchoff::setTouchoffRef(const double &value)
{
    ui->doubleSpinBox_TouchoffRef->setValue(value);
}

void Widget_Touchoff::setTouchoffGap(const double &value)
{
    ui->doubleSpinBox_InitialGap->setValue(value);
}

void Widget_Touchoff::setTouchoffUtilization(const bool &execute)
{
    ui->checkBox_UtilizeTouchoff->setChecked(execute);
}

void Widget_Touchoff::on_pushButton_ExecuteTouchoff_released()
{
    CommandExecuteProfilePtr commandTouchoffExecute = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::TOUCHOFF,"touchof");
    m_Galil->executeCommand(commandTouchoffExecute);
}

void Widget_Touchoff::slot_UpdateMotionProfileState(const MotionProfileState &state)
{
    if(state.getProfileState()->getType() == MotionProfile::ProfileType::TOUCHOFF)
    {
        ProfileState_Touchoff* castState = (ProfileState_Touchoff*)state.getProfileState().get();

        switch (castState->getCurrentCode()) {
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::CLEARED:
            ui->lineEdit_TouchoffCode->setText("");
            break;
        default:
            break;
        }
    }
}

void Widget_Touchoff::on_pushButton_TouchoffRef_released()
{
    int position = m_Galil->stateInterface->getAxisStatus(MotorAxis::Z)->getPosition().getPosition();
    ui->doubleSpinBox_TouchoffRef->setValue(position/10.0);
    //By setting the value of the spinbox this should call the event on value changed and transmit to the motion controller
}

void Widget_Touchoff::on_doubleSpinBox_TouchoffRef_valueChanged(double arg1)
{
//    uint64_t position = arg1 * 10.0; //this conversion will take um to counts
//    Command_VariablePtr commandTouchoffRef = std::make_shared<Command_Variable>("touchref",position);
//    m_Galil->executeCommand(commandTouchoffRef);
}

void Widget_Touchoff::on_doubleSpinBox_InitialGap_valueChanged(double arg1)
{
//    int desiredGap = arg1 * 10.0; //this conversion will take um to counts
//    Command_VariablePtr commandTouchoffGap = std::make_shared<Command_Variable>("initgap",desiredGap);
//    m_Galil->executeCommand(commandTouchoffGap);
}

void Widget_Touchoff::on_checkBox_ReferenceOldPosition_toggled(bool val)
{
    if(val)
    {
        ui->doubleSpinBox_TouchoffRef->setEnabled(false);
    }else
    {
        ui->doubleSpinBox_TouchoffRef->setEnabled(true);
    }
}
