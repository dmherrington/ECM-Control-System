#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->pushButton_transmit->setEnabled(false);
    ui->actionTransmit_To_Munk->setEnabled(false);

    ui->pushButton_transmit->setToolTip("Connect to the munk in order to transmit the segments.");
    ui->pushButton_AddSegment->setToolTip("Add an additional segment for the munk power supply to process.");
    ui->progressBar->setToolTip("Status bar reflecting the state of syncrhonization to the munk using the current register segment.");
    ui->comboBox_comPort->setToolTip("Select the appropriate com port the munk.");

    const auto infos = QSerialPortInfo::availablePorts();

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->comboBox_comPort->addItem(port.portName());
    }
    connect(ui->actionGraph_Legend, &QAction::triggered, this, &MainWindow::onGraphLegend);


    connect(ui->segmentWidget,SIGNAL(updatedData(std::list<registers_Munk::SegmentTimeDataDetailed>)),
            this,SLOT(widgetSegmentDisplay_dataUpdate(std::list<registers_Munk::SegmentTimeDataDetailed>)));



    m_PowerSupply = new MunkPowerSupply();
    connect(m_PowerSupply,SIGNAL(signal_ConnectionStatusUpdated(bool)), this, SLOT(slot_ConnectionStatusUpdate(bool)));
    connect(m_PowerSupply,SIGNAL(signal_CommunicationError(std::string,std::string)), this, SLOT(slot_CommunicationError(std::string,std::string)));
    connect(m_PowerSupply,SIGNAL(signal_CommunicationUpdate(std::string,std::string)), this, SLOT(slot_CommunicationUpdate(std::string,std::string)));
    connect(m_PowerSupply,SIGNAL(signal_FaultCodeRecieved(int,std::string)), this, SLOT(slot_FaultCodeRecieved(int,std::string)));
    connect(m_PowerSupply,SIGNAL(signal_SegmentException(std::string,std::string)),this,SLOT(slot_SegmentException(std::string,std::string)));

    connect(m_PowerSupply,SIGNAL(signal_SegmentWriteProgress(int,int)),this,SLOT(slot_WriteProgressUpdated(int,int)));
    connect(m_PowerSupply,SIGNAL(signal_SegmentSetAck(std::string)),this,SLOT(slot_SegmentSetAck(std::string)));

    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir settingsDirectory(QString::fromStdString(rootPath + "/Munk/segments"));
        settingsDirectory.mkpath(QString::fromStdString(rootPath + "/Munk/segments"));
        munkSegmentsPath = settingsDirectory.absolutePath() + "/generalSegments.json";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private SLOTS related to events triggered from the munk library
/////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::slot_ConnectionStatusUpdate(const bool &open_close)
{
    ui->pushButton_transmit->setEnabled(open_close);
    ui->actionTransmit_To_Munk->setEnabled(open_close);

    if(open_close)
        statusBar()->showMessage(tr("Connection Opened"),2500);
    else
        statusBar()->showMessage(tr("Connection Closed"),2500);
}

void MainWindow::slot_CommunicationError(const std::string &type, const std::string &msg)
{
    QMessageBox msgBox;
    msgBox.setText("A communication error has been thrown from the MUNK.");
    msgBox.setInformativeText(QString::fromStdString(msg));
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();
}

void MainWindow::slot_CommunicationUpdate(const std::string &name, const std::string &msg)
{
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(name));
    msgBox.setInformativeText(QString::fromStdString(msg));
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void MainWindow::slot_SegmentSetAck(const std::string &msg)
{
    statusBar()->showMessage(QString::fromStdString(msg),1000);
}

void MainWindow::slot_SegmentException(const std::string &RW, const std::string &meaning)
{
    QMessageBox msgBox;
    msgBox.setText("A fault code has been thrown when" + QString::fromStdString(RW) + "from the MUNK.");
    msgBox.setInformativeText(QString::fromStdString(meaning));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.exec();
}

void MainWindow::slot_FaultCodeRecieved(const int &regNum, const std::string &msg)
{
    QMessageBox msgBox;
    msgBox.setText("A fault code has been thrown from register" + QString::number(regNum)+ " on the MUNK.");
    msgBox.setInformativeText(QString::fromStdString(msg));
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();
}

