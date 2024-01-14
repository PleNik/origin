#include <iostream>
#include<Windows.h>
#include<string>
#include "counter.h"
#include"userinteraction.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Вы хотите указать начальное значене счетчика? Введтие да или нет: ";
    std::string userInput;
    std::cin >> userInput;

    int initialCounterValue = 0;

    if (userInput == "да") {
        std::cout << "Введите начальное значение счетчика: ";
        std::cin >> initialCounterValue;

        Counter counter(initialCounterValue);

        userInteractionWithTheCounter(counter);
    }
    else {
        Counter counter1;
        userInteractionWithTheCounter(counter1);
    }

    std::cout << "До свидания!" << std::endl;

    return 0;
}