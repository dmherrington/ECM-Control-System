#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const auto infos = QSerialPortInfo::availablePorts();

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(port.portName());
    }

    m_PowerSupply = new MunkPowerSupply();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ConnectSerialPort_released()
{
    m_PowerSupply->openSerialPort();
}

void MainWindow::on_pushButton_ConfigureSerialPort_released()
{
    QString comPortName = ui->comboBox->currentText();
    m_PowerSupply->configureSerialPort(comPortName);
}
