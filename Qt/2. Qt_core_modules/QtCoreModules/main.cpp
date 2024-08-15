#include <QCoreApplication>
#include<QSqlDatabase>
#include<QAbstractSocket>
#include<QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject* object = new QObject;

    QSqlDatabase sqlDatabase;
    QAbstractSocket abstractSocket(QAbstractSocket::TcpSocket, object);

    delete object;

    return a.exec();
}
