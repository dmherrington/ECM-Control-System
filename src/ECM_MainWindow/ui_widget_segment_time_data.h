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
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_voltage;
    QDoubleSpinBox *doubleSpinBox_current;
    QDoubleSpinBox *doubleSpinBox_duration;
    QComboBox *comboBox;

    void setupUi(QWidget *Widget_SegmentTimeData)
    {
        if (Widget_SegmentTimeData->objectName().isEmpty())
            Widget_SegmentTimeData->setObjectName(QStringLiteral("Widget_SegmentTimeData"));
        Widget_SegmentTimeData->setEnabled(true);
        Widget_SegmentTimeData->resize(55, 113);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_SegmentTimeData->sizePolicy().hasHeightForWidth());
        Widget_SegmentTimeData->setSizePolicy(sizePolicy);
        Widget_SegmentTimeData->setMinimumSize(QSize(55, 100));
        Widget_SegmentTimeData->setMaximumSize(QSize(267, 16777215));
        layoutWidget = new QWidget(Widget_SegmentTimeData);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 169, 102));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_voltage = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_voltage->setObjectName(QStringLiteral("doubleSpinBox_voltage"));

        gridLayout->addWidget(doubleSpinBox_voltage, 0, 0, 1, 1);

        doubleSpinBox_current = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_current->setObjectName(QStringLiteral("doubleSpinBox_current"));

        gridLayout->addWidget(doubleSpinBox_current, 1, 0, 1, 1);

        doubleSpinBox_duration = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_duration->setObjectName(QStringLiteral("doubleSpinBox_duration"));

        gridLayout->addWidget(doubleSpinBox_duration, 2, 0, 1, 1);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(10, 0));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        comboBox->setMinimumContentsLength(10);

        gridLayout->addWidget(comboBox, 3, 0, 1, 1);


        retranslateUi(Widget_SegmentTimeData);

        QMetaObject::connectSlotsByName(Widget_SegmentTimeData);
    } // setupUi

    void retranslateUi(QWidget *Widget_SegmentTimeData)
    {
        Widget_SegmentTimeData->setWindowTitle(QApplication::translate("Widget_SegmentTimeData", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget_SegmentTimeData: public Ui_Widget_SegmentTimeData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SEGMENT_TIME_DATA_H
