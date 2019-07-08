#include "window_notifications.h"
#include "ui_window_notifications.h"

Window_Notifications::Window_Notifications(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_Notifications)
{
    ui->setupUi(this);
}

Window_Notifications::~Window_Notifications()
{
    delete ui;
}

void Window_Notifications::addNewNotification(const common::NotificationUpdate &update)
{
    Widget_DetailedNotification* widgetDetailedNotification = new Widget_DetailedNotification();
    widgetDetailedNotification->setNotification(update);

    QListWidgetItem* newItem = new QListWidgetItem();
    newItem->setSizeHint(widgetDetailedNotification->sizeHint());
    widgetDetailedNotification->setAssociatedWidget(newItem);

    ui->listWidget_Notifications->addItem(newItem);
    ui->listWidget_Notifications->setItemWidget(newItem,widgetDetailedNotification);

    ui->listWidget_Notifications->scrollToBottom();
//    this->m_MapOperations.insert(std::pair<QListWidgetItem*,TableWidget_OperationDescriptor*>(newItem,tableDescriptor));
}

