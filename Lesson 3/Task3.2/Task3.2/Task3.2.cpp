#include <iostream>
#include<Windows.h>
#include<string>

class Counter
{
private:
    int value;

public:
    void setIncrement() {
        value++;
    };


    void setDecrement() {
        value--;
    };

    void printValue() {
        std::cout << value << std::endl;
    };

    Counter() {
        this->value = 1;
    };

    Counter(int value) {
        this->value = value;
    };

};

bool userInteractionWithTheCounter(Counter& counter);

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
    else
    {
        Counter counter1;
        userInteractionWithTheCounter(counter1);
    }

    std::cout << "До свидания!" << std::endl;

    return 0;
}

bool userInteractionWithTheCounter(Counter& counter) {
    char command;
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'х'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.setIncrement();
            break;

        case '-':
            counter.setDecrement();
            break;

        case '=':
            counter.printValue();
            break;
        }

    } while (command != 'х');

    return false;
};