#include <iostream>
#include<Windows.h>

#include"DynamicLeaving.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите имя: ";
	std::string name;
	std::cin >> name;

	DynamicLeaving::Leaver lvr;

	std::cout << lvr.leave(name) << std::endl;

	return 0;
}