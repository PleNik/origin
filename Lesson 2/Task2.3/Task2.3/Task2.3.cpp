#include <iostream>
#include<string>
#include<Windows.h>

struct Address
{
    Address(const std::string& city, const std::string& street, int houseNumber, int apartamentNumber, int index)
    {
        this->city = city;
        this->street = street;
        this->houseNumber = houseNumber;
        this->apartamentNumber = apartamentNumber;
        this->index = index;
    }

    std::string city;
    std::string street;
    int houseNumber = 0;
    int apartamentNumber = 0;
    int index = 0;
};

void printAddress(const Address& address)
{
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout <<"Номер дома: " << address.houseNumber << std::endl;
    std::cout << "Номер квартиры: " << address.apartamentNumber << std::endl;
    std::cout << "Индекс: " << address.index << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Address address1("Москва", "Арбат", 12, 8, 123456);
    Address address2("Ижевск", "Пушкина", 59, 143, 953769);
    
    printAddress(address1);
    std::cout << "\n";

    printAddress(address2);

    return 0;
}