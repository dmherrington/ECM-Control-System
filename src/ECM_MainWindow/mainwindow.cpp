#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    iFWD(NULL),iREV(NULL),vFWD(NULL),vREV(NULL),genData(NULL)
{
    ui->setupUi(this);
    //mainLayout.setSizeConstraint(QLayout::SetFixedSize);

    //QObject::connect(newData, &Widget_SegmentTimeData::valueChanged_Voltage, this, &MainWindow::onChanged_voltageValue);

    const auto infos = QSerialPortInfo::availablePorts();

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(port.portName());
    }

    m_PowerSupply = new MunkPowerSupply();
    connect(m_PowerSupply,SIGNAL(signal_NewCurrentSetpoint(DataParameter::SegmentCurrentSetpoint,DataParameter::SegmentCurrentSetpoint)),
            this,SLOT(onNewCurrentData(DataParameter::SegmentCurrentSetpoint,DataParameter::SegmentCurrentSetpoint)));
    connect(m_PowerSupply,SIGNAL(signal_NewVoltageSetpoint(DataParameter::SegmentVoltageSetpoint,DataParameter::SegmentVoltageSetpoint)),
            this, SLOT(onNewVoltageData(DataParameter::SegmentVoltageSetpoint,DataParameter::SegmentVoltageSetpoint)));
    connect(m_PowerSupply,SIGNAL(signal_NewTimeSetpoint(DataParameter::SegmentTimeGeneral)),this,SLOT(onNewGeneralData(DataParameter::SegmentTimeGeneral)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ConnectSerialPort_released()
{
    Widget_SegmentTimeData* newData3 = new Widget_SegmentTimeData();
    ui->horizontalLayout->addWidget(newData3);
    //m_PowerSupply->openSerialPort();
}

void MainWindow::on_pushButton_ConfigureSerialPort_released()
{
    QString comPortName = ui->comboBox->currentText();
    m_PowerSupply->configureSerialPort(comPortName);
}

void MainWindow::on_pushButton_GenerateValid_released()
{
    DataParameter::SegmentTimeDetailed detailedData(1);
    DataParameter::SegmentTimeDataDetailed detailedOne(10,50,Data::SegmentMode::FORWARD,200);
    detailedData.appendRegisterData(detailedOne);
    DataParameter::SegmentTimeDataDetailed detailedFour(10,102,Data::SegmentMode::DEAD,77);
    detailedData.appendRegisterData(detailedFour);

    m_PowerSupply->generateAndTransmitMessage(detailedData);
}

void MainWindow::on_pushButton_GenerateInvalid_released()
{
    DataParameter::SegmentTimeDetailed detailedData(1);
    DataParameter::SegmentTimeDataDetailed detailedOne(10,50,Data::SegmentMode::FORWARD,100);
    detailedData.appendRegisterData(detailedOne);
    DataParameter::SegmentTimeDataDetailed detailedFour(10,102,Data::SegmentMode::FORWARD,100);
    detailedData.appendRegisterData(detailedFour);
    DataParameter::SegmentTimeDataDetailed detailedFive(50,133,Data::SegmentMode::FORWARD,100);
    detailedData.appendRegisterData(detailedFive);
    DataParameter::SegmentTimeDataDetailed detailedSeven(70,151,Data::SegmentMode::FORWARD,100);
    detailedData.appendRegisterData(detailedSeven);
    m_PowerSupply->generateAndTransmitMessage(detailedData);

}

void MainWindow::onNewCurrentData(const DataParameter::SegmentCurrentSetpoint &currentSetpointREV, const DataParameter::SegmentCurrentSetpoint &currentSetpointFWD)
{
    std::cout<<"I have new current data"<<std::endl;
    if(iFWD)
    {
        delete iFWD;
        iFWD = NULL;
    }

    if(iREV)
    {
        delete iREV;
        iREV = NULL;
    }

    iREV = new DataParameter::SegmentCurrentSetpoint(currentSetpointREV);
    iFWD = new DataParameter::SegmentCurrentSetpoint(currentSetpointFWD);

    ui->dataRI->setText(iREV->getFullMessage().toHex().toUpper());
    ui->dataFI->setText(iFWD->getFullMessage().toHex().toUpper());
}

void MainWindow::onNewVoltageData(const DataParameter::SegmentVoltageSetpoint &voltageSetpointREV, const DataParameter::SegmentVoltageSetpoint &voltageSetpointFWD)
{
    std::cout<<"I have new voltage data"<<std::endl;
    if(vREV)
    {
        delete vREV;
        vREV = NULL;
    }

    if(vFWD)
    {
        delete vFWD;
        vFWD = NULL;
    }
    vREV = new DataParameter::SegmentVoltageSetpoint(voltageSetpointREV);
    vFWD = new DataParameter::SegmentVoltageSetpoint(voltageSetpointFWD);

    ui->dataRV->setText(vREV->getFullMessage().toHex().toUpper());
    ui->dataFV->setText(vFWD->getFullMessage().toHex().toUpper());
}

void MainWindow::onNewGeneralData(const DataParameter::SegmentTimeGeneral &segmentTime)
{
    std::cout<<"I have new general data"<<std::endl;
    if(genData)
    {
        delete genData;
        genData = NULL;
    }
    genData = new DataParameter::SegmentTimeGeneral(segmentTime);

    ui->dataFull->setText(genData->getFullMessage().toHex().toUpper());
}

void MainWindow::on_pushButton_SendRevI_released()
{
    if(iREV)
    {
        m_PowerSupply->transmitMessage(iREV->getFullMessage());
    }
}

void MainWindow::on_pushButton_SendFI_released()
{
    if(iFWD)
    {
        m_PowerSupply->transmitMessage(iFWD->getFullMessage());
    }
}

void MainWindow::on_pushButton_SendRV_released()
{
    if(vREV)
    {
        m_PowerSupply->transmitMessage(vREV->getFullMessage());
    }
}

void MainWindow::on_pushButton_SendFV_released()
{
    if(vFWD)
    {
        m_PowerSupply->transmitMessage(vFWD->getFullMessage());
    }
}

void MainWindow::on_pushButton_SendData_released()
{
    if(genData)
    {
        m_PowerSupply->transmitMessage(genData->getFullMessage());
    }
}

void MainWindow::onChanged_voltageValue(const double &value)
{
    std::cout<<"New voltage value received of: "<<value<<std::endl;
}

