#include "window_motion_profile.h"
#include "ui_window_motion_profile.h"

Window_MotionProfile::Window_MotionProfile(GalilMotionController *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_MOTION_PROFILE,"Motion Profile",parent),
    m_MotionController(obj),
    ui(new Ui::Window_MotionProfile)
{
    ui->setupUi(this);
    ui->led_ProgramCurrent->setDiameter(5);
    ui->led_ProgramCurrent->setColor(QColor(255,0,0));

    GeneralDialogWindow::readWindowSettings();

    connect(m_MotionController,SIGNAL(signal_MCNewProgramReceived(GalilCurrentProgram)),this,SLOT(slot_MCNewProgramAvailable(GalilCurrentProgram)));
}

Window_MotionProfile::~Window_MotionProfile()
{
    delete ui;
}

void Window_MotionProfile::closeEvent(QCloseEvent *event)
{
    saveToFile(getPreviousSettingsPath());
    GeneralDialogWindow::closeEvent(event);
}


void Window_MotionProfile::on_actionOpen_triggered()
{
    std::string extensionFilter = "Open TXT Files (*.txt);; Open DMC Files (*.dmc)";

    QString filePath = GeneralDialogWindow::onOpenAction(extensionFilter);
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_MotionProfile::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_MotionProfile::on_actionSave_triggered()
{
    QString filePath = GeneralDialogWindow::onSaveAction("txt");
    if(!filePath.isEmpty())
        this->saveToFile(filePath);
}

void Window_MotionProfile::on_actionSave_As_triggered()
{
    QString filePath = GeneralDialogWindow::onSaveAsAction("txt");
    if(!filePath.isEmpty())
        this->saveToFile(filePath);
}

void Window_MotionProfile::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->statusbar->showMessage("Couldn't open file for saving.",2000);
        return;
    }

    QTextStream outStream(&saveFile);
    outStream << ui->codeTextEdit->toPlainText();
    saveFile.close();
}

void Window_MotionProfile::openFromFile(const QString &filePath)
{
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream inStream(&file);
    QString programText = inStream.readAll();
    file.close();

    ui->codeTextEdit->setPlainText(programText);
}

void Window_MotionProfile::slot_MCNewProgramAvailable(const GalilCurrentProgram &program)
{
    ui->codeTextEdit->clear();
    ui->codeTextEdit->setPlainText(QString::fromStdString(program.getProgram()));
    ui->led_ProgramCurrent->setColor(QColor(0,255,0));
}

void Window_MotionProfile::on_codeTextEdit_textChanged()
{
    ui->led_ProgramCurrent->setColor(QColor(255,0,0));
}

void Window_MotionProfile::on_pushButton_UploadProgram_released()
{
    std::string programString = ui->codeTextEdit->toPlainText().toStdString();

    ProgramGeneric newProgram;
    newProgram.setProgramString(programString);

    CommandUploadProgramPtr commandUploadDefault = std::make_shared<CommandUploadProgram>();
    commandUploadDefault->setProgram(newProgram);
    m_MotionController->executeCommand(commandUploadDefault);
}

void Window_MotionProfile::on_pushButton_DownloadProgram_released()
{
    CommandDownloadProgramPtr commandDownloadDefault = std::make_shared<CommandDownloadProgram>();
    m_MotionController->executeCommand(commandDownloadDefault);
}
