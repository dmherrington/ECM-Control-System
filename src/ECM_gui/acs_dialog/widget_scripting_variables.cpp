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

//    connect(m_MotionController, SIGNAL(signal_MCNewProgramVariableList(Operation_VariableList)),
//            this, SLOT(slot_onNewlyAvailableUserVariables(Operation_VariableList)));

    if(m_MotionController->isDeviceConnected())
    {
        Operation_LabelList currentLabels = m_MotionController->m_StateInterface->m_BufferManager->getCurrentOperationLabels();
        Operation_VariableList currentVariables = m_MotionController->m_StateInterface->m_BufferManager->getCurrentUserVariables();

        loadFromCurrentProgram(currentLabels, currentVariables);
    }

    m_MotionController->AddLambda_FinishedUploadingVariables(this,[this](const bool &success, const Operation_VariableList &variableList){
        if(success)
        {
            updateProgramVariables(variableList);
        }
    });

    m_MotionController->AddLambda_FinishedUploadingScript(this,[this](const bool &success, const SPII_CurrentProgram &program){
        if(success)
        {
            loadFromCurrentProgram(program.getCurrentOperationLabels(), program.getCurrentUserVariables(),
                                   ui->comboBox_ProgramLabels->currentText().toStdString(), false);
        }
    });

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
    updateProgramVariables(vars , useLoadedVars);

    if(!profileName.empty())
        this->setProfileName(profileName);
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

Operation_VariableList Widget_ScriptingVariables::getVariableList() const
{
    Operation_VariableList currentVars;

    std::map<std::string, Widget_VariableDescriptor*>::const_iterator it;
    for (it=m_VariableDescriptors.begin(); it!=m_VariableDescriptors.end(); ++it)
    {
        Widget_VariableDescriptor* currentWidget = it->second;
        std::string variableName; double variableValue;
        currentWidget->getVariableProperties(variableName, variableValue);
        currentVars.addVariable(variableName, variableValue);
    }

    return currentVars;
}

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

void Widget_ScriptingVariables::updateProgramVariables(const Operation_VariableList &list, const bool &restoreVariables)
{
    //This will allow us to save the old variables first
    Operation_VariableList oldVariableList = m_ConfiguredVariables;


    std::map<std::string, double> currentVariableList = list.getVariableMap();

    for (std::map<std::string, double>::iterator it=currentVariableList.begin(); it!=currentVariableList.end(); ++it)
    {
        Widget_VariableDescriptor* tableVariable = new Widget_VariableDescriptor(it->first, it->second);
        if(restoreVariables)
        {
            double oldValue = 0.0;
            if(oldVariableList.getVariableValue(it->first,oldValue))
                tableVariable->setVariableValue(oldValue);
        }
        QListWidgetItem* newItem = new QListWidgetItem();
        newItem->setSizeHint(tableVariable->sizeHint());
        ui->listWidget_Variables->addItem(newItem);
        ui->listWidget_Variables->setItemWidget(newItem,tableVariable);

        m_VariableDescriptors.insert(std::pair<std::string, Widget_VariableDescriptor*>(it->first,tableVariable));
    }
}

