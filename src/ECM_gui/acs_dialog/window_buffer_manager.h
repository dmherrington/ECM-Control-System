#ifndef WINDOW_BUFFER_MANAGER_H
#define WINDOW_BUFFER_MANAGER_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>

#include "widget_buffer_descriptor.h"

namespace Ui {
class Window_BufferManager;
}

class Window_BufferManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_BufferManager(QWidget *parent = nullptr);
    ~Window_BufferManager();

public:
    void setInitialBufferCount(const unsigned int &count, const unsigned int &dBuffer);

private:
    Ui::Window_BufferManager *ui;

    std::map<unsigned int, Widget_BufferDescriptor*> m_BufferDescriptors;
};

#endif // WINDOW_BUFFER_MANAGER_H
