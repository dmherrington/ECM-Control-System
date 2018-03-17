#include "widget_variable_data_display.h"
#include "ui_widget_variable_data_display.h"

WidgetVariableDataDisplay::WidgetVariableDataDisplay(QWidget *parent) :
    QWidget(parent), ui(new Ui::WidgetVariableDataDisplay)
{
    ui->setupUi(this);

    profile = new ProgramGenericProfile();

    this->blockSignals(true);

    ui->lineEdit_profileName->setText(QString::fromStdString(this->profile->getProfileName()));

    this->blockSignals(false);
}

WidgetVariableDataDisplay::~WidgetVariableDataDisplay()
{
    delete ui;
}

ProgramGenericProfile WidgetVariableDataDisplay::getProfile() const
{
    ProgramGenericProfile newProfile(*this->profile);
    std::cout<<"Lets check this"<<std::endl;
    return newProfile;
}

std::string WidgetVariableDataDisplay::getProfileName() const
{
    return this->profile->getProfileName();
}

void WidgetVariableDataDisplay::setProfileName(const std::string &name)
{
    this->profile->setProfileName(name);
    ui->lineEdit_profileName->setText(QString::fromStdString(this->profile->getProfileName()));
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

std::vector<std::string> WidgetVariableDataDisplay::getDisplayNames() const
{
    std::vector<std::string> rtn;
    for(unsigned int i = 0; i < vectorData.size(); i++)
    {
        rtn.push_back(vectorData.at(i)->getDisplayName());
    }
    return rtn;
}

std::vector<std::string> WidgetVariableDataDisplay::getVariableNames() const
{
    std::vector<std::string> rtn;
    for(unsigned int i = 0; i < vectorData.size(); i++)
    {
        rtn.push_back(vectorData.at(i)->getVariableName());
    }
    return rtn;
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
    if(this->profile->getProfileName() != currentString)
    {
        this->profile->setProfileName(currentString);
        this->setDataChanged(true);
        emit signal_updatedProfileName(currentString);
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
    //Initialize a new object for the entire profile
    //This will be the object that we add all the data to for this single instance
    QJsonObject newObject;

    //next update the profile object with all of the settings
    std::map<std::string, ProgramProfileVariable> settingsData;

    for(unsigned int i = 0; i < vectorData.size(); i++)
    {
        std::string name = vectorData.at(i)->getDisplayName();
        settingsData[name] = vectorData.at(i)->getProfileVariable();
    }

    this->profile->setVariableMap(settingsData);
    this->profile->write(newObject);

    //Add the object to the json data structure with a key equivalent to the profile name
    json[QString::fromStdString(this->profile->getProfileName())] = newObject;
}


void WidgetVariableDataDisplay::updateProfile(const ProgramGenericProfile &data)
{
    profile->copyData(data);
    this->updateRendering();
    std::map<std::string,ProgramProfileVariable> mapVariables = profile->getVariableMap();
    std::map<std::string,ProgramProfileVariable>::iterator mapIterator;
    for(mapIterator = mapVariables.begin(); mapIterator != mapVariables.end(); ++mapIterator)
    {
        WidgetVariableData* dataWidget = this->addNewVariable();
        dataWidget->setVariableData(mapIterator->second);
    }
}

void WidgetVariableDataDisplay::updateRendering()
{
    this->blockSignals(true);
    ui->lineEdit_profileName->setText(QString::fromStdString(this->profile->getProfileName()));
    ui->lineEdit_profileLabel->setText(QString::fromStdString(this->profile->getProfileLabel()));
    ui->doubleSpinBox_PGain->setValue(this->profile->profileGain.getGainValue(GainType::PGain));
    ui->doubleSpinBox_IGain->setValue(this->profile->profileGain.getGainValue(GainType::IGain));
    ui->doubleSpinBox_DGain->setValue(this->profile->profileGain.getGainValue(GainType::DGain));
    this->blockSignals(false);
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

void WidgetVariableDataDisplay::on_doubleSpinBox_PGain_editingFinished()
{
    double value = this->ui->doubleSpinBox_PGain->value();
    this->profile->profileGain.setGainValue(GainType::PGain,value);
}

void WidgetVariableDataDisplay::on_doubleSpinBox_IGain_editingFinished()
{
    double value = this->ui->doubleSpinBox_IGain->value();
    this->profile->profileGain.setGainValue(GainType::IGain,value);
}

void WidgetVariableDataDisplay::on_doubleSpinBox_DGain_editingFinished()
{
    double value = this->ui->doubleSpinBox_DGain->value();
    this->profile->profileGain.setGainValue(GainType::DGain,value);
}

void WidgetVariableDataDisplay::on_lineEdit_profileLabel_editingFinished()
{
    this->profile->setProfileLabel(this->ui->lineEdit_profileLabel->text().toStdString());
}
