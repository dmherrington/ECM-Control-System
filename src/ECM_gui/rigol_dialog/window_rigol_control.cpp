#include "window_rigol_control.h"
#include "ui_window_rigol_control.h"

Window_RigolControl::Window_RigolControl(const RigolOscilliscope* obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_RigolControl),
    m_Rigol(obj)
{
    ui->setupUi(this);
}

Window_RigolControl::~Window_RigolControl()
{
    delete ui;
}

void Window_RigolControl::on_pushButton_Done_released()
{
    emit signal_RigolHideWindow();
}

void Window_RigolControl::on_comboBox_Channel_currentIndexChanged(const QString &arg1)
{
    this->resetRadioButtons();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(arg1);
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
   commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_VAMP);
   m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_AVG_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_VAVG);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_BASE_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_VBASE);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_FDELAY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_FDELAY);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_FPHASE_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_FPHASE);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_FREQUENCY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_FREQUENCY);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_FTIME_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_FTIME);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_MAREA_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_MAREA);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_MAX_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_VMAX);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_MIN_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_VMIN);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_MPAREA_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_MPAREA);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_NDUTY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_NDUTY);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_NWIDTH_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_NWIDTH);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_OVERSHOOT_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_OVERSHOOT);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_PDUTY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_PDUTY);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_PERIOD_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_PERIOD);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_PRESHOOT_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_PRESHOOT);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_PWIDTH_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_PWIDTH);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_RDELAY_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_RDELAY);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_RMS_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_VRMS);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_RPHASE_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_RPHASE);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_RTIME_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_RTIME);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_VPP_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_VPP);
    m_Rigol->addPollingMeasurement(newMeasurement);
}

void Window_RigolControl::on_radioButton_VTOP_toggled(bool checked)
{
    QString comboboxText = ui->comboBox_Channel->currentText();
    data_Rigol::AvailableChannels currentChannel = data_Rigol::AvailableChannelsDisplayToEnum(comboboxText.toStdString());
    commands_Rigol::MeasureCommand_Item newMeasurement(currentChannel,data_Rigol::MeasurementTypes::MEASURE_VTOP);
    m_Rigol->addPollingMeasurement(newMeasurement);
}
