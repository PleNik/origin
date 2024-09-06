#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sb_initNum->setValue(200000);
    ui->rb_synchOff->setChecked(true);

   race1 = new Controller(&m);
   race2 = new Controller(&m);

   concurRace1 = new ExampleRace(&m);
   concurRace2 = new ExampleRace(&m);

    //������� �� ���������� ������ �������
    connect(race1, &Controller::sig_WorkFinish, [&](){
        //���������� ������ ����� ������ ����� �������� ������
        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("������� ����� �����: " + QString::number(number) + ", � ������ ���� " +
                                  QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }

    });

    connect(race2, &Controller::sig_WorkFinish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("������� ����� �����: " + QString::number(number) + ", � ������ ���� " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }

    });


    connect(concurRace1, &ExampleRace::sig_Finish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("������� ����� �����: " + QString::number(number) + ", � ������ ���� " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }
    });

    connect(concurRace2, &ExampleRace::sig_Finish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("������� ����� �����: " + QString::number(number) + ", � ������ ���� " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//����� ��������� ��� ������
void MainWindow::StartRace(void){


    if(ui->rb_qtConcur->isChecked()){

        //��� ��

        futConcurRace1 = QtConcurrent::run(&ExampleRace::DoWork, concurRace1, &number,
                                                   ui->rb_qtConcur->isChecked(),ui->sb_initNum->value());


        futConcurRace2 = QtConcurrent::run(&ExampleRace::DoWork, concurRace2, &number,
                                                   ui->rb_qtConcur->isChecked(),ui->sb_initNum->value());


    }
    else{
        emit race1->operate(&number, ui->rb_mutexOn->isChecked(), ui->sb_initNum->value());
        emit race2->operate(&number, ui->rb_mutexOn->isChecked(), ui->sb_initNum->value());
    }
}

//��������� ������ "�����"
void MainWindow::on_pb_start_clicked()
{
    ui->pb_start->setEnabled(false);
    countFinish = 0;
    number = 0;
    StartRace( );
}
