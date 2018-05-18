#include "window_rigol_control.h"
#include "ui_window_rigol_control.h"

Window_RigolControl::Window_RigolControl(RigolOscilliscope *obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_RigolControl),
    m_Rigol(obj)
{
    ui->setupUi(this);
    connect(m_Rigol,SIGNAL(signal_RigolConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(slot_OscilliscopeConnectionUpdate(common::comms::CommunicationConnection)));
    connect(m_Rigol,SIGNAL(signal_RigolLoadComplete()),this,SLOT(slot_onLoadComplete()));

    connect(ui->widget_RadioButtons,SIGNAL(signal_onRadioButtonChange(data_Rigol::MeasurementTypes,bool)),this,SLOT(slot_onRadioButtonChange(data_Rigol::MeasurementTypes,bool)));

    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_1)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_2)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_3)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_4)));

    //Setting up the proper directory paths for all of the stuff
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir loggingDirectory(QString::fromStdString(rootPath + "/Rigol/logs"));
        QDir setupDirectory(QString::fromStdString(rootPath + "/Rigol/setup"));
        QDir settingsDirectory(QString::fromStdString(rootPath + "/Rigol/settings"));

        loggingDirectory.mkpath(QString::fromStdString(rootPath + "/Rigol/logs"));
        setupDirectory.mkpath(QString::fromStdString(rootPath + "/Rigol/setup"));
        settingsDirectory.mkpath(QString::fromStdString(rootPath + "/Rigol/settings"));

        loggingPath = loggingDirectory.absolutePath() + "/";
        previousSettingsPath = setupDirectory.absolutePath() + "/previousSettings.json";
        currentSettingsPath = "";
    }

}

void Window_RigolControl::getSettingsPath(std::string &filePath) const
{
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QFile settingsDirectory(QString::fromStdString(rootPath + "/Rigol/settings"));
        QFileInfo fileInfo(settingsDirectory);
        filePath = fileInfo.absolutePath().toStdString();
    }
}

Window_RigolControl::~Window_RigolControl()
{
    delete ui;
}

bool Window_RigolControl::isWindowHidden() const
{
    return windowHidden;
}

void Window_RigolControl::readSettings()
{
    QSettings settings("Rigol Window", "ECM Application");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

void Window_RigolControl::closeEvent(QCloseEvent *event)
{
    UNUSED(event);
    QSettings settings("Rigol Window", "ECM Application");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    m_Rigol->saveMeasurementsToFile(previousSettingsPath.toStdString());
}

void Window_RigolControl::hideEvent(QHideEvent *event)
{
    UNUSED(event);
    windowHidden = true;
    emit signal_onRigolWindowChanged(false);
}

void Window_RigolControl::showEvent(QShowEvent *event)
{
    UNUSED(event);
    windowHidden = false;
}

void Window_RigolControl::on_pushButton_Done_released()
{
    windowHidden = true;
    this->hide();
}

void Window_RigolControl::slot_OscilliscopeConnectionUpdate(const common::comms::CommunicationConnection &value)
{
    if(value.isConnected())
        ui->widget_PumpOn->setColor(QColor(0,255,0));
    else
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


/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITH PARAMETERS MENU BAR
/////////////////////////////////////////////////////////////////////////

void Window_RigolControl::on_actionClose_triggered()
{
    this->hide();
}

void Window_RigolControl::on_actionSave_triggered()
{
    if(currentSettingsPath == "")
        this->on_actionSave_As_triggered();
    else
        m_Rigol->saveMeasurementsToFile(currentSettingsPath.toStdString());
}

void Window_RigolControl::on_actionSave_As_triggered()
{
    std::string settingsPath = "";
    this->getSettingsPath(settingsPath);
    QString fullFile = saveAsFileDialog(settingsPath,"json");
    if(!fullFile.isEmpty() && !fullFile.isNull()){
        m_Rigol->saveMeasurementsToFile(fullFile.toStdString());
    }
}

void Window_RigolControl::on_actionOpen_triggered()
{
    std::string settingsPath = "";
    this->getSettingsPath(settingsPath);
    QString filePath = loadFileDialog(settingsPath,"json");

    if(!filePath.isEmpty()&& !filePath.isNull()){
        currentSettingsPath = filePath;
        m_Rigol->loadMeaurements(currentSettingsPath.toStdString());
    }
}

QString Window_RigolControl::saveAsFileDialog(const std::string &filePath, const std::string &suffix)
{
    QFileDialog fileDialog(this, "Save program as:");
    QDir galilProgramDirectory(QString::fromStdString(filePath));
    fileDialog.setDirectory(galilProgramDirectory);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    QString nameFilter = "Open Files (*.";
    nameFilter += QString::fromStdString(suffix) + ")";
    fileDialog.setNameFilter(nameFilter);
    fileDialog.setDefaultSuffix(QString::fromStdString(suffix));
    fileDialog.exec();
    QString fullFilePath = fileDialog.selectedFiles().first();
    return fullFilePath;
}

QString Window_RigolControl::loadFileDialog(const std::string &filePath, const std::string &suffix)
{
    QFileDialog fileDialog(this, "Choose profile to open");
    QDir galilProgramDirectory(QString::fromStdString(filePath));
    fileDialog.setDirectory(galilProgramDirectory);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    QString nameFilter = "Open Files (*.";
    nameFilter += QString::fromStdString(suffix) + ")";
    fileDialog.setNameFilter(nameFilter);
    fileDialog.setDefaultSuffix(QString::fromStdString(suffix));
    fileDialog.exec();
    QString fullFilePath = fileDialog.selectedFiles().first();
    return fullFilePath;
}
