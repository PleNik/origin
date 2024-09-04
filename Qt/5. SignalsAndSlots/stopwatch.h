#ifndef STOPWATCH_H
#define STOPWATCH_H

#include<QObject>
#include<QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject* parent = nullptr);

    QString strDataTime;
    QString strTimeCircle;

    void StartStopwath();
    void StopStopwatch();
    void ResetStopwatch();

    void StartTimerCircle();
    void StopTimerCircle();

    //void updateCircleTime();

private:
    int milliseconds, seconds, minutes;
    int lap_milliseconds;
    int secondsCircle;
    bool resetTimer  = true;
    int timeCircle;
    int timePrevLap;

    QTimer* timer;


public slots:
    void slotUpdateDataTime();
    void updateCircleTime();

signals:
    void sig_SendCircleTime(QString str);

};

#endif // STOPWATCH_H
