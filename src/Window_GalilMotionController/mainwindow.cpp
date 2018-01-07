#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_Galil = new galilMotionController();

    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir settingsDirectory(QString::fromStdString(rootPath + "/Galil/profiles"));
        settingsDirectory.mkpath(QString::fromStdString(rootPath + "/Galil/profiles"));
        this->profilePath = settingsDirectory.absolutePath().toStdString() + "/generalProfile.json";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_Program_triggered()
{
    m_Galil->saveProgram(ui->programText->toPlainText().toStdString());
}

void MainWindow::on_actionSave_As_Program_triggered()
{
    std::string programPath = "";
    m_Galil->getProgramPath(programPath);
    QString fullFile = saveAsFileDialog(programPath,"txt");
    if(!fullFile.isEmpty()&& !fullFile.isNull()){
        m_Galil->saveProgramAs(fullFile.toStdString(),ui->programText->toPlainText().toStdString());
    }
}

void MainWindow::on_actionLoad_Program_triggered()
{
    std::string programPath = "";
    m_Galil->getProgramPath(programPath);
    QString filePath = loadFileDialog(programPath,"txt");

    if(!filePath.isEmpty()&& !filePath.isNull()){
        std::string programText = "";
        m_Galil->loadProgram(filePath.toStdString(),programText);
        ui->programText->clear();
        ui->programText->setText(QString::fromStdString(programText));
    }
}

/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITHIN THE MANUAL MOVE PANEL
/////////////////////////////////////////////////////////////////////////

//!
//! \brief event indicating the user wants to begin performing
//! a jog manuever away from the machining surface.
//!
void MainWindow::on_pushButton_IncreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value()) * (-1);
    CommandJog* beginJog = new CommandJog(MotorAxis::Z,jogRate);
    m_Galil->executeCommand(beginJog);
    delete beginJog;
}

//!
//! \brief event indicating the user wants to cease performing
//! a jog manuever away from the machining surface.
//!
void MainWindow::on_pushButton_IncreaseJog_released()
{
    CommandStop* stop = new CommandStop(MotorAxis::Z);
    m_Galil->executeCommand(stop);
    delete stop;
}

//!
//! \brief event indicating the user wants to begin performing
//! a jog manuever towards the machining surface.
//!
void MainWindow::on_pushButton_DecreaseJog_pressed()
{
    int jogRate = abs(ui->spinBox_Jog->value());
    CommandJog* beginJog = new CommandJog(MotorAxis::Z,jogRate);
    m_Galil->executeCommand(beginJog);
    delete beginJog;
}

//!
//! \brief event indicating the user wants to cease performing
//! a jog manuever towards the machining surface.
//!
void MainWindow::on_pushButton_DecreaseJog_released()
{
    CommandStop* stop = new CommandStop(MotorAxis::Z);
    m_Galil->executeCommand(stop);
    delete stop;
}


//!
//! \brief event indicating the user wants to step
//! the relative amount away from the machining surface.
//! The distance is equal to the spin box.
//!
void MainWindow::on_pushButton_IncreaseRelativeMove_clicked()
{
    int relativeDistance = abs(ui->spinBox_RelativeMove->value()) * (-1);
    CommandRelativeMove* move = new CommandRelativeMove(MotorAxis::Z, relativeDistance);
    m_Galil->executeCommand(move);
    delete move;
}

//!
//! \brief signal event indicating the user wants to step
//! the relative amount towards the machining surface.
//! The distance is equal to the spin box.
//!
void MainWindow::on_pushButton_DecreaseRelativeMove_clicked()
{
    int relativeDistance = abs(ui->spinBox_RelativeMove->value());
    CommandRelativeMove* move = new CommandRelativeMove(MotorAxis::Z, relativeDistance);
    m_Galil->executeCommand(move);
    delete move;
}
/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITH PARAMETERS MENU BAR
/////////////////////////////////////////////////////////////////////////

void MainWindow::on_actionSave_Current_Parameters_triggered()
{
    m_Galil->saveSettings();
}

