#ifndef DIALOG_SETTINGS_EDITOR_H
#define DIALOG_SETTINGS_EDITOR_H

#include <QDialog>
#include <QSettings>
#include <QCloseEvent>

namespace Ui {
class Dialog_SettingsEditor;
}

class Dialog_SettingsEditor : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_SettingsEditor(QWidget *parent = 0);
    ~Dialog_SettingsEditor();

private:
    void readSettings();

    void closeEvent(QCloseEvent *event) override;

private slots:
    void slot_EventAccepted();

private:
    Ui::Dialog_SettingsEditor *ui;
};

#endif // DIALOG_SETTINGS_EDITOR_H
