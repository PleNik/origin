#ifndef WINDOWCONNECTINGTODB_H
#define WINDOWCONNECTINGTODB_H

#include <QDialog>

namespace Ui {
class WindowConnectingToDb;
}

class WindowConnectingToDb : public QDialog
{
    Q_OBJECT

public:
    explicit WindowConnectingToDb(QWidget *parent = nullptr);
    ~WindowConnectingToDb();

private:
    Ui::WindowConnectingToDb *ui;
};

#endif // WINDOWCONNECTINGTODB_H
