#include <iostream>
#include<vector>

template<class T>
void squaring(T& a) {
    a *= a;
}

template<>
void squaring(std::vector<int>& v) {
    for (auto& i : v) {
        i *= i;
    }
}

int main() {
    int x = 4;
    std::cout << "[IN]: " << x << std::endl;
    squaring(x);
    std::cout << "[OUT]: " << x << std::endl;

    std::vector<int> vect {-1, 4, 8};
    std::cout << "[IN]: ";
    for (const auto i : vect)
        std::cout << i << ", ";
    std::cout << std::endl;

    squaring(vect);
    std::cout << "[OUT]: ";
    for (const auto& i : vect)
        std::cout << i << ", ";

}