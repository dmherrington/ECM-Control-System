#include "mainwindow.h"
#include "ui_mainwindow.h"
//2015 german reisling
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_Galil = new galilMotionController();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_Program_triggered()
{

}

//void MainWindow::onSave()
//{
//    QFile saveFile(m_FilePath);

//    if (!saveFile.open(QIODevice::WriteOnly)) {
//        qWarning("Couldn't open save file.");
//    }

//    QJsonObject saveObject;
//    ui->segmentWidget->write(saveObject);
//    QJsonDocument saveDoc(saveObject);
//    saveFile.write(saveDoc.toJson());
//}

void MainWindow::on_actionSave_As_Program_triggered()
{
    QFileDialog fileDialog(this, "Save program as:");

    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath)
    {
        std::string rootPath(ECMPath);
        QDir galilProgramDirectory(QString::fromStdString(rootPath + "/GalilPrograms/"));
        galilProgramDirectory.mkpath(QString::fromStdString(rootPath + "/GalilPrograms/"));
        fileDialog.setDirectory(galilProgramDirectory);
    }
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setNameFilter("Open Files (*.txt)");
    fileDialog.setDefaultSuffix("txt");
    fileDialog.exec();
    QString filePath = fileDialog.selectedFiles().first();

    if(!filePath.isEmpty()&& !filePath.isNull()){
        QString programString = ui->programText->toPlainText();
        bool saved = m_Galil->saveProgramAs(filePath.toStdString(),programString.toStdString());
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

}

//!
//! \brief event indicating the user wants to cease performing
//! a jog manuever away from the machining surface.
//!
void MainWindow::on_pushButton_IncreaseJog_released()
{

}

//!
//! \brief event indicating the user wants to begin performing
//! a jog manuever towards the machining surface.
//!
void MainWindow::on_pushButton_DecreaseJog_pressed()
{

}

//!
//! \brief event indicating the user wants to cease performing
//! a jog manuever towards the machining surface.
//!
void MainWindow::on_pushButton_DecreaseJog_released()
{

}


//!
//! \brief event indicating the user wants to step
//! the relative amount away from the machining surface.
//! The distance is equal to the spin box.
//!
void MainWindow::on_pushButton_IncreaseRelativeMove_clicked()
{

}

//!
//! \brief signal event indicating the user wants to step
//! the relative amount towards the machining surface.
//! The distance is equal to the spin box.
//!
void MainWindow::on_pushButton_DecreaseRelativeMove_clicked()
{

}

void MainWindow::on_actionSave_Current_Parameters_triggered()
{
    m_Galil->saveSettings();
}

void MainWindow::on_actionSave_As_Current_Parameters_triggered()
{

}

void MainWindow::on_actionLoad_Parameters_triggered()
{
    std::string settingsPath = "";
    m_Galil->getSettingsPath(settingsPath);
    QString fullFile = loadFileDialog(settingsPath,"json");
    m_Galil->loadSettings(fullFile.toStdString());
}

QString MainWindow::loadFileDialog(const std::string &filePath, const std::string &suffix)
{
    QFileDialog fileDialog(this, "Choose file to open");
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

