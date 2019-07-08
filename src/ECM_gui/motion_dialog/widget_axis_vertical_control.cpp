#include "widget_axis_vertical_control.h"
#include "ui_widget_axis_vertical_control.h"

Widget_AxisVerticalControl::Widget_AxisVerticalControl(const MotorAxis &axis, SPIIMotionController *motionObject, QWidget *parent) :
    QWidget(parent), Widget_AbstractAxisControl(),
    ui(new Ui::Widget_AxisVerticalControl)
{
    ui->setupUi(this);

    pertinentAxis = axis;
    m_MotionController = motionObject;

    ui->spinBox_Jog->setToolTip("Jogging Speed");
    ui->spinBox_RelativeMoveSpeed->setToolTip("Relative Move Speed");
    ui->spinBox_RelativeMove->setToolTip("Relative Move Distance");

}

Widget_AxisVerticalControl::~Widget_AxisVerticalControl()
{
    delete ui;
}

void Widget_AxisVerticalControl::lockAllMotionButtons(const bool &shouldLock)
{
    lockRelativeMove(shouldLock);
    lockJogMove(shouldLock);
}

void Widget_AxisVerticalControl::lockRelativeMove(const bool &shouldLock)
{
    ui->pushButton_DecreaseJog->setDisabled(shouldLock);
    ui->pushButton_IncreaseJog->setDisabled(shouldLock);
}

void Widget_AxisVerticalControl::lockJogMove(const bool &shouldLock)
{
    ui->pushButton_IncreaseRelativeMove->setDisabled(shouldLock);
    ui->pushButton_DecreaseRelativeMove->setDisabled(shouldLock);
}

void Widget_AxisVerticalControl::on_pushButton_IncreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value()) * (getAxisSign(pertinentAxis, Direction::DIRECTION_INCREASE));
    CommandJogPtr beginJog = std::make_shared<CommandJog>(pertinentAxis,jogRate);
    m_MotionController->executeCommand(beginJog);
}

void Widget_AxisVerticalControl::on_pushButton_IncreaseJog_released()
{
    CommandStopPtr stopJog = std::make_shared<CommandStop>(pertinentAxis);
    m_MotionController->executeCommand(stopJog);
}

void Widget_AxisVerticalControl::on_pushButton_DecreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value()) * (getAxisSign(pertinentAxis, Direction::DIRECTION_DECREASE));
    CommandJogPtr beginJog = std::make_shared<CommandJog>(pertinentAxis,jogRate);
    m_MotionController->executeCommand(beginJog);
}

void Widget_AxisVerticalControl::on_pushButton_DecreaseJog_released()
{
    CommandStopPtr stopJog = std::make_shared<CommandStop>(pertinentAxis);
    m_MotionController->executeCommand(stopJog);
}

void Widget_AxisVerticalControl::on_pushButton_IncreaseRelativeMove_released()
{
    int relativeMoveSpeed = ui->spinBox_RelativeMoveSpeed->value();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(pertinentAxis, relativeMoveSpeed);
    m_MotionController->executeCommand(commandSpeed);

    int relativeDistance = abs(ui->spinBox_RelativeMove->value()) * (getAxisSign(pertinentAxis, Direction::DIRECTION_INCREASE));

    CommandRelativeMovePtr startIncreaseRelativeMove = std::make_shared<CommandRelativeMove>();
    startIncreaseRelativeMove->addRelativeMoveDistance(pertinentAxis, relativeDistance);
    m_MotionController->executeCommand(startIncreaseRelativeMove);
}

void Widget_AxisVerticalControl::on_pushButton_DecreaseRelativeMove_released()
{
    int relativeMoveSpeed = ui->spinBox_RelativeMoveSpeed->value();
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(pertinentAxis, relativeMoveSpeed);
    m_MotionController->executeCommand(commandSpeed);

    int relativeDistance = abs(ui->spinBox_RelativeMove->value()) * (getAxisSign(pertinentAxis, Direction::DIRECTION_DECREASE));;
    CommandRelativeMovePtr startDecreaseRelativeMove = std::make_shared<CommandRelativeMove>();
    startDecreaseRelativeMove->addRelativeMoveDistance(pertinentAxis, relativeDistance);
    m_MotionController->executeCommand(startDecreaseRelativeMove);
}
