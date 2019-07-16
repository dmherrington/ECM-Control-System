#ifndef DIALOG_SOFTWARE_VERSION_H
#define DIALOG_SOFTWARE_VERSION_H

#include <QDialog>

#include <map>
#include <string>

#include "widget_sofware_versioning.h"

namespace Ui {
class Dialog_SoftwareVersion;
}

class Dialog_SoftwareVersion : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_SoftwareVersion(const std::map<std::string, std::string> &swMap, QWidget *parent = 0);
    ~Dialog_SoftwareVersion();

private:
    Ui::Dialog_SoftwareVersion *ui;
};

#endif // DIALOG_SOFTWARE_VERSION_H
