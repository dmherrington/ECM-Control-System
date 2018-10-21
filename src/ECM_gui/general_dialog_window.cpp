#include "general_dialog_window.h"

GeneralDialogWindow::GeneralDialogWindow(const DialogWindowTypes &type, const QString &name, QWidget *parent):
    QMainWindow(parent),
    windowType(type), windowName(name)
{
    //Setting up the proper directory paths for all of the stuff
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir loggingDirectory(QString::fromStdString(rootPath + "/" + name.toStdString() + "/logs"));
        QDir setupDirectory(QString::fromStdString(rootPath + "/" + name.toStdString() + "/setup"));
        QDir settingsDirectory(QString::fromStdString(rootPath + "/" + name.toStdString() + "/settings"));

        loggingDirectory.mkpath(QString::fromStdString(rootPath + "/" + name.toStdString() + "/logs"));
        setupDirectory.mkpath(QString::fromStdString(rootPath + "/" + name.toStdString() + "/setup"));
        settingsDirectory.mkpath(QString::fromStdString(rootPath + "/" + name.toStdString() + "/settings"));

        loggingPath = loggingDirectory.absolutePath() + "/";
        previousSettingsPath = setupDirectory.absolutePath() + "/previousSettings.json";
        currentSettingsPath = "";
    }
}

bool GeneralDialogWindow::isWindowHidden() const
{
    return this->windowHidden;
}

/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITH PARAMETERS MENU BAR
/////////////////////////////////////////////////////////////////////////
void GeneralDialogWindow::saveWindowSettings()
{
    QSettings settings(windowName +"_Window", "ECM Application");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void GeneralDialogWindow::readWindowSettings()
{
    QSettings settings(windowName +"_Window", "ECM Application");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITH PARAMETERS MENU BAR
/////////////////////////////////////////////////////////////////////////

void GeneralDialogWindow::closeEvent(QCloseEvent *event)
{
    UNUSED(event);
    saveWindowSettings();
}

void GeneralDialogWindow::hideEvent(QHideEvent *event)
{
    UNUSED(event);
    windowHidden = true;
    emit signal_DialogWindowVisibilty(this->windowType,false);
}

void GeneralDialogWindow::showEvent(QShowEvent *event)
{
    UNUSED(event);
    windowHidden = false;
    emit signal_DialogWindowVisibilty(this->windowType,true);

}

/////////////////////////////////////////////////////////////////////////
/// USER HAS INTERACTED WITH PARAMETERS MENU BAR
/////////////////////////////////////////////////////////////////////////

void GeneralDialogWindow::onCloseAction()
{
    this->close();
}

QString GeneralDialogWindow::onSaveAction(const std::string &extension)
{
    if(currentSettingsPath == "")
        this->onSaveAsAction(extension);

    return currentSettingsPath;
}

QString GeneralDialogWindow::onSaveAsAction(const std::string &extension)
{
    std::string settingsPath = "";
    this->getSettingsPath(settingsPath);
    currentSettingsPath = saveAsFileDialog(settingsPath,extension);
    return currentSettingsPath;
}

QString GeneralDialogWindow::onOpenAction(const std::string &extensionFilter)
{
    std::string settingsPath = "";
    this->getSettingsPath(settingsPath);
    QString filePath = loadFileDialog(settingsPath,extensionFilter);

    if(!filePath.isEmpty()&& !filePath.isNull()){
        currentSettingsPath = filePath;
    }

    return filePath;
}

void GeneralDialogWindow::getSettingsPath(std::string &filePath) const
{
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QFile settingsDirectory(QString::fromStdString(rootPath + "/" + this->windowName.toStdString() + "/settings/"));
        QFileInfo fileInfo(settingsDirectory);
        filePath = fileInfo.absolutePath().toStdString();
    }
}

QString GeneralDialogWindow::getPreviousSettingsPath() const
{
    return previousSettingsPath;
}

QString GeneralDialogWindow::saveAsFileDialog(const std::string &filePath, const std::string &suffix)
{
    QString fullFilePath = "";
    QFileDialog fileDialog(this, "Save program as:");
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
    {
        fullFilePath = fileDialog.selectedFiles().first();
    }
    return fullFilePath;
}

QString GeneralDialogWindow::loadFileDialog(const std::string &filePath, const std::string &nameFilter)
{
    QString fullFilePath = "";
    QFileDialog fileDialog(this, "Choose profile to open");
    QDir galilProgramDirectory(QString::fromStdString(filePath));
    fileDialog.setDirectory(galilProgramDirectory);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
//    QString nameFilter = "Open TXT Files (*.";
//    nameFilter += QString::fromStdString(suffix) + ")";
    fileDialog.setNameFilter(QString::fromStdString(nameFilter));
    //fileDialog.setDefaultSuffix(QString::fromStdString(suffix));
    fileDialog.exec();
    if(fileDialog.selectedFiles().size() > 0)
    {
        fullFilePath = fileDialog.selectedFiles().first();
    }
    return fullFilePath;
}
