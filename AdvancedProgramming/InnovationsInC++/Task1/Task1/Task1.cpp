#include <iostream>
#include<vector>
#include<algorithm>



int main() {

	setlocale(LC_ALL, "ru");

	std::vector<int> v {4,7,9,14,12};



	auto func = [&v](int value) {
		for (auto i = v.begin(); i != v.end(); i++) {
			if (*i % 2)
				*i *= value;
		}
	};
	std::cout << "Входные данные: ";
	for (const auto& i : v) {
		std::cout << i << " ";
	}

	std::cout << std::endl;

	func(3);

	std::cout << "Выходные данные: ";
	for (const auto& i : v) {
		std::cout << i << " ";
	}
	
	return 0;
}