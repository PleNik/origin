#include"userinteraction.h"

bool userInteractionWithTheCounter(Counter& counter) {
    char command;
    do {
        std::cout << "������� ������� ('+', '-', '=' ��� '�'): ";
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

    } while (command != '�');

    return false;
};