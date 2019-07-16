#ifndef WIDGET_SOFWARE_VERSIONING_H
#define WIDGET_SOFWARE_VERSIONING_H

#include <QWidget>

namespace Ui {
class Widget_SofwareVersioning;
}

class Widget_SofwareVersioning : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_SofwareVersioning(const std::string &libraryName, const std::string &versionNumber, QWidget *parent = 0);
    ~Widget_SofwareVersioning();

private:
    Ui::Widget_SofwareVersioning *ui;
};

#endif // WIDGET_SOFWARE_VERSIONING_H
