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
    connect(ui->actionGraph_Legend, &QAction::triggered, this, &MainWindow::onGraphLegend);


    connect(ui->segmentWidget,SIGNAL(updatedData(std::list<DataParameter::SegmentTimeDataDetailed>)),
            this,SLOT(widgetSegmentDisplay_dataUpdate(std::list<DataParameter::SegmentTimeDataDetailed>)));



    m_PowerSupply = new MunkPowerSupply();
    connect(m_PowerSupply, SIGNAL(signal_SerialPortStatus(bool,std::string)), this, SLOT(slot_SerialPortStatus(bool,std::string)));

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
    if(open_close)
        statusBar()->showMessage(tr("Connection Opened"),2500);
    else
        statusBar()->showMessage(tr("Connection Closed"),2500);
}

void MainWindow::slot_CommunicationError()
{

}

void MainWindow::slot_CommunicationUpdate()
{

}

void MainWindow::slot_SegmentSetAck()
{

}

void MainWindow::slot_SegmentException()
{

}

void MainWindow::slot_FaultCodeRecieved()
{
    QMessageBox msgBox;
    msgBox.setText("A fault code has been thrown from the MUNK.");
    msgBox.setInformativeText("");
    msgBox.setIcon(QMessageBox::Critical);
    int ret = msgBox.exec();
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
    DataParameter::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
    m_PowerSupply->generateAndTransmitMessage(dataSegment);
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
