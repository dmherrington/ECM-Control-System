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
    ui->lineEdit_profileName->setText(QString::fromStdString(this->profileName));
}

WidgetVariableData* WidgetVariableDataDisplay::addNewVariable()
{
    WidgetVariableData* newData = new WidgetVariableData();
    vectorData.push_back(newData);

    ui->verticalLayout->addWidget(newData);
    connect(newData,SIGNAL(signalRemoveWidget(WidgetVariableData*)),
            this,SLOT(removeVariableWidget(WidgetVariableData*)));

    connect(newData,SIGNAL(signalDataChanged()),
            this,SLOT(on_dataChanged()));

    QSize size = newData->sizeHint();
    this->setFixedWidth(size.width() + 40);

    return newData;
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
    std::string currentString = ui->lineEdit_profileName->text().toStdString();
    if(this->profileName != currentString)
    {
        this->profileName = currentString;
        this->setDataChanged(true);
        emit signal_updatedProfileName(this->profileName);
    }
}

void WidgetVariableDataDisplay::on_pushButton_addVariable_clicked()
{
    this->addNewVariable();
}

void WidgetVariableDataDisplay::read(const QJsonArray &jsonArray)
{
    this->blockSignals(true);
    for(int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObject = jsonArray[i].toObject();
        WidgetVariableData* dataObj = this->addNewVariable();
        dataObj->read(jsonObject);
    }
    this->blockSignals(false);
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

void WidgetVariableDataDisplay::setDataChanged(const bool &changed)
{
    this->_hasDataChanged = changed;
}

bool WidgetVariableDataDisplay::hasDataChanged()
{
    return this->_hasDataChanged;
}

void WidgetVariableDataDisplay::on_dataChanged()
{
    this->_hasDataChanged = true;
}
