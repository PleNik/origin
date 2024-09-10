#ifndef GRAPHICCHART_H
#define GRAPHICCHART_H

///Подключаем все что нужно для графиков
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>
#include <QObject>

#define FIRST_GRAPH 0

class GraphicChart : public QObject
{
    Q_OBJECT

public:
    GraphicChart(uint32_t numberGr = 0);

    void AddDataToGrahp(QVector<double> x, QVector<double> y, uint32_t numGraph);
    void ClearGraph(QChart* chart);
    void UpdateGraph(QChart* chart);


signals:
     void sig_dataIsReadyForRendering();

private:

    QList<QLineSeries*> ptrGraph;
    uint32_t numGraphs = 0;

};

#endif // GRAPHICCHART_H
