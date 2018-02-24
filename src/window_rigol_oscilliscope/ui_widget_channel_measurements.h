/********************************************************************************
** Form generated from reading UI file 'widget_channel_measurements.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_CHANNEL_MEASUREMENTS_H
#define UI_WIDGET_CHANNEL_MEASUREMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetChannelMeasurements
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Channel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QListWidget *listWidget_Measurements;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *WidgetChannelMeasurements)
    {
        if (WidgetChannelMeasurements->objectName().isEmpty())
            WidgetChannelMeasurements->setObjectName(QStringLiteral("WidgetChannelMeasurements"));
        WidgetChannelMeasurements->resize(282, 118);
        gridLayout = new QGridLayout(WidgetChannelMeasurements);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_Channel = new QLabel(WidgetChannelMeasurements);
        label_Channel->setObjectName(QStringLiteral("label_Channel"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_Channel->setFont(font);

        horizontalLayout->addWidget(label_Channel);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        listWidget_Measurements = new QListWidget(WidgetChannelMeasurements);
        listWidget_Measurements->setObjectName(QStringLiteral("listWidget_Measurements"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget_Measurements->sizePolicy().hasHeightForWidth());
        listWidget_Measurements->setSizePolicy(sizePolicy);
        listWidget_Measurements->setMinimumSize(QSize(250, 0));
        listWidget_Measurements->setMaximumSize(QSize(250, 16777215));
        listWidget_Measurements->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listWidget_Measurements->setSelectionMode(QAbstractItemView::ContiguousSelection);
        listWidget_Measurements->setResizeMode(QListView::Adjust);

        horizontalLayout_2->addWidget(listWidget_Measurements);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(WidgetChannelMeasurements);

        QMetaObject::connectSlotsByName(WidgetChannelMeasurements);
    } // setupUi

    void retranslateUi(QWidget *WidgetChannelMeasurements)
    {
        WidgetChannelMeasurements->setWindowTitle(QApplication::translate("WidgetChannelMeasurements", "Form", Q_NULLPTR));
        label_Channel->setText(QApplication::translate("WidgetChannelMeasurements", "Default Channel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetChannelMeasurements: public Ui_WidgetChannelMeasurements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_CHANNEL_MEASUREMENTS_H
