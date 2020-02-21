#include "widget_front_panel_touchoff.h"
#include "ui_widget_front_panel_touchoff.h"

WidgetFrontPanel_Touchoff::WidgetFrontPanel_Touchoff(const std::vector<MotorAxis> &applicableAxis, SPIIMotionController *obj, QWidget *parent) :
    ui(new Ui::WidgetFrontPanel_Touchoff),
    m_MotionController(obj)
{
    ui->setupUi(this);

    ui->widget_LEDTouchoffStatus->setDiameter(7);

    connect(m_MotionController,SIGNAL(signal_MCUpdatedProfileState(MotionProfileState)),this,SLOT(slot_UpdateMotionProfileState(MotionProfileState)));

    for (size_t axisIndex = 0; axisIndex < applicableAxis.size(); axisIndex++)
    {
        MotorAxis currentAxis = applicableAxis.at(axisIndex);

        TouchoffWidget_AxisValue* axisValueWidget = new TouchoffWidget_AxisValue(applicableAxis.at(axisIndex));

        connect(axisValueWidget,SIGNAL(signal_AxisValueChanged()),this,SLOT(slot_AxisValueChanged()));
        connect(axisValueWidget, SIGNAL(signal_PushButtonRun(MotorAxis)), this, SLOT(slot_OnRunPushButton(MotorAxis)));
        m_TouchoffValues.insert(std::pair<MotorAxis,TouchoffWidget_AxisValue*>(currentAxis, axisValueWidget));

        ui->verticalLayout_Values->addWidget(axisValueWidget);
    }
}

void WidgetFrontPanel_Touchoff::executingAutomatedSequence(const bool &shouldBlock)
{
    ui->pushButton_ExecuteTouchoff->setDisabled(shouldBlock);
    ui->pushButton_TouchoffRef->setDisabled(shouldBlock);

    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator it;
    for(it = m_TouchoffValues.begin(); it != m_TouchoffValues.end(); ++it)
    {
        it->second->executingAutomatedSequence(shouldBlock);
    }
}

WidgetFrontPanel_Touchoff::~WidgetFrontPanel_Touchoff()
{
    delete ui;
}

void WidgetFrontPanel_Touchoff::slot_AxisValueChanged()
{

}

void WidgetFrontPanel_Touchoff::slot_OnRunPushButton(const MotorAxis &axis)
{
    TouchoffWidget_AxisValue* axisValueWidget = m_TouchoffValues.at(axis);

    int direction = axisValueWidget->getAxisDirection();
    Command_VariablePtr commandDirection = std::make_shared<Command_Variable>("directionGlobal ");
    commandDirection->setVariableValue(direction);
    m_MotionController->executeCommand(commandDirection);

    on_pushButton_ExecuteTouchoff_released();
}

void WidgetFrontPanel_Touchoff::on_pushButton_ExecuteTouchoff_released()
{
    transmitTouchoffParameters();

    CommandExecuteProfilePtr commandTouchoffExecute = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::TOUCHOFF,"TOUCHOFF");
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
            ui->widget_LEDTouchoffStatus->setColor(QColor(255,0,0));
//            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
            ui->widget_LEDTouchoffStatus->setColor(QColor(255,255,0));
//            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
            ui->widget_LEDTouchoffStatus->setColor(QColor(0,255,0));
//            ui->lineEdit_TouchoffCode->setText(QString::fromStdString(ProfileState_Touchoff::TOUCHOFFCodesToString(castState->getCurrentCode())));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED:
            ui->widget_LEDTouchoffStatus->setColor(QColor(255,0,0));
//            ui->lineEdit_TouchoffCode->setText("");
            break;
        default:
            break;
        }
    }
}

void WidgetFrontPanel_Touchoff::on_pushButton_TouchoffRef_released()
{
    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator it = m_TouchoffValues.begin();

    for (; it!=m_TouchoffValues.end(); ++it)
    {
        double axisPosition = 0.0;
        if(m_MotionController->m_StateInterface->getAxisPosition(it->first,axisPosition))
        {
            TouchoffWidget_AxisValue* currentWidget = it->second;
            currentWidget->setRefValue(axisPosition);
        }
    }
}

void WidgetFrontPanel_Touchoff::on_pushButton_TouchoffGap_released()
{

}

void WidgetFrontPanel_Touchoff::updateAvailableAxes(const std::vector<MotorAxis> &axes)
{

    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator it = m_TouchoffValues.begin();

    for (; it!=m_TouchoffValues.end();)
    {
        ui->verticalLayout_Values->removeWidget(it->second);
        delete it->second;
        it = m_TouchoffValues.erase(it);
    }

    m_TouchoffValues.clear();
\
    for (size_t axisIndex = 0; axisIndex < axes.size(); axisIndex++)
    {
        MotorAxis currentAxis = axes.at(axisIndex);

        TouchoffWidget_AxisValue* axisValueWidget = new TouchoffWidget_AxisValue(currentAxis);
        connect(axisValueWidget,SIGNAL(signal_AxisValueChanged()),this,SLOT(slot_AxisValueChanged()));

        m_TouchoffValues.insert(std::pair<MotorAxis,TouchoffWidget_AxisValue*>(currentAxis, axisValueWidget));

        ui->verticalLayout_Values->addWidget(axisValueWidget);
    }
}

void WidgetFrontPanel_Touchoff::transmitTouchoffParameters()
{
    Command_VariableArrayPtr commandRef = std::make_shared<Command_VariableArray>();
    commandRef->setVariableName("startTouchOffPosition");

    std::vector<double> refVector, gapVector;
    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator refIterator = m_TouchoffValues.begin();

    for(;refIterator!=m_TouchoffValues.end();++refIterator)
    {
        double refValue = 0.0, gapValue = 0.0;
        TouchoffWidget_AxisValue* currentWidget = refIterator->second;
        currentWidget->getAxisValue(refValue,gapValue);

        refVector.push_back(refValue);
        gapVector.push_back(refValue);
    }
    commandRef->setVariableValue(refVector);
    m_MotionController->executeCommand(commandRef);


    Command_VariablePtr commandGap = std::make_shared<Command_Variable>("startingGap");
    refIterator = m_TouchoffValues.find(MotorAxis::Z);
    if(refIterator != m_TouchoffValues.end())
    {
        double refValue = 0.0, gapValue = 0.0;
        TouchoffWidget_AxisValue* currentWidget = refIterator->second;
        currentWidget->getAxisValue(refValue,gapValue);
        commandGap->setVariableValue(gapValue);
    }
    m_MotionController->executeCommand(commandGap);
}

