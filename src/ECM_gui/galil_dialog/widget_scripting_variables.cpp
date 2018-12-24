#include "widget_scripting_variables.h"
#include "ui_widget_scripting_variables.h"

Widget_ScriptingVariables::Widget_ScriptingVariables(GalilMotionController* galilObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_ScriptingVariables)
{
    ui->setupUi(this);

    m_Galil = galilObject;

    ui->doubleSpinBox_CutDepth->setToolTip("Profile Variable: maxdepth");
    ui->doubleSpinBox_RetractDistance->setToolTip("Profile Variable: rtdist");
    ui->doubleSpinBox_StepSize->setToolTip("Profile Variable: step");
    ui->spinBox_RetractSpeed->setToolTip("Profile Variable: backsp");
    ui->spinBox_PlungeSpeed->setToolTip("Profile Variable: forsp");
    ui->doubleSpinBox_CutSpeed->setToolTip("Profile Variable: speed");
    ui->spinBox_RetractPeriod->setToolTip("Profile Variable: rtfq");
    ui->spinBox_Pause->setToolTip("Profile Variable: rtpause");

    m_OperationalProgram.updateVariableValue("maxdepth",ui->doubleSpinBox_CutDepth->value() * 10.0);
    m_OperationalProgram.updateVariableValue("rtdist",ui->doubleSpinBox_RetractDistance->value() * 10.0);
    m_OperationalProgram.updateVariableValue("step",ui->doubleSpinBox_StepSize->value() * 10.0);
    m_OperationalProgram.updateVariableValue("backsp",ui->spinBox_RetractSpeed->value() * 10.0);
    m_OperationalProgram.updateVariableValue("forsp",ui->spinBox_PlungeSpeed->value() * 10.0);
    m_OperationalProgram.updateVariableValue("speed",ui->doubleSpinBox_CutSpeed->value() * 10.0);
    m_OperationalProgram.updateVariableValue("rtfq",ui->spinBox_RetractPeriod->value());
    m_OperationalProgram.updateVariableValue("rtpause",ui->spinBox_Pause->value());

    if(m_Galil->isDeviceConnected())
    {
        loadFromCurrentProgram(m_Galil->getCurrentMCProgram());
    }

    m_Galil->AddLambda_FinishedUploadingScript(this,[this](const bool &completed, const GalilCurrentProgram &program){
        if(completed)
        {
            loadFromCurrentProgram(program, ui->comboBox_ProgramLabels->currentText().toStdString(), false);
        }
    });

}

Widget_ScriptingVariables::~Widget_ScriptingVariables()
{
    m_Galil->RemoveHost(this);

    delete ui;
}

void Widget_ScriptingVariables::loadFromCurrentProgram(const GalilCurrentProgram &program, const std::string &profileName, const bool &useLoadedVars)
{
    //This will allow us to save the old variables first
    ProgramVariableList oldVariableList = m_OperationalProgram.getVariableList();

    //Load what we can from the new program
    m_OperationalProgram = program;
    updateProgramVariables(m_OperationalProgram.getVariableList());
    updateProgramLabels(m_OperationalProgram.getLabelList());
    if(!profileName.empty())
        this->setProfileName(profileName);

    if(!useLoadedVars)
    {
        //Set the old variable list to the current config
        m_OperationalProgram.setVariableList(oldVariableList);
        //Restore the old variable list visually
        updateProgramVariables(oldVariableList);
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

GalilCurrentProgram Widget_ScriptingVariables::getDesiredProgram() const
{
    return this->m_OperationalProgram;
}

ProgramVariableList Widget_ScriptingVariables::getVariableList() const
{
    return m_OperationalProgram.getVariableList();
}

void Widget_ScriptingVariables::updateProgramLabels(const ProgramLabelList &list)
{
    if(list.getLabelList().isEmpty())
        return;

    m_OperationalProgram.setLabelList(list);

    QString currentLabel = ui->comboBox_ProgramLabels->currentText();
    ui->comboBox_ProgramLabels->clear();

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

void Widget_ScriptingVariables::on_doubleSpinBox_CutDepth_editingFinished()
{
    double currentVariableValue = ui->doubleSpinBox_CutDepth->value() * 10.0;
    m_OperationalProgram.updateVariableValue("maxdepth",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("maxdepth",currentVariableValue);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_doubleSpinBox_RetractDistance_editingFinished()
{
    double currentVariableValue = ui->doubleSpinBox_RetractDistance->value() * 10.0;
    m_OperationalProgram.updateVariableValue("rtdist",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtdist",currentVariableValue);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_doubleSpinBox_StepSize_editingFinished()
{
    double currentVariableValue = ui->doubleSpinBox_StepSize->value() * 10.0;
    m_OperationalProgram.updateVariableValue("step",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("step",currentVariableValue);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_spinBox_RetractSpeed_editingFinished()
{
    double currentVariableValue = ui->spinBox_RetractSpeed->value() * 10.0;
    m_OperationalProgram.updateVariableValue("backsp",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("backsp",currentVariableValue);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_spinBox_PlungeSpeed_editingFinished()
{
    double currentVariableValue = ui->spinBox_PlungeSpeed->value() * 10.0;
    m_OperationalProgram.updateVariableValue("forsp",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("forsp",currentVariableValue);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_doubleSpinBox_CutSpeed_editingFinished()
{
    double currentVariableValue = ui->doubleSpinBox_CutSpeed->value() * 10.0;
    m_OperationalProgram.updateVariableValue("speed",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("speed",currentVariableValue);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_spinBox_RetractPeriod_editingFinished()
{
    double currentVariableValue = ui->spinBox_RetractPeriod->value();
    m_OperationalProgram.updateVariableValue("rtfq",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtfq",currentVariableValue);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_spinBox_Pause_editingFinished()
{
    double currentVariableValue = ui->spinBox_Pause->value();
    m_OperationalProgram.updateVariableValue("maxdepth",currentVariableValue);
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtpause",currentVariableValue);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::updateProgramVariables(const ProgramVariableList &list)
{
    double value = 0;
    if(list.getVariableValue("maxdepth",value))
        ui->doubleSpinBox_CutDepth->setValue(value / 10.0);
    if(list.getVariableValue("rtdist",value))
        ui->doubleSpinBox_RetractDistance->setValue(value / 10.0);
    if(list.getVariableValue("step",value))
        ui->doubleSpinBox_StepSize->setValue(value / 10.0);
    if(list.getVariableValue("backsp",value))
        ui->spinBox_RetractSpeed->setValue(static_cast<int>(value / 10.0));
    if(list.getVariableValue("forsp",value))
        ui->spinBox_PlungeSpeed->setValue(static_cast<int>(value / 10.0));
    if(list.getVariableValue("speed",value))
        ui->doubleSpinBox_CutSpeed->setValue(value / 10.0);
    if(list.getVariableValue("rtfq",value))
        ui->spinBox_RetractPeriod->setValue(static_cast<int>(value));
    if(list.getVariableValue("rtpause",value))
        ui->spinBox_Pause->setValue(static_cast<int>(value));
}

