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

    connect(m_Galil, SIGNAL(signal_MCNewProgramVariableList(ProgramVariableList)), this, SLOT(slot_MCNEWProgramVariableList(ProgramVariableList)));

    currentVarList.addVariable("maxdepth",ui->doubleSpinBox_CutDepth->value() * 10.0);
    currentVarList.addVariable("rtdist",ui->doubleSpinBox_RetractDistance->value() * 10.0);
    currentVarList.addVariable("step",ui->doubleSpinBox_StepSize->value() * 10.0);
    currentVarList.addVariable("backsp",ui->spinBox_RetractSpeed->value() * 10.0);
    currentVarList.addVariable("forsp",ui->spinBox_PlungeSpeed->value() * 10.0);
    currentVarList.addVariable("speed",ui->doubleSpinBox_CutSpeed->value() * 10.0);
    currentVarList.addVariable("rtfq",ui->spinBox_RetractPeriod->value());
    currentVarList.addVariable("rtpause",ui->spinBox_Pause->value());

}

Widget_ScriptingVariables::~Widget_ScriptingVariables()
{
    delete ui;
}

void Widget_ScriptingVariables::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray MCDataArray;

    QJsonObject dataObject;
    dataObject["profileName"] = QString::fromStdString(this->getProfileName());

    QJsonArray MCVariableArray;

    std::map<std::string,double> variableMap = currentVarList.getVariableMap();
    std::map<std::string,double>::iterator it = variableMap.begin();

    for(;it!=variableMap.end();++it)
    {
        QJsonObject varObject;
        std::string variableKey = it->first;
        varObject[QString::fromStdString(variableKey)] = it->second;
        MCVariableArray.append(varObject);
    }

    dataObject["variableData"] = MCVariableArray;

    MCDataArray.append(dataObject);
    saveObject["MotionControlData"] = MCDataArray;
}

void Widget_ScriptingVariables::readFromJSON(const QJsonObject &openObject)
{
    ProgramVariableList newList;
    newList.clearVariableList();

    QJsonArray MCDataArray = openObject["MotionControlData"].toArray();
    QJsonObject dataObject = MCDataArray[0].toObject();

    QString profileString = dataObject["profileName"].toString();
    int profileIndex = ui->comboBox_ProgramLabels->findText(profileString);
    if(profileIndex > 0)
        ui->comboBox_ProgramLabels->setCurrentIndex(profileIndex);

    QJsonArray MCVariableArray = dataObject["variableData"].toArray();
    for (int variableIndex = 0; variableIndex < MCVariableArray.size(); ++variableIndex) {
        QJsonObject variableObject = MCVariableArray[variableIndex].toObject();
        QString variableKey = variableObject.keys().at(0);
        double variableValue = variableObject.value(variableKey).toDouble();
        newList.addVariable(variableKey.toStdString(),variableValue);
    }

    this->slot_MCNEWProgramVariableList(newList);
}

std::string Widget_ScriptingVariables::getProfileName() const
{
    return this->ui->comboBox_ProgramLabels->currentText().toStdString();
}

ProgramVariableList Widget_ScriptingVariables::getVariableList() const
{
    return currentVarList;
}

void Widget_ScriptingVariables::updateProgramLabels(const ProgramLabelList &list)
{
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
    //Command_Variable command("maxdepth",ui->doubleSpinBox_CutDepth->value() * 10);
    Command_VariablePtr command = std::make_shared<Command_Variable>("maxdepth",ui->doubleSpinBox_CutDepth->value() * 10.0);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_doubleSpinBox_RetractDistance_editingFinished()
{
    //Command_Variable command("rtdist",ui->doubleSpinBox_RetractDistance->value() * 10);
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtdist",ui->doubleSpinBox_RetractDistance->value() * 10.0);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_doubleSpinBox_StepSize_editingFinished()
{
    //Command_Variable command("step",ui->doubleSpinBox_StepSize->value() * 10);
    Command_VariablePtr command = std::make_shared<Command_Variable>("step",ui->doubleSpinBox_StepSize->value() * 10.0);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_spinBox_RetractSpeed_editingFinished()
{
    //Command_Variable command("backsp",ui->spinBox_RetractSpeed->value() * 10);
    Command_VariablePtr command = std::make_shared<Command_Variable>("backsp",ui->spinBox_RetractSpeed->value() * 10.0);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_spinBox_PlungeSpeed_editingFinished()
{
    //Command_Variable command("forsp",ui->spinBox_PlungeSpeed->value() * 10);
    Command_VariablePtr command = std::make_shared<Command_Variable>("forsp",ui->spinBox_PlungeSpeed->value() * 10.0);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_doubleSpinBox_CutSpeed_editingFinished()
{
    //Command_Variable command("speed",ui->doubleSpinBox_CutSpeed->value() * 10);
    Command_VariablePtr command = std::make_shared<Command_Variable>("speed",ui->doubleSpinBox_CutSpeed->value() * 10.0);
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_spinBox_RetractPeriod_editingFinished()
{
    //Command_Variable command("rtfq",ui->spinBox_RetractPeriod->value());
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtfq",ui->spinBox_RetractPeriod->value());
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::on_spinBox_Pause_editingFinished()
{
    //Command_Variable command("rtpause",ui->spinBox_Pause->value());
    Command_VariablePtr command = std::make_shared<Command_Variable>("rtpause",ui->spinBox_Pause->value());
    //m_Galil->executeCommand(command);
}

void Widget_ScriptingVariables::slot_MCNEWProgramVariableList(const ProgramVariableList &variables)
{
    this->currentVarList = variables;

    double value = 0;
    if(variables.getVariableValue("maxdepth",value))
        ui->doubleSpinBox_CutDepth->setValue(value / 10.0);
    if(variables.getVariableValue("rtdist",value))
        ui->doubleSpinBox_RetractDistance->setValue(value / 10.0);
    if(variables.getVariableValue("step",value))
        ui->doubleSpinBox_StepSize->setValue(value / 10.0);
    if(variables.getVariableValue("backsp",value))
        ui->spinBox_RetractSpeed->setValue(value / 10.0);
    if(variables.getVariableValue("forsp",value))
        ui->spinBox_PlungeSpeed->setValue(value / 10.0);
    if(variables.getVariableValue("speed",value))
        ui->doubleSpinBox_CutSpeed->setValue(value / 10.0);
    if(variables.getVariableValue("rtfq",value))
        ui->spinBox_RetractPeriod->setValue(value);
    if(variables.getVariableValue("rtpause",value))
        ui->spinBox_Pause->setValue(value);
}

void Widget_ScriptingVariables::slot_MCNewProgramLabelList(const ProgramLabelList &labels)
{
    std::string currentProgram = ui->comboBox_ProgramLabels->currentText().toStdString();

    ui->comboBox_ProgramLabels->clear();

    ui->comboBox_ProgramLabels->addItems(labels.getLabelList());

    if(labels.doesLabelExist(currentProgram))
    {
        int boxIndex = ui->comboBox_ProgramLabels->findText(QString::fromStdString(currentProgram));
        ui->comboBox_ProgramLabels->setCurrentIndex(boxIndex);
    }
}
