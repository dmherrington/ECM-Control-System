#include "widget_rigol_radio.h"
#include "ui_widget_rigol_radio.h"

Widget_RigolRadio::Widget_RigolRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_RigolRadio)
{
    ui->setupUi(this);
}

Widget_RigolRadio::~Widget_RigolRadio()
{
    delete ui;
}

void Widget_RigolRadio::setRadioButton(const data_Rigol::MeasurementTypes &measurement, const bool &value)
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

void Widget_RigolRadio::resetRadioButtons()
{
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
}

void Widget_RigolRadio::on_radioButton_AMP_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_VAMP,checked);
}

void Widget_RigolRadio::on_radioButton_AVG_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_VAVG,checked);
}

void Widget_RigolRadio::on_radioButton_BASE_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_VBASE,checked);
}

void Widget_RigolRadio::on_radioButton_FDELAY_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_FDELAY,checked);
}

void Widget_RigolRadio::on_radioButton_FPHASE_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_FPHASE,checked);
}

void Widget_RigolRadio::on_radioButton_FREQUENCY_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_FREQUENCY,checked);
}

void Widget_RigolRadio::on_radioButton_FTIME_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_FTIME,checked);
}

void Widget_RigolRadio::on_radioButton_MAREA_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_MAREA,checked);
}

void Widget_RigolRadio::on_radioButton_MAX_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_VMAX,checked);
}

void Widget_RigolRadio::on_radioButton_MIN_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_VMIN,checked);
}

void Widget_RigolRadio::on_radioButton_MPAREA_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_MPAREA,checked);
}

void Widget_RigolRadio::on_radioButton_NDUTY_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_NDUTY,checked);
}

void Widget_RigolRadio::on_radioButton_NWIDTH_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_NWIDTH,checked);
}

void Widget_RigolRadio::on_radioButton_OVERSHOOT_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_OVERSHOOT,checked);
}

void Widget_RigolRadio::on_radioButton_PDUTY_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_PDUTY,checked);
}

void Widget_RigolRadio::on_radioButton_PERIOD_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_PERIOD,checked);
}

void Widget_RigolRadio::on_radioButton_PRESHOOT_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_PRESHOOT,checked);
}

void Widget_RigolRadio::on_radioButton_PWIDTH_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_PWIDTH,checked);
}

void Widget_RigolRadio::on_radioButton_RDELAY_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_RDELAY,checked);
}

void Widget_RigolRadio::on_radioButton_RMS_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_VRMS,checked);
}

void Widget_RigolRadio::on_radioButton_RPHASE_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_RPHASE,checked);
}

void Widget_RigolRadio::on_radioButton_RTIME_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_RTIME,checked);
}

void Widget_RigolRadio::on_radioButton_VPP_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_VPP,checked);
}

void Widget_RigolRadio::on_radioButton_VTOP_toggled(bool checked)
{
    emit signal_onRadioButtonChange(data_Rigol::MeasurementTypes::MEASURE_VTOP,checked);
}

