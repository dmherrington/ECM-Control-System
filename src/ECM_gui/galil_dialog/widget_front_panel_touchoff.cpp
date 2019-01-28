#include "widget_front_panel_touchoff.h"
#include "ui_widget_front_panel_touchoff.h"

WidgetFrontPanel_Touchoff::WidgetFrontPanel_Touchoff(GalilMotionController *obj, QWidget *parent) :
    ui(new Ui::WidgetFrontPanel_Touchoff),
    m_MotionController(obj)
{
    ui->setupUi(this);

    connect(m_MotionController,SIGNAL(signal_GalilUpdatedProfileState(MotionProfileState)),this,SLOT(slot_UpdateMotionProfileState(MotionProfileState)));

    m_MotionController->stateInterface->statusVariableValues->addVariableNotifier("touchref",this,[this]{
        bool oldState = ui->doubleSpinBox_TouchoffRef->blockSignals(true);
        double value = 0.0;
        m_MotionController->stateInterface->statusVariableValues->getVariableValue("touchref",value);
        ui->doubleSpinBox_TouchoffRef->setValue(value);
        ui->doubleSpinBox_TouchoffRef->blockSignals(oldState);
    });

    m_MotionController->stateInterface->statusVariableValues->addVariableNotifier("initgap",this,[this]{
        bool oldState = ui->doubleSpinBox_InitialGap->blockSignals(true);
        double value = 0.0;
        m_MotionController->stateInterface->statusVariableValues->getVariableValue("initgap",value);
        ui->doubleSpinBox_InitialGap->setValue(value);
        ui->doubleSpinBox_InitialGap->blockSignals(oldState);
    });
}

WidgetFrontPanel_Touchoff::~WidgetFrontPanel_Touchoff()
{
    delete ui;
}

void WidgetFrontPanel_Touchoff::on_pushButton_ExecuteTouchoff_released()
{

    uint64_t position = static_cast<uint64_t>(ui->doubleSpinBox_TouchoffRef->value() * 10.0); //this conversion will take um to counts
    Command_VariablePtr commandTouchoffRef = std::make_shared<Command_Variable>("touchref",position);
    m_MotionController->executeCommand(commandTouchoffRef);

    int desiredGap = static_cast<int>(ui->doubleSpinBox_InitialGap->value() * 10.0); //this conversion will take um to counts
    Command_VariablePtr commandTouchoffGap = std::make_shared<Command_Variable>("initgap",desiredGap);
    m_MotionController->executeCommand(commandTouchoffGap);

    CommandExecuteProfilePtr commandTouchoffExecute = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::TOUCHOFF,"touchof");
    m_MotionController->executeCommand(commandTouchoffExecute);
}

void WidgetFrontPanel_Touchoff::slot_UpdateMotionProfileState(const MotionProfileState &state)
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
            ui->lineEdit_TouchoffCode->setText("");
            break;
        default:
            break;
        }
    }
}

void WidgetFrontPanel_Touchoff::on_pushButton_TouchoffRef_released()
{
    uint64_t position = m_MotionController->stateInterface->getAxisStatus(MotorAxis::Z)->position.get().getPosition();
    ui->doubleSpinBox_TouchoffRef->setValue(position/10.0);
    //By setting the value of the spinbox this should call the event on value changed and transmit to the motion controller
}

void WidgetFrontPanel_Touchoff::on_pushButton_TouchoffGap_released()
{

}


void WidgetFrontPanel_Touchoff::on_doubleSpinBox_TouchoffRef_valueChanged(double arg1)
{
    UNUSED(arg1);
//    uint64_t position = arg1 * 10.0; //this conversion will take um to counts
//    Command_VariablePtr commandTouchoffRef = std::make_shared<Command_Variable>("touchref",position);
//    m_MotionController->executeCommand(commandTouchoffRef);
}

void WidgetFrontPanel_Touchoff::on_doubleSpinBox_InitialGap_valueChanged(double arg1)
{
    UNUSED(arg1);
//    int desiredGap = arg1 * 10.0; //this conversion will take um to counts
//    Command_VariablePtr commandTouchoffGap = std::make_shared<Command_Variable>("initgap",desiredGap);
//    m_MotionController->executeCommand(commandTouchoffGap);
}
