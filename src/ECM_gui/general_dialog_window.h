#ifndef GENERAL_DIALOG_WINDOW_H
#define GENERAL_DIALOG_WINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QObject>
#include <QString>
#include <QSettings>
#include <QDir>

#include "common/common.h"

class GeneralDialogWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum class DialogWindowTypes
    {
        WINDOW_CONNECTIONS,
        WINDOW_PUMP,
        WINDOW_OSCILLISCOPE,
        WINDOW_POWERSUPPLY,
        WINDOW_TOUCHOFF,
        WINDOW_MOTION_PROFILE
    };

    GeneralDialogWindow(const DialogWindowTypes &type, const QString &name, QWidget *parent);

public:
    bool isWindowHidden() const;

signals:
     virtual void signal_DialogWindowVisibilty(const DialogWindowTypes &type, const bool &visibility) = 0;

protected:
    virtual void onCloseAction();

    virtual QString onSaveAction();

    virtual QString onSaveAsAction();

    virtual QString onOpenAction();

protected:
    virtual void saveWindowSettings();

    virtual void readWindowSettings();

protected:

    virtual void closeEvent(QCloseEvent *event);

    void hideEvent(QHideEvent *event);

    void showEvent(QShowEvent *event);

protected:
    QString loadFileDialog(const std::string &filePath, const std::string &suffix);
    QString saveAsFileDialog(const std::string &filePath, const std::string &suffix);
    void getSettingsPath(std::string &filePath) const;
    QString getPreviousSettingsPath() const;



protected:
    DialogWindowTypes windowType;
    QString windowName;

    bool windowHidden = true;

    QString loggingPath;
    QString previousSettingsPath;
    QString currentSettingsPath;
};

#endif // GENERAL_DIALOG_WINDOW_H
