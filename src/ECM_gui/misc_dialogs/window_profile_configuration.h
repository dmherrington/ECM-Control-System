#ifndef WINDOW_PROFILE_CONFIGURATION_H
#define WINDOW_PROFILE_CONFIGURATION_H

#include <QMainWindow>

namespace Ui {
class Window_ProfileConfiguration;
}

class Window_ProfileConfiguration : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_ProfileConfiguration(QWidget *parent = 0);
    ~Window_ProfileConfiguration();

private:
    Ui::Window_ProfileConfiguration *ui;
};

#endif // WINDOW_PROFILE_CONFIGURATION_H
