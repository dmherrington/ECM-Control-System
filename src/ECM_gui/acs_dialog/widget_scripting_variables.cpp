#include "widget_scripting_variables.h"
#include "ui_widget_scripting_variables.h"

Widget_ScriptingVariables::Widget_ScriptingVariables(SPIIMotionController *motionControllerObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_ScriptingVariables)
{
    ui->setupUi(this);

    m_MotionController = motionControllerObject;

    connect(m_MotionController, SIGNAL(signal_MCNewProgramLabelList(Operation_LabelList)),
            this, SLOT(slot_onNewlyAvailableLabels(Operation_LabelList)));

    connect(m_MotionController, SIGNAL(signal_MCNewProgramVariableList(Operation_VariableList)),
            this, SLOT(slot_onNewlyAvailableUserVariables(Operation_VariableList)));

    if(m_MotionController->isDeviceConnected())
    {
        //loadFromCurrentProgram(m_Galil->getCurrentMCProgram());
    }

//    m_Galil->AddLambda_FinishedUploadingScript(this,[this](const bool &completed, const GalilCurrentProgram &program){
//        if(completed)
//        {
//            loadFromCurrentProgram(program, ui->comboBox_ProgramLabels->currentText().toStdString(), false);
//        }
//    });

}

Widget_ScriptingVariables::~Widget_ScriptingVariables()
{
    m_MotionController->RemoveHost(this);

    delete ui;
}

void Widget_ScriptingVariables::loadFromCurrentProgram(const Operation_LabelList &labels, const Operation_VariableList &vars,
                                                       const std::string &profileName, const bool &useLoadedVars)
{
    //Load what we can from the new program
    updateProgramLabels(labels);
    updateProgramVariables(vars);

    if(!profileName.empty())
        this->setProfileName(profileName);

    if(!useLoadedVars)
    {
        //Set the old variable list to the current config
        //m_OperationalProgram.setVariableList(oldVariableList);
        //Restore the old variable list visually
        //updateProgramVariables(oldVariableList);
    }
}

void Widget_ScriptingVariables::setProfileName(const std::string &name)
{
    int profileIndex = ui->comboBox_ProgramLabels->findText(QString::fromStdString(name));
    if(profileIndex > 0)
        ui->comboBox_ProgramLabels->setCurrentIndex(profileIndex);
}

std::string Widget_ScriptingVariables::getProfileName() const
{
    return this->ui->comboBox_ProgramLabels->currentText().toStdString();
}

//GalilCurrentProgram Widget_ScriptingVariables::getDesiredProgram() const
//{
//    return this->m_OperationalProgram;
//}

//ProgramVariableList Widget_ScriptingVariables::getVariableList() const
//{
//    return m_OperationalProgram.getVariableList();
//}

void Widget_ScriptingVariables::slot_onNewlyAvailableLabels(const Operation_LabelList &list)
{
    updateProgramLabels(list);
}

void Widget_ScriptingVariables::slot_onNewlyAvailableUserVariables(const Operation_VariableList &vars)
{
    updateProgramVariables(vars);
}

void Widget_ScriptingVariables::updateProgramLabels(const Operation_LabelList &list)
{
    QString currentLabel = ui->comboBox_ProgramLabels->currentText();
    ui->comboBox_ProgramLabels->clear();

    if(list.getLabelList().isEmpty())
    {
        return;
    }
    //m_OperationalProgram.setLabelList(list);

    std::map<std::string,int> programLabels = list.getLabelMap();
    std::map<std::string,int>::iterator it = programLabels.begin();
    for(;it!=programLabels.end();++it)
    {
        ui->comboBox_ProgramLabels->addItem(QString::fromStdString(it->first));
    }

    int foundIndex = ui->comboBox_ProgramLabels->findText(currentLabel);
    if(foundIndex > -1)
    {
        ui->comboBox_ProgramLabels->setCurrentIndex(foundIndex);
    }
}

/*
void Widget_ScriptingVariables::on_doubleSpinBox_CutDepth_editingFinished()
{
    double currentVariableValue = ui->doubleSpinBox_CutDepth->value() * 10.0;
    //m_OperationalProgram.updateVariableValue("maxdepth",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("maxdepth",currentVariableValue);
}

void Widget_ScriptingVariables::on_doubleSpinBox_RetractDistance_editingFinished()
{
    double currentVariableValue = ui->doubleSpinBox_RetractDistance->value() * 10.0;
    //m_OperationalProgram.updateVariableValue("rtdist",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtdist",currentVariableValue);
}

void Widget_ScriptingVariables::on_doubleSpinBox_StepSize_editingFinished()
{
    double currentVariableValue = ui->doubleSpinBox_StepSize->value() * 10.0;
    //m_OperationalProgram.updateVariableValue("step",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("step",currentVariableValue);
}

void Widget_ScriptingVariables::on_spinBox_RetractSpeed_editingFinished()
{
    double currentVariableValue = ui->spinBox_RetractSpeed->value() * 10.0;
    //m_OperationalProgram.updateVariableValue("backsp",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("backsp",currentVariableValue);
}

void Widget_ScriptingVariables::on_spinBox_PlungeSpeed_editingFinished()
{
    double currentVariableValue = ui->spinBox_PlungeSpeed->value() * 10.0;
    //m_OperationalProgram.updateVariableValue("forsp",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("forsp",currentVariableValue);
}

void Widget_ScriptingVariables::on_doubleSpinBox_CutSpeed_editingFinished()
{
    double currentVariableValue = ui->doubleSpinBox_CutSpeed->value() * 10.0;
    //m_OperationalProgram.updateVariableValue("speed",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("speed",currentVariableValue);
}

void Widget_ScriptingVariables::on_spinBox_RetractPeriod_editingFinished()
{
    double currentVariableValue = ui->spinBox_RetractPeriod->value();
    //m_OperationalProgram.updateVariableValue("rtfq",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtfq",currentVariableValue);
}

void Widget_ScriptingVariables::on_spinBox_Pause_editingFinished()
{
    double currentVariableValue = ui->spinBox_Pause->value();
    //m_OperationalProgram.updateVariableValue("maxdepth",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtpause",currentVariableValue);
}
*/


void Widget_ScriptingVariables::clearVariableTable()
{
    ui->listWidget_Variables->clear();

    for (std::map<std::string, Widget_VariableDescriptor*>::iterator it=m_VariableDescriptors.begin(); it!=m_VariableDescriptors.end();)
    {
        Widget_VariableDescriptor* currentWidget = it->second;
        delete currentWidget;
        m_VariableDescriptors.erase(it++);
    }
}

void Widget_ScriptingVariables::updateProgramVariables(const Operation_VariableList &list)
{
    //This will allow us to save the old variables first
    Operation_VariableList oldVariableList = m_ConfiguredVariables;


    std::map<std::string, double> currentVariableList = list.getVariableMap();

    for (std::map<std::string, double>::iterator it=currentVariableList.begin(); it!=currentVariableList.end(); ++it)
    {
        Widget_VariableDescriptor* tableVariable = new Widget_VariableDescriptor(it->first, it->second);
        QListWidgetItem* newItem = new QListWidgetItem();
        newItem->setSizeHint(tableVariable->sizeHint());
        ui->listWidget_Variables->addItem(newItem);
        ui->listWidget_Variables->setItemWidget(newItem,tableVariable);
    }


}

