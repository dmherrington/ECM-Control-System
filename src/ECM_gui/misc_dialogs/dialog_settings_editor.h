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
    explicit Dialog_SettingsEditor(QWidget *parent = nullptr);
    ~Dialog_SettingsEditor();

    double getPlottingDuration() const;
private:
    void readSettings();

    void closeEvent(QCloseEvent *event) override;

private slots:
    void slot_EventAccepted();

private:
    Ui::Dialog_SettingsEditor *ui;
};

#endif // DIALOG_SETTINGS_EDITOR_H
