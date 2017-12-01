#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_Galil = new galilMotionController();
    GOpen()

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_Program_triggered()
{

}

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

    QString programString = ui->textEdit->toPlainText();
    bool saved = m_Galil->saveProgramAs(filePath.toStdString(),programString.toStdString());
}

void MainWindow::on_actionLoad_Program_triggered()
{
    QFileDialog fileDialog(this, "Choose file to open");
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath)
    {
        std::string rootPath(ECMPath);
        QDir galilProgramDirectory(QString::fromStdString(rootPath + "/GalilPrograms/"));
        fileDialog.setDirectory(galilProgramDirectory);
    }
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setNameFilter("Open Files (*.txt)");
    fileDialog.setDefaultSuffix("txt");
    fileDialog.exec();
    QString filePath = fileDialog.selectedFiles().first();
    std::string programText = "";
    m_Galil->loadProgram(filePath.toStdString(),programText);
    ui->textEdit->clear();
    ui->textEdit->setText(QString::fromStdString(programText));
}
