#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(size_t i = 1; i<=10; ++i) {

        ui->cmB_List->addItem(QString("Элемент № %1").arg(i));
    }

    ui->pB_Toggle->setText("Увеличение прогресс-бар");
    ui->pB_Toggle->setCheckable(true);

    ui->rB_On->setText("Увеличение прогресс-бар на 20%");
    ui->rB_Of->setText("Увеличение прогресс-бар на 10%");

    ui->prBar_Process->setMinimum(0);
    ui->prBar_Process->setMaximum(10);
    ui->prBar_Process->setValue(0);
    ui->prBar_Process->setFormat("%p%");

    ui->rB_On->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_Toggle_toggled(bool checked)
{
    if(checked==true) {

        ui->pB_Toggle->setStyleSheet("background-color : grey");

        int current_progress_bar = ui->prBar_Process->value();
        if(ui->rB_On->isChecked()) {
            current_progress_bar +=2 ;
        } else
            current_progress_bar ++;

        if(current_progress_bar>10) {
            ui->prBar_Process->setValue(0);
        }

        ui->prBar_Process->setValue(current_progress_bar);
  }else
     ui->pB_Toggle->setStyleSheet("background-color : light grey");
}