void MainWindow::on_actionSave_As_Current_Parameters_triggered()
{
    std::string settingsPath = "";
    m_Galil->getSettingsPath(settingsPath);
    QString fullFile = saveAsFileDialog(settingsPath,"json");
    if(!fullFile.isEmpty()&& !fullFile.isNull()){
        m_Galil->saveSettingsAs(fullFile.toStdString());
    }
}

void MainWindow::on_actionLoad_Parameters_triggered()
{
    std::string settingsPath = "";
    m_Galil->getSettingsPath(settingsPath);
    QString fullFile = loadFileDialog(settingsPath,"json");
    if(!fullFile.isEmpty()&& !fullFile.isNull()){
        m_Galil->loadSettings(fullFile.toStdString());
    }
}

QString MainWindow::saveAsFileDialog(const std::string &filePath, const std::string &suffix)
{
    QFileDialog fileDialog(this, "Save program as:");
    QDir galilProgramDirectory(QString::fromStdString(filePath));
    fileDialog.setDirectory(galilProgramDirectory);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    QString nameFilter = "Open Files (*.";
    nameFilter += QString::fromStdString(suffix) + ")";
    fileDialog.setNameFilter(nameFilter);
    fileDialog.setDefaultSuffix(QString::fromStdString(suffix));
    fileDialog.exec();
    QString fullFilePath = fileDialog.selectedFiles().first();
    return fullFilePath;
}

void MainWindow::on_pushButton_CMDSend_clicked()
{
    QString programString = ui->textEdit_CMD->toPlainText();
    m_Galil->executeStringCommand(programString.toStdString());
}

void MainWindow::on_pushButton_MotorEnable_clicked()
{
    CommandMotorEnable* command = new CommandMotorEnable();
    command->setEnableAxis(MotorAxis::Z);
    m_Galil->executeCommand(command);
    delete command;
}

void MainWindow::on_pushButton_MotorDisable_clicked()
{
    CommandMotorDisable* command = new CommandMotorDisable();
    command->setDisableAxis(MotorAxis::Z);
    m_Galil->executeCommand(command);
    delete command;
}

void MainWindow::on_pushButton_RunProfile_clicked()
{
    CommandExecuteProgram* start = new CommandExecuteProgram();
    m_Galil->executeCommand(start);
    delete start;
}

void MainWindow::on_pushButton_UploadProgram_clicked()
{
    m_Galil->uploadProgram(ui->programText->toPlainText().toStdString());
}

void MainWindow::on_pushButton_DownloadProgram_clicked()
{
    std::string programText ="";
    m_Galil->downloadProgram(programText);
    ui->programText->setText(QString::fromStdString(programText));
}

void MainWindow::on_actionOpen_Connection_triggered()
{
    m_Galil->openConnection("169.254.78.101 -d");
}

void MainWindow::on_actionClose_Connection_triggered()
{
    m_Galil->closeConnection();
}

void MainWindow::on_action_LoadProfile_triggered()
{
    QString path = loadFileDialog(this->profilePath,"json");
    if(!path.isEmpty()&& !path.isNull()){
        QFile profileFile(path);

        if (!profileFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open file.");
        }
        else
        {
            QSize widgetSize;
            this->clearProfileTabs();
            QByteArray loadData = profileFile.readAll();
            QJsonDocument loadDoc = QJsonDocument::fromJson(loadData);
            QJsonObject outerObj = loadDoc.object();
            foreach(const QString& key, outerObj.keys()) {

                //gather up the component into a complete profile item
                QJsonObject profileObj  = outerObj[key].toObject();
                //let us create a profile object from the data
                SettingsGenericProfile profile;
                profile.read(profileObj);
                WidgetProfileDisplay* newWidget = new WidgetProfileDisplay();
                m_ProfileDisplay[profile.getProfileName()] = newWidget;
                newWidget->loadProfile(profile);
                this->ui->tabWidget->addTab(newWidget,QString::fromStdString(profile.getProfileName()));
                widgetSize = newWidget->size();
            }
        }
    }
}

void MainWindow::clearProfileTabs()
{
    this->ui->tabWidget->clear();
}


QString MainWindow::loadFileDialog(const std::string &filePath, const std::string &suffix)
{
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
    QString fullFilePath = fileDialog.selectedFiles().first();
    return fullFilePath;
}
