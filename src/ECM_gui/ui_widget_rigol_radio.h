/********************************************************************************
** Form generated from reading UI file 'widget_rigol_radio.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_RIGOL_RADIO_H
#define UI_WIDGET_RIGOL_RADIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_RigolRadio
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_MAX;
    QRadioButton *radioButton_BASE;
    QRadioButton *radioButton_OVERSHOOT;
    QRadioButton *radioButton_PERIOD;
    QRadioButton *radioButton_PWIDTH;
    QRadioButton *radioButton_RDELAY;
    QRadioButton *radioButton_MIN;
    QRadioButton *radioButton_AMP;
    QRadioButton *radioButton_PRESHOOT;
    QRadioButton *radioButton_FREQUENCY;
    QRadioButton *radioButton_NWIDTH;
    QRadioButton *radioButton_FDELAY;
    QRadioButton *radioButton_VPP;
    QRadioButton *radioButton_AVG;
    QRadioButton *radioButton_MAREA;
    QRadioButton *radioButton_RTIME;
    QRadioButton *radioButton_PDUTY;
    QRadioButton *radioButton_RPHASE;
    QRadioButton *radioButton_VTOP;
    QRadioButton *radioButton_RMS;
    QRadioButton *radioButton_MPAREA;
    QRadioButton *radioButton_FTIME;
    QRadioButton *radioButton_NDUTY;
    QRadioButton *radioButton_FPHASE;

    void setupUi(QWidget *Widget_RigolRadio)
    {
        if (Widget_RigolRadio->objectName().isEmpty())
            Widget_RigolRadio->setObjectName(QString::fromUtf8("Widget_RigolRadio"));
        Widget_RigolRadio->resize(482, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_RigolRadio->sizePolicy().hasHeightForWidth());
        Widget_RigolRadio->setSizePolicy(sizePolicy);
        Widget_RigolRadio->setMinimumSize(QSize(482, 100));
        Widget_RigolRadio->setMaximumSize(QSize(482, 100));
        layoutWidget = new QWidget(Widget_RigolRadio);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 485, 100));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_MAX = new QRadioButton(layoutWidget);
        radioButton_MAX->setObjectName(QString::fromUtf8("radioButton_MAX"));
        radioButton_MAX->setMinimumSize(QSize(0, 20));
        radioButton_MAX->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        radioButton_MAX->setFont(font);
        radioButton_MAX->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_MAX, 0, 0, 1, 1);

        radioButton_BASE = new QRadioButton(layoutWidget);
        radioButton_BASE->setObjectName(QString::fromUtf8("radioButton_BASE"));
        radioButton_BASE->setMinimumSize(QSize(0, 20));
        radioButton_BASE->setMaximumSize(QSize(16777215, 20));
        radioButton_BASE->setFont(font);
        radioButton_BASE->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_BASE, 0, 1, 1, 1);

        radioButton_OVERSHOOT = new QRadioButton(layoutWidget);
        radioButton_OVERSHOOT->setObjectName(QString::fromUtf8("radioButton_OVERSHOOT"));
        radioButton_OVERSHOOT->setMinimumSize(QSize(0, 20));
        radioButton_OVERSHOOT->setMaximumSize(QSize(16777215, 20));
        radioButton_OVERSHOOT->setFont(font);
        radioButton_OVERSHOOT->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_OVERSHOOT, 0, 2, 1, 1);

        radioButton_PERIOD = new QRadioButton(layoutWidget);
        radioButton_PERIOD->setObjectName(QString::fromUtf8("radioButton_PERIOD"));
        radioButton_PERIOD->setMinimumSize(QSize(0, 20));
        radioButton_PERIOD->setMaximumSize(QSize(16777215, 20));
        radioButton_PERIOD->setFont(font);
        radioButton_PERIOD->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_PERIOD, 0, 3, 1, 1);

        radioButton_PWIDTH = new QRadioButton(layoutWidget);
        radioButton_PWIDTH->setObjectName(QString::fromUtf8("radioButton_PWIDTH"));
        radioButton_PWIDTH->setMinimumSize(QSize(0, 20));
        radioButton_PWIDTH->setMaximumSize(QSize(16777215, 20));
        radioButton_PWIDTH->setFont(font);
        radioButton_PWIDTH->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_PWIDTH, 0, 4, 1, 1);

        radioButton_RDELAY = new QRadioButton(layoutWidget);
        radioButton_RDELAY->setObjectName(QString::fromUtf8("radioButton_RDELAY"));
        radioButton_RDELAY->setMinimumSize(QSize(0, 20));
        radioButton_RDELAY->setMaximumSize(QSize(16777215, 20));
        radioButton_RDELAY->setFont(font);
        radioButton_RDELAY->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_RDELAY, 0, 5, 1, 1);

        radioButton_MIN = new QRadioButton(layoutWidget);
        radioButton_MIN->setObjectName(QString::fromUtf8("radioButton_MIN"));
        radioButton_MIN->setMinimumSize(QSize(0, 20));
        radioButton_MIN->setMaximumSize(QSize(16777215, 20));
        radioButton_MIN->setFont(font);
        radioButton_MIN->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_MIN, 1, 0, 1, 1);

        radioButton_AMP = new QRadioButton(layoutWidget);
        radioButton_AMP->setObjectName(QString::fromUtf8("radioButton_AMP"));
        radioButton_AMP->setMinimumSize(QSize(0, 20));
        radioButton_AMP->setMaximumSize(QSize(16777215, 20));
        radioButton_AMP->setFont(font);
        radioButton_AMP->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_AMP, 1, 1, 1, 1);

        radioButton_PRESHOOT = new QRadioButton(layoutWidget);
        radioButton_PRESHOOT->setObjectName(QString::fromUtf8("radioButton_PRESHOOT"));
        radioButton_PRESHOOT->setMinimumSize(QSize(0, 20));
        radioButton_PRESHOOT->setMaximumSize(QSize(16777215, 20));
        radioButton_PRESHOOT->setFont(font);
        radioButton_PRESHOOT->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_PRESHOOT, 1, 2, 1, 1);

        radioButton_FREQUENCY = new QRadioButton(layoutWidget);
        radioButton_FREQUENCY->setObjectName(QString::fromUtf8("radioButton_FREQUENCY"));
        radioButton_FREQUENCY->setMinimumSize(QSize(0, 20));
        radioButton_FREQUENCY->setMaximumSize(QSize(16777215, 20));
        radioButton_FREQUENCY->setFont(font);
        radioButton_FREQUENCY->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_FREQUENCY, 1, 3, 1, 1);

        radioButton_NWIDTH = new QRadioButton(layoutWidget);
        radioButton_NWIDTH->setObjectName(QString::fromUtf8("radioButton_NWIDTH"));
        radioButton_NWIDTH->setMinimumSize(QSize(0, 20));
        radioButton_NWIDTH->setMaximumSize(QSize(16777215, 20));
        radioButton_NWIDTH->setFont(font);
        radioButton_NWIDTH->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_NWIDTH, 1, 4, 1, 1);

        radioButton_FDELAY = new QRadioButton(layoutWidget);
        radioButton_FDELAY->setObjectName(QString::fromUtf8("radioButton_FDELAY"));
        radioButton_FDELAY->setMinimumSize(QSize(0, 20));
        radioButton_FDELAY->setMaximumSize(QSize(16777215, 20));
        radioButton_FDELAY->setFont(font);
        radioButton_FDELAY->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_FDELAY, 1, 5, 1, 1);

        radioButton_VPP = new QRadioButton(layoutWidget);
        radioButton_VPP->setObjectName(QString::fromUtf8("radioButton_VPP"));
        radioButton_VPP->setMinimumSize(QSize(0, 20));
        radioButton_VPP->setMaximumSize(QSize(16777215, 20));
        radioButton_VPP->setFont(font);
        radioButton_VPP->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_VPP, 2, 0, 1, 1);

        radioButton_AVG = new QRadioButton(layoutWidget);
        radioButton_AVG->setObjectName(QString::fromUtf8("radioButton_AVG"));
        radioButton_AVG->setMinimumSize(QSize(0, 20));
        radioButton_AVG->setMaximumSize(QSize(16777215, 20));
        radioButton_AVG->setFont(font);
        radioButton_AVG->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_AVG, 2, 1, 1, 1);

        radioButton_MAREA = new QRadioButton(layoutWidget);
        radioButton_MAREA->setObjectName(QString::fromUtf8("radioButton_MAREA"));
        radioButton_MAREA->setMinimumSize(QSize(0, 20));
        radioButton_MAREA->setMaximumSize(QSize(16777215, 20));
        radioButton_MAREA->setFont(font);
        radioButton_MAREA->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_MAREA, 2, 2, 1, 1);

        radioButton_RTIME = new QRadioButton(layoutWidget);
        radioButton_RTIME->setObjectName(QString::fromUtf8("radioButton_RTIME"));
        radioButton_RTIME->setMinimumSize(QSize(0, 20));
        radioButton_RTIME->setMaximumSize(QSize(16777215, 20));
        radioButton_RTIME->setFont(font);
        radioButton_RTIME->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_RTIME, 2, 3, 1, 1);

        radioButton_PDUTY = new QRadioButton(layoutWidget);
        radioButton_PDUTY->setObjectName(QString::fromUtf8("radioButton_PDUTY"));
        radioButton_PDUTY->setMinimumSize(QSize(0, 20));
        radioButton_PDUTY->setMaximumSize(QSize(16777215, 20));
        radioButton_PDUTY->setFont(font);
        radioButton_PDUTY->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_PDUTY, 2, 4, 1, 1);

        radioButton_RPHASE = new QRadioButton(layoutWidget);
        radioButton_RPHASE->setObjectName(QString::fromUtf8("radioButton_RPHASE"));
        radioButton_RPHASE->setMinimumSize(QSize(0, 20));
        radioButton_RPHASE->setMaximumSize(QSize(16777215, 20));
        radioButton_RPHASE->setFont(font);
        radioButton_RPHASE->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_RPHASE, 2, 5, 1, 1);

        radioButton_VTOP = new QRadioButton(layoutWidget);
        radioButton_VTOP->setObjectName(QString::fromUtf8("radioButton_VTOP"));
        radioButton_VTOP->setMinimumSize(QSize(0, 20));
        radioButton_VTOP->setMaximumSize(QSize(16777215, 20));
        radioButton_VTOP->setFont(font);
        radioButton_VTOP->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_VTOP, 3, 0, 1, 1);

        radioButton_RMS = new QRadioButton(layoutWidget);
        radioButton_RMS->setObjectName(QString::fromUtf8("radioButton_RMS"));
        radioButton_RMS->setMinimumSize(QSize(0, 20));
        radioButton_RMS->setMaximumSize(QSize(16777215, 20));
        radioButton_RMS->setFont(font);
        radioButton_RMS->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_RMS, 3, 1, 1, 1);

        radioButton_MPAREA = new QRadioButton(layoutWidget);
        radioButton_MPAREA->setObjectName(QString::fromUtf8("radioButton_MPAREA"));
        radioButton_MPAREA->setMinimumSize(QSize(0, 20));
        radioButton_MPAREA->setMaximumSize(QSize(16777215, 20));
        radioButton_MPAREA->setFont(font);
        radioButton_MPAREA->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_MPAREA, 3, 2, 1, 1);

        radioButton_FTIME = new QRadioButton(layoutWidget);
        radioButton_FTIME->setObjectName(QString::fromUtf8("radioButton_FTIME"));
        radioButton_FTIME->setMinimumSize(QSize(0, 20));
        radioButton_FTIME->setMaximumSize(QSize(16777215, 20));
        radioButton_FTIME->setFont(font);
        radioButton_FTIME->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_FTIME, 3, 3, 1, 1);

        radioButton_NDUTY = new QRadioButton(layoutWidget);
        radioButton_NDUTY->setObjectName(QString::fromUtf8("radioButton_NDUTY"));
        radioButton_NDUTY->setMinimumSize(QSize(0, 20));
        radioButton_NDUTY->setMaximumSize(QSize(16777215, 20));
        radioButton_NDUTY->setFont(font);
        radioButton_NDUTY->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_NDUTY, 3, 4, 1, 1);

        radioButton_FPHASE = new QRadioButton(layoutWidget);
        radioButton_FPHASE->setObjectName(QString::fromUtf8("radioButton_FPHASE"));
        radioButton_FPHASE->setMinimumSize(QSize(0, 20));
        radioButton_FPHASE->setMaximumSize(QSize(16777215, 20));
        radioButton_FPHASE->setFont(font);
        radioButton_FPHASE->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_FPHASE, 3, 5, 1, 1);


        retranslateUi(Widget_RigolRadio);

        QMetaObject::connectSlotsByName(Widget_RigolRadio);
    } // setupUi

    void retranslateUi(QWidget *Widget_RigolRadio)
    {
        Widget_RigolRadio->setWindowTitle(QApplication::translate("Widget_RigolRadio", "Form", nullptr));
        radioButton_MAX->setText(QApplication::translate("Widget_RigolRadio", "MAX", nullptr));
        radioButton_BASE->setText(QApplication::translate("Widget_RigolRadio", "BASE", nullptr));
        radioButton_OVERSHOOT->setText(QApplication::translate("Widget_RigolRadio", "OVERSHOOT", nullptr));
        radioButton_PERIOD->setText(QApplication::translate("Widget_RigolRadio", "PERIOD", nullptr));
        radioButton_PWIDTH->setText(QApplication::translate("Widget_RigolRadio", "PWIDTH", nullptr));
        radioButton_RDELAY->setText(QApplication::translate("Widget_RigolRadio", "RDELAY", nullptr));
        radioButton_MIN->setText(QApplication::translate("Widget_RigolRadio", "MIN", nullptr));
        radioButton_AMP->setText(QApplication::translate("Widget_RigolRadio", "AMP", nullptr));
        radioButton_PRESHOOT->setText(QApplication::translate("Widget_RigolRadio", "PRESHOOT", nullptr));
        radioButton_FREQUENCY->setText(QApplication::translate("Widget_RigolRadio", "FREQUENCY", nullptr));
        radioButton_NWIDTH->setText(QApplication::translate("Widget_RigolRadio", "NWIDTH", nullptr));
        radioButton_FDELAY->setText(QApplication::translate("Widget_RigolRadio", "FDELAY", nullptr));
        radioButton_VPP->setText(QApplication::translate("Widget_RigolRadio", "VPP", nullptr));
        radioButton_AVG->setText(QApplication::translate("Widget_RigolRadio", "AVG", nullptr));
        radioButton_MAREA->setText(QApplication::translate("Widget_RigolRadio", "MAREA", nullptr));
        radioButton_RTIME->setText(QApplication::translate("Widget_RigolRadio", "RTIME", nullptr));
        radioButton_PDUTY->setText(QApplication::translate("Widget_RigolRadio", "PDUTY", nullptr));
        radioButton_RPHASE->setText(QApplication::translate("Widget_RigolRadio", "RPHASE", nullptr));
        radioButton_VTOP->setText(QApplication::translate("Widget_RigolRadio", "VTOP", nullptr));
        radioButton_RMS->setText(QApplication::translate("Widget_RigolRadio", "RMS", nullptr));
        radioButton_MPAREA->setText(QApplication::translate("Widget_RigolRadio", "MPAREA", nullptr));
        radioButton_FTIME->setText(QApplication::translate("Widget_RigolRadio", "FTIME", nullptr));
        radioButton_NDUTY->setText(QApplication::translate("Widget_RigolRadio", "NDUTY", nullptr));
        radioButton_FPHASE->setText(QApplication::translate("Widget_RigolRadio", "FPHASE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_RigolRadio: public Ui_Widget_RigolRadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_RIGOL_RADIO_H
