#include <QCoreApplication>
#include <QAbstractSocket>
#include <QHostAddress>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject* object = new(QObject);

    QAbstractSocket abstractSocket(QAbstractSocket::TcpSocket, object);

    QHostAddress address;

    address.setAddress("192.168.123.132");

    return a.exec();
}