void MainWindow::slot_WriteProgressUpdated(const int &completed, const int &required)
{
    int value = completed/required;
    if(segmentUnlocked)
        this->ui->progressBar->setValue(completed/required);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private SLOTS related to actions triggered directly from the GUI
/////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_actionLoad_triggered()
{
    QString fullFile = loadFileDialog(this->getMunkSegmentsPath().toStdString(),"json");
    this->munkCurrentFile = fullFile;
    if(!fullFile.isEmpty()&& !fullFile.isNull()){
        this->loadMunkPowerSegment(fullFile);
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(!munkCurrentFile.isEmpty())
    {
        this->saveSettings(this->munkSegmentsPath);
    }
    else
    {
        this->on_actionSave_As_triggered();
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fullFile = saveAsFileDialog(this->getMunkSegmentsPath().toStdString(),"json");
    if(!fullFile.isEmpty() && !fullFile.isNull()){
        this->munkCurrentFile = fullFile;
        this->saveSettings(this->munkCurrentFile);
    }
}

void MainWindow::on_actionOpen_Connection_triggered()
{
    m_PowerSupply->openSerialPort(ui->comboBox_comPort->currentText());
}

void MainWindow::on_actionClose_Connection_triggered()
{
    m_PowerSupply->closeSerialPort();
}

void MainWindow::on_actionTransmit_To_Munk_triggered()
{
    segmentUnlocked = true;
    registers_Munk::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
    m_PowerSupply->generateAndTransmitMessage(dataSegment);
}

void MainWindow::onGraphLegend()
{
//    bool isShowing = ui->graphWidget->legend->visible();
//    ui->graphWidget->legend->setVisible(!isShowing);
//    ui->graphWidget->replot();
}


void MainWindow::widgetSegmentDisplay_dataUpdate(const std::list<registers_Munk::SegmentTimeDataDetailed> &newData)
{
    segmentUnlocked = false;
    ui->progressBar->setValue(0);

    std::list<registers_Munk::SegmentTimeDataDetailed>::const_iterator iterator;

    std::vector<double> voltageVector;
    std::vector<double> currentVector;
    std::vector<double> timeVector;

    double beginningValue = 0;
    double endingValue = 0;

    for (iterator = newData.begin(); iterator != newData.end(); ++iterator) {
        registers_Munk::SegmentTimeDataDetailed subData = *iterator;

        beginningValue = endingValue;
        endingValue += (((double)subData.getTimeValue())/1000.0);

        timeVector.push_back(beginningValue);
        timeVector.push_back(endingValue);

        double voltageValue = subData.getGraphingVoltage();
        double currentValue = subData.getGraphingCurrent();

        voltageVector.push_back(voltageValue);
        voltageVector.push_back(voltageValue);

        currentVector.push_back(currentValue);
        currentVector.push_back(currentValue);

    }

    //ui->graphWidget->updateData(QVector<double>::fromStdVector(timeVector), QVector<double>::fromStdVector(voltageVector), QVector<double>::fromStdVector(currentVector));
}

void MainWindow::on_pushButton_AddSegment_released()
{
    segmentUnlocked = false;
    ui->progressBar->setValue(0);

    ui->segmentWidget->addNewSegment();
    ui->segmentWidget->cbiSegmentDataInterface_UpdatedData();
}

QString MainWindow::saveAsFileDialog(const std::string &filePath, const std::string &suffix)
{
    QString fullFilePath;
    QFileDialog fileDialog(this, "Save profile as:");
    QDir galilProgramDirectory(QString::fromStdString(filePath));
    fileDialog.setDirectory(galilProgramDirectory);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    QString nameFilter = "Save Files (*.";
    nameFilter += QString::fromStdString(suffix) + ")";
    fileDialog.setNameFilter(nameFilter);
    fileDialog.setDefaultSuffix(QString::fromStdString(suffix));
    fileDialog.exec();
    if(fileDialog.selectedFiles().size() > 0)
        fullFilePath = fileDialog.selectedFiles().first();
    return fullFilePath;
}

QString MainWindow::loadFileDialog(const std::string &filePath, const std::string &suffix)
{
    QString fullFilePath;
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
    if(fileDialog.selectedFiles().size() > 0)
        fullFilePath = fileDialog.selectedFiles().first();
    return fullFilePath;
}

QString MainWindow::getMunkSegmentsPath()
{
    QFile file(munkSegmentsPath);
    QFileInfo fileInfo(file);
    return fileInfo.absolutePath();
}

void MainWindow::saveSettings(const QString &path)
{
    QFile saveFile(path);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    QJsonObject saveObject;
    ui->segmentWidget->write(saveObject);
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}

void MainWindow::loadMunkPowerSegment(const QString &path)
{
    QFile loadFile(path);
     if (!loadFile.open(QIODevice::ReadOnly)) return;

    QByteArray loadData = loadFile.readAll();
    loadFile.close();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    ui->segmentWidget->read(loadDoc.object());
}

void MainWindow::on_pushButton_transmit_released()
{
    this->on_actionTransmit_To_Munk_triggered();
}

void MainWindow::on_actionExit_triggered()
{
    m_PowerSupply->closeSerialPort();
    qApp->quit();
}

