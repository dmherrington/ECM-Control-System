/********************************************************************************
** Form generated from reading UI file 'widget_segment_time_data.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_SegmentTimeData
{
public:
    QFormLayout *formLayout;
    QDoubleSpinBox *doubleSpinBox_voltage;
    QDoubleSpinBox *doubleSpinBox_current;
    QDoubleSpinBox *doubleSpinBox_duration;
    QComboBox *comboBox;

    void setupUi(QWidget *Widget_SegmentTimeData)
    {
        if (Widget_SegmentTimeData->objectName().isEmpty())
            Widget_SegmentTimeData->setObjectName(QStringLiteral("Widget_SegmentTimeData"));
        Widget_SegmentTimeData->setEnabled(true);
        Widget_SegmentTimeData->resize(130, 120);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_SegmentTimeData->sizePolicy().hasHeightForWidth());
        Widget_SegmentTimeData->setSizePolicy(sizePolicy);
        Widget_SegmentTimeData->setMinimumSize(QSize(0, 0));
        Widget_SegmentTimeData->setMaximumSize(QSize(134, 120));
        formLayout = new QFormLayout(Widget_SegmentTimeData);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        doubleSpinBox_voltage = new QDoubleSpinBox(Widget_SegmentTimeData);
        doubleSpinBox_voltage->setObjectName(QStringLiteral("doubleSpinBox_voltage"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox_voltage->sizePolicy().hasHeightForWidth());
        doubleSpinBox_voltage->setSizePolicy(sizePolicy1);
        doubleSpinBox_voltage->setMinimumSize(QSize(0, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, doubleSpinBox_voltage);

        doubleSpinBox_current = new QDoubleSpinBox(Widget_SegmentTimeData);
        doubleSpinBox_current->setObjectName(QStringLiteral("doubleSpinBox_current"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_current->sizePolicy().hasHeightForWidth());
        doubleSpinBox_current->setSizePolicy(sizePolicy1);
        doubleSpinBox_current->setMinimumSize(QSize(0, 0));

        formLayout->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_current);

        doubleSpinBox_duration = new QDoubleSpinBox(Widget_SegmentTimeData);
        doubleSpinBox_duration->setObjectName(QStringLiteral("doubleSpinBox_duration"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_duration->sizePolicy().hasHeightForWidth());
        doubleSpinBox_duration->setSizePolicy(sizePolicy1);
        doubleSpinBox_duration->setMinimumSize(QSize(0, 0));

        formLayout->setWidget(2, QFormLayout::LabelRole, doubleSpinBox_duration);

        comboBox = new QComboBox(Widget_SegmentTimeData);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(0, 0));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        comboBox->setMinimumContentsLength(0);

        formLayout->setWidget(3, QFormLayout::LabelRole, comboBox);


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
