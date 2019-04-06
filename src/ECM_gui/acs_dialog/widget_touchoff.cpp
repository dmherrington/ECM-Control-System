#include "widget_touchoff.h"
#include "ui_widget_touchoff.h"

Widget_Touchoff::Widget_Touchoff(SPIIMotionController *motionControlObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Touchoff)
{
    ui->setupUi(this);

    m_MotionController = motionControlObject;
}

Widget_Touchoff::~Widget_Touchoff()
{
    delete ui;
}

void Widget_Touchoff::loadFromTouchoffConfig(const Configuration_Touchoff &config)
{
    std::map<MotorAxis,double> touchoffGap = config.getTouchoffGap();
    std::map<MotorAxis,double> touchoffRef = config.getTouchoffRef();

    this->ui->doubleSpinBox_InitialGapX->setValue(touchoffGap.at(MotorAxis::X));
    this->ui->doubleSpinBox_InitialGapY->setValue(touchoffGap.at(MotorAxis::Y));
    this->ui->doubleSpinBox_InitialGapZ->setValue(touchoffGap.at(MotorAxis::Z));

    this->ui->doubleSpinBox_TouchoffRefX->setValue(touchoffRef.at(MotorAxis::X));
    this->ui->doubleSpinBox_TouchoffRefY->setValue(touchoffRef.at(MotorAxis::Y));
    this->ui->doubleSpinBox_TouchoffRefZ->setValue(touchoffRef.at(MotorAxis::Z));

    this->ui->checkBox_UtilizeTouchoff->setChecked(config.shouldTouchoffBeUtilized());
    this->ui->checkBox_ReferenceOldPosition->setChecked(config.shouldTouchoffUtilizePreviousPosition());
}

Configuration_Touchoff Widget_Touchoff::getCurrentTouchoffConfig() const
{
    Configuration_Touchoff currentConfig;
    currentConfig.setTouchoffRef(getTouchoffRefMap());
    currentConfig.setTouchoffGap(getTouchoffGapMap());
    currentConfig.setTouchoffUtilization(this->ui->checkBox_UtilizeTouchoff->isChecked());
    currentConfig.setTouchoffUtilizePreviousPosition(this->ui->checkBox_ReferenceOldPosition->isChecked());
    return currentConfig;
}

std::map<MotorAxis, double>  Widget_Touchoff::getTouchoffRefMap() const
{
    std::map<MotorAxis, double> rtnRef;
    rtnRef.insert(std::pair<MotorAxis,double>(MotorAxis::X,ui->doubleSpinBox_TouchoffRefX->value()));
    rtnRef.insert(std::pair<MotorAxis,double>(MotorAxis::Y,ui->doubleSpinBox_TouchoffRefY->value()));
    rtnRef.insert(std::pair<MotorAxis,double>(MotorAxis::Z,ui->doubleSpinBox_TouchoffRefZ->value()));
    return rtnRef;
}

std::map<MotorAxis, double>  Widget_Touchoff::getTouchoffGapMap() const
{
    std::map<MotorAxis, double> rtnRef;
    rtnRef.insert(std::pair<MotorAxis,double>(MotorAxis::X,ui->doubleSpinBox_InitialGapX->value()));
    rtnRef.insert(std::pair<MotorAxis,double>(MotorAxis::Y,ui->doubleSpinBox_InitialGapY->value()));
    rtnRef.insert(std::pair<MotorAxis,double>(MotorAxis::Z,ui->doubleSpinBox_InitialGapZ->value()));
    return rtnRef;
}

void Widget_Touchoff::setTouchoffUtilization(const bool &execute)
{
    ui->checkBox_UtilizeTouchoff->setChecked(execute);
}

void Widget_Touchoff::on_pushButton_TouchoffRef_released()
{
    Status_PositionPerAxis posX, posY, posZ;
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::X,posX);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Y,posY);
    m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(MotorAxis::Z,posZ);

    ui->doubleSpinBox_TouchoffRefX->setValue(posX.getPosition());
    ui->doubleSpinBox_TouchoffRefY->setValue(posY.getPosition());
    ui->doubleSpinBox_TouchoffRefZ->setValue(posZ.getPosition());
}

void Widget_Touchoff::on_doubleSpinBox_TouchoffRef_valueChanged(double arg1)
{
    UNUSED(arg1);
}

void Widget_Touchoff::on_doubleSpinBox_InitialGap_valueChanged(double arg1)
{
    UNUSED(arg1);
}

void Widget_Touchoff::on_checkBox_ReferenceOldPosition_toggled(bool val)
{
    if(val)
    {
        ui->doubleSpinBox_TouchoffRefX->setValue(0.0);
        ui->doubleSpinBox_TouchoffRefX->setEnabled(false);
        ui->doubleSpinBox_TouchoffRefY->setValue(0.0);
        ui->doubleSpinBox_TouchoffRefY->setEnabled(false);
        ui->doubleSpinBox_TouchoffRefZ->setValue(0.0);
        ui->doubleSpinBox_TouchoffRefZ->setEnabled(false);
    }else
    {
        ui->doubleSpinBox_TouchoffRefX->setEnabled(true);
        ui->doubleSpinBox_TouchoffRefY->setEnabled(true);
        ui->doubleSpinBox_TouchoffRefZ->setEnabled(true);
    }
}
