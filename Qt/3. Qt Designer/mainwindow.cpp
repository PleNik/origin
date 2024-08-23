#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialog_window_connect_to_Db = new DialogWindowConnectToDb(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_ConnectToDb_clicked()
{
    dialog_window_connect_to_Db->show();
}

