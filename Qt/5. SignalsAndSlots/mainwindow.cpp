#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_timer = new QTimer(this);
    stopwatch = new Stopwatch(this);

    ui->pb_startStop->setText("СТАРТ");
    ui->pb_circle->setEnabled(false);

    this->setWindowTitle("Stopwatch");

    connect (update_timer, &QTimer::timeout, this, &MainWindow::UpdateDataTime);
    update_timer->start(100);

    connect(stopwatch, &Stopwatch::sig_SendCircleTime, this, &MainWindow::RcvCircleTime);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_startStop_clicked()
{
    if(buttonStartOrStop) {

        buttonStartOrStop = !buttonStartOrStop;
        ui->pb_startStop->setText("СТОП");
        stopwatch->StartStopwath();
        ui->pb_circle->setEnabled(true);

    } else {
        buttonStartOrStop = !buttonStartOrStop;
        ui->pb_startStop->setText("СТАРТ");
        stopwatch->StopStopwatch();
        ui->pb_circle->setEnabled(false);

    }

}

void MainWindow::RcvCircleTime(QString str)
{
    ui->tb_timeCircle->append("Круг " + QString::number(numberCircle) + " " + " время: " + str + "мс");
}

void MainWindow::UpdateDataTime()
{
    QString str = stopwatch->strDataTime;
    ui->lb_time->setText(str);
}


void MainWindow::on_pb_circle_clicked()
{
    numberCircle ++;
    //QString str = stopwatch->strTimeCircle;
    stopwatch->updateCircleTime();

}

void MainWindow::on_pb_clear_clicked()
{
    ui->tb_timeCircle->clear();

    stopwatch->ResetStopwatch();

    numberCircle = 0;
}

