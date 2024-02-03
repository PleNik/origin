#include <iostream>
#include<Windows.h>

#include"Greeter.h"


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введтие имя: ";
    std::string name;
    std::cin >> name;

    Greeting::Greeter grt;

    std::cout << grt.greet(name) << std::endl;

    return 0;
}