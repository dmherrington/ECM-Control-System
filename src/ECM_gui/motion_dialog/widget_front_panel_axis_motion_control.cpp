#include "widget_front_panel_axis_motion_control.h"
#include "ui_widget_front_panel_axis_motion_control.h"


WidgetFrontPanel_AxisMotionControl::WidgetFrontPanel_AxisMotionControl(const MotorAxis &axis, SPIIMotionController *motionControlObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetFrontPanel_AxisMotionControl)
{
    qRegisterMetaType<common::TuplePositionalString>("TuplePositionalString");

    ui->setupUi(this);
    ui->label_AxisControl->setText(QString::fromStdString(AxisToString(axis)));

    pertinentAxis = axis;
    m_MotionController = motionControlObject;

    switch (axis) {
    case MotorAxis::X:
    {
        Widget_AxisHorizontalControl* tmpObject = new Widget_AxisHorizontalControl(axis,motionControlObject);
        m_ControlWidget = tmpObject;
        ui->frame->layout()->addWidget(tmpObject);
        break;
    }
    case MotorAxis::Y:
    case MotorAxis::Z:
    {
        Widget_AxisVerticalControl* tmpObject = new Widget_AxisVerticalControl(axis,motionControlObject);
        m_ControlWidget = tmpObject;
        ui->frame->layout()->addWidget(tmpObject);
        break;
    }
    default:
        break;
    }

    connect(m_MotionController, SIGNAL(signal_MCNewMotionState(ECM::SPII::SPIIState,QString)),
            this, SLOT(slot_MCNewMotionState(ECM::SPII::SPIIState,QString)));

    connect(m_MotionController, SIGNAL(signal_MCNewPosition(common::TuplePositionalString,common_data::MachinePositionalState,bool)),
            this, SLOT(slot_NewPositionalData(common::TuplePositionalString,common_data::MachinePositionalState,bool)));
}

WidgetFrontPanel_AxisMotionControl::~WidgetFrontPanel_AxisMotionControl()
{
    delete ui;
}

int WidgetFrontPanel_AxisMotionControl::getCurrentJogSpeed() const
{
    return 0;
}

void WidgetFrontPanel_AxisMotionControl::slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state, const bool &valueChanged)
{
    UNUSED(tuple);

    if(valueChanged)
    {
        double currentPosition;
        bool validRequest = state.getPositionalState()->getAxisPosition(pertinentAxis,common_data::PositionUnit::UNIT_POSITION_MICRO_METER, currentPosition);
        if(validRequest)
            ui->lineEdit_MachinePosition->setText(QString::number(currentPosition));
    }
}

void WidgetFrontPanel_AxisMotionControl::slot_LockMotionButtons(const bool &lock)
{
    m_ControlWidget->lockAllMotionButtons(lock);
}

void WidgetFrontPanel_AxisMotionControl::slot_MCNewMotionState(const ECM::SPII::SPIIState &state, const QString &stateString)
{
    UNUSED(stateString);
    switch (state) {
    case ECM::SPII::SPIIState::STATE_ESTOP:
    case ECM::SPII::SPIIState::STATE_HOME_POSITIONING:
    case ECM::SPII::SPIIState::STATE_MOTION_STOP:
    case ECM::SPII::SPIIState::STATE_READY_STOP:
    case ECM::SPII::SPIIState::STATE_SCRIPT_EXECUTION:
    case ECM::SPII::SPIIState::STATE_TOUCHOFF:
    case ECM::SPII::SPIIState::STATE_UNKNOWN:
    {

        m_ControlWidget->lockAllMotionButtons(false);
        break;
    }
    case ECM::SPII::SPIIState::STATE_IDLE:
    case ECM::SPII::SPIIState::STATE_READY:
    {
        m_ControlWidget->lockRelativeMove(false);
        break;
    }
    case ECM::SPII::SPIIState::STATE_JOGGING:
    case ECM::SPII::SPIIState::STATE_MANUAL_POSITIONING:
    {
        //We do not want to change the state condition of the button in this state
        //This is because if we go to lock the buttons the release event will either
        //trigger immediately or never be emitted.
        m_ControlWidget->lockRelativeMove(true);
        break;
    }
    default:
        break;
    }

}
