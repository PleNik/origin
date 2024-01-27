#include<iostream>
#include<string>
#include<windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите имя: ";
	std::string name;
	std::cin >> name;

	std::cout << "Здравствуйте, " << name << std::endl;

	return 0;
}