#include <iostream>
#include<vector>

template<typename T>
void move_vectors(std::vector<T>& v1, std::vector<T>& v2) {
	v2 = std::move(v1);
}

int main() {

	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;

	std::cout << "vector one before move:" << std::endl;
	for (const auto& i : one)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "vector two before move:" << std::endl;
	for (const auto& i : two)
		std::cout << i << " ";
	std::cout << "\n\n";

	move_vectors(one, two);

	std::cout << "vector one after move:" << std::endl;
	for (const auto& i : one)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "vector two after move:" << std::endl;
	for (const auto& i : two)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}