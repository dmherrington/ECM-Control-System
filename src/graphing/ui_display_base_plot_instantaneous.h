/********************************************************************************
** Form generated from reading UI file 'display_base_plot_instantaneous.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_BASE_PLOT_INSTANTANEOUS_H
#define UI_DISPLAY_BASE_PLOT_INSTANTANEOUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plot_handler.h"

QT_BEGIN_NAMESPACE

class Ui_DisplayBasePlotInstantaneous
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget_AcclerationData;
    QWidget *tab_1;
    QGridLayout *gridLayout;
    graphing::PlotHandler *customPlot;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_yWindow;
    QDoubleSpinBox *doubleSpinBox_windowHigh;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_windowLow;
    QLabel *label_10;
    QPushButton *pushButton_Legend;
    QPushButton *pushButton_tagDisplayed;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_Grid;
    QPushButton *pushButton_GridSpacing;
    QDoubleSpinBox *doubleSpinBox_gridY;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_gridX;
    QLabel *label_8;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QTableWidget *instantReadings;

    void setupUi(QWidget *DisplayBasePlotInstantaneous)
    {
        if (DisplayBasePlotInstantaneous->objectName().isEmpty())
            DisplayBasePlotInstantaneous->setObjectName(QLatin1String("DisplayBasePlotInstantaneous"));
        DisplayBasePlotInstantaneous->resize(356, 363);
        DisplayBasePlotInstantaneous->setStyleSheet(QLatin1String(""));
        verticalLayout_2 = new QVBoxLayout(DisplayBasePlotInstantaneous);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QLatin1String("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        tabWidget_AcclerationData = new QTabWidget(DisplayBasePlotInstantaneous);
        tabWidget_AcclerationData->setObjectName(QLatin1String("tabWidget_AcclerationData"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QLatin1String("tab_1"));
        gridLayout = new QGridLayout(tab_1);
        gridLayout->setObjectName(QLatin1String("gridLayout"));
        customPlot = new graphing::PlotHandler(tab_1);
        customPlot->setObjectName(QLatin1String("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(customPlot, 0, 0, 1, 1);

        tabWidget_AcclerationData->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QLatin1String("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QLatin1String("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 20, 127, 95));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QLatin1String("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_yWindow = new QPushButton(layoutWidget);
        pushButton_yWindow->setObjectName(QLatin1String("pushButton_yWindow"));

        gridLayout_4->addWidget(pushButton_yWindow, 0, 0, 1, 2);

        doubleSpinBox_windowHigh = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_windowHigh->setObjectName(QLatin1String("doubleSpinBox_windowHigh"));

        gridLayout_4->addWidget(doubleSpinBox_windowHigh, 1, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QLatin1String("label_9"));
        QFont font;
        font.setPointSize(10);
        label_9->setFont(font);

        gridLayout_4->addWidget(label_9, 1, 1, 1, 1);

        doubleSpinBox_windowLow = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_windowLow->setObjectName(QLatin1String("doubleSpinBox_windowLow"));
        doubleSpinBox_windowLow->setMinimum(-1000);
        doubleSpinBox_windowLow->setMaximum(1000);

        gridLayout_4->addWidget(doubleSpinBox_windowLow, 2, 0, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QLatin1String("label_10"));
        label_10->setFont(font);

        gridLayout_4->addWidget(label_10, 2, 1, 1, 1);

        pushButton_Legend = new QPushButton(tab_2);
        pushButton_Legend->setObjectName(QLatin1String("pushButton_Legend"));
        pushButton_Legend->setGeometry(QRect(180, 130, 75, 23));
        pushButton_tagDisplayed = new QPushButton(tab_2);
        pushButton_tagDisplayed->setObjectName(QLatin1String("pushButton_tagDisplayed"));
        pushButton_tagDisplayed->setGeometry(QRect(180, 170, 75, 23));
        layoutWidget_2 = new QWidget(tab_2);
        layoutWidget_2->setObjectName(QLatin1String("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 95, 128));
        gridLayout_5 = new QGridLayout(layoutWidget_2);
        gridLayout_5->setObjectName(QLatin1String("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_Grid = new QPushButton(layoutWidget_2);
        pushButton_Grid->setObjectName(QLatin1String("pushButton_Grid"));

        gridLayout_5->addWidget(pushButton_Grid, 0, 0, 1, 2);

        pushButton_GridSpacing = new QPushButton(layoutWidget_2);
        pushButton_GridSpacing->setObjectName(QLatin1String("pushButton_GridSpacing"));

        gridLayout_5->addWidget(pushButton_GridSpacing, 1, 0, 1, 2);

        doubleSpinBox_gridY = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_gridY->setObjectName(QLatin1String("doubleSpinBox_gridY"));
        doubleSpinBox_gridY->setMaximum(100);

        gridLayout_5->addWidget(doubleSpinBox_gridY, 2, 0, 1, 1);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QLatin1String("label_7"));
        label_7->setFont(font);

        gridLayout_5->addWidget(label_7, 2, 1, 1, 1);

        doubleSpinBox_gridX = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_gridX->setObjectName(QLatin1String("doubleSpinBox_gridX"));
        doubleSpinBox_gridX->setMaximum(100);

        gridLayout_5->addWidget(doubleSpinBox_gridX, 3, 0, 1, 1);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QLatin1String("label_8"));
        label_8->setFont(font);

        gridLayout_5->addWidget(label_8, 3, 1, 1, 1);

        tabWidget_AcclerationData->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QLatin1String("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QLatin1String("gridLayout_3"));
        instantReadings = new QTableWidget(tab_3);
        instantReadings->setObjectName(QLatin1String("instantReadings"));
        instantReadings->setEnabled(true);
        QFont font1;
        font1.setPointSize(8);
        instantReadings->setFont(font1);
        instantReadings->setEditTriggers(QAbstractItemView::NoEditTriggers);
        instantReadings->setSelectionMode(QAbstractItemView::NoSelection);
        instantReadings->setTextElideMode(Qt::ElideNone);
        instantReadings->setRowCount(0);
        instantReadings->setColumnCount(0);
        instantReadings->horizontalHeader()->setVisible(false);
        instantReadings->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(instantReadings, 0, 0, 1, 1);

        tabWidget_AcclerationData->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget_AcclerationData);


        retranslateUi(DisplayBasePlotInstantaneous);

        tabWidget_AcclerationData->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DisplayBasePlotInstantaneous);
    } // setupUi

    void retranslateUi(QWidget *DisplayBasePlotInstantaneous)
    {
        DisplayBasePlotInstantaneous->setWindowTitle(QApplication::translate("DisplayBasePlotInstantaneous", "Form", nullptr));
        tabWidget_AcclerationData->setTabText(tabWidget_AcclerationData->indexOf(tab_1), QApplication::translate("DisplayBasePlotInstantaneous", "Plot", nullptr));
        pushButton_yWindow->setText(QApplication::translate("DisplayBasePlotInstantaneous", "Y-Scale Custom", nullptr));
        label_9->setText(QApplication::translate("DisplayBasePlotInstantaneous", "MAX", nullptr));
        label_10->setText(QApplication::translate("DisplayBasePlotInstantaneous", "MIN", nullptr));
        pushButton_Legend->setText(QApplication::translate("DisplayBasePlotInstantaneous", "LEGEND ON", nullptr));
        pushButton_tagDisplayed->setText(QApplication::translate("DisplayBasePlotInstantaneous", "DISPLAY TAG", nullptr));
        pushButton_Grid->setText(QApplication::translate("DisplayBasePlotInstantaneous", "GRID OFF", nullptr));
        pushButton_GridSpacing->setText(QApplication::translate("DisplayBasePlotInstantaneous", "GRID MAN", nullptr));
        label_7->setText(QApplication::translate("DisplayBasePlotInstantaneous", "Y", nullptr));
        label_8->setText(QApplication::translate("DisplayBasePlotInstantaneous", "X", nullptr));
        tabWidget_AcclerationData->setTabText(tabWidget_AcclerationData->indexOf(tab_2), QApplication::translate("DisplayBasePlotInstantaneous", "Graph Properties", nullptr));
        tabWidget_AcclerationData->setTabText(tabWidget_AcclerationData->indexOf(tab_3), QApplication::translate("DisplayBasePlotInstantaneous", "Instantaneous", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayBasePlotInstantaneous: public Ui_DisplayBasePlotInstantaneous {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_BASE_PLOT_INSTANTANEOUS_H
