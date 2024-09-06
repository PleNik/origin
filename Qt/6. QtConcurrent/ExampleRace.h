#ifndef EXAMPLERACE_H
#define EXAMPLERACE_H

#include <QThread>
#include <QMutex>
#include <functional>

//������� ����� � ������� ����� ������������� ���, ����������� � ���������� �������
class ExampleRace : public QObject{
    Q_OBJECT
    QMutex* mut;    //����� ������� �������� �������������

public:
    //����������� �������
    ExampleRace(QMutex* m) : mut(m){
    }
    //�������� ��������� �� ���������� ������� ����� ����������������, ���� ��������� ���������, � ��������� ��������
    void DoWork(uint32_t* inc, bool mutexOn, int numIterat);

signals:

    void sig_Finish( void );

};


//�����-������� QThread, ������� ����� ������������ ��� ����� �� �������. ������ ��� ��������� ������������ QThread,
//����� �������������� ����� run, �� ������������ Qt ����������� ������ ������ ���.
class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread; //��������� ������
    QMutex* mut; //����������� �������

public:
    Controller(QMutex* m) : mut(m) {

        ExampleRace *race = new ExampleRace(mut); //��������� ������ ������
        race->moveToThread(&workerThread); //�������� � �����
        connect(&workerThread, &QThread::finished, race, &QObject::deleteLater); //�� ���������� ������ ������� ��������� ������
        connect(this, &Controller::operate, race, &ExampleRace::DoWork); //��������� "�������" �����
        connect(race, &ExampleRace::sig_Finish, this, &Controller::sig_WorkFinish); //������������ ������ ��� ����������� � GUI
        workerThread.start(); //��������� ������ ������
    }
    ~Controller(){

        //��������� ������ ������
        workerThread.quit();
        workerThread.wait();

    }

signals:
    void operate( uint32_t *num, bool mutexOn, int numIterat );
    void sig_WorkFinish( void );

};


#endif // EXAMPLERACE_H
