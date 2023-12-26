#include <iostream>
#include<Windows.h>

enum class Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите номер месяца: ";
    int userInput;
    std::cin >> userInput;

    

    while (userInput) {

        Months month = static_cast<Months>(userInput);

        switch (month)
        {
        case Months::January:

            std::cout << "Январь" << std::endl;
            break;

        case Months::February:

            std::cout << "Февраль" << std::endl;
            break;

        case Months::March:

            std::cout << "Март" << std::endl;
            break;

        case Months::April:

            std::cout << "Апрель" << std::endl;
            break;

        case Months::May:

            std::cout << "Май" << std::endl;
            break;

        case Months::June:

            std::cout << "Июнь" << std::endl;
            break;

        case Months::July:

            std::cout << "Июль" << std::endl;
            break;

        case Months::August:

            std::cout << "Август" << std::endl;
            break;

        case Months::September:

            std::cout << "Сентябрь" << std::endl;
            break;

        case Months::October:

            std::cout << "Октябрь" << std::endl;
            break;

        case Months::November:

            std::cout << "Ноябрь" << std::endl;
            break;

        case Months::December:

            std::cout << "Декабрь" << std::endl;
            break;

        default:

            std::cout << "Неправильный номер!" << std::endl;
            break;
        }

        std::cout << "Введите номер месяца: ";
        std::cin >> userInput;
    }

    std::cout << "До свидания" << std::endl;

    return 0;
}