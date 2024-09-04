#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) : QObject{parent}
{
    this->milliseconds = 0, this->seconds = 0; this->minutes = 0;
    this->lap_milliseconds = 0;
    timer = new QTimer(this);

    connect (timer, &QTimer::timeout, this, &Stopwatch::slotUpdateDataTime);

}

void Stopwatch::StartStopwath()
{
    timer->start(1);
}

void Stopwatch::StopStopwatch()
{
    timer->stop();
}

void Stopwatch::ResetStopwatch()
{
    milliseconds = 0;
    lap_milliseconds = 0;
    seconds = 0;
    minutes = 0;
    timePrevLap = 0;
    //resetTimer = false;

}

void Stopwatch::updateCircleTime()
{
    timeCircle = lap_milliseconds - timePrevLap;
    timePrevLap = lap_milliseconds;

    strTimeCircle = QString::number(timeCircle);
    emit sig_SendCircleTime(strTimeCircle);

}

void Stopwatch::slotUpdateDataTime()
{

    milliseconds++;

    lap_milliseconds++;

   if(milliseconds >= 1000) {
       milliseconds = 0;
       seconds++;
   }
   if(seconds >= 60) {
       seconds = 0;
       minutes++;
   }

   strDataTime = QString::number(minutes) + "   :   "
           + QString::number(seconds) + "   :   "
           + QString::number(milliseconds);


}

