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

    QVector<double> voltageVector;
    QVector<double> currentVector;
    QVector<double> timeVector;

    for (iterator = newData.begin(); iterator != newData.end(); ++iterator) {
        DataParameter::SegmentTimeDataDetailed subData = *iterator;

        if(timeVector.size() == 0)
        {
            voltageVector.push_back(subData.getSegmentVoltage());
            currentVector.push_back(subData.getSegmentCurrent());
            timeVector.push_back(0);
        }

        unsigned int beginning = timeVector.back() * 10.0;
        unsigned int ending = (timeVector.back() + (subData.getTimeValue()/1000.0)) * 10.0;

        for(unsigned int i = beginning; i <= ending; i++)
        {
            voltageVector.push_back(subData.getSegmentVoltage());
            currentVector.push_back(subData.getSegmentCurrent());
            timeVector.push_back(i/10.0);
        }
    }

    ui->graphWidget->updateData(timeVector,voltageVector,currentVector);
}

void MainWindow::on_pushButton_released()
{
    ui->segmentWidget->addNewSegment();
}

void MainWindow::on_pushButton_transmit_released()
{
    DataParameter::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
    m_PowerSupply->generateAndTransmitMessage(dataSegment);
}
