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

private:
    int milliseconds, seconds, minutes;
    int secondsCircle;
    bool resetTimer  = true;

    QTimer* timer;
    QTimer* timerCircle;

public slots:
    void slotUpdateDataTime();
    void slotUpdateCircleTime();

};

#endif // STOPWATCH_H
