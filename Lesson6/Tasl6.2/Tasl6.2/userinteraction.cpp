#include"userinteraction.h"

bool userInteractionWithTheCounter(Counter& counter) {
    char command;
    do {
        std::cout << "¬ведите команду ('+', '-', '=' или 'х'): ";
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