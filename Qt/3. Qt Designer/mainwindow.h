#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"dialogwindowconnecttodb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_ConnectToDb_clicked();

private:
    Ui::MainWindow *ui;
    DialogWindowConnectToDb* dialog_window_connect_to_Db;
};
#endif // MAINWINDOW_H
