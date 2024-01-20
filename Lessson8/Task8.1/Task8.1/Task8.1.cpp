#include <iostream>
#include<string>
#include<Windows.h>

int function(std::string str, int fobidden_length);

int main() {
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int fobidden_length{};
    std::cout << "Введите запретную длину: ";
    std::cin >> fobidden_length;

    std::string str;
    

    while (true) {

        std::cout << "Введите слово: ";
        std::cin >> str;

        try {

            std::cout << "Длина слова " << str << " равна " << function(str, fobidden_length) << std::endl;
        }
        catch (const char* bad_length) {
            std::cout << bad_length << std::endl;
            break;
        }

    }

    return 0;
}

int function(std::string str, int fobidden_length)
{
    if (str.length() != fobidden_length) {

        return str.length();
    }
    
    throw "Вы ввели слово запретной длины! До свидания";
}
