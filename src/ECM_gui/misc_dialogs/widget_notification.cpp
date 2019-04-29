#include "widget_notification.h"
#include "ui_widget_notification.h"

Widget_Notification::Widget_Notification(const ECM_API *apiObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Notification)
{
    qRegisterMetaType<common::NotificationUpdate>("NotificationUpdate");

    ui->setupUi(this);
    m_API = apiObject;

    connect(m_API->m_MotionController, SIGNAL(signal_MCNotification(common::NotificationUpdate)),
            this, SLOT(slot_NewNotification(common::NotificationUpdate)));

    connect(m_API->m_Munk, SIGNAL(signal_MunkNotification(common::NotificationUpdate)),
            this, SLOT(slot_NewNotification(common::NotificationUpdate)));
}

Widget_Notification::~Widget_Notification()
{
    delete ui;
}

void Widget_Notification::slot_NewNotification(const NotificationUpdate &update)
{
    addNewNotification(update);
}

void Widget_Notification::addNewNotification(const common::NotificationUpdate &update)
{
    Widget_DetailedNotification* widgetDetailedNotification = new Widget_DetailedNotification();
    widgetDetailedNotification->setNotification(update);

    QListWidgetItem* newItem = new QListWidgetItem();
    newItem->setSizeHint(widgetDetailedNotification->sizeHint());
    widgetDetailedNotification->setAssociatedWidget(newItem);

    ui->listWidget_Notifications->addItem(newItem);
    ui->listWidget_Notifications->setItemWidget(newItem,widgetDetailedNotification);
}
