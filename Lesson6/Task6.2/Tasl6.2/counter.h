#pragma once
#include<iostream>

class Counter
{
private:
    int value;

public:
    void setIncrement();

    void setDecrement();

    void printValue();

    Counter();

    Counter(int value);

};