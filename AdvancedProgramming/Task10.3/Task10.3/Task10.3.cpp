#include <iostream>

#include"my_ptr.h"


int main() {

	int* p = new int(5);
	msp::my_unique_ptr<int> p1(p);
	p1.relese();

	msp::my_unique_ptr<std::string> str (new std::string("Hello"));
	
	std::cout << *str << std::endl;
}
