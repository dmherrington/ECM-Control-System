/********************************************************************************
** Form generated from reading UI file 'widget_segment_time_data.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SEGMENT_TIME_DATA_H
#define UI_WIDGET_SEGMENT_TIME_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_SegmentTimeData
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QComboBox *comboBox;

    void setupUi(QWidget *Widget_SegmentTimeData)
    {
        if (Widget_SegmentTimeData->objectName().isEmpty())
            Widget_SegmentTimeData->setObjectName(QStringLiteral("Widget_SegmentTimeData"));
        Widget_SegmentTimeData->setEnabled(true);
        Widget_SegmentTimeData->resize(55, 100);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_SegmentTimeData->sizePolicy().hasHeightForWidth());
        Widget_SegmentTimeData->setSizePolicy(sizePolicy);
        Widget_SegmentTimeData->setMinimumSize(QSize(55, 100));
        Widget_SegmentTimeData->setMaximumSize(QSize(267, 16777215));
        widget = new QWidget(Widget_SegmentTimeData);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 55, 100));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_3 = new QDoubleSpinBox(widget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));

        gridLayout->addWidget(doubleSpinBox_3, 0, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(widget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 1, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(widget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));

        gridLayout->addWidget(doubleSpinBox_2, 2, 0, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 3, 0, 1, 1);


        retranslateUi(Widget_SegmentTimeData);

        QMetaObject::connectSlotsByName(Widget_SegmentTimeData);
    } // setupUi

    void retranslateUi(QWidget *Widget_SegmentTimeData)
    {
        Widget_SegmentTimeData->setWindowTitle(QApplication::translate("Widget_SegmentTimeData", "Form", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget_SegmentTimeData", "Value", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class Widget_SegmentTimeData: public Ui_Widget_SegmentTimeData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SEGMENT_TIME_DATA_H
