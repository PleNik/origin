#include "windowconnectingtodb.h"
#include "ui_windowconnectingtodb.h"

WindowConnectingToDb::WindowConnectingToDb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowConnectingToDb)
{
    ui->setupUi(this);
}

WindowConnectingToDb::~WindowConnectingToDb()
{
    delete ui;
}
