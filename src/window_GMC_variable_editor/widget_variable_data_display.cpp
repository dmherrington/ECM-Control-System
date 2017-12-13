#include "widget_variable_data_display.h"
#include "ui_widget_variable_data_display.h"

WidgetVariableDataDisplay::WidgetVariableDataDisplay(QWidget *parent) :
    QWidget(parent), ui(new Ui::WidgetVariableDataDisplay),
    profileName("Default")
{
    ui->setupUi(this);

    this->blockSignals(true);

    ui->lineEdit_profileName->setText(QString::fromStdString(this->profileName));

    this->blockSignals(false);
}

WidgetVariableDataDisplay::~WidgetVariableDataDisplay()
{
    delete ui;
}
std::string WidgetVariableDataDisplay::getProfileName() const
{
    return this->profileName;
}

void WidgetVariableDataDisplay::setProfileName(const std::string &name)
{
    this->profileName = name;
}

void WidgetVariableDataDisplay::addNewVariable()
{
    WidgetVariableData* newData = new WidgetVariableData();
    vectorData.push_back(newData);

    ui->verticalLayout->addWidget(newData);
    connect(newData,SIGNAL(signalRemoveWidget(WidgetVariableData*)),
            this,SLOT(removeVariableWidget(WidgetVariableData*)));

    QSize currentSize = this->size();
    QSize size = newData->sizeHint();
    this->setFixedWidth(size.width() + 40);
}

void WidgetVariableDataDisplay::removeVariableWidget(WidgetVariableData *obj)
{
    ui->verticalLayout->removeWidget(obj);

    std::vector<WidgetVariableData*>::iterator it;
    for(it = vectorData.begin(); it != vectorData.end(); ++it)
    {
        if(*it == obj)
        {
            vectorData.erase(it);
            break;
        }
    }

    delete obj;
    obj = NULL;
}

void WidgetVariableDataDisplay::on_lineEdit_profileName_editingFinished()
{
    this->profileName = ui->lineEdit_profileName->text().toStdString();
    emit signal_updatedProfileName(this->profileName);
}

void WidgetVariableDataDisplay::on_pushButton_addVariable_clicked()
{
    this->addNewVariable();
}

void WidgetVariableDataDisplay::read(const QJsonObject &json)
{
//    QJsonArray segmentDataArray = json["linearProfile"].toArray();
//    QJsonObject arrayObject = segmentDataArray[0].toObject();
//    this->setDepthofCut(arrayObject["depthOfCut"].toInt());
//    this->setCutSpeed(arrayObject["cutSpeed"].toInt());
}
void WidgetVariableDataDisplay::write(QJsonObject &json) const
{
    QJsonArray variableDataArray;
    for(unsigned int i = 0; i < vectorData.size(); i++)
    {
        vectorData.at(i)->write(variableDataArray);

    }
    json[QString::fromStdString(this->profileName)] = variableDataArray;
}
