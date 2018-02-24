/********************************************************************************
** Form generated from reading UI file 'widget_measurement_type.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MEASUREMENT_TYPE_H
#define UI_WIDGET_MEASUREMENT_TYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetMeasurementType
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_Measurement;
    QPushButton *pushButton_RemoveMeasurement;

    void setupUi(QWidget *WidgetMeasurementType)
    {
        if (WidgetMeasurementType->objectName().isEmpty())
            WidgetMeasurementType->setObjectName(QStringLiteral("WidgetMeasurementType"));
        WidgetMeasurementType->resize(248, 46);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetMeasurementType->sizePolicy().hasHeightForWidth());
        WidgetMeasurementType->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(WidgetMeasurementType);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_Measurement = new QLineEdit(WidgetMeasurementType);
        lineEdit_Measurement->setObjectName(QStringLiteral("lineEdit_Measurement"));
        lineEdit_Measurement->setMaximumSize(QSize(160, 30));
        QFont font;
        font.setPointSize(12);
        lineEdit_Measurement->setFont(font);

        horizontalLayout->addWidget(lineEdit_Measurement);

        pushButton_RemoveMeasurement = new QPushButton(WidgetMeasurementType);
        pushButton_RemoveMeasurement->setObjectName(QStringLiteral("pushButton_RemoveMeasurement"));
        pushButton_RemoveMeasurement->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(pushButton_RemoveMeasurement);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(WidgetMeasurementType);

        QMetaObject::connectSlotsByName(WidgetMeasurementType);
    } // setupUi

    void retranslateUi(QWidget *WidgetMeasurementType)
    {
        WidgetMeasurementType->setWindowTitle(QApplication::translate("WidgetMeasurementType", "Form", Q_NULLPTR));
        pushButton_RemoveMeasurement->setText(QApplication::translate("WidgetMeasurementType", "Remove", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetMeasurementType: public Ui_WidgetMeasurementType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MEASUREMENT_TYPE_H
