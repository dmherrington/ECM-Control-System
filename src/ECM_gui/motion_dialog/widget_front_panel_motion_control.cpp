#include "widget_front_panel_motion_control.h"
#include "ui_widget_front_panel_motion_control.h"

WidgetFrontPanel_MotionControl::WidgetFrontPanel_MotionControl(const std::vector<MotorAxis> &axis, SPIIMotionController *motionControllerObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetFrontPanel_MotionControl)
{
    qRegisterMetaType<common::TuplePositionalString>("TuplePositionalString");

    ui->setupUi(this);

    for(size_t index = 0; index < axis.size(); index++)
    {
        WidgetFrontPanel_AxisMotionControl* newAxisControl = new WidgetFrontPanel_AxisMotionControl(axis.at(index),motionControllerObject);
        m_WidgetAxisControl.insert(std::pair<MotorAxis,WidgetFrontPanel_AxisMotionControl*>(axis.at(index), newAxisControl));
        ui->verticalLayout->insertWidget(static_cast<int>(index + 1), newAxisControl);
    }
}

WidgetFrontPanel_MotionControl::~WidgetFrontPanel_MotionControl()
{
    delete ui;
}

