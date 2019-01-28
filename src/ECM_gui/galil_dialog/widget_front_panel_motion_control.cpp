#include "widget_front_panel_motion_control.h"
#include "ui_widget_front_panel_motion_control.h"

WidgetFrontPanel_MotionControl::WidgetFrontPanel_MotionControl(GalilMotionController* galilObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetFrontPanel_MotionControl)
{
    qRegisterMetaType<common::TuplePositionalString>("TuplePositionalString");

    ui->setupUi(this);

    m_Galil = galilObject;

    ui->spinBox_Jog->setToolTip("Jogging Speed");
    ui->spinBox_RelativeMoveSpeed->setToolTip("Relative Move Speed");
    ui->spinBox_RelativeMove->setToolTip("Relative Move Distance");

    connect(m_Galil, SIGNAL(signal_MCNewMotionState(ECM::Galil::GalilState,QString)),
            this, SLOT(slot_MCNewMotionState(ECM::Galil::GalilState,QString)));

    connect(m_Galil, SIGNAL(signal_MCNewPosition(common::TuplePositionalString,common_data::MachinePositionalState,bool)),
            this, SLOT(slot_NewPositionalData(common::TuplePositionalString,common_data::MachinePositionalState,bool)));
}

WidgetFrontPanel_MotionControl::~WidgetFrontPanel_MotionControl()
{
    delete ui;
}

int WidgetFrontPanel_MotionControl::getCurrentJogSpeed() const
{
    return ui->spinBox_Jog->value();
}

void WidgetFrontPanel_MotionControl::on_pushButton_IncreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value()) * (-1);
    CommandJogPtr beginJog = std::make_shared<CommandJog>(MotorAxis::Z,jogRate);
    //CommandJog beginJog(MotorAxis::Z,jogRate);
    m_Galil->executeCommand(beginJog);
}

void WidgetFrontPanel_MotionControl::on_pushButton_IncreaseJog_released()
{
    CommandStopPtr stopJog = std::make_shared<CommandStop>(MotorAxis::Z);
    //CommandStop stop(MotorAxis::Z);
    m_Galil->executeCommand(stopJog);
}

void WidgetFrontPanel_MotionControl::on_pushButton_DecreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value());
    CommandJogPtr beginJog = std::make_shared<CommandJog>(MotorAxis::Z,jogRate);
    //CommandJog beginJog(MotorAxis::Z,jogRate);
    m_Galil->executeCommand(beginJog);
}

void WidgetFrontPanel_MotionControl::on_pushButton_DecreaseJog_released()
{
    CommandStopPtr stopJog = std::make_shared<CommandStop>(MotorAxis::Z);
    m_Galil->executeCommand(stopJog);
}

void WidgetFrontPanel_MotionControl::on_pushButton_IncreaseRelativeMove_released()
{
    int relativeMoveSpeed = ui->spinBox_RelativeMoveSpeed->value();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(MotorAxis::Z, relativeMoveSpeed);
    m_Galil->executeCommand(commandSpeed);

    int relativeDistance = abs(ui->spinBox_RelativeMove->value()) * (-1);
    CommandRelativeMovePtr startIncreaseRelativeMove = std::make_shared<CommandRelativeMove>(MotorAxis::Z, relativeDistance);
    m_Galil->executeCommand(startIncreaseRelativeMove);
}

void WidgetFrontPanel_MotionControl::on_pushButton_DecreaseRelativeMove_released()
{
    int relativeMoveSpeed = ui->spinBox_RelativeMoveSpeed->value();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(MotorAxis::Z, relativeMoveSpeed);
    m_Galil->executeCommand(commandSpeed);

    int relativeDistance = abs(ui->spinBox_RelativeMove->value());
    CommandRelativeMovePtr startDecreaseRelativeMove = std::make_shared<CommandRelativeMove>(MotorAxis::Z, relativeDistance);
    m_Galil->executeCommand(startDecreaseRelativeMove);
}

void WidgetFrontPanel_MotionControl::slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state, const bool &valueChanged)
{
    UNUSED(tuple);

    if(valueChanged)
    {
        double currentPosition = state.getPositionalState()->getAxisPosition(common_data::PositionUnit::UNIT_POSITION_MICRO_METER);
        ui->lineEdit_MachinePosition->setText(QString::number(currentPosition));
    }
}

void WidgetFrontPanel_MotionControl::slot_LockMotionButtons(const bool &lock)
{
    ui->pushButton_DecreaseJog->setDisabled(lock);
    ui->pushButton_IncreaseJog->setDisabled(lock);

    ui->pushButton_IncreaseRelativeMove->setDisabled(lock);
    ui->pushButton_DecreaseRelativeMove->setDisabled(lock);
}

void WidgetFrontPanel_MotionControl::slot_MCNewMotionState(const ECM::Galil::GalilState &state, const QString &stateString)
{
    UNUSED(stateString);
    switch (state) {
    case ECM::Galil::GalilState::STATE_ESTOP:
    case ECM::Galil::GalilState::STATE_HOME_POSITIONING:
    case ECM::Galil::GalilState::STATE_MOTION_STOP:
    case ECM::Galil::GalilState::STATE_READY_STOP:
    case ECM::Galil::GalilState::STATE_SCRIPT_EXECUTION:
    case ECM::Galil::GalilState::STATE_TOUCHOFF:
    case ECM::Galil::GalilState::STATE_UNKNOWN:
    {

        ui->pushButton_IncreaseRelativeMove->setDisabled(false);
        ui->pushButton_DecreaseRelativeMove->setDisabled(false);
        break;
    }
    case ECM::Galil::GalilState::STATE_IDLE:
    case ECM::Galil::GalilState::STATE_READY:
    {
        ui->pushButton_IncreaseRelativeMove->setDisabled(false);
        ui->pushButton_DecreaseRelativeMove->setDisabled(false);
        break;
    }
    case ECM::Galil::GalilState::STATE_JOGGING:
    case ECM::Galil::GalilState::STATE_MANUAL_POSITIONING:
    {
        //We do not want to change the state condition of the button in this state
        //This is because if we go to lock the buttons the release event will either
        //trigger immediately or never be emitted.
        ui->pushButton_IncreaseRelativeMove->setDisabled(true);
        ui->pushButton_DecreaseRelativeMove->setDisabled(true);
        break;
    }
    default:
        break;
    }

}
