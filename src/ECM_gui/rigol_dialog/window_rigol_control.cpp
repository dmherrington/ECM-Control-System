#include "window_rigol_control.h"
#include "ui_window_rigol_control.h"

Window_RigolControl::Window_RigolControl(RigolOscilliscope *obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_RigolControl),
    m_Rigol(obj)
{
    ui->setupUi(this);

    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_1)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_2)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_3)));
    ui->comboBox_Channel->addItem(QString::fromStdString(AvailableChannelsToDisplayString(AvailableChannels::CHANNEL_4)));
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
    QSettings settings("Rigol Window", "ECM Application");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void Window_RigolControl::hideEvent(QHideEvent *event)
{
    windowHidden = true;
}

void Window_RigolControl::showEvent(QShowEvent *event)
{
    windowHidden = false;
}

void Window_RigolControl::on_pushButton_Done_released()
{
    windowHidden = true;
    this->hide();
}

void Window_RigolControl::on_comboBox_Channel_currentIndexChanged(const QString &arg1)
{
    this->resetRadioButtons();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(arg1.toStdString());
    commands_Rigol::RigolMeasurementQueue currentQueue = m_Rigol->getCurrentPollingMeasurements();
    std::vector<data_Rigol::MeasurementTypes> currentMeasurements = currentQueue.getMeasurementItemsPerChannel(currentChannel);
    for(int i = 0; i < currentMeasurements.size(); i++)
        setRadioButton(currentMeasurements.at(i),true);
}

void Window_RigolControl::setRadioButton(const data_Rigol::MeasurementTypes &measurement, const bool &value)
{
    switch (measurement) {
    case data_Rigol::MeasurementTypes::MEASURE_VAMP:
        ui->radioButton_AMP->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_VAVG:
        ui->radioButton_AVG->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_VBASE:
        ui->radioButton_BASE->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_FDELAY:
        ui->radioButton_FDELAY->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_FPHASE:
        ui->radioButton_FPHASE->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_FREQUENCY:
        ui->radioButton_FREQUENCY->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_FTIME:
        ui->radioButton_FTIME->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_MAREA:
        ui->radioButton_MAREA->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_VMAX:
        ui->radioButton_MAX->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_VMIN:
        ui->radioButton_MIN->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_MPAREA:
        ui->radioButton_MPAREA->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_NDUTY:
        ui->radioButton_NDUTY->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_NWIDTH:
        ui->radioButton_NWIDTH->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_OVERSHOOT:
        ui->radioButton_OVERSHOOT->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_PDUTY:
        ui->radioButton_PDUTY->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_PERIOD:
        ui->radioButton_PERIOD->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_PRESHOOT:
        ui->radioButton_PRESHOOT->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_PWIDTH:
        ui->radioButton_PWIDTH->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_RDELAY:
        ui->radioButton_RDELAY->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_VRMS:
        ui->radioButton_RMS->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_RPHASE:
        ui->radioButton_RPHASE->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_RTIME:
        ui->radioButton_RTIME->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_VPP:
        ui->radioButton_VPP->setChecked(value);
        break;
    case data_Rigol::MeasurementTypes::MEASURE_VTOP:
        ui->radioButton_VTOP->setChecked(value);
        break;
    default:
        break;
    }
}

void Window_RigolControl::resetRadioButtons()
{
    QObject::blockSignals(true);
    ui->radioButton_AMP->setChecked(false);
    ui->radioButton_AVG->setChecked(false);
    ui->radioButton_BASE->setChecked(false);
    ui->radioButton_FDELAY->setChecked(false);
    ui->radioButton_FPHASE->setChecked(false);
    ui->radioButton_FREQUENCY->setChecked(false);
    ui->radioButton_FTIME->setChecked(false);
    ui->radioButton_MAREA->setChecked(false);
    ui->radioButton_MAX->setChecked(false);
    ui->radioButton_MIN->setChecked(false);
    ui->radioButton_MPAREA->setChecked(false);
    ui->radioButton_NDUTY->setChecked(false);
    ui->radioButton_NWIDTH->setChecked(false);
    ui->radioButton_OVERSHOOT->setChecked(false);
    ui->radioButton_PDUTY->setChecked(false);
    ui->radioButton_PERIOD->setChecked(false);
    ui->radioButton_PRESHOOT->setChecked(false);
    ui->radioButton_PWIDTH->setChecked(false);
    ui->radioButton_RDELAY->setChecked(false);
    ui->radioButton_RMS->setChecked(false);
    ui->radioButton_RPHASE->setChecked(false);
    ui->radioButton_RTIME->setChecked(false);
    ui->radioButton_VPP->setChecked(false);
    ui->radioButton_VTOP->setChecked(false);
    QObject::blockSignals(false);
}

void Window_RigolControl::on_radioButton_AMP_toggled(bool checked)
{

    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_VAMP);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_AVG_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_VAVG);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_BASE_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_VBASE);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_FDELAY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_FDELAY);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_FPHASE_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_FPHASE);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_FREQUENCY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_FREQUENCY);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_FTIME_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_FTIME);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_MAREA_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_MAREA);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_MAX_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_VMAX);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_MIN_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_VMIN);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_MPAREA_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_MPAREA);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_NDUTY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_NDUTY);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_NWIDTH_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_NWIDTH);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_OVERSHOOT_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_OVERSHOOT);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_PDUTY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_PDUTY);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_PERIOD_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_PERIOD);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_PRESHOOT_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_PRESHOOT);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_PWIDTH_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_PWIDTH);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_RDELAY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_RDELAY);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_RMS_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_VRMS);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_RPHASE_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_RPHASE);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_RTIME_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_RTIME);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_VPP_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_VPP);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_VTOP_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement("Rigol",currentChannel,data_Rigol::MeasurementTypes::MEASURE_VTOP);
    if(checked)
        m_Rigol->addPollingMeasurement(newMeasurement);
    else
        m_Rigol->removePollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_actionClose_triggered()
{
    this->hide();
}
