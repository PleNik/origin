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

    connect(update_timer, SIGNAL(timeout()), SLOT(UpdateDataTime()));
    update_timer->start(100);
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
        stopwatch->StartTimerCircle();
        ui->pb_circle->setEnabled(true);

    } else {
        buttonStartOrStop = !buttonStartOrStop;
        ui->pb_startStop->setText("СТАРТ");
        stopwatch->StopStopwatch();
        stopwatch->StopTimerCircle();
        ui->pb_circle->setEnabled(false);

    }

}

void MainWindow::UpdateDataTime()
{
    QString str = stopwatch->strDataTime;
    ui->lb_time->setText(str);
}

void MainWindow::on_pb_circle_clicked()
{
    numberCircle ++;
    stopwatch->StopTimerCircle();
    QString str = stopwatch->strTimeCircle;
    ui->tb_timeCircle->append("Круг " + QString::number(numberCircle) + ", время: " + str + " сек");
    //ui->tb_timeCircle->append(str);
    stopwatch->StartTimerCircle();

}


void MainWindow::on_pb_clear_clicked()
{
    stopwatch->StopTimerCircle();
    ui->tb_timeCircle->clear();

    stopwatch->ResetStopwatch();

    numberCircle = 0;



}

