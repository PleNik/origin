#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) : QObject{parent}
{
    this->milliseconds = 0, this->seconds = 0; this->minutes = 0;
    timer = new QTimer(this);
    timerCircle = new QTimer(this);

    connect (timer, SIGNAL(timeout()), SLOT(slotUpdateDataTime()));
    connect(timerCircle, SIGNAL(timeout()), SLOT(slotUpdateCircleTime()));
    //timerCircle->start(1000);
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
    seconds = 0;
    minutes = 0;
    resetTimer = false;

}

void Stopwatch::StartTimerCircle()
{
    timerCircle->start(1000);
}

void Stopwatch::StopTimerCircle()
{
    timerCircle->stop();
    secondsCircle = 0;
}

void Stopwatch::slotUpdateDataTime()
{

    milliseconds++;

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

void Stopwatch::slotUpdateCircleTime()
{
    secondsCircle++;
    strTimeCircle = QString::number(secondsCircle);
}

