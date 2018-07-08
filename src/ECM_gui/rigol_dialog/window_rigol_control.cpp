#include "window_rigol_control.h"
#include "ui_window_rigol_control.h"

Window_RigolControl::Window_RigolControl(RigolOscilliscope *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_OSCILLISCOPE,"RigolOS",parent),
    ui(new Ui::Window_RigolControl),
    m_Rigol(obj)
{
    ui->setupUi(this);
    connect(m_Rigol,SIGNAL(signal_RigolCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_OscilliscopeConnectionUpdate(common::comms::CommunicationUpdate)));
    connect(m_Rigol,SIGNAL(signal_RigolLoadComplete()),this,SLOT(slot_onLoadComplete()));

    connect(ui->widget_RadioButtons,SIGNAL(signal_onRadioButtonChange(data_Rigol::MeasurementTypes,bool)),this,SLOT(slot_onRadioButtonChange(data_Rigol::MeasurementTypes,bool)));

    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_1)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_2)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_3)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_4)));

    GeneralDialogWindow::readWindowSettings();

    openFromFile(GeneralDialogWindow::getPreviousSettingsPath());
}

Window_RigolControl::~Window_RigolControl()
{
    delete ui;
}

void Window_RigolControl::closeEvent(QCloseEvent *event)
{
    saveToFile(getPreviousSettingsPath());
    GeneralDialogWindow::closeEvent(event);
}

void Window_RigolControl::on_pushButton_Done_released()
{
    windowHidden = true;
    this->hide();
}

void Window_RigolControl::slot_OscilliscopeConnectionUpdate(const common::comms::CommunicationUpdate &value)
{
    if(value.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
        ui->widget_PumpOn->setColor(QColor(0,255,0));
    else if(value.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED)
        ui->widget_PumpOn->setColor(QColor(255,0,0));
}

void Window_RigolControl::slot_onRadioButtonChange(const MeasurementTypes &measurement, const bool &checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,measurement);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::slot_onLoadComplete()
{
    const bool wasBlocked = ui->widget_RadioButtons->blockSignals(true);
    ui->widget_RadioButtons->resetRadioButtons();
    QString comboText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboText.toStdString());
    commands_Rigol::RigolMeasurementQueue currentQueue = m_Rigol->getCurrentPollingMeasurements();
    std::vector<data_Rigol::MeasurementTypes> currentMeasurements = currentQueue.getMeasurementItemsPerChannel(currentChannel);
    for(unsigned int i = 0; i < currentMeasurements.size(); i++)
        ui->widget_RadioButtons->setRadioButton(currentMeasurements.at(i),true);
    ui->widget_RadioButtons->blockSignals(wasBlocked);
}

void Window_RigolControl::on_comboBox_Channel_currentIndexChanged(const QString &arg1)
{
    const bool wasBlocked = ui->widget_RadioButtons->blockSignals(true);
    ui->widget_RadioButtons->resetRadioButtons();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(arg1.toStdString());
    commands_Rigol::RigolMeasurementQueue currentQueue = m_Rigol->getCurrentPollingMeasurements();
    std::vector<data_Rigol::MeasurementTypes> currentMeasurements = currentQueue.getMeasurementItemsPerChannel(currentChannel);
    for(unsigned int i = 0; i < currentMeasurements.size(); i++)
        ui->widget_RadioButtons->setRadioButton(currentMeasurements.at(i),true);
    ui->widget_RadioButtons->blockSignals(wasBlocked);
}


///////////////////////////////////////////////////////////////////////////////////////////////
/// Action events triggered from the menu bar
///////////////////////////////////////////////////////////////////////////////////////////////

void Window_RigolControl::on_actionOpen_triggered()
{
    QString filePath = GeneralDialogWindow::onOpenAction();
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_RigolControl::on_actionSave_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAction();
    saveToFile(settingsPath);
}

void Window_RigolControl::on_actionSave_As_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAsAction();
    saveToFile(settingsPath);
}

void Window_RigolControl::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_RigolControl::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    QJsonObject saveObject;
    commands_Rigol::RigolMeasurementQueue currentQueue = m_Rigol->getCurrentPollingMeasurements();
    currentQueue.write(saveObject);
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}

void Window_RigolControl::openFromFile(const QString &filePath)
{
    QFile loadFile(filePath);
     if (!loadFile.open(QIODevice::ReadOnly)) return;

    QByteArray loadData = loadFile.readAll();
    loadFile.close();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    QJsonObject jsonObject = loadDoc.object();
    commands_Rigol::RigolMeasurementQueue loadQueue;
    loadQueue.read(jsonObject);
    m_Rigol->loadFromQueue(loadQueue);
}
