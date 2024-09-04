#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Stopwatch* stopwatch;
    bool buttonStartOrStop = true;

    int numberCircle = 0;

    QTimer* update_timer;

public slots:
    void UpdateDataTime();


private slots:
    void on_pb_startStop_clicked();
    void RcvCircleTime(QString str);

    void on_pb_circle_clicked();
    void on_pb_clear_clicked();
};
#endif // MAINWINDOW_H
