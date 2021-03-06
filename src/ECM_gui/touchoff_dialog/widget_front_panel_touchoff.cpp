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
        TouchoffWidget_AxisValue* gapValueWidget = new TouchoffWidget_AxisValue(applicableAxis.at(axisIndex));
        TouchoffWidget_AxisValue* refValueWidget = new TouchoffWidget_AxisValue(applicableAxis.at(axisIndex));

        connect(gapValueWidget,SIGNAL(signal_AxisValueChanged()),this,SLOT(slot_AxisValueChanged()));
        m_TouchoffRefValues.insert(std::pair<MotorAxis,TouchoffWidget_AxisValue*>(currentAxis, refValueWidget));
        m_TouchoffGapValues.insert(std::pair<MotorAxis,TouchoffWidget_AxisValue*>(currentAxis, gapValueWidget));

        ui->verticalLayout_touchoffRef->addWidget(refValueWidget);
        ui->verticalLayout_initialGap->addWidget(gapValueWidget);
    }
}

void WidgetFrontPanel_Touchoff::executingAutomatedSequence(const bool &shouldBlock)
{
    ui->pushButton_ExecuteTouchoff->setDisabled(shouldBlock);
    ui->pushButton_TouchoffRef->setDisabled(shouldBlock);

    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator it;
    for(it = m_TouchoffRefValues.begin(); it != m_TouchoffRefValues.end(); ++it)
    {
        it->second->executingAutomatedSequence(shouldBlock);
    }

    for(it = m_TouchoffGapValues.begin(); it != m_TouchoffGapValues.end(); ++it)
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

void WidgetFrontPanel_Touchoff::on_pushButton_ExecuteTouchoff_released()
{
    transmitTouchoffGap();

    transmitTouchoffReference();

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
    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator it = m_TouchoffRefValues.begin();

    for (; it!=m_TouchoffRefValues.end(); ++it)
    {
        Status_PositionPerAxis axisPosition;
        if(m_MotionController->m_StateInterface->m_AxisPosition->getAxisPosition(it->first,axisPosition))
        {
            TouchoffWidget_AxisValue* currentWidget = it->second;
            currentWidget->setAxisValue(axisPosition.getPosition());
        }
    }
}

void WidgetFrontPanel_Touchoff::on_pushButton_TouchoffGap_released()
{

}

void WidgetFrontPanel_Touchoff::transmitTouchoffReference()
{
    Command_VariableArrayPtr command = std::make_shared<Command_VariableArray>();
    command->setVariableName("startTouchOffPosition");

    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator refIterator = m_TouchoffRefValues.begin();

    std::vector<double> refVector;

    for(;refIterator!=m_TouchoffRefValues.end();++refIterator)
    {
        TouchoffWidget_AxisValue* currentWidget = refIterator->second;
        refVector.push_back(currentWidget->getAxisValue());
    }

    command->setVariableValue(refVector);

    m_MotionController->executeCommand(command);
}

void WidgetFrontPanel_Touchoff::transmitTouchoffGap()
{

    Command_VariablePtr command = std::make_shared<Command_Variable>("startingGap");
    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator gapIterator = m_TouchoffGapValues.find(MotorAxis::Z);
    if(gapIterator != m_TouchoffGapValues.end())
    {
        command->setVariableValue(gapIterator->second->getAxisValue());
    }
//    Command_VariableArrayPtr command = std::make_shared<Command_VariableArray>();
//    command->setVariableName("startingGap");

//    std::map<MotorAxis,TouchoffWidget_AxisValue*>::iterator gapIterator = m_TouchoffGapValues.begin();

//    std::vector<double> refVector;

//    for(;gapIterator!=m_TouchoffGapValues.end();++gapIterator)
//    {
//        TouchoffWidget_AxisValue* currentWidget = gapIterator->second;
//        refVector.push_back(currentWidget->getAxisValue());
//    }

//    command->setVariableValue(refVector);

    m_MotionController->executeCommand(command);
}
