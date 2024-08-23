#include "dialogwindowconnecttodb.h"
#include "ui_dialogwindowconnecttodb.h"

DialogWindowConnectToDb::DialogWindowConnectToDb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindowConnectToDb)
{
    ui->setupUi(this);

    window_connecting_to_Db = new WindowConnectingToDb(this);
}

DialogWindowConnectToDb::~DialogWindowConnectToDb()
{
    delete ui;
}

void DialogWindowConnectToDb::on_pB_OkConnektToDb_clicked()
{
    window_connecting_to_Db->show();
}

