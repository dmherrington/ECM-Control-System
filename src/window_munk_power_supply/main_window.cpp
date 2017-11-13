#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const auto infos = QSerialPortInfo::availablePorts();

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->comboBox_comPort->addItem(port.portName());
    }

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onOpen);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSave);
    connect(ui->actionSave_As, &QAction::triggered, this, &MainWindow::onSaveAs);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::onExit);


    connect(ui->actionGraph_Legend, &QAction::triggered, this, &MainWindow::onGraphLegend);


    connect(ui->segmentWidget,SIGNAL(updatedData(std::list<DataParameter::SegmentTimeDataDetailed>)),
            this,SLOT(widgetSegmentDisplay_dataUpdate(std::list<DataParameter::SegmentTimeDataDetailed>)));



    m_PowerSupply = new MunkPowerSupply();
    connect(m_PowerSupply, SIGNAL(signal_SerialPortStatus(bool,std::string)), this, SLOT(slot_SerialPortStatus(bool,std::string)));

    char* ECMPath = getenv("ECM_ROOT");
    std::string rootPath(ECMPath);
    m_FilePath = QString::fromStdString(rootPath + "save.json");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpen()
{
    QFileDialog fileDialog(this, "Choose file to open");
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setNameFilter("Open Files (*.json)");
    fileDialog.setDefaultSuffix("json");
    fileDialog.exec();
    m_FilePath = fileDialog.selectedFiles().first();

    QFile loadFile(m_FilePath);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
    }

    QByteArray loadData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    ui->segmentWidget->read(loadDoc.object());
}
void MainWindow::onSave()
{
    QFile saveFile(m_FilePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    QJsonObject saveObject;
    ui->segmentWidget->write(saveObject);
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
}

void MainWindow::onSaveAs()
{

    QFileDialog fileDialog(this, "Choose file to save");
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setNameFilter("Save Files (*.json)");
    fileDialog.setDefaultSuffix("json");
    fileDialog.exec();
    m_FilePath = fileDialog.selectedFiles().first();
    std::cout<<"The new filepath is: "<<m_FilePath.toStdString()<<std::endl;
}

void MainWindow::onExit()
{
    m_PowerSupply->closeSerialPort();

    QApplication::quit();
}

void MainWindow::onGraphLegend()
{
    bool isShowing = ui->graphWidget->legend->visible();
    ui->graphWidget->legend->setVisible(!isShowing);
    ui->graphWidget->replot();
}

void MainWindow::widgetSegmentDisplay_dataUpdate(const std::list<DataParameter::SegmentTimeDataDetailed> &newData)
{
    std::list<DataParameter::SegmentTimeDataDetailed>::const_iterator iterator;

    std::vector<double> voltageVector;
    std::vector<double> currentVector;
    std::vector<double> timeVector;

    unsigned int beginningValue = 0;
    unsigned int endingValue = 0;

    for (iterator = newData.begin(); iterator != newData.end(); ++iterator) {
        DataParameter::SegmentTimeDataDetailed subData = *iterator;

        beginningValue = endingValue;
        endingValue += (((double)subData.getTimeValue())/1000.0)*10.0;
        double voltageValue = subData.getSegmentVoltage();
        double currentValue = subData.getSegmentCurrent();
        for(unsigned int i = beginningValue; i <= endingValue; i++)
        {
            voltageVector.push_back(voltageValue);
            currentVector.push_back(currentValue);
            timeVector.push_back(i/10.0);
        }

    }

    ui->graphWidget->updateData(QVector<double>::fromStdVector(timeVector), QVector<double>::fromStdVector(voltageVector), QVector<double>::fromStdVector(currentVector));
}

void MainWindow::on_pushButton_released()
{
    ui->segmentWidget->addNewSegment();
    ui->segmentWidget->cbiSegmentDataInterface_UpdatedData();
}

void MainWindow::on_pushButton_transmit_released()
{
    DataParameter::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
    m_PowerSupply->generateAndTransmitMessage(dataSegment);
}

void MainWindow::slot_SerialPortStatus(const bool &open_close, const std::string &errorString)
{
    if(open_close)
    {
        QMessageBox *dialog = new QMessageBox();
        dialog->setIcon(QMessageBox::Information);
        dialog->setText("The serial port was open succesfully.");
        dialog->exec();
        ui->pushButton_connect->setText("DISCONNECT");
    }
    else
    {
        QMessageBox *dialog = new QMessageBox();
        dialog->setIcon(QMessageBox::Information);
        std::string newString = "The serial port was not opened succesfully.\n " + errorString;
        dialog->setText(QString::fromStdString(newString));
    }
}


void MainWindow::on_pushButton_connect_released()
{
    QString comPortName = ui->comboBox_comPort->currentText();
    m_PowerSupply->configureSerialPort(comPortName);
    m_PowerSupply->openSerialPort();
}
