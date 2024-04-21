#include <iostream>
#include<vector>
#include<list>
#include<set>
#include<string>


template<class T>
void print_container(T& cont) {
	for (auto itr = cont.begin(); itr != cont.end(); itr++)
		std::cout<<*itr << " ";
	std::cout << std::endl;
}


int main() {

	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set);

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list);

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector);
}
