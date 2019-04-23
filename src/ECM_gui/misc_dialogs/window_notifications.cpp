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
    Detailed_Notification newNotification(update);

    Widget_DetailedNotification* widgetDetailedNotification = new Widget_DetailedNotification();

    QListWidgetItem* newItem = new QListWidgetItem();
    newItem->setSizeHint(widgetDetailedNotification->sizeHint());

//    newItem->setSizeHint(tableDescriptor->sizeHint());
//    ui->listWidget->addItem(newItem);
//    ui->listWidget->setItemWidget(newItem,tableDescriptor);

//    this->m_MapOperations.insert(std::pair<QListWidgetItem*,TableWidget_OperationDescriptor*>(newItem,tableDescriptor));

//    return tableDescriptor;
}

