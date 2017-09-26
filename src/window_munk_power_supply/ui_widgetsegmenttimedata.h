/********************************************************************************
** Form generated from reading UI file 'widgetsegmenttimedata.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSEGMENTTIMEDATA_H
#define UI_WIDGETSEGMENTTIMEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSegmentTimeData
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_SegmentName;
    QComboBox *comboBox_Mode;
    QFrame *line;
    QDoubleSpinBox *doubleSpinBox_Voltage;
    QFrame *line_2;
    QDoubleSpinBox *doubleSpinBox_Current;
    QFrame *line_3;
    QDoubleSpinBox *doubleSpinBox_Time;
    QFrame *line_4;
    QPushButton *pushButton;

    void setupUi(QWidget *WidgetSegmentTimeData)
    {
        if (WidgetSegmentTimeData->objectName().isEmpty())
            WidgetSegmentTimeData->setObjectName(QStringLiteral("WidgetSegmentTimeData"));
        WidgetSegmentTimeData->resize(126, 206);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSegmentTimeData->sizePolicy().hasHeightForWidth());
        WidgetSegmentTimeData->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(WidgetSegmentTimeData);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 0, 2, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_SegmentName = new QLabel(WidgetSegmentTimeData);
        label_SegmentName->setObjectName(QStringLiteral("label_SegmentName"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_SegmentName->sizePolicy().hasHeightForWidth());
        label_SegmentName->setSizePolicy(sizePolicy1);
        label_SegmentName->setMinimumSize(QSize(120, 0));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_SegmentName->setFont(font);
        label_SegmentName->setFrameShape(QFrame::Panel);
        label_SegmentName->setFrameShadow(QFrame::Sunken);
        label_SegmentName->setLineWidth(3);
        label_SegmentName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_SegmentName);

        comboBox_Mode = new QComboBox(WidgetSegmentTimeData);
        comboBox_Mode->setObjectName(QStringLiteral("comboBox_Mode"));
        sizePolicy1.setHeightForWidth(comboBox_Mode->sizePolicy().hasHeightForWidth());
        comboBox_Mode->setSizePolicy(sizePolicy1);
        comboBox_Mode->setMinimumSize(QSize(120, 0));

        verticalLayout->addWidget(comboBox_Mode);

        line = new QFrame(WidgetSegmentTimeData);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(120, 0));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        doubleSpinBox_Voltage = new QDoubleSpinBox(WidgetSegmentTimeData);
        doubleSpinBox_Voltage->setObjectName(QStringLiteral("doubleSpinBox_Voltage"));
        doubleSpinBox_Voltage->setEnabled(true);
        doubleSpinBox_Voltage->setMinimumSize(QSize(120, 0));
        QFont font1;
        font1.setPointSize(10);
        doubleSpinBox_Voltage->setFont(font1);
        doubleSpinBox_Voltage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(doubleSpinBox_Voltage);

        line_2 = new QFrame(WidgetSegmentTimeData);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMinimumSize(QSize(120, 0));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        doubleSpinBox_Current = new QDoubleSpinBox(WidgetSegmentTimeData);
        doubleSpinBox_Current->setObjectName(QStringLiteral("doubleSpinBox_Current"));
        doubleSpinBox_Current->setMinimumSize(QSize(120, 0));
        doubleSpinBox_Current->setFont(font1);
        doubleSpinBox_Current->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(doubleSpinBox_Current);

        line_3 = new QFrame(WidgetSegmentTimeData);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setMinimumSize(QSize(120, 0));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        doubleSpinBox_Time = new QDoubleSpinBox(WidgetSegmentTimeData);
        doubleSpinBox_Time->setObjectName(QStringLiteral("doubleSpinBox_Time"));
        doubleSpinBox_Time->setEnabled(true);
        doubleSpinBox_Time->setMinimumSize(QSize(120, 0));
        doubleSpinBox_Time->setFont(font1);
        doubleSpinBox_Time->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Time->setDecimals(1);

        verticalLayout->addWidget(doubleSpinBox_Time);

        line_4 = new QFrame(WidgetSegmentTimeData);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setMinimumSize(QSize(120, 0));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        pushButton = new QPushButton(WidgetSegmentTimeData);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(120, 0));
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WidgetSegmentTimeData);

        QMetaObject::connectSlotsByName(WidgetSegmentTimeData);
    } // setupUi

    void retranslateUi(QWidget *WidgetSegmentTimeData)
    {
        WidgetSegmentTimeData->setWindowTitle(QApplication::translate("WidgetSegmentTimeData", "Form", Q_NULLPTR));
        label_SegmentName->setText(QApplication::translate("WidgetSegmentTimeData", "Segment # 8", Q_NULLPTR));
        pushButton->setText(QApplication::translate("WidgetSegmentTimeData", "REMOVE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetSegmentTimeData: public Ui_WidgetSegmentTimeData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSEGMENTTIMEDATA_H
