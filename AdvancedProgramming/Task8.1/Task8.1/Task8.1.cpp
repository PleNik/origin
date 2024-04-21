#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

	
void print_info(std::vector<int>& vec_int) {
	for (const auto& i : vec_int)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main() {
	std::string user_input;
	std::getline(std::cin, user_input); //запись из потокового ввода в строку user_input

	std::vector<int> v;
	
	std::istringstream iss (user_input); //для извлечения чисел из строки

	int int_value;
	while (iss>>int_value)
	{
		v.push_back(int_value);
	}

	std::cout << "[IN]: ";
	print_info(v);

std:sort(v.begin(), v.end(),
	[](const int& lhs, const int& rhs) {
		return lhs < rhs;
	}
);

	auto it = std::unique(v.begin(), v.end());
	v.erase(it, v.end());

	std::cout << "[OUT]: ";
	print_info(v);

}