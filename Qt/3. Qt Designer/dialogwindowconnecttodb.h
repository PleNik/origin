#ifndef DIALOGWINDOWCONNECTTODB_H
#define DIALOGWINDOWCONNECTTODB_H

#include <QDialog>
#include"windowconnectingtodb.h"

namespace Ui {
class DialogWindowConnectToDb;
}

class DialogWindowConnectToDb : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWindowConnectToDb(QWidget *parent = nullptr);
    ~DialogWindowConnectToDb();

private slots:
    void on_pB_OkConnektToDb_clicked();

private:
    Ui::DialogWindowConnectToDb *ui;
    WindowConnectingToDb* window_connecting_to_Db;
};

#endif // DIALOGWINDOWCONNECTTODB_H
