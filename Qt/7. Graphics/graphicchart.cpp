#include "graphicchart.h"

GraphicChart::GraphicChart(uint32_t numberGr)
{
    numGraphs = numberGr;
    ptrGraph.resize(numGraphs);

    //Создадим объекты серий
    for(int i = 0; i<numGraphs; i++){
        ptrGraph[i] = new QLineSeries(this);
    }
}

void GraphicChart::AddDataToGrahp(QVector<double> x, QVector<double> y, uint32_t numGraph)
{
    //Зададим размер графика, т.е. количество точек.
    uint32_t size = 0;
    //Необходимо, чтобы х и у были равны.
    if(x.size() >= y.size()){
        size = y.size();
    }
    else{
        size = x.size();
    }

    //Добавление точек в серию осуществляется при помощи метода append.
    for(int j = 0; j<size; j++){
        ptrGraph[numGraph]->append(x[j],y[j]);
    }
}

void GraphicChart::ClearGraph(QChart *chart)
{
    //Необходимо очистить все графики
    for(int i = 0; i<numGraphs; i++){
    //Очищаем серии
        ptrGraph[i]->clear();

        //Удаляем серии из графика
        chart->removeSeries(ptrGraph[i]);
    }
}

void GraphicChart::UpdateGraph(QChart *chart)
{
    for(int i = 0; i<numGraphs; i++){
        chart->addSeries(ptrGraph[i]);
    }
}
