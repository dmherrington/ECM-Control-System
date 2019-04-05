#include "widget_axis_horizontal_control.h"
#include "ui_widget_axis_horizontal_control.h"

Widget_AxisHorizontalControl::Widget_AxisHorizontalControl(const MotorAxis &axis, SPIIMotionController *motionObject, QWidget *parent) :
    QWidget(parent), Widget_AbstractAxisControl(),
    ui(new Ui::Widget_AxisHorizontalControl)
{
    ui->setupUi(this);

    ui->spinBox_Jog->setToolTip("Jogging Speed");
    ui->spinBox_RelativeMoveSpeed->setToolTip("Relative Move Speed");
    ui->spinBox_RelativeMove->setToolTip("Relative Move Distance");
}

Widget_AxisHorizontalControl::~Widget_AxisHorizontalControl()
{
    delete ui;
}

void Widget_AxisHorizontalControl::lockAllMotionButtons(const bool &shouldLock)
{
    lockRelativeMove(shouldLock);
    lockJogMove(shouldLock);
}

void Widget_AxisHorizontalControl::lockRelativeMove(const bool &shouldLock)
{
    ui->pushButton_DecreaseJog->setDisabled(shouldLock);
    ui->pushButton_IncreaseJog->setDisabled(shouldLock);
}

void Widget_AxisHorizontalControl::lockJogMove(const bool &shouldLock)
{
    ui->pushButton_IncreaseRelativeMove->setDisabled(shouldLock);
    ui->pushButton_DecreaseRelativeMove->setDisabled(shouldLock);
}

void Widget_AxisHorizontalControl::on_pushButton_IncreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value()) * (-1);
    CommandJogPtr beginJog = std::make_shared<CommandJog>(pertinentAxis,jogRate);
    m_MotionController->executeCommand(beginJog);
}

void Widget_AxisHorizontalControl::on_pushButton_IncreaseJog_released()
{
    CommandStopPtr stopJog = std::make_shared<CommandStop>(pertinentAxis);
    m_MotionController->executeCommand(stopJog);
}

void Widget_AxisHorizontalControl::on_pushButton_DecreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value());
    CommandJogPtr beginJog = std::make_shared<CommandJog>(pertinentAxis,jogRate);
    m_MotionController->executeCommand(beginJog);
}

void Widget_AxisHorizontalControl::on_pushButton_DecreaseJog_released()
{
    CommandStopPtr stopJog = std::make_shared<CommandStop>(pertinentAxis);
    m_MotionController->executeCommand(stopJog);
}

void Widget_AxisHorizontalControl::on_pushButton_IncreaseRelativeMove_released()
{
    int relativeMoveSpeed = ui->spinBox_RelativeMoveSpeed->value();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(pertinentAxis, relativeMoveSpeed);
    m_MotionController->executeCommand(commandSpeed);

    int relativeDistance = abs(ui->spinBox_RelativeMove->value()) * (-1);
    CommandRelativeMovePtr startIncreaseRelativeMove = std::make_shared<CommandRelativeMove>();
    startIncreaseRelativeMove->addRelativeMoveDistance(pertinentAxis, relativeDistance, Direction::DIRECTION_POSITIVE);
    m_MotionController->executeCommand(startIncreaseRelativeMove);
}

void Widget_AxisHorizontalControl::on_pushButton_DecreaseRelativeMove_released()
{
    int relativeMoveSpeed = ui->spinBox_RelativeMoveSpeed->value();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(pertinentAxis, relativeMoveSpeed);
    m_MotionController->executeCommand(commandSpeed);

    int relativeDistance = abs(ui->spinBox_RelativeMove->value());
    CommandRelativeMovePtr startDecreaseRelativeMove = std::make_shared<CommandRelativeMove>();
    startDecreaseRelativeMove->addRelativeMoveDistance(pertinentAxis, relativeDistance, Direction::DIRECTION_NEGATIVE);
    m_MotionController->executeCommand(startDecreaseRelativeMove);
}
