#include "window_motion_control.h"
#include "ui_window_motion_control.h"

Window_MotionControl::Window_MotionControl(GalilMotionController* galilObject, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_MOTION_CONTROL,"Motion Control",parent),
    ui(new Ui::Window_MotionControl)
{
    qRegisterMetaType<common::TuplePositionalString>("TuplePositionalString");

    ui->setupUi(this);

    m_Galil = galilObject;

    ui->spinBox_Jog->setToolTip("Jogging Speed");
    ui->spinBox_RelativeMoveSpeed->setToolTip("Relative Move Speed");
    ui->spinBox_RelativeMove->setToolTip("Relative Move Distance");

    connect(m_Galil, SIGNAL(signal_MCNewPosition(common::TuplePositionalString,common_data::MachinePositionalState,bool)), this, SLOT(slot_NewPositionalData(common::TuplePositionalString,common_data::MachinePositionalState,bool)));
}

Window_MotionControl::~Window_MotionControl()
{
    delete ui;
}

void Window_MotionControl::closeEvent(QCloseEvent *event)
{
    GeneralDialogWindow::closeEvent(event);
}

int Window_MotionControl::getCurrentJogSpeed() const
{
    return ui->spinBox_Jog->value();
}

void Window_MotionControl::on_pushButton_IncreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value()) * (-1);
    CommandJogPtr beginJog = std::make_shared<CommandJog>(MotorAxis::Z,jogRate);
    //CommandJog beginJog(MotorAxis::Z,jogRate);
    m_Galil->executeCommand(beginJog);
}

void Window_MotionControl::on_pushButton_IncreaseJog_released()
{
    CommandStopPtr stopJog = std::make_shared<CommandStop>(MotorAxis::Z);
    //CommandStop stop(MotorAxis::Z);
    m_Galil->executeCommand(stopJog);
}

void Window_MotionControl::on_pushButton_DecreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value());
    CommandJogPtr beginJog = std::make_shared<CommandJog>(MotorAxis::Z,jogRate);
    //CommandJog beginJog(MotorAxis::Z,jogRate);
    m_Galil->executeCommand(beginJog);
}

void Window_MotionControl::on_pushButton_DecreaseJog_released()
{
    CommandStopPtr stopJog = std::make_shared<CommandStop>(MotorAxis::Z);
    m_Galil->executeCommand(stopJog);
}

void Window_MotionControl::on_pushButton_IncreaseRelativeMove_released()
{
    int relativeMoveSpeed = ui->spinBox_RelativeMoveSpeed->value();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(MotorAxis::Z, relativeMoveSpeed);
    m_Galil->executeCommand(commandSpeed);

    int relativeDistance = abs(ui->spinBox_RelativeMove->value()) * (-1);
    CommandRelativeMovePtr startIncreaseRelativeMove = std::make_shared<CommandRelativeMove>(MotorAxis::Z, relativeDistance);
    m_Galil->executeCommand(startIncreaseRelativeMove);
}

void Window_MotionControl::on_pushButton_DecreaseRelativeMove_released()
{
    int relativeMoveSpeed = ui->spinBox_RelativeMoveSpeed->value();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(MotorAxis::Z, relativeMoveSpeed);
    m_Galil->executeCommand(commandSpeed);

    int relativeDistance = abs(ui->spinBox_RelativeMove->value());
    CommandRelativeMovePtr startDecreaseRelativeMove = std::make_shared<CommandRelativeMove>(MotorAxis::Z, relativeDistance);
    m_Galil->executeCommand(startDecreaseRelativeMove);
}

void Window_MotionControl::slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state, const bool &valueChanged)
{
    UNUSED(tuple);

    if(valueChanged)
    {
        double currentPosition = state.getPositionalState()->getAxisPosition(common_data::PositionUnit::UNIT_POSITION_MICRO_METER);
        ui->lineEdit_MachinePosition->setText(QString::number(currentPosition));
    }
}

void Window_MotionControl::slot_LockMotionButtons(const bool &lock)
{
    ui->pushButton_DecreaseJog->setDisabled(lock);
    ui->pushButton_IncreaseJog->setDisabled(lock);

    ui->pushButton_IncreaseRelativeMove->setDisabled(lock);
    ui->pushButton_DecreaseRelativeMove->setDisabled(lock);
}
