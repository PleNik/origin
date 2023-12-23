#include <iostream>
#include<Windows.h>

enum class Months {
    Январь = 1,
    Февраль,
    Март,
    Апрель,
    Май,
    Июнь,
    Июль,
    Август,
    Сентябрь,
    Октябрь,
    Ноябрь,
    Декабрь
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите номер месяца: ";
    int userInput;
    std::cin >> userInput;

    while (userInput) {
        switch (userInput)
        {
        case static_cast<int>(Months::Январь):

            std::cout << "Январь" << std::endl;
            break;

        case static_cast<int>(Months::Февраль):

            std::cout << "Февраль" << std::endl;
            break;

        case static_cast<int>(Months::Март):

            std::cout << "Март" << std::endl;
            break;

        case static_cast<int>(Months::Апрель):

            std::cout << "Апрель" << std::endl;
            break;

        case static_cast<int>(Months::Май):

            std::cout << "Май" << std::endl;
            break;

        case static_cast<int>(Months::Июнь):

            std::cout << "Июнь" << std::endl;
            break;

        case static_cast<int>(Months::Июль):

            std::cout << "Июль" << std::endl;
            break;

        case static_cast<int>(Months::Август):

            std::cout << "Август" << std::endl;
            break;

        case static_cast<int>(Months::Сентябрь):

            std::cout << "Сентябрь" << std::endl;
            break;

        case static_cast<int>(Months::Октябрь):

            std::cout << "Октябрь" << std::endl;
            break;

        case static_cast<int>(Months::Ноябрь):

            std::cout << "Ноябрь" << std::endl;
            break;

        case static_cast<int>(Months::Декабрь):

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