#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//    std::list<WidgetSegmentTimeData*>::iterator iterator;

//    QVector<double> voltageVector;
//    QVector<double> currentVector;
//    QVector<double> timeVector;

//    double maxI = 0.0, maxV = 0.0;


//    for (iterator = m_dataList.begin(); iterator != m_dataList.end(); ++iterator) {
//        WidgetSegmentTimeData* newData = *iterator;

//        if(timeVector.size() == 0)
//        {
//            voltageVector.push_back(newData->getData()->getSegmentVoltage());
//            currentVector.push_back(newData->getData()->getSegmentCurrent());
//            timeVector.push_back(0);
//        }

//        unsigned int beginning = timeVector.back() * 10.0;
//        unsigned int ending = (timeVector.back() + newData->getData()->getTimeValue()) * 10.0;
//        double current = newData->getData()->getSegmentCurrent();
//        double voltage = newData->getData()->getSegmentVoltage();


//        if(current > maxI)
//            maxI = current;

//        if(voltage > maxV)
//            maxV = voltage;

//        for(unsigned int i = beginning; i <= ending; i++)
//        {
//            voltageVector.push_back(newData->getData()->getSegmentVoltage());
//            currentVector.push_back(newData->getData()->getSegmentCurrent());
//            timeVector.push_back(i/10.0);
//        }
//    }
//    currentGraph->setData(timeVector,currentVector);
//    voltageGraph->setData(timeVector,voltageVector);

//    ui->graphWidget->yAxis->setRange(0, maxV + 1.0);
//    currentGraph->rescaleAxes(true);

//    ui->graphWidget->replot();

void MainWindow::on_pushButton_released()
{
    ui->segmentWidget->addNewSegment();
    QSize currentSize = this->size();
    QSize recSize = this->sizeHint();

    int desWidth;
    if(recSize.width() < currentSize.width())
        desWidth = currentSize.width();
    else
        desWidth = recSize.width();

    this->resize(desWidth, currentSize.height());
    this->setMinimumSize(desWidth, recSize.height());
}
