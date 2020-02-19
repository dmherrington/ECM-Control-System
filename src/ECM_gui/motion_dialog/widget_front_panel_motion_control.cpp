#include "widget_front_panel_motion_control.h"
#include "ui_widget_front_panel_motion_control.h"

WidgetFrontPanel_MotionControl::WidgetFrontPanel_MotionControl(const std::vector<MotorAxis> &axis, SPIIMotionController *motionControllerObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetFrontPanel_MotionControl)
{
    qRegisterMetaType<common::TuplePositionalString>("TuplePositionalString");

    ui->setupUi(this);

    unsigned int desiredTab = 0;
    for(size_t index = 0; index < axis.size(); index++)
    {
        WidgetFrontPanel_AxisMotionControl* newAxisControl = new WidgetFrontPanel_AxisMotionControl(axis.at(index),motionControllerObject);
        m_WidgetAxisControl.insert(std::pair<MotorAxis,WidgetFrontPanel_AxisMotionControl*>(axis.at(index), newAxisControl));
        ui->tabWidget->addTab(newAxisControl, "AXIS: " + QString::fromStdString(AxisToString(axis.at(index))));
        if(axis.at(index) == MotorAxis::Z)
            desiredTab = static_cast<unsigned int>(index);
    }

    ui->tabWidget->setCurrentIndex(static_cast<int>(desiredTab));
}

WidgetFrontPanel_MotionControl::~WidgetFrontPanel_MotionControl()
{
    delete ui;
}

