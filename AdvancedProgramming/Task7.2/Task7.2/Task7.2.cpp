#include <iostream>
#include<set>

int main() {
    std::cout << "[IN]:" << std::endl;
    int size = 0;
    int value = 0;
    std::set<int> my_set;

    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> value;
        my_set.insert(value);
    }

    std::cout << "[OUT]:"<<std::endl;

   for (auto itr = my_set.rbegin(); itr != my_set.rend(); itr++)
        std::cout << *itr << std::endl;
}
