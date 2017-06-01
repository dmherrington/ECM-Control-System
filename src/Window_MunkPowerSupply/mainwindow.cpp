#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "library_munk_power_supply/data/type_segment_level.h"
#include "library_munk_power_supply/data/type_segment_mode.h"
#include "library_munk_power_supply/data/type_read_write.h"
#include "library_munk_power_supply/data/type_prescalar_power.h"
#include "library_munk_power_supply/data_registers/segment_times.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUiElements();

    QObject::connect(ui->pushButton_generatemsg,SIGNAL(clicked()),this,SLOT(generateMessage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUiElements()
{
  std::vector<std::string> seglvls;
  std::vector<std::string> segmodes;
  std::vector<std::string> rw;
  std::vector<std::string> segscaler;

  seglvls = Data::getListOfSegmentLevel();
  segmodes = Data::getListOfSegmentMode();
  rw = Data::getListOfReadWriteType();
  segscaler = Data::getListOfSegmentPower();

  for (int unsigned i=0;i<seglvls.size();i++)
  {
      ui->comboBox_lvl->addItem(QString::fromStdString(seglvls[i]));
  }
  for (int unsigned i=0;i<segmodes.size();i++)
  {
      ui->comboBox_polarity->addItem(QString::fromStdString(segmodes[i]));
  }
  for (int unsigned i=0;i<rw.size();i++)
  {
      ui->comboBox_RW->addItem(QString::fromStdString(rw[i]));
  }
  for (int unsigned i=0;i<segscaler.size();i++)
  {
      ui->comboBox_scaler->addItem(QString::fromStdString(segscaler[i]));
  }
}

void MainWindow::generateMessage()
{
    int address = ui->spinBox_address->value();
    int noseg = ui->spinBox_nosegments->value();

    DataParameter::SegmentTimes* segmentTime = new DataParameter::SegmentTimes(1,noseg);
    segmentTime->setSlaveAddress(address);
    segmentTime->setReadorWrite(Data::ReadWriteTypeFromString(ui->comboBox_RW->currentText().toStdString()));

//    DataParameter::SegmentTimeData segData;
//    segData.setSegmentLevel(Data::SegmentLevelFromString(ui->comboBox_lvl->currentText().toStdString()));
//    segData.setSegmentMode(Data::SegmentModeFromString(ui->comboBox_polarity->currentText().toStdString()));
//    segData.setSegmentPower(Data::SegmentPowerFromString(ui->comboBox_scaler->currentText().toStdString()));
//    segData.setTimeValue(ui->spinBox_time->value());

    Data::SegmentLevel lvl = Data::SegmentLevelFromString(ui->comboBox_lvl->currentText().toStdString());
    Data::SegmentMode mode = Data::SegmentModeFromString(ui->comboBox_polarity->currentText().toStdString());
    Data::SegmentPower scaler = Data::SegmentPowerFromString(ui->comboBox_scaler->currentText().toStdString());
    int time = ui->spinBox_time->value();

    DataParameter::SegmentTimeData segData(lvl,mode,scaler,time);

    segmentTime->updateRegisterData(0,segData);
    QByteArray out = segmentTime->getFullMessage();

    ui->textEdit_OutputMessage->setText(out.toHex().toUpper());
}

void MainWindow::on_pushButton_generatemsg_clicked()
{

}
